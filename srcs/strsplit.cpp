/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:58:59 by oexall            #+#    #+#             */
/*   Updated: 2016/09/27 15:08:01 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expertsystem.h>

void split(const std::string &str, char delim, std::vector<std::string> &elems)
{
	std::stringstream	ss;
	std::string			item;

	ss.str(str);
	while (getline(ss, item, delim))
	{
		if (!item.empty())
			elems.push_back(item);
	}
}

std::vector<std::string> 	strsplit(std::string &s, char delim)
{
	std::vector<std::string> elem;

	split(s, delim, elem);
	return (elem);
}
