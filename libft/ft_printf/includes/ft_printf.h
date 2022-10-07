/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:07:28 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/10/06 19:40:52 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				space;
	int				plus;
	int				hash;
	int				mods;
	int				over;
	int				min_over;
	int				star;
	unsigned int	base;
}					t_flags;

int					ft_printf(const char *str, ...);
int					form_spec(int c);
int					is_flag(int c);
int					ft_treatment(va_list *args, t_flags *flags);
int					ft_treat_width(int width, int minus, int has_zero);
int					ft_treat_char(va_list *args, t_flags *flags);
int					ft_treat_string(va_list *args, t_flags *flags);
int					ft_treat_int(va_list *args, t_flags *flags);
int					ft_treat_percent(t_flags *flags);
int					ft_treat_oct(va_list *args, t_flags *flags);
int					ft_treat_hex(va_list *args, t_flags *flags);
int					ft_treat_uns_int(va_list *args, t_flags *flags);
int					ft_flag_dot(const char *save, int start, t_flags *flags, \
								va_list args);
int					ft_putchar2(int c);
long double			ft_power(int power, long double base);
int					ft_treat_pointer(va_list *args, t_flags *flags);
int					ft_check_mods(int c);
int					ft_strlen2(const char *str);
int					ft_iszerof(t_flags *flags, long long int num);
int					ft_treat_float(va_list *args, t_flags *flags);
long long int		ft_manage_mods(va_list *args, t_flags *flags);
unsigned long long	ft_manage_u_mods(va_list *args, t_flags *flags);
long double			ft_manage_f_mods(va_list *args, t_flags *flags);
long double			ft_rounder(long double num, t_flags *flags);
long double			ft_rounding(int i, long double num);

char				*ft_manage_int_sign(t_flags *flags, char *str, \
										long long int num);
char				*ft_manage_int_zero(t_flags *flags, char *str);
char				*ft_hex_hash_mod(t_flags *flags, char *str, \
					unsigned long long num, int len2);
char				*ft_strjoin_f2(char *s1, char *s2);
char				*ft_strjoin_f1(char *s1, char *s2);
char				*ft_itoa_signed(long long int n);
char				*ft_itoa_uns(unsigned long long int num, t_flags *flags);
char				*ft_str_tolower(char *str);
char				ft_char_sign(t_flags *flags, char sign);
char				*ft_add_hash(t_flags *flags, char *str, \
								unsigned long long num);
char				*ft_add_minus(char *str, t_flags *flags, int is_neg);

void				ft_flag_parse(char *str, t_flags *flags);
void				ft_init_flags(t_flags *flags);
void				ft_star(va_list *args, t_flags *flags);
void				ft_manage_star(t_flags *flags);

#endif