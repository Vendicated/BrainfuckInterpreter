#include <iostream>
#include <iterator>
#include <string>

#include "brainfuck.hpp"

int main()
{
	std::istreambuf_iterator<char> begin(std::cin), end;
	std::string input(begin, end);

	int exit_code = 0;
	Brainfuck bf(input.c_str());

	try
	{
		bf.run();
		std::cout << '\n';
	}
	catch (const InvalidBrainfuckChar &ex)
	{
		exit_code = 1;
		std::cout << ex.what() << '\n';
	}

	return exit_code;
}
