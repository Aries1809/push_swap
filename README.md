*This project has been created as part of the 42 curriculum by kseltenr, skaprash.*

# push_swap

## Description

`push_swap` sorts a list of integers using two stacks, **a** and **b**, and a small set of
allowed operations. The program does not print the sorted numbers. It prints the
**list of operations** that sorts them, and that list should be as short as possible.

At the start, every number is on stack **a** (the first argument is the top) and **b** is
empty. At the end, **a** must be in ascending order with the smallest number on top, and
**b** must be empty. These are the allowed operations:

| Op | Effect |
|----|--------|
| `sa` / `sb` / `ss` | swap the top two elements of a / b / both |
| `pa` / `pb` | move the top of b to a / the top of a to b |
| `ra` / `rb` / `rr` | rotate a / b / both up (top becomes bottom) |
| `rra` / `rrb` / `rrr` | rotate a / b / both down (bottom becomes top) |

This version of the subject asks for **four strategies inside one binary**. Each one has a
complexity class, and that class is measured in *number of operations produced*:

| Flag | Strategy | Class |
|------|----------|-------|
| `--simple` | Insertion sort adaptation | O(n²) |
| `--medium` | Bucket (chunk) sort with ~√n buckets | O(n√n) |
| `--complex` | 3-way quicksort over four stack "locations" | O(n log n) |
| `--adaptive` (default) | Picks one of the above from the measured disorder | per regime |

The bonus part is a `checker` program. It reads operations from stdin, runs them on the
given stack and prints `OK` or `KO`.

## Instructions

### Build

```sh
make            # builds libft, then push_swap
make bonus      # builds checker
make clean      # removes object files
make fclean     # removes object files, libft.a, push_swap and checker
make re         # fclean + all
make DEBUG=1    # -g3 build; also prints the final stack after sorting
```

The project is compiled with `cc -Wall -Wextra -Werror`. The Makefile builds `libft/`
through that folder's own Makefile and does not relink when nothing has changed.

### Run

```sh
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <numbers...>
```

* Numbers can be given as separate arguments, in one quoted string, or mixed:
  `./push_swap 3 2 1`, `./push_swap "3 2 1"` and `./push_swap "3 2" 1` are all the same.
* Flags can go anywhere in the argument list. Giving the same strategy flag twice is
  allowed. Giving two *different* strategies is an error.
* With no arguments, nothing is printed.
* On invalid input, the program prints `Error\n` on **stderr** and exits with status 1.
  Invalid input means something that is not an integer (`1a`, `-`, `+`, `""`), a value
  outside the `int` range, a duplicate (`0` and `-0` count as duplicates), or an unknown
  flag.

### Examples

```sh
$ ./push_swap 2 1 3 6 5 8
pb
pb
pb
sa
pa
pa
ra
pa
rra

$ ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG
OK

$ ./push_swap $(shuf -i 0-9999 -n 500) | wc -l
4148

$ ./push_swap --simple 3 2 3
Error
```

### Benchmark mode

`--bench` writes metrics to **stderr** after sorting. The operations still go to stdout,
so the two outputs can be piped or redirected separately:

```sh
$ ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
$ ./push_swap --bench $ARG > /dev/null                  # metrics only
$ ./push_swap --bench $ARG 2> bench.txt | ./checker $ARG # check + save metrics
OK
$ cat bench.txt
[bench] disorder:	50.10%
[bench] strategy:	Adaptive / O(n log n)
[bench] total_ops:	4148
[bench] sa:	142	sb:	0	ss:	0
[bench] pa:	941	pb:	941
[bench] ra:	507	rb:	485	rr:	218
[bench] rra:	457	rrb:	441	rrr:	16
```

In adaptive mode, the strategy line also shows the complexity class of the method the
adaptive strategy actually used.

### Checker (bonus)

```sh
$ ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

The checker parses arguments the same way as `push_swap`. It prints `Error` on stderr for
bad arguments, and also for any line that is not exactly one operation followed by `\n`
(`SA`, `sa `, ` sa` and a last line with no newline are all rejected). With no arguments
it prints nothing.

## Algorithms

### Shared groundwork

* **Stack representation:** a doubly linked list with `top`, `bot` and `size`. Every
  operation costs O(1): push, swap and rotate in both directions.
* **Index normalisation:** after parsing, each value is replaced by its rank (`0 … n-1`)
  in `node->index`. All algorithms work on ranks, so they don't depend on the actual
  values, and bucket and pivot boundaries become simple integer ranges.
* **Disorder:** computed before any move, exactly as the subject defines it: the number
  of pairs `(i < j)` with `a[i] > a[j]`, divided by `n(n-1)/2`. This is O(n²) time and
  O(1) extra space. It is the normalised inversion count, also known as the normalised
  Kendall tau distance from the sorted order.
* **Peephole optimiser (`combine.c`):** every operation goes through `ps_op`, which keeps
  one pending operation. When the next operation arrives, the pair is merged
  (`ra`+`rb` → `rr`, `rra`+`rrb` → `rrr`, `sa`+`sb` → `ss`) or dropped because the two
  cancel out (`pa`/`pb`, `ra`/`rra`, `rb`/`rrb`, `rr`/`rrr`, `sa`/`sa`, …). This never
  changes the final state, and it never makes the output longer.
* **Small inputs:** two elements take one `sa`. Three elements are handled by
  `sort_three`, which needs at most 2 operations.

### 1. Simple: insertion sort (O(n²))

1. Push everything except three elements to **b** (`pb`), then sort the three left in **a**.
2. For each element on top of **b**, find where it belongs in **a**: the smallest element
   of **a** that is bigger than it, or the minimum of **a** if there is none. Rotate that
   position to the top the shorter way (`ra` or `rra`), then `pa`.
3. At the end, rotate the minimum to the top.

**Bound:** step 1 takes at most n operations. Each insertion takes at most ⌊|a|/2⌋ + 1
operations, and |a| grows from 3 to n. Adding it up gives at most n²/4 + O(n), so
**O(n²) time**. **Space:** the n nodes plus O(1).

This is the classic insertion sort, with the rotation of **a** playing the part of the
element shifting. It is easy to prove correct, and on inputs with very few inversions the
insertion points sit close to the top of **a**, so it stays cheap there.

### 2. Medium: bucket / chunk sort (O(n√n))

1. Let `r` be the smallest integer with `n / r ≤ r` (≈ √n), and `k = max(1, ⌊2r/5⌋)` the
   number of buckets. Bucket `i` holds the ranks `[i·n/k, (i+1)·n/k)`, and the last
   bucket takes whatever is left over.
2. For each bucket in turn, rotate **a** and `pb` every element that belongs to the
   bucket. If a pushed element is in the **lower half** of its bucket, it is sent to the
   bottom of **b** right away with `rb`. **b** ends up shaped like a mountain:
   `[U_{k-1} … U_1 U_0 L_0 L_1 … L_{k-1}]`. Each bucket's upper half sits near the top and
   its lower half near the bottom, so the largest remaining values are always close to
   one of the two ends.
3. Empty **b** from the largest rank down: rotate the maximum to the top the shorter way
   and `pa`. If the second-largest is cheaper to reach, push it first, then the maximum,
   then `sa`.

**Bound:** each bucket pass needs at most one full turn of **a**, so phase 2 costs at most
`k·n + 2n = O(n√n)`. In phase 3, the maximum is always within one half-bucket
(≤ n/k ≈ 2.5√n) of an end of **b**, so each `pa` costs O(√n) and the n of them cost
**O(n√n)**. **Space:** the n nodes plus O(1).

**Why 2/5·√n buckets rather than √n:** each bucket costs up to one full rotation of **a**,
while bigger buckets make phase 3 longer. Testing showed that fewer, larger buckets plus
the upper/lower split of step 2 minimise the total. The number of buckets still grows as
Θ(√n), so the class does not change.

### 3. Complex: 3-way quicksort over four locations (O(n log n))

A **chunk** is a group of `size` consecutive ranks that sits at one of four locations:
`TOP_A`, `BOT_A`, `TOP_B` or `BOT_B`. Sorting a chunk means leaving it sorted at the top
of **a**.

1. Take the chunk's minimum rank `lo` and split the range into thirds with two pivots,
   `lo + size/3` and `lo + 2·size/3`.
2. Read the chunk element by element from its location and send each one to a new
   location based on its third. The **max** third goes to A, the **mid** third to B or
   the bottom of A, and the **min** third to the far end of B:

   | from | max → | mid → | min → |
   |------|-------|-------|-------|
   | TOP_A | BOT_A | TOP_B | BOT_B |
   | BOT_A | TOP_A | TOP_B | BOT_B |
   | TOP_B | TOP_A | BOT_A | BOT_B |
   | BOT_B | TOP_A | BOT_A | TOP_B |

   Shortcut: if the next element is already the chunk's largest value and the chunk is
   not at `TOP_A`, it goes straight to the top of **a**, where it already belongs.
3. Recurse on the **max**, then the **mid**, then the **min** chunk. Each one ends up
   sorted at the top of **a**, on top of the previous one, so **a** grows correctly from
   the largest values down.
4. Base cases: chunks of size 1 or 2 are moved to `TOP_A` (with an `sa` if needed).
   Chunks of size 3 get a dedicated ≤3-move routine.

**Bound:** moving one element between any two locations takes at most 3 operations (for
example `rrb pa ra`). Each split moves every element of the chunk once, and the chunk
sizes shrink by a factor of 3, so the recursion is ⌈log₃ n⌉ levels deep. That gives
≤ 3n·⌈log₃ n⌉ + O(n) operations, which is **O(n log n)**. **Space:** the n nodes plus
an O(log n) recursion stack.

**Why not radix sort:** an LSD binary radix sort is also in the code (commented out in
`complex.c`). It always costs about `n·⌈log₂ n⌉` `pa`/`pb`/`ra` operations, whatever the
input looks like. Here it averaged **~1265** operations for 100 numbers and **~7760** for
500, compared with **~620** and **~4140** for the 3-way quicksort. The quicksort wins for
two reasons. Splitting into thirds needs log₃ levels instead of log₂, and using all four
stack ends means nothing is rotated "out of the way" without being placed.

### 4. Adaptive (default)

```
disorder <  0.2  → simple   (insertion sort)   O(n²)
disorder <  0.5  → medium   (bucket sort)      O(n√n)
disorder >= 0.5  → complex  (3-way quicksort)  O(n log n)
```

**Thresholds:** we use the regime boundaries given by the subject. Here is why each
method fits its regime:

* **Low disorder (< 0.2):** few pairs are inverted, so most elements are already near
  their final position relative to the others. The insertion point for each element is
  usually close to the top of **a**, which is where insertion sort is cheapest. It is also
  the only regime where an O(n²) method is allowed.
* **Medium disorder (0.2 – 0.5):** the bucket sort's cost hardly depends on the input
  order, and it is the cheapest method for n ≈ 100 (see the table below). The O(n√n) bound
  holds whatever the input looks like.
* **High disorder (≥ 0.5):** at this level the input is essentially random. The 3-way
  quicksort has the best asymptotic bound and gives the lowest counts for large n.

**Complexity of the adaptive strategy:** choosing the strategy costs O(n²) *time* to
compute the disorder, but **zero operations**. In the Push_swap model, the cost is
therefore exactly that of the chosen method: O(n²), O(n√n) or O(n log n), as the subject
requires for each regime. Space is O(n) in every case.

## Performance

Average operation counts measured with an independent checker (all results `OK`).
Random inputs were drawn uniformly, and the disorder levels were produced by random
transpositions of a sorted list.

| n | disorder | adaptive | simple | medium | complex |
|---|----------|---------:|-------:|-------:|--------:|
| 100 | random (~0.5) | **600** (max 644) | 1457 | 579 | 622 |
| 500 | random (~0.5) | **4559** (max 5202) | 32287 | 5089 | 4136 |
| 100 | 0.07 | 359 | 359 | 413 | 571 |
| 100 | 0.31 | 555 | 1112 | 555 | 628 |
| 500 | 0.06 | 4239 | 4239 | 3298 | 3965 |
| 500 | 0.31 | 4774 | 24444 | 4774 | 4179 |

The subject's targets are < 700 operations for 100 numbers and < 5500 for 500 numbers
("excellent"). Both are met on random input with every strategy except `--simple`.

On random data the disorder is close to 0.5. Its standard deviation is about ±0.03 for
n = 100 and ±0.015 for n = 500. This means adaptive mode picks medium or complex roughly
half the time each, and that is why the adaptive averages fall between the two.

## Project structure

```
inc/push_swap.h                 types (t_node, t_stack, t_ps, t_op, t_chunk…) and prototypes
src/main.c                      push_swap entry point, strategy dispatch
src/main_bonus.c                checker entry point
src/init/parsing.c              argument / flag parsing and validation
src/init/stack.c                stack creation, free, sortedness, rank normalisation
src/operations/                 primitive stack moves, op application/printing, peephole combiner
src/algorithms/simple.c         insertion sort
src/algorithms/medium.c         bucket sort
src/algorithms/complex.c        3-way quicksort (+ radix sort kept for reference)
src/algorithms/complex_helpers/ chunk access and base cases for the quicksort
src/algorithms/general_helpers/ rotations, moves between locations, sort_three
src/algorithms/adaptive.c       disorder-based selection
src/bench/                      disorder metric and --bench output
libft/                          our libft (+ ft_printf, ft_dprintf, get_next_line)
```

## Contributions

* **kseltenr:** project setup and Makefile, stack and parsing code, operations and
  peephole combiner, disorder metric and `--bench` mode, the **simple** (insertion sort)
  and **complex** (3-way quicksort) strategies, the **adaptive** strategy, the bonus
  `checker`, and the final rework and tuning of the medium strategy.
* **skaprash:** the first implementation of the **medium** bucket sort (distributing
  buckets to b and extracting the maximum back to a), and the early sortedness-check
  helper.

## Resources

* Insertion sort: <https://en.wikipedia.org/wiki/Insertion_sort>
* Bucket sort: <https://en.wikipedia.org/wiki/Bucket_sort>
* Quicksort and 3-way partitioning: <https://en.wikipedia.org/wiki/Quicksort>
* Radix sort: <https://en.wikipedia.org/wiki/Radix_sort>
* Big O notation: <https://en.wikipedia.org/wiki/Big_O_notation>
* Inversions, the basis of the disorder metric:
  <https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)>
* Kendall tau distance: <https://en.wikipedia.org/wiki/Kendall_tau_distance>
* Cormen, Leiserson, Rivest, Stein: *Introduction to Algorithms*, chapters on insertion
  sort, quicksort and sorting in linear time.

### Use of AI

An AI assistant (Claude) was used **after the implementation** to review the finished
code against the subject and to test it. It ran edge-case and error-handling tests,
Valgrind leak checks, op-count benchmarks across disorder levels, and a comparison with
the commented-out radix sort. It also drafted this README from those results and from
our code. We checked its explanations against the implementation.
