*This project has been created as part of the 42 curriculum by kseltenr*

# Description

libft is the first project of the 42 core curriculum, in which I had to recreate standard C library functions from scratch without relying on external libraries.

The primary goal of the project is to build an understanding of C programming, pointers, and manual memory management.
By coding these functions, I compiled my own custom static library (libft.a). This library becomes an essential, personalized toolkit that I will use and expand throughout the rest of the 42 curriculum.

This version of libft also includes my [ft_printf](#ft_printf) and [get_next_line](#get_next_line) projects (both with bonus), plus [ft_fprintf](#ft_fprintf) and [ft_dprintf](#ft_dprintf), so everything can be linked from a single `libft.a`.

## Project structure

```
libft/
├── Makefile
├── inc/
│   ├── libft.h                  # main header, includes the four below
│   ├── ft_printf_bonus.h
│   ├── ft_fprintf.h
│   ├── ft_dprintf.h
│   └── get_next_line_bonus.h
└── src/
    ├── libc/                    # original libft functions
    ├── printf/                  # ft_printf
    ├── fprintf/                 # ft_fprintf
    ├── dprintf/                 # ft_dprintf
    └── gnl/                     # get_next_line
```

## Functions from `<ctype.h>`

- [ft_isascii](src/libc/ft_isascii.c): test for ASCII character
- [ft_isalnum](src/libc/ft_isalnum.c): alphanumeric character test
- [ft_isalpha](src/libc/ft_isalpha.c): alphabetic character test
- [ft_isdigit](src/libc/ft_isdigit.c): decimal-digit character test
- [ft_isprint](src/libc/ft_isprint.c): printing character test
- [ft_tolower](src/libc/ft_tolower.c): uppercase to lowercase letter conversion
- [ft_toupper](src/libc/ft_toupper.c): lowercase to uppercase letter conversion

## Functions from `<stdlib.h>`

- [ft_atoi](src/libc/ft_atoi.c): convert ASCII string to integer
- [ft_calloc](src/libc/ft_calloc.c): memory allocation

## Functions from `<strings.h>`

- [ft_bzero](src/libc/ft_bzero.c): write zeroes to a byte string
- [ft_memset](src/libc/ft_memset.c): write a byte to a byte string
- [ft_memchr](src/libc/ft_memchr.c): locate byte in byte string
- [ft_memcmp](src/libc/ft_memcmp.c): compare byte string
- [ft_memmove](src/libc/ft_memmove.c): copy byte string
- [ft_memcpy](src/libc/ft_memcpy.c): copy memory area

## Functions from `<string.h>`

- [ft_strlen](src/libc/ft_strlen.c): find length of string
- [ft_strchr](src/libc/ft_strchr.c): locate character in string (first occurrence)
- [ft_strrchr](src/libc/ft_strrchr.c): locate character in string (last occurrence)
- [ft_strnstr](src/libc/ft_strnstr.c): locate a substring in a string (size bounded)
- [ft_strncmp](src/libc/ft_strncmp.c): compare strings (size bounded)
- [ft_strdup](src/libc/ft_strdup.c): save a copy of a string (with malloc)
- [ft_strlcpy](src/libc/ft_strlcpy.c): size bounded string copying
- [ft_strlcat](src/libc/ft_strlcat.c): size bounded string concatenation

## Non-standard functions

- [ft_putchar_fd](src/libc/ft_putchar_fd.c): output character to given file
- [ft_putstr_fd](src/libc/ft_putstr_fd.c): output string to given file
- [ft_putendl_fd](src/libc/ft_putendl_fd.c): output string to given file with newline
- [ft_putnbr_fd](src/libc/ft_putnbr_fd.c): output integer to given file
- [ft_itoa](src/libc/ft_itoa.c): convert integer to ASCII string
- [ft_substr](src/libc/ft_substr.c): extract substring from string
- [ft_strtrim](src/libc/ft_strtrim.c): trim beginning and end of string with specified character
- [ft_strjoin](src/libc/ft_strjoin.c): concatenate two strings into a new string (with malloc)
- [ft_split](src/libc/ft_split.c): split string with specified character as delimiter into an array of strings
- [ft_strmapi](src/libc/ft_strmapi.c): create a new string from modifying string with specified function
- [ft_striteri](src/libc/ft_striteri.c): apply a function to each character of a string, passing its index as an argument so it can be modified in place

## Linked list functions

- [ft_lstnew](src/libc/ft_lstnew.c): create new list
- [ft_lstsize](src/libc/ft_lstsize.c): count elements of a list
- [ft_lstlast](src/libc/ft_lstlast.c): find last element of list
- [ft_lstadd_back](src/libc/ft_lstadd_back.c): add new element at end of list
- [ft_lstadd_front](src/libc/ft_lstadd_front.c): add new element at beginning of list
- [ft_lstdelone](src/libc/ft_lstdelone.c): delete element from list
- [ft_lstclear](src/libc/ft_lstclear.c): delete sequence of elements of list from a starting point
- [ft_lstiter](src/libc/ft_lstiter.c): apply function to content of all list's elements
- [ft_lstmap](src/libc/ft_lstmap.c): apply function to content of all list's elements into a new list

## ft_printf

- [ft_printf](src/printf/ft_printf_bonus.c): formatted output to stdout, returns the number of characters printed
  - conversions: `%c %s %p %d %i %u %x %X %%`
  - flags: `-` `0` `#` `+` and space, plus field width and `.precision`
- [ft_parse_bonus.c](src/printf/ft_parse_bonus.c): reads flags, width, precision and conversion into a `t_spec`
- [ft_convert_bonus.c](src/printf/ft_convert_bonus.c): turns numbers and strings into their printed form
- [ft_emit_bonus.c](src/printf/ft_emit_bonus.c): writes the result with padding and prefixes

## ft_fprintf

- [ft_fprintf](src/fprintf/ft_fprintf.c): like `ft_printf`, but writes to the `FILE *` stream given as first argument, like `fprintf` (`ft_fprintf(stderr, "error: %s\n", msg)`), returns the number of characters printed or `-1` on error
  - same conversions and flags as `ft_printf`, and reuses its parser ([ft_parse_bonus.c](src/printf/ft_parse_bonus.c))
- [ft_fconvert.c](src/fprintf/ft_fconvert.c) and [ft_femit.c](src/fprintf/ft_femit.c): same as the `ft_printf` versions, but write to the stream stored in `t_spec` (through `fwrite`, so output is buffered like the other stdio functions)

## ft_dprintf

- [ft_dprintf](src/dprintf/ft_dprintf.c): like `ft_printf`, but writes to the file descriptor given as first argument, like `dprintf` (`ft_dprintf(2, "error: %s\n", msg)`), returns the number of characters printed or `-1` on error
  - same conversions and flags as `ft_printf`, and reuses its parser ([ft_parse_bonus.c](src/printf/ft_parse_bonus.c))
- [ft_dconvert.c](src/dprintf/ft_dconvert.c) and [ft_demit.c](src/dprintf/ft_demit.c): same as the `ft_printf` versions, but write to the file descriptor stored in `t_spec` (through `write`, so output is unbuffered)

## get_next_line

- [get_next_line](src/gnl/get_next_line_bonus.c): returns the next line read from a file descriptor (including the `\n`), or `NULL` at end of file or on error
  - works with several file descriptors at the same time
  - read size is set by `BUFFER_SIZE` (default 42)
- [get_next_line_utils_bonus.c](src/gnl/get_next_line_utils_bonus.c): buffer helpers (finding the newline, extracting a line, growing the buffer)

# Instructions

## 1. Compilation

run in the terminal:
```bash
cd path/to/libft && make
```

To use a different buffer size for get_next_line:
```bash
make BUFFER_SIZE=1
```
Changing `BUFFER_SIZE` recompiles get_next_line automatically, no `make re` needed.

Other rules: `make clean` (remove object files), `make fclean` (also remove `libft.a`), `make re` (rebuild everything).

## 2. Usage

- include this header in the code (it also gives access to `ft_printf`, `ft_fprintf`, `ft_dprintf` and `get_next_line`):
```c
#include "libft.h"
```
- add these flags when compiling the code:
```bash
-I path/to/libft/inc -L path/to/libft -lft
```

## 3. Tester

I used this tester: [libftTester](https://github.com/Tripouille/libftTester)

Most files in `src/libc/` also have a commented-out test `main` at the bottom, with instructions on how to run it.

# Resources

Manual pages of the functions, geeksforgeeks.org for understanding concepts better (eg. malloc, linked lists)

AI was used to reformat some code, like replacing spaces with tabs and similar minor norm issues.
It also was used to add test mains before the peer evaluations.
