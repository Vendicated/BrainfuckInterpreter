#include <sstream>
#include <iostream>

class UnmatchedBrainfuckBracket: public std::exception {
	virtual const char* what() const throw() {
		return "Unmatched [ or ]";
	}
};

class InvalidBrainfuckChar: public std::exception {
	private:
		char character;
	
	public:
		InvalidBrainfuckChar(char character) {
			this->character = character;
		}

		virtual const char* what() const throw() {
			std::ostringstream stream;
			stream << "Invalid Character " << character << " at character ";
			
			const std::string str = stream.str();
			const char* output = str.c_str();

			return output;
		}
};

class Brainfuck {
	public:
		char arr[30000] = {0};
		char *ptr = arr;
		const char *cursor;

	Brainfuck(const char* bf) {
			cursor = bf;
	}

  void run() {
    while (*cursor) {
			walk();
			cursor++;
		}
	}

	void go_to_closing_bracket() {
		while (1) {
			cursor++;
			if (*cursor == '[') go_to_closing_bracket();
			else if (*cursor == ']') break;
		} 
	}

	void go_to_opening_bracket() {
		int depth = 0;
		do { 
			if (*cursor == ']') depth++;
			else if (*cursor == '[') depth--;
			cursor--;
		}
		while (depth); 
	}

	void walk() {
		switch(*cursor) {
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
				if (*ptr == '\0') go_to_closing_bracket();
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
			case '\n':
			case ' ':
				break;
			default:
				throw InvalidBrainfuckChar(*cursor); 
		}
	}

};

