
#include "expertsystem.h"

void	get_rules(t_info *info)
{
	int	q_mark;
	int	equal;
	int	implies;
	int	w_implies;

	for (size_t i = 0; i < info->data.size(); i++)
	{	
		q_mark = info->data[i].find("?", 0);
		equal = info->data[i].find("=", 0);
		implies = info->data[i].find("=>");
		w_implies= info->data[i].find("<=>");
		if ((q_mark == -1 || equal == -1) && (implies != -1 || w_implies != -1))
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
			get_rules(&info);
			for (size_t i = 0; i < info.rules.size(); i++)
				cout << info.rules[i] << endl;
			solve_queries(&info);
		}
	}
	return (0);
}
