// "Сломать" инкремент в цикле. Замерить время.
// Выполнить цикл при помощи std::mutex. Замерить время.
// Выполнить цикл при помощи CAS. Замерить время.

#include <thread>
#include <vector>

int i = 0;

void naive_method(int& int_)
{
	unsigned int threads_amount = std::thread::hardware_concurrency();

	std::vector<std::thread> threads_vector;


}

int main()
{

}