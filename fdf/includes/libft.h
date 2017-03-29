/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:49:10 by apoisson          #+#    #+#             */
/*   Updated: 2017/03/29 04:33:05 by apoisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_rect
{
	t_coord			*coord1;
	t_coord			*coord2;
	int				color;
}					t_rect;

/*
** PART I
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
		const char *little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** PART II
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** PART III
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** EXTRA
*/

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isspace(int c);
int					ft_check_spaces(int c);
void				ft_strrev(char *s);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
void				ft_putnbr_endl(int n);
void				ft_putnbr_short(short n);
void				ft_putnbr_long(long n);
void				ft_putnbr_u_short(unsigned short n);
void				ft_putnbr_u_long(unsigned long n);
void				ft_putnbr_u_int(unsigned int n);
char				*ft_itoa_base(int value, int base, int maj);
char				*ft_ltoa_base(long value, int base, int maj);
char				*ft_lltoa_base(long long value, int base, int maj);
char				*ft_ulltoa_base(unsigned long long value, int base, int maj);
char				*ft_ultoa_base(long value, int base, int maj);
char				*ft_ultoa_base_2(long value, int base, int maj);
char				*ft_stoa_base(short value, int base, int maj);
char				*ft_usstoa_base(int value, int base, int maj);
char				*ft_ltoa_unsigned(long int value);
char				*ft_lltoa_unsigned(long long int value);
char				*ft_stoa_unsigned(short value);
char				*ft_sstoa(int value);
char				*ft_itoa_unsigned(int value);
char				*ft_strjoinf(char *s1, char *s2);
char				*ft_straddchar(char *s, char c);
int					ft_recursive_power(int nb, int power);
void				ft_bspace(char *s, size_t n);
char				*ft_strspace(size_t size);
size_t				ft_lslen(wchar_t *s);
int					ft_atoi_base(const char *str, int base);
double				ft_atof(const char *str);

void				ft_set_coord(t_coord *coord, int x, int y);
t_coord				*ft_new_coord(int a, int b);
t_rect				*ft_new_rect(t_coord *coord1, t_coord *coord2, int color);

#endif
