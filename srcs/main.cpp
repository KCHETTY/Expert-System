/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 10:28:11 by oexall            #+#    #+#             */
/*   Updated: 2016/09/27 14:54:29 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expertsystem.h>

// trim from start (in place)
static inline void ltrim(std::string &s) 
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		std::not1(std::ptr_fun<int, int>(std::isspace))));
}

// trim from end (in place)
static inline void rtrim(std::string &s) 
{
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) 
{
	ltrim(s);
	rtrim(s);
}


int	main(int argc, char **argv)
{
	std::string	line;
	std::vector<std::string> lines;

	if (argc != 2)
		std::cout << "Invalid Parameters Given" << std::endl;
	else 
	{
		std::ifstream input(argv[1]);
		while (getline(input, line).good()) 
		{
			if (line[0] == '#' || line.empty())
				continue;
			line.erase(line.find("#", 0), 1000000);
			trim(line);
			if (line.empty())
				continue;
			lines.push_back(line);
		}
		input.close();
	}
	process(lines);	
	//DEBUG
	for (size_t i = 0; i < lines.size(); i++)
		std::cout << "L: " << lines[i] << std::endl;
	return (0);
}
