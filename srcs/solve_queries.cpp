
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

bool	solve(char query, t_info *info)
{
	bool	result;
	//bool	oldresult;
	//int		negation

	result = info->values[query - 'A'];
	cout << "second result: " << result << endl;
	return (result);
}

void	solve_data(t_info *info)
{
	cout << info->queries.size() << endl;
	size_t		i;
	bool	result;
	
	result = false;
	for (i = 1; i < info->queries.size(); i++)
	{
		result = solve(info->queries[i], info);
		cout << "first result: " << result << endl;
	}
}

void	solve_queries(t_info *info)
{
	initialize_data(info);
	solve_data(info);	
	cout << endl;
	for (size_t o = 0; o < 26; o++)
		cout << info->values[o] << endl;
}
