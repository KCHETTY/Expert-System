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

#include "expertsystem.h"

void split(const string &str, char delim, vector<string> &elems)  
{                                                                                
	stringstream   ss;                                                      
	string         item;                                                    

	ss.str(str);                                                                 
	while (getline(ss, item, delim))                                             
	{                                                                            
		if (!item.empty())                                                       
			elems.push_back(item);                                               
	}                                                                            
}                                                                                

vector<string>    strsplit(string &s, char delim)                 
{                                                                                
	vector<string> elem;                                               

	split(s, delim, elem);                                                       
	return (elem);                                                               
}                  

bool	check_line(string line)
{
	vector<string> split;

	regex char_regex("\\!?[A-Z]");
	regex op_regex("[+\\|^]");
	regex imp_regex("(=>)|(<=>)");
	regex qry_regex("((\\=)|(\\?))?[A-Z]+");

	split = strsplit(line, ' ');
	for (size_t j = 0; j < split.size(); j++)
	{
		if (!(regex_match(split[j], qry_regex) || regex_match(split[j], qry_regex) || 
		regex_match(split[j], char_regex) || 
		regex_match(split[j], op_regex) || 
		regex_match(split[j], imp_regex)))
		{
			return (false);
		}
	}
	return (true);
}

void	process(t_info *info)
{
	for (size_t i = 0; i < info->data.size(); i++)
	{
		if (!check_line(info->data[i]))
		{
			cout << "Line " << i + 1 << ": Syntax Error!" << endl;
			return ;
		}
	}
}
