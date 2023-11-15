/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:34:15 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/11/15 10:24:04 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Megaphone.hpp"

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
				Megaphone string = Megaphone(argv[i]);
				string.toUpper();
				std::cout << string.getString() << " ";
			}
			std::cout << std::endl;			
			break ;
	}
	return 0;
}
