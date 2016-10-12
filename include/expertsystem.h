/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:16:15 by oexall            #+#    #+#             */
/*   Updated: 2016/09/27 15:47:49 by oexall           ###   ########.fr       */
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
	vector<string>	data;
}					t_info;

int		save_data(t_info *info, string file);

void	process(t_info *info);
//std::vector<std::string> strsplit(std::string &s, char delim);

#endif
