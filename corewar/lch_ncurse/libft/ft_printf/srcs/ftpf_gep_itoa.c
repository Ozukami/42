/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_float_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:25 by lcharbon          #+#    #+#             */
/*   Updated: 2017/06/10 02:36:50 by lcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*make_str(t_float *st, double n, int over_pre)
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
	if (n < 0)
		ret = ft_strjoindel("-", ret, 2);
	ret = ft_strjoindel(ret, "e", 1);
	ret = ft_strjoindel(ret, "-", 1);
	if (st->e < 10)
		ret = ft_strjoindel(ret, "0", 1);
	ret = ft_strjoindel(ret, ft_itoa(st->e), 3);
	return (ret);
}

char					*ftpf_gep_itoa(double n, int pre, int over_pre)
{
	t_float				st;
	long				nb;

	st.e = 0;
	st.tmp = n;
	if (n < 0)
		st.tmp = n * -1;
	while (st.tmp < 1 && st.tmp > -1)
	{
		st.tmp *= 10;
		st.e++;
	}
	st.t1 = ft_abs((long)st.tmp);
	st.tmp = st.tmp - st.t1;
	st.tmp = st.tmp * ft_power(10, pre);
	st.t2 = ft_abs((unsigned long)st.tmp);
	nb = st.t2;
	while (nb % 10 == 0 && nb != 0)
		nb /= 10;
	st.t2 = nb;
	return (make_str(&st, n, over_pre));
}
