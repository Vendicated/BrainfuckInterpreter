#include <sstream>
#include <iostream>

class UnmatchedBracketException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Brainfuck SyntaxError: Unmatched [ or ]";
	}
};

class Brainfuck
{
private:
	char arr[30000] = {0};
	char *ptr = arr;
	const char *cursor;

	void go_to_closing_bracket()
	{
		while (1)
		{
			cursor++;
			if (*cursor == '[')
				go_to_closing_bracket();
			else if (*cursor == ']')
				break;
		}
	}

	void go_to_opening_bracket()
	{
		int depth = 0;
		do
		{
			if (*cursor == ']')
				depth++;
			else if (*cursor == '[')
				depth--;
			cursor--;
		} while (depth);
	}

	void walk()
	{
		switch (*cursor)
		{
		case '>':
			ptr++;
			break;
		case '<':
			ptr--;
			break;
		case '+':
			(*ptr)++;
			break;
		case '-':
			(*ptr)--;
			break;
		case '[':
			if (*ptr == '\0')
				go_to_closing_bracket();
			break;
		case ']':
			go_to_opening_bracket();
			break;
		case '.':
			std::cout << *ptr;
			break;
		case ',':
			std::cin >> *ptr;
			break;
		}
	}

public:
	Brainfuck(const char *bf)
	{
		cursor = bf;
	}

	static void validate(const char *bf)
	{
		int depth = 0;

		while (*bf)
		{
			if (*bf == '[')
				depth++;
			else if (*bf == ']')
				depth--;

			if (depth < 0)
				break;

			bf++;
		}

		if (depth)
			throw UnmatchedBracketException();
	}

	void evaluate()
	{
		while (*cursor)
		{
			walk();
			cursor++;
		}
	}
};
