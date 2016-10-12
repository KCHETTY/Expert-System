
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

bool	save_data(t_info *info, string file)
{
	cout << file << endl;

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
		if (i > 0)	
			line.erase(line.find("#", 0), line.length());	
		trim(line);                                                          
		if (line.empty())                                                    
			continue;                                                        
		info->data.push_back(line);                                               
	}                                                                        
	input.close();
	
	conf = process(info);
	//DEBUG                                                                      
	for (size_t i = 0; i < info->data.size(); i++)                                    
		cout << "L: " << info->data[i] << endl;                             
	return (conf);  
}
