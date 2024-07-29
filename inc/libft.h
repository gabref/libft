/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:43:08 by galves-f          #+#    #+#             */
/*   Updated: 2024/07/29 22:53:13 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define LIBFT_INT_MAX 2147483647
# define LIBFT_INT_MIN -2147483648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Returns 1 if the input is a letter in the ASCII table */
int					ft_isalpha(int c);
/* Returns 1 if the input is a number in the ASCII table */
int					ft_isdigit(int c);
/* Returns 1 if the input is a number or a letter in the ASCII table */
int					ft_isalnum(int c);
/* Returns whether or not a value belongs to the ASCII table */
int					ft_isascii(int c);
/* Returns whether a character is printable */
int					ft_isprint(int c);
/* Returns length of a string */
size_t				ft_strlen(const char *s);
/* Assigns a character n times to a part of the memory*/
void				*ft_memset(void *s, int c, size_t n);
/* Writes n zeroes to the string s */
void				ft_bzero(void *s, size_t n);
/* Copies from one part of memory to another, ignoring possible overlaps*/
void				*ft_memcpy(void *dest, const void *src, size_t n);
/* Copies from one part of memory to another, preventing possible overlaps*/
void				*ft_memmove(void *dest, const void *src, size_t n);
/* Concatenates two strings ensuring it ends with \0 */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
/* Concatenates two strings ensuring it ends with \0 */
size_t				ft_strlcat(char *dst, const char *src, size_t size);
/* Makes every lowercase character in a string uppercase */
int					ft_toupper(int c);
/* Makes every uppercase character in a string lowercase */
int					ft_tolower(int c);
/* Looks for a specific character inside a given string,
 * returning pointer to it*/
char				*ft_strchr(const char *s, int c);
/* Looks for a given character in a string, reading it from back to front */
char				*ft_strrchr(const char *s, int c);
/* Compares two strings up to the n-th character */
int					ft_strncmp(const char *s1, const char *s2, size_t n);
/* Looks for a matching character inside a part of the memory */
void				*ft_memchr(const void *s, int c, size_t n);
/* Compares two parts of memory, returning 0 if they're the same,
 * or a nonzero value */
int					ft_memcmp(const void *s1, const void *s2, size_t n);
/* Tries to find a substring (needle) in a second string (haystack)
 * before the n-th char is reached */
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
/* Reads a String, and, after ignoring spaces
with ft_isspace, saves the string into an integer */
int					ft_atoi(const char *nptr);
/* Saves enoug space and duplicates a string */
char				*ft_strdup(const char *s);
/* Reserves x blocks of y bits of memory */
void				*ft_calloc(size_t nmemb, size_t size);
/* Copies from the n-th char of a string */
char				*ft_substr(char const *s, unsigned int start, size_t len);
/* Concatenates two strings allocating enough space first */
char				*ft_strjoin(char const *s1, char const *s2);
/* Removes occurrences of characters in a string from the start
 * and end of another one */
char				*ft_strtrim(char const *s1, char const *set);
/* Splits a string according to a given separator character */
char				**ft_split(char const *s, char c);
char				**ft_split_word(char const *s, char *charset);
/* Saves the given number as a string (char array) */
char				*ft_itoa(int n);
/* Applies a function (mapping) to every element in a string */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/* Prints a character to the given file descriptor */
void				ft_putchar_fd(char c, int fd);
/* Prints string to the given file descriptor */
void				ft_putstr_fd(char *s, int fd);
/* Prints a string followed by a new line \n to a given file descriptor */
void				ft_putendl_fd(char *s, int fd);
/* Prints number to the given file descriptor */
void				ft_putnbr_fd(int n, int fd);

// ==========================================
// =============== LINKED LIST ==============
// ==========================================

/* Creates new node allocating with malloc */
t_list				*ft_lstnew(void *content);
/* Adds new node at the beginning of the linked list */
void				ft_lstadd_front(t_list **lst, t_list *newn);
/* Returns number of elements of linked list */
int					ft_lstsize(t_list *lst);
/* Retrieves last node of the list */
t_list				*ft_lstlast(t_list *lst);
/* Adds new node at the end of the linked list */
void				ft_lstadd_back(t_list **lst, t_list *newn);
/* Deletes, frees, and applies function del to content of a given node */
void				ft_lstdelone(t_list *lst, void (*del)(void *));
/* Removes a node from the list without freeing it */
void				ft_lstremove(t_list **lst, t_list *node);
/* Removes a node from the list, freeing it */
void				ft_lstremove_del(t_list **lst, t_list *node,
						void (*del)(void *));
/* Deletes a given element and every element after that */
void				ft_lstclear(t_list **lst, void (*del)(void *));
/* Applies a function to the content of every node of the linked list */
void				ft_lstiter(t_list *lst, void (*f)(void *));
/* Applies function to a copy of the list, freeing when necessary */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstget(t_list *lst, int index);
void				ft_lstiter_param(t_list *lst, void (*f)(void *, void *),
						void *ptr);

int					ft_isword(char *str, char *charset);

/* Retrieves length of a number in a given base */
int					ft_nbrlen_base(long n, int base);

/* Replica of ft_itoa which works with unsigned numbers */
char				*ft_uitoa(unsigned int n);

/* Calculates the power of a number given a base with recursion */
int					ft_pow(int nb, int power);

/* Returns sqare root of number as closest (rounded) int */
int					ft_sqrt(int nb);

long				ft_atol(const char *str);

/* Converts a character to a string */
char				*ft_char_to_string(char c);

void				ft_free_multiple(int n, ...);
void				ft_free_2d_array(void **arr);

#endif
