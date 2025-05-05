#include "automat.h"

Automat::Automat()
{
	current_state = &Automat::q1;
	stack_head = input_head = 0;
	stop_flag = false;
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
		case '\0':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			return;
		}
		break;
	case '1':
		switch (input_head)
		{
		case '1':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		case '\0':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			return;
		}
		break;
	case '0':
		switch (input_head)
		{
		case '1':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		case '\0':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			return;
		}
		break;
	default:
		std::cout << "REJECT";
		stop_flag = true;
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
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		case '\0':
			std::cout << '1' << std::endl;
			std::cout << "ACCEPT";
			stop_flag = true;
			return;
		default:
			std::cout << "REJECT";
			stop_flag = true;
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
		case '\0':
			std::cout << '0' << std::endl;
			magazin.pop_back();
			break;
		default:
			std::cout << "REJECT";
			stop_flag = true;
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
		case '\0':
			std::cout << '1' << std::endl;
			magazin.pop_back();
			current_state = &Automat::q3;
			break;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			return;
		}
		break;
	default:
		std::cout << "REJECT";
		stop_flag = true;
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
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		case '\n':
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
			return;
		}
		break;
	case '1':
		switch (input_head)
		{
		case '1':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		case '\n':
			std::cout << '1' << std::endl;
			magazin.pop_back();
			break;
		case EOF:
			std::cout << '1' << std::endl;
			magazin.pop_back();
			break;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			return;
		}
		break;
	case '0':
		switch (input_head)
		{
		case '1':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		case '0':
			std::cout << "REJECT";
			stop_flag = true;
			return;
		case '\n':
			std::cout << '0' << std::endl;
			magazin.pop_back();
			break;
		case EOF:
			std::cout << '0' << std::endl;
			magazin.pop_back();
			break;
		default:
			std::cout << "REJECT";
			stop_flag = true;
			return;
		}
		break;
	default:
		std::cout << "REJECT";
		stop_flag = true;
		return;
	}
}

void Automat::parse(const char* file_name_)
{
	std::fstream in(file_name_);
	magazin.push_back('E');

	while (getline(in, input))
	{
		stack_head = magazin.back();
		input_head = input.front();

		while (!stop_flag)
		{
			stack_head = magazin.back();

			if (current_state == &Automat::q1)
				q1();
			else if (current_state == &Automat::q2)
				q2();
			else
				q3();

			input.erase(input.begin());
			if (!input.empty())
				input_head = input.front();
			else
				input_head = '\0';
		}

		stop_flag = false;
	}
}
