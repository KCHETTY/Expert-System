/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:16:15 by oexall            #+#    #+#             */
/*   Updated: 2016/10/16 14:23:05 by kchetty          ###   ########.fr       */
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

typedef struct		s_info
{
	int				values[26];
	vector<string>	data;
	vector<string>  component;
	vector<string>	next;
	vector<string>	rules;
	vector<char>	queries;
	vector<char>	defines;
}					t_info;

bool	save_data(t_info *info, string file);
bool	process(t_info *info);
void	solve_queries(t_info *info);
int		brackets4(string data, t_info *info);
string	remove_whitespace(string data);
string  getsub(string rule, size_t *start, size_t *count);
int     ops(string rule);
bool 	get_var_value(char op, t_info *info);
bool    isop(char c);
#endif
