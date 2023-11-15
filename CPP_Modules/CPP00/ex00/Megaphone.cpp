/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:34:15 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/11/15 12:11:19 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char const *argv[])
{
	switch (argc)
	{
		case 1:
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
			break ;
		default:
			for (int i = 1 ; i < argc ; i++)
			{
				for (int k = 0 ; argv[i][k] != '\0' ; k ++)
					std::cout << static_cast<char>(std::toupper(argv[i][k]));
				if (i != argc - 1)
					std::cout << " ";
			}
			std::cout << std::endl;			
			break ;
	}
	return 0;
}
