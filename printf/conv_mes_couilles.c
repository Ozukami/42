char		*ft_get_arg_d(va_list ap, t_conv *list)
{
	if (ft_strequ(list->mod, "j"))
		arg = (ft_ltoa_base(va_arg(ap, long int), 10, 0));
	else if (ft_strequ(list->mod, "l") || ft_strequ(list->mod, "z"))
		arg = (ft_ultoa_base(va_arg(ap, long int), 10, 0));
	else if (ft_strequ(list->mod, "h"))
		arg = (ft_stoa_base((short)va_arg(ap, int), 10, 0));
	else if (ft_strequ(list->mod, "ll"))
		arg = (ft_lltoa_base(va_arg(ap, long long int), 10, 0));
	else if (ft_strequ(list->mod, "hh"))
		arg = (ft_sstoa(va_arg(ap, int)));
	else
		arg = (ft_itoa_base(va_arg(ap, int), 10, 0));
}

size_t		ft_va_arg_o(va_list ap, t_conv *list, char **str)
{
	if (ft_strequ(list->mod, "l") || ft_strequ(list->mod, "j")
			|| ft_strequ(list->mod, "z"))
		arg = ft_ulltoa_base(va_arg(ap, unsigned long long int), 8, 0);
	else if (ft_strequ(list->mod, "h"))
		arg = ft_stoa_base((short)va_arg(ap, int), 8, 0);
	else if (ft_strequ(list->mod, "ll"))
		arg = ft_ulltoa_base(va_arg(ap, unsigned long long int), 8, 0);
	else if (ft_strequ(list->mod, "hh"))
		arg = ft_usstoa_base((unsigned char)va_arg(ap, int), 8, 0);
	else
		arg = ft_itoa_base(va_arg(ap, int), 8, 0);
}

size_t		ft_va_arg_p(va_list ap, t_conv *list, char **str)
{
	arg = ft_ulltoa_base(va_arg(ap, unsigned long long int), 16, 0);
}

size_t		ft_va_arg_u(va_list ap, t_conv *list, char **str)
{
	if (ft_strequ(list->mod, "h"))
		arg = ft_stoa_unsigned((short)va_arg(ap, int));
	else if (ft_strequ(list->mod, "l") || ft_strequ(list->mod, "z")
			|| ft_strequ(list->mod, "j"))
		arg = ft_ltoa_unsigned(va_arg(ap, long int));
	else if (ft_strequ(list->mod, "ll"))
		arg = ft_lltoa_unsigned(va_arg(ap, long long int));
	else if (ft_strequ(list->mod, "hh"))
		arg = ft_usstoa_base((unsigned char)va_arg(ap, int), 10, 0);
	else
		arg = ft_itoa_unsigned(va_arg(ap, long long int));
}

char		*ft_get_arg_x(va_list ap, t_conv *list)
{
	if (ft_strequ(list->mod, "j"))
		return (ft_ulltoa_base(va_arg(ap, long int), 16,
					(list->type == 'x') ? 0 : 1));
	else if (ft_strequ(list->mod, "l") || ft_strequ(list->mod, "z"))
		return (ft_ultoa_base_2(va_arg(ap, long int), 16,
					(list->type == 'x') ? 0 : 1));
	else if (ft_strequ(list->mod, "ll"))
		return (ft_ulltoa_base(va_arg(ap, unsigned long long int), 16,
					(list->type == 'x') ? 0 : 1));
	else if (ft_strequ(list->mod, "h"))
		return (ft_stoa_base((short)va_arg(ap, int), 16,
					(list->type == 'x') ? 0 : 1));
	else if (ft_strequ(list->mod, "hh"))
		return (ft_usstoa_base((unsigned char)va_arg(ap, int), 16,
					(list->type == 'x') ? 0 : 1));
	else
		return (ft_itoa_base(va_arg(ap, int), 16, (list->type == 'x') ? 0 : 1));
}
