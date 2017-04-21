#include "ch_13_ex_42.h"
#include <iostream>

void runQueries(std::ifstream& in_file)
{
	TextQuery tq(in_file);
	while(true) {
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if(!(std::cin >> s) || s == "q")
			break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main()
{
	std::ifstream file("README.txt");
	runQueries(file);
}
