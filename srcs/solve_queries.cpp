
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

void	solve_queries(t_info *info)
{
	initialize_data(info);
	
	cout << endl;
	for (size_t o = 0; o < 26; o++)
		cout << info->values[o] << endl;
}
