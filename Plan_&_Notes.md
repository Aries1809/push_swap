##Chapter V
###Objectives
The goal of this project is to make you discover algorithmic complexity in a very
concrete way.
Sorting numbers is easy; sorting them fast with only two stacks and a handful of allowed
moves is another story. Sorting a fully random list and sorting an almost sorted list are
also two extremely different things.
You will quickly see how the choice of algorithm can make the difference between a quick
win and an endless scroll of operations.




###Mandatory part
###VI.2
The rules
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
without any duplicate.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
sa (swap a): Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
9Push_swap
Because Swap_push doesn’t feel as natural
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by one.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by one.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by one.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by one.
The last element becomes the first one.
rrr : rra and rrb at the same time.


###VI.3 ~~~~~~~~~~~~~
Algorithm requirements
you must implement four distinct sorting strategies
Your program must be able to select a strategy at runtime based on the input configuration.


###VI.3.1 ~~~~~~~~~~~~~~~~~
####Complexity model and operation constraints
        ??????
 When you state a complexity class,
it must reflect the cost measured in number of Push_swap operations generated,
not the theoretical complexity of a classical array-based algorithm.
        ??????  //WTF does any of this mean...?//


###VI.3.2 ~~~~~~~~~~~~~~~~~
Disorder metric (mandatory)