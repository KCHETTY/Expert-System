/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:16:15 by oexall            #+#    #+#             */
/*   Updated: 2016/10/12 09:16:11 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_SYSTEM_H
# define EXPERT_SYSTEM_H

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <vector>
# include <regex>

using namespace std;

typedef struct		s_components
{
	char			*letter;
	bool			conf;
	struct			*next;
}					t_components

typedef struct		s_info
{
	vector<string>	data;
	vector<string>  component;
	vector<string>	next;
	t_components	*comp;
}					t_info;

bool	save_data(t_info *info, string file);
void	parse_data(t_info *info);
bool	process(t_info *info);
//std::vector<std::string> strsplit(std::string &s, char delim);

#endif
