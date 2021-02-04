#include <iostream>
#include <iterator>
#include <string>

#include "brainfuck.hpp"

int main()
{
	std::istreambuf_iterator<char> begin(std::cin), end;
	std::string input(begin, end);

	try
	{
		Brainfuck::validate(input.c_str());
	}
	catch (const UnmatchedBracketException &ex)
	{
		std::cout << ex.what() << '\n';
		return EXIT_FAILURE;
	}

	Brainfuck bf(input.c_str());

	bf.run();
	std::cout << '\n';

	return EXIT_SUCCESS;
}
