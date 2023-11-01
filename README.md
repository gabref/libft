# libft

| Program name | libft.a |
| Turn in files | Makefile, libft.h, ft_*.c |
| Makefile | NAME, all, clean, fclean, re |
| External functs. | Detailed below |
| Libft authorized | n/a |
| Description | Write your own library: a collection of functions that will be a useful tool for your cursus. |

## Part 1 - Libc functions
To begin, you must redo a set of functions from the libc. Your functions will have the
same prototypes and implement the same behaviors as the originals. They must comply
with the way they are defined in their man. The only difference will be their names. They
will begin with the ’ft_’ prefix. For instance, `strlen` becomes `ft_strlen`.<br>
These function do not require any external functions

- [x] isalpha
- [x] isdigit
- [x] isalnum
- [x] isascii
- [x] isprint
- [x] strlen
- [ ] memset
- [ ] bzero
- [ ] memcpy
- [ ] memmove
- [ ] strlcpy
- [ ] strlcat
- [ ] toupper
- [ ] tolower
- [ ] strchr
- [ ] strrchr
- [ ] strncmp
- [ ] memchr
- [ ] memcmp
- [ ] strnstr
- [ ] atoi

In order to implement the two following functions, you will use `malloc()`

- [ ] calloc
- [ ] strdup

## Part 2 - Additional functions
In this second part, you must develop a set of functions that are either not int the `libc`, or that are part of it but in a different form. (Description and prototypes are in the pdf)

- [ ] ft_substr
- [ ] ft_strjoin
- [ ] ft_strtrim
- [ ] ft_split
- [ ] ft_itoa
- [ ] ft_strmapi
- [ ] ft_striteri
- [ ] ft_putchar_fd
- [ ] ft_putstr_fd
- [ ] ft_putendl_fd
- [ ] ft_putnbr_fd

## Bonus Part

- [ ] ft_lstnew
- [ ] ft_lstadd_front
- [ ] ft_lstsize
- [ ] ft_lstlast
- [ ] ft_lstadd_back
- [ ] ft_lstdelone
- [ ] ft_lstclear
- [ ] ft_lstiter
- [ ] ft_lstmap
