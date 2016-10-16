
#include "expertsystem.h"

void	get_rules(t_info *info)
{
	int k, l, j, o;

	for (size_t i = 0; i < info->data.size(); i++)
	{	
		k = info->data[i].find("?", 0);
		l = info->data[i].find("=", 0);
		j = info->data[i].find("=>");
		o = info->data[i].find("<=>");
		if ((k == -1 || l == -1) && (j != -1 || o != -1))
			info->rules.push_back(info->data[i]);
	}
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		cout << "Invalid Parameters!" << endl;
	else
	{
		if (save_data(&info, argv[1]) == true)
		{
			cout << "HELLO CHODE!!!" << endl;
			get_rules(&info);
			for (size_t i = 0; i < info.rules.size(); i++)
				cout << info.rules[i] << endl;
			solve_queries(&info);
		}
	}
	return (0);
}
