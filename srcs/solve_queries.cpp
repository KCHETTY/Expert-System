
#include "expertsystem.h"

void	initialize_data(t_info *info)
{
	int value = 0;
	int i;

	for (size_t o = 0; o < 26; o++)                                                 
		info->values[o] = 0; 

	for (size_t arr = 1; arr < info->defines.size(); arr++)
	{
		value = (info->defines[arr] - 'A');
		cout << value << endl;
		i = -1;
		while (++i < 26)
		{
			if (value == i)
				info->values[i] = 1;
			else if (info->values[i] != 1)
				info->values[i] = 0;
		}
		cout << "value" << endl;
	}

}

string	remove_whitespace(string data)
{
	string new_data;

	for (size_t i = 0; i < data.length(); i++)
	{
		if (data[i] != ' ' && data[i] != '\t')
			new_data.push_back(data[i]);
	}
	return (new_data);
}

int		brackets(string rule)
{
	for (size_t i = 0; i < rule.length(); i++)
	{
		if (rule[i] == '(' || rule[i] == ')')
			return (1);
	}
	return (0);
}

string 	getsub(string rule, size_t *start, size_t *count)
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

string	brackets3(string rule, t_info *info)
{
	size_t	start;
	size_t	count;
	string sub;
	string val;

	int check_and = rule.find("+");
	int check_or = rule.find("|");
	int check_xor = rule.find("^");
	if (check_and != -1)
	{
		start = rule.find("+") - 1;
		sub = getsub(rule, &start, &count);
	}
	else if (check_or != -1)
	{
		start = rule.find("|") - 1;
		sub = getsub(rule, &start, &count);
	}
	else if (check_xor != -1)
	{
		start = rule.find("^") - 1;	
		sub = getsub(rule, &start, &count);
	}
	else
		return (rule);
	val = (brackets4(sub, info)) ? "1" : "0";
	rule.replace(start, count , val);
	return (rule);
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

bool	isop(char c)
{
	return (c == '+' || c == '|' || c == '^');
}

int	brackets4(string data, t_info *info)
{
	cout << data << endl;
		
	bool v1;
	bool n1 = false;
	bool v2;
	bool n2 = false;
	char op;
	size_t i = 0;

	if ((isalpha(data[0]) != 0) && (data[1] == '=' || data[1] == '<'))
		return (get_var_value(data[0], info));
	if (data.length() == 1)
		return (get_var_value(data[0], info));
	if (data.length() == 2 && data[0] == '!')
		return (!get_var_value(data[1], info));
	if (data[0] == '!' && isalpha(data[1]) != 0 && (data[2] == '=' || data[2] == '<'))
		return (!get_var_value(data[1], info));
	if (data[0] == '1')
		return (1);
	if (data[0] == '0')
		return (0);
	if (data[i] == '!')
	{
		n1 = true;
		i++;
	}
	v1 = (n1) ? !get_var_value(data[i++], info) : get_var_value(data[i++], info);
	cout << v1 << endl;
	if (!isop(data[i]))
		cout << "error" << endl;
	op = data[i++];

	if (data[i] == '!')
	{
		n2 = true;
		i++;
	}
	v2 = (n2) ? !get_var_value(data[i++], info) : get_var_value(data[i++], info);
	switch (op)
	{
		case '+' :
			return (v1 & v2);
			break ;
		case '|' :
			return (v1 | v2);
			break ;
		case '^' :
			return (v1 ^ v2);
			break ;
		default :
			cout << "Error" << endl;
			return (false);
	}
}

int		ops(string rule)
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


string	brackets2(string rule, t_info *info)
{
	size_t start;
	size_t end;
//	size_t len;
	string temp;

	start = rule.rfind("(");
	if (start != (size_t)-1)
	{
		temp = rule.substr(start);
		end = temp.find(")");
		temp = temp.substr(1, end - 1);
	}
	else
		return (rule);
	while (ops(temp) > 0)
	{
		temp = brackets3(temp, info);
	}
	rule.replace(start, end + 1, temp);
	return (rule);
}

bool	solve1(string rule, t_info *info)
{
	rule = remove_whitespace(rule);
	while (brackets(rule))
	{	
		rule = brackets2(rule, info);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (ops(rule) > 0)
	{
		rule = brackets3(rule, info);
	}
	if (rule[0] != '0' && rule[1] != '1')
		rule = (brackets4(rule, info)) ? '1' : '0';
	return (rule[0] == '1');
	//return (rule);
}

void	find_query(t_info *info, bool result, string rule)
{
	rule = remove_whitespace(rule);
	int h = rule.find("=>");
	int j = rule.find("<=>");
	int val = 0;

	cout << "BOOL " << result << endl;
	cout << info->values[1] << endl;
	if (h != -1)
	{
		rule = rule.substr(h);
		h = rule.find('>') + 1;
		rule = rule.substr(h);
	}
	else if (j != -1)
	{
		rule = rule.substr(j);
		j = rule.find('>') + 1;
		rule = rule.substr(j);
	}

	for (size_t b = 0; b < rule.size(); b++)
	{
		val = rule[b] - 'A';
		if (isalpha(rule[b]))
			info->values[val] = result;
		if (rule[b] == '!' && isalpha(rule[++b]))
			info->values[val] = !result;
	}
}

bool	solve(char query, t_info *info)
{
	bool	result;
	bool	oldresult;
	//int		negation

	result = info->values[query - 'A'];
		
	cout << "//////////////////////////////////////Query////////////////////////  " << query << endl;
	oldresult = result;
	for (size_t i = 0; i < info->rules.size(); i++)
	{
		result = solve1(info->rules[i], info);
		find_query(info, result, info->rules[i]);
	}
	return (oldresult);
}

void	solve_data(t_info *info)
{
	size_t		i;
	//bool	result;
	
	//result = false;
	for (i = 1; i < info->queries.size(); i++)
	{
		//result = 
		solve(info->queries[i], info);
		/*if (result == true)
			cout << info->queries[i] << " is true!!" << endl;
		else if (result == false)	
			cout << info->queries[i] << " is false!!" << endl;*/
	}	
}

void	solve_queries(t_info *info)
{
	int val = 0;
	initialize_data(info);
	solve_data(info);
	for (size_t p = 1; p < info->queries.size(); p++)
	{
		val = info->queries[p] - 'A';
		if (info->values[val] == false)
			cout << info->queries[p] << " is false..." << endl;
		else if (info->values[val] == true)
			cout << info->queries[p] << " is true..." << endl;
	}
	cout << endl;
	for (size_t o = 0; o < 26; o++)
		cout << info->values[o] << endl;
}
