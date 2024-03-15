/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:31:19 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/14 13:51:25 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_sign(int nb)
{
	if (nb < 0 && nb >= -2147483647)
		write(1, "-", 1);
}

void	ft_putnbr_fd(int nb)
{
	int	tab[10];
	int	i;

	i = 0;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	ft_sign(nb);
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
		write(1, "0", 1);
	while (nb > 0)
	{
		tab[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &tab[i], 1);
		i--;
	}
	write(1, "\n", 1);
}
