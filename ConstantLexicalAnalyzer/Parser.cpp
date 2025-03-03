#include "Parser.h"

int Parser::transliterator(int ch_)
{
	if (isdigit(ch_))
	{
		current = ch_ - '0';

		return DIGIT;
	}
	else if (ch_ == '+' || ch_ == '-')
		return SIGN;
	else if (ch_ == 'E' || ch_ == 'e')
		return EXP;
	else if (ch_ == '.')
		return DOT;
	else if (ch_ == EOF || ch_ == ' ' || ch_ == '\n')
		return END;
	else
		return OTHER;
}

int Parser::q0() { return s_q0; }

int Parser::q1() { return s_q1; }

int Parser::q2() { return s_q2; }

int Parser::q3() { return s_q3; }

int Parser::q4() { return s_q4; }

int Parser::q5() { return s_q5; }

int Parser::q6() { return s_q6; }

int Parser::Skip() { return s_Skip; }

int Parser::P1()
{
	number_r = current;

	return s_q1;
}

int Parser::P2()
{
	number_r = 0;
	counter_r = 0;

	return s_q6;
}

int Parser::P3()
{
	number_r = number_r * 10 + current;

	return s_q1;
}

int Parser::P4()
{
	counter_r = 0;

	return s_q3;
}

int Parser::P5()
{
	counter_r = 0;

	return s_q2;
}

int Parser::P6()
{
	number_r = number_r * 10 + current;
	++counter_r;

	return s_q2;
}

int Parser::P7() { return s_q3; }

int Parser::P8()
{
	order_r = current;
	sign_r = true;

	return s_q5;
}

int Parser::P9()
{
	(current == '-') ? (sign_r = false) : (sign_r = true);

	return s_q4;
}

int Parser::P10()
{
	order_r = current;

	return s_q5;
}

int Parser::P11()
{
	order_r = order_r * 10 + current;

	return s_q5;
}

int Parser::P12()
{
	number_r = current;
	counter_r = 1;

	return s_q2;
}

int Parser::K1()
{
	res = number_r;

	std::cout << "Результат: " << res << std::endl;

	current = number_r = counter_r = order_r = error_code = 0;
	res = 0.0;
	sign_r = false;

	return s_q0;
}

int Parser::K2()
{
	res = number_r;

	std::cout << "Результат: " << res / pow(10, counter_r) << std::endl;

	current = number_r = counter_r = order_r = error_code = 0;
	res = 0.0;
	sign_r = false;

	return s_q0;
}

int Parser::K3()
{
	res = number_r;

	(sign_r) ? (counter_r += order_r) : (counter_r -= order_r);

	std::cout << "Результат: " << res / pow(10, counter_r) << std::endl;

	current = number_r = counter_r = order_r = error_code = 0;
	res = 0.0;
	sign_r = false;

	return s_q0;
}

int Parser::ErrorOther()
{
	std::cout << "Ошибка: Встречен недопустимый символ при объявлении константы" << std::endl;

	return s_Skip;
}

int Parser::Error0()
{
	std::cout << "Ошибка: Ожидалась целая часть или начало дробной части" << std::endl;

	return s_Skip;
}

int Parser::Error1()
{
	std::cout << "Ошибка: Ожидались цифра, E или точка" << std::endl;

	return s_Skip;
}

int Parser::Error2()
{
	std::cout << "Ошибка: Ожидалась цифра или E после точки" << std::endl;

	return s_Skip;
}

int Parser::Error3()
{
	std::cout << "Ошибка: Ожидались цифра или знак после E" << std::endl;

	return s_Skip;
}


