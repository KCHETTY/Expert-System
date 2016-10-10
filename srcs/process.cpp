/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:25:51 by oexall            #+#    #+#             */
/*   Updated: 2016/09/28 08:17:07 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expertsystem.h>

bool	check_line(std::string line)
{
	std::vector<std::string> split;
	std::regex char_regex("\\!?[A-Z]");
	std::regex op_regex("[+\\|^]");
	std::regex imp_regex("(=>)|(<=>)");
	std::regex qry_regex("((\\=)|(\\?))?[A-Z]+");

	split = strsplit(line, ' ');
	for (size_t j = 0; j < split.size(); j++)
	{
		if (!(std::regex_match(split[j], qry_regex) || 
			std::regex_match(split[j], qry_regex) ||
			std::regex_match(split[j], char_regex) || 
			std::regex_match(split[j], op_regex) ||
			std::regex_match(split[j], imp_regex)))
		{
			return (false);
		}
	}
	return (true);
}

void	process(std::vector<std::string> lines)
{
	for (size_t i = 0; i < lines.size(); i++)
	{
		if (!check_line(lines[i]))
		{
			std::cout << "Line " << i + 1 << ": Syntax Error!" << std::endl;
			return ;
		}
	}
}
