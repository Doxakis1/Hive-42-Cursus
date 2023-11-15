/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaratzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:17:05 by mkaratzi          #+#    #+#             */
/*   Updated: 2023/11/15 10:21:22 by mkaratzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


class Megaphone
{
	private:
		std::string m_string;
	public:
		Megaphone(){
			m_string = "";
		}
		Megaphone(const char *string)
		{
			m_string = string;
		}
		~Megaphone(){}
	const std::string& getString()
	{
		return m_string;
	}
	void	toUpper()
	{
		for ( size_t i = 0; i < m_string.length() ; i++)
			m_string[i] = std::toupper(m_string[i]);
	}
};
