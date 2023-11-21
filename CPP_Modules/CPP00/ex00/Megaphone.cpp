/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <mkaratzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:34:15 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/11/21 14:12:15 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1 ; i < argc ; i++)
		{
			std::string output(argv[i]);
			for (size_t k = 0; k < output.length(); k++)
				output.at(k) = std::toupper(output.at(k));
			std::cout << output;
		}
		std::cout << std::endl;
	}
	return 0;
}
