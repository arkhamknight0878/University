#include <iostream>
#include <vector>
#include <math.h>

#define M_PI 3.14159265358979323846

typedef std::vector<double>::const_iterator dvector_it;

namespace numerical_methods
{
	/**
	 * @brief		: Считает машинный эпсилон в забисимости от желаемого типа данных T.
	 * @tparam T	: Тип данных, для которого необходими найти машинный эпсилон.
	 * @return		: Машинный эпсилон для типа данных T.
	 */
	template <typename T>
	T calculate_machine_eps()
	{
		// Машинный эпсилон - минимальное число, которое при сложении с единицей даёт число большее (строго) единицы.
		T epsilon = 1.0;

		while ((T)(1.0 + epsilon) != T(1.0))
			epsilon /= 2.0;

		return epsilon * 2.0;
	}

	/**
	 * @brief				: Находит первый эл-нт, который строго больше x в области [range_begin, range_end).
	 * @param range_begin	: Итератор на начало области поиска.
	 * @param range_end		: Итератор на конец области поиска.
	 * @param x				: Эл-нт, относительно которого мы ищем верхнюю границу.
	 * @return				: Итератор на найденный эл-нт, если он есть в области, итератор на последний эл-нт области в противном случае.
	 */
	dvector_it upper_bound(dvector_it range_begin, dvector_it range_end, const double x)
	{
		std::vector<double>::const_iterator it = range_begin;

		while ((it + 1) != range_end && *it <= x)
			++it;

		return it;
	}

	/**
	 * @brief		: Считает число инкрементов итератора begin, необходимое чтобы дойти до итератора last.
	 * @param begin	: Итератор, указывающий на первый эл-нт.
	 * @param last	: Итератор, указывающий на последний эл-нт области.
	 * @return		: Число инкрементов итератора begin, необходимое чтобы дойти до итератора last.
	 */
	int distance(dvector_it begin, dvector_it last)
	{
		int dst = 0;

		while (begin != last)
		{
			dst++;
			begin++;
		}

		return dst;
	}

	/**
	 * @brief					: Ф-ия подсчёта кусочно-линейной интерполяции для числа x_interpolated.
	 * @param x_coord			: Отсортированный по возрастанию вектор координат входных точек по оси X.
	 * @param y_coord			: Отсортированный по возрастанию вектор координат входных точек по оси Y.
	 * @param x_interpolated	: Координата по оси X, для которой нужно найти значение интерполяции.
	 * @return					: Значение интерполяции в точке x_interpolated.
	 */
	double linear_interpolation(const std::vector<double>& x_coord, const std::vector<double>& y_coord, double x_interpolated)
	{
		// Проверяем наборы точек на пустоту и одинаковое кол-во эл-ов.
		if (x_coord.empty() || y_coord.empty() || (x_coord.size() != y_coord.size()))
			throw std::invalid_argument("Input values must be valid and have the same size.");

		// Если на входе была всего одна точка, которая не равна x_interpolated, то интерполяция невожзможна.
		if (x_coord.size() == 1)
		{
			if (x_interpolated == x_coord[0])
				return y_coord[0];
			else
				throw std::out_of_range("It is impossible to interpolate whith single point whith that value of x.");
		}

		// Проверка на вхождение x_interpolated в мн-во начальных точек.
		if (x_interpolated < x_coord.front() || x_interpolated > x_coord.back())
			throw std::out_of_range("x is outside X values range => Interpolation isn't possible.");

		if (x_interpolated == y_coord.back())
			return y_coord.back();

		// Первый эл-нт строго больший, чем x_interpolated.
		dvector_it it = upper_bound(x_coord.begin(), x_coord.end(), x_interpolated);

		int r_border = distance(x_coord.begin(), it);	// Правая граница интерполируемого интервала.
		int l_border = r_border - 1;					// Левая граница интерполируемого интервала.

		// Значения границ интервалов.
		double x1 = x_coord[l_border];
		double x2 = x_coord[r_border];
		double y1 = y_coord[l_border];
		double y2 = y_coord[r_border];

		// Рассчёт интерполяции по формуле кусочно-линейной интерполяции.
		if (x1 == x2)
			return y1;
		else
			return (y1 + (y2 - y1) * (x2 - x1) / (x2 - x1));
	}

	/**
	 * @brief	: Рассчёт значения производной ф-ии y = sinx в заданной точке x.
	 * @param x	: Точка, в которой необходимо найти производную.
	 * @param h : Шаг дифференциирования.
	 * @return	: Производная ф-ии y = sinx в точке x.
	 */
	double derivative_of_sin(const double x, const double h = 1e-9)
	{
		if (!h)
			throw std::invalid_argument("h must be greater than zero.");

		return (std::sin(x + h) - std::sin(x - h)) / (2.0 * h);
	}

	void print_vector(const std::vector<double>& vector)
	{
		dvector_it it = vector.begin();

		std::cout << '(';
		while (it + 1 != vector.end())
		{
			std::cout << *it << ", ";
			++it;
		}
		std::cout << *it << ')';
	}
}

int main()
{
	// -----------------------------------------------------------------------------------------------------------------

	std::cout << "1) Machine Epsilone:" << std::endl;
	std::cout << "   a. For float type:" << std::endl;
	std::cout << "      Numeric Limits std = " << std::numeric_limits<float>::epsilon() << std::endl;
	std::cout << "      My function        = " << numerical_methods::calculate_machine_eps<float>() << std::endl;
	std::cout << "   b. For double type:" << std::endl;
	std::cout << "      Numeric Limits std = " << std::numeric_limits<double>::epsilon() << std::endl;
	std::cout << "      My function        = " << numerical_methods::calculate_machine_eps<double>() << std::endl;
	std::cout << std::endl;

	// -----------------------------------------------------------------------------------------------------------------

	std::vector<double> x_vector = { 1.0,  2.0,  3.0,  4.0,  5.0  };
	std::vector<double> y_vector = { 10.0, 15.0, 12.0, 18.0, 20.0 };
	std::vector<double> x_values = { 2.5,  1.0,  5.0,  0.5,  5.5,  3.0 };

	std::cout << "2) Linear Interpolation:" << std::endl;
	std::cout << "   X input vector: "; numerical_methods::print_vector(x_vector); std::cout << std::endl;
	std::cout << "   Y input vector: "; numerical_methods::print_vector(y_vector); std::cout << std::endl;
	std::cout << "   x values: ";		 numerical_methods::print_vector(x_values); std::cout << std::endl;
	std::cout << std::endl;

	for (double x_interpolated : x_values)
	{
		try
		{
			std::cout << "   Interpolation for x = " << x_interpolated << ": " << numerical_methods::linear_interpolation(x_vector, y_vector, x_interpolated) << std::endl;
		}
		catch (const std::exception& error)
		{
			std::cerr << "   Interpolation error for x = " << x_interpolated << ": " << error.what() << std::endl;
		}
	}

	std::cout << std::endl;

	// -----------------------------------------------------------------------------------------------------------------

	try
	{
		double x = M_PI / 3;
		double exact_div = cos(x);
		std::cout << "3) Derivative of y = sinx:" << std::endl;
		std::cout << "   x = " << x << " (pi/3)" << std::endl;
		std::cout << "   Derivative of y: " << exact_div << std::endl << std::endl;


		double h = 1e-9;
		double calculated_div = numerical_methods::derivative_of_sin(x, h);
		std::cout << "   Derivative of y' using my function with h = " << h << ": " << calculated_div << std::endl;
		std::cout << "   Avsolute error: " << std::fabs(exact_div - calculated_div) << std::endl << std::endl;

		h = 1e-3;
		calculated_div = numerical_methods::derivative_of_sin(x, h);
		std::cout << "   Derivative of y' using my function with h = " << h << ": " << calculated_div << std::endl;
		std::cout << "   Avsolute error: " << std::fabs(exact_div - calculated_div) << std::endl << std::endl;
	}
	catch (const std::exception& error)
	{
		std::cerr << "Derivative error: " << error.what() << std::endl;
	}

	return 0;
}