/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 14:12:54 by kchetty           #+#    #+#             */
/*   Updated: 2016/10/16 14:20:32 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expertsystem.h"

string  remove_whitespace(string data)
{
	string new_data;

	for (size_t i = 0; i < data.length(); i++)
	{
		if (data[i] != ' ' && data[i] != '\t')
			new_data.push_back(data[i]);
	}
	return (new_data);
}

string  getsub(string rule, size_t *start, size_t *count)
{
	*count = 3;
	if (rule[*start + 2] == '!')
		*count += 1;
	if (rule[*start - 1] == '!')
	{
		*start -= 1;
		*count += 1;
	}
	string test = rule.substr(*start, *count);
	return (rule.substr(*start, *count));
}

int     ops(string rule)
{
	size_t count;
	size_t i;
	count = 0;
	i = 0;

	while (i < rule.length())
	{
		if (isop(rule[i]))
			count++;
		i++;
	}

	return (count);
}

bool get_var_value(char op, t_info *info)
{
	char test;


	if (op == '1')
		return (true);
	if (op == '0')
		return (false);
	for (size_t i = 0; i < 26; i++)
	{
		test = i + 'A';
		if (test == op)
		{
			return (info->values[i]);
		}
	}
	cout << "error: no value found" << endl;
	return (false);
}

bool    isop(char c)
{
	return (c == '+' || c == '|' || c == '^');
}

