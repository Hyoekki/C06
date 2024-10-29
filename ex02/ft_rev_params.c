/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:36:46 by jhyokki           #+#    #+#             */
/*   Updated: 2024/09/16 13:51:52 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv += argc - 1;
		while (argc-- > 1)
		{
			while (**argv)
			{
				write(1, *argv, 1);
				(*argv)++;
			}
			write(1, "\n", 1);
			argv--;
		}
	}
}
