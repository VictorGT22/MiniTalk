/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:21:08 by victgonz          #+#    #+#             */
/*   Updated: 2023/05/11 09:41:52 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>

typedef struct t_list {
	void			*content;
	struct t_list	*next;	
}t_list;

int				ft_isalpha(int c);
int				ft_strlen(const char *str);
int				ft_nbrlen(long int nbr);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_vic_isspace(char c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_instr(char *str, char c);
void			*ft_calloc(int nmemb, int size);
char			*ft_strdup(char *str);
void			ft_add_in_str(char *str, char c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int nb);
void			*ft_memchr(const void *str, int c, size_t n);
char			*ft_strrchr(const char *str, char c);
char			*ft_strchr(const char *str, char c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *str, char c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void			ft_striteri(char *str, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *n);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *n);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
t_list			*ft_lstlast(t_list *lst);
void			free_arr(char **arr);
#endif