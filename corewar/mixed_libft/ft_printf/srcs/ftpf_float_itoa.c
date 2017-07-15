/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_float_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 02:03:57 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*ft_itoa_hexa_neg(int i, long long n)
{
	char				*ret;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(ret = ft_strnew(i + 1)))
		return (NULL);
	ret[0] = '-';
	n = n * -1;
	while (i > 0)
	{
		ret[i] = n % 16 + 48;
		n /= 16;
		i--;
	}
	ft_reverse_str(ret);
	return (ret);
}

char					*ft_itoa_hexa(long long n)
{
	char				*ret;
	int					i;
	long long			nmem;

	nmem = n;
	i = 0;
	while (nmem != 0)
	{
		nmem = nmem / 10;
		i++;
	}
	if (n <= 0)
		return (ft_itoa_hexa_neg(i, n));
	if (!(ret = ft_strnew(i)))
		return (NULL);
	i--;
	while (i >= 0)
	{
		ret[i] = n % 16 + 48;
		n /= 16;
		i--;
	}
	ft_reverse_str(ret);
	return (ret);
}

char					*ft_get_mantisse(double n, t_float *st)
{
	char				*ret;

	ret = ft_strjoindel(ft_itoa_hexa(ft_abs(st->t1)), ".", 1);
	ret = ft_strjoindel(ret, ft_itoa_hexa(st->t2), 2);
	ret = ft_strjoindel("0x", ret, 2);
	if (n < 0)
		ret = ft_strjoindel("-", ret, 2);
	ret = ft_strjoindel(ret, "p+0", 1);
	return (ret);
}

static char				*make_str(t_float *st, int over_pre)
{
	char				*ret;
	char				*tmp;

	ret = ft_strjoindel(ft_itoa(st->t1), ".", 1);
	ret = ft_strjoindel(ret, ft_itoa(st->t2), 3);
	if (over_pre > 0)
	{
		tmp = ft_itoa(st->t2);
		ret = ft_strjoindel(ret,
		ft_strnewch(over_pre - ft_strlen(tmp), '0'), 3);
		free(tmp);
	}
	return (ret);
}

char					*ftpf_float_itoa(double n, int pre, int x, int over_pre)
{
	t_float				st;

	st.t1 = (long)n;
	if (pre == 0 && x != 1)
		return (ft_itoa(st.t1));
	st.tmp = n - st.t1;
	if (st.tmp < 0)
		st.tmp *= -1;
	st.tmp = st.tmp * ft_power(10, pre);
	if ((unsigned long)st.tmp == (unsigned long)(st.tmp + 0.5))
		st.t2 = ft_abs((unsigned long)st.tmp);
	else
		st.t2 = ft_abs((unsigned long)st.tmp) + 1;
	if (x == 1)
		return (ft_get_mantisse(n, &st));
	return (make_str(&st, over_pre));
}
