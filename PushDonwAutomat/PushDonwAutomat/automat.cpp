#include "automat.h"

Automat::Automat()
{
	current_state = &Automat::q1;
	stack_head = input_head = 0;
	stop_flag = false;
	error_flag = false;
}

Automat::~Automat() { ; }

void Automat::q1()
{
	switch (stack_head)
	{
	case 'E':
		switch (input_head)
		{
		case '1':
			current_state = &Automat::q2;
			magazin.push_back('1');
			break;
		case '0':
			current_state = &Automat::q2;
			magazin.push_back('0');
			break;
		case '\n':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '\0':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case EOF:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		}
		break;
	case '1':
		switch (input_head)
		{
		case '1':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '\n':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '\0':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case EOF:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		}
		break;
	case '0':
		switch (input_head)
		{
		case '1':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '\n':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '\0':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case EOF:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		}
		break;
	default:
		std::cout << "REJECT";
		stop_flag = true;
		error_flag = true;
		return;
	}
}

void Automat::q2()
{
	switch (stack_head)
	{
	case 'E':
		switch (input_head)
		{
		case '1':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '\n':
			output.push_back('1');
			std::cout << "ACCEPT";
			stop_flag = true;
			return;
		case '\0':
			output.push_back('1');
			std::cout << "ACCEPT";
			stop_flag = true;
			return;
		case EOF:
			output.push_back('1');
			std::cout << "ACCEPT";
			stop_flag = true;
			return;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		}
		break;
	case '1':
		switch (input_head)
		{
		case '1':
			magazin.push_back('1');
			break;
		case '0':
			magazin.push_back('0');
			break;
		case '\n':
			output.push_back('0');
			magazin.pop_back();
			break;
		case '\0':
			output.push_back('0');
			magazin.pop_back();
			break;
		case EOF:
			output.push_back('0');
			magazin.pop_back();
			break;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		}
		break;
	case '0':
		switch (input_head)
		{
		case '1':
			magazin.push_back('1');
			break;
		case '0':
			magazin.push_back('0');
			break;
		case '\n':
			output.push_back('1');
			magazin.pop_back();
			current_state = &Automat::q3;
			break;
		case '\0':
			output.push_back('1');
			magazin.pop_back();
			current_state = &Automat::q3;
			break;
		case EOF:
			output.push_back('1');
			magazin.pop_back();
			current_state = &Automat::q3;
			break;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		}
		break;
	default:
		std::cout << "REJECT";
		stop_flag = true;
		error_flag = true;
		return;
	}
}

void Automat::q3()
{
	switch (stack_head)
	{
	case 'E':
		switch (input_head)
		{
		case '1':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '\n':
			std::cout << "ACCEPT";
			stop_flag = true;
			return;
		case '\0':
			std::cout << "ACCEPT";
			stop_flag = true;
			return;
		case EOF:
			std::cout << "ACCEPT";
			stop_flag = true;
			return;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		}
		break;
	case '1':
		switch (input_head)
		{
		case '1':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '\n':
			output.push_back('1');
			magazin.pop_back();
			break;
		case '\0':
			output.push_back('1');
			magazin.pop_back();
			break;
		case EOF:
			output.push_back('1');
			magazin.pop_back();
			break;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		}
		break;
	case '0':
		switch (input_head)
		{
		case '1':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		case '\n':
			output.push_back('0');
			magazin.pop_back();
			break;
		case '\0':
			output.push_back('0');
			magazin.pop_back();
			break;
		case EOF:
			output.push_back('0');
			magazin.pop_back();
			break;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			error_flag = true;
			return;
		}
		break;
	default:
		std::cout << "REJECT";
		stop_flag = true;
		error_flag = true;
		return;
	}
}

void Automat::rundown_output()
{
	std::cout << "(";

	if (current_state == &Automat::q1)
		std::cout << "q1, ";
	else if (current_state == &Automat::q2)
		std::cout << "q2, ";
	else
		std::cout << "q3, ";

	std::string tmp = magazin;
	std::reverse(tmp.begin(), tmp.end());

	std::cout << input << ", " << tmp << ")" << std::endl;
}

void Automat::parse(const char* file_name_)
{
	std::fstream in(file_name_);
	magazin.push_back('E');

	while (getline(in, input))
	{
		std::cout << "Input: " << input << std::endl;

		stack_head = magazin.back();
		input_head = input.front();
		current_state = &Automat::q1;

		while (!stop_flag)
		{
			rundown_output();

			stack_head = magazin.back();

			(this->*current_state)();

			input.erase(input.begin());
			if (!input.empty())
				input_head = input.front();
			else
				input_head = '\0';
		}

		if (!error_flag)
		{
			std::reverse(output.begin(), output.end());
			std::cout << std::endl << "Output: " << output;
		}
		std::cout << std::endl << std::endl;

		stop_flag = false;
		error_flag = false;
		output.clear();
	}
}
