
#include "expertsystem.h"

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
		}
		else
			cout << "Syntax Error!" << endl;
	}
	return (0);
}
