
#include "expertsystem.h"

// trim from start (in place)                                                    
static inline void ltrim(std::string &s)                                         
{                                                                                
	s.erase(s.begin(), find_if(s.begin(), s.end(),                          
		not1(ptr_fun<int, int>(isspace))));                       
}                                                                                

// trim from end (in place)                                                      
static inline void rtrim(string &s)                                         
{                                                                                
	s.erase(find_if(s.rbegin(), s.rend(),                                   
		not1(ptr_fun<int, int>(isspace))).base(), s.end());       
}                                                                                

// trim from both ends (in place)                                                
static inline void trim(string &s)                                          
{                                                                                
	ltrim(s);                                                                    
	rtrim(s);                                                                    
}

void	save_defines(t_info *info, string line, int check)
{
	int i, j, k;

	i = 0;
	if (((k = line.find("=>")) == -1) && ((j = line.find("<=>")) == -1))
	{
		if (check == 1)
			info->defines.push_back(line[0]);
		if (check == 2)
			info->queries.push_back(line[0]);
		if (check == 1)
		{
			while(line[++i])
			{
				if (isalpha(line[i]))
					info->defines.push_back(line[i]);		
			}
		}
		else if (check == 2)
		{
			while(line[++i])
			{
				if (isalpha(line[i]))
					info->queries.push_back(line[i]);
			}
		}
	}
}

bool	save_data(t_info *info, string file)
{
	string		line;
	int			i;
	bool		conf = false;
	ifstream	input(file);

	i = 0;
	while (getline(input, line).good())                                      
	{                
		if (line[0] == '#' || line.empty())                                  
			continue;
		i = line.find("#", 0);	
		cout << i << endl;
		if (i > 0)	
			line.erase(line.find("#", 0), line.length());	
		trim(line);                                                          
		if (line.empty())                                           
			continue;
		if (line.find("=", 0) == 0)
			save_defines(info, line, 1);
		if (line.find("?", 0) == 0)
			save_defines(info, line, 2);
		info->data.push_back(line);                                               
	}                                                                        
	input.close();
	
	conf = process(info);
	//DEBUG                                                                      
	for (size_t k = 0; k < info->data.size(); k++)                                    
		cout << "L: " << info->data[k] << endl;

	for (size_t j = 0; j < info->defines.size(); j++)
	{
		cout << "chode" << endl;
		cout << info->defines[j] << endl;
	}

	for (size_t u = 0; u < info->queries.size(); u++)
		cout << info->queries[u] << endl;

	return (conf);  
}
