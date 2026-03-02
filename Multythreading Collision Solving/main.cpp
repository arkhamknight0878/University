// "Сломать" инкремент в цикле. Замерить время.
// Выполнить цикл при помощи std::mutex. Замерить время.
// Выполнить цикл при помощи CAS. Замерить время.

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <atomic>

int global_var = 0;
std::atomic<int> global_atomic{ 0 };

void naive_increment()
{
	for (int i = 0; i < 1000000; ++i)
		++global_var;
}

void mutex_increment()
{
	std::mutex new_mutex;

	for (int i = 0; i < 1000000; ++i)
	{
		new_mutex.lock();
		++global_var;
		new_mutex.unlock();
	}
}

void cas_increment()
{
	for (int i = 0; i < 1000000; ++i)
		++global_atomic;
}

int main()
{
	int threads_amount = std::thread::hardware_concurrency();

	std::vector<std::thread> threads_vector;

	// 1. Наивный метод:

	auto start = std::chrono::steady_clock::now();

	for (int i = 0; i < threads_amount; ++i)
		threads_vector.emplace_back(naive_increment);

	auto finish = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);

	for (auto& it : threads_vector)
		it.join();

	threads_vector.clear();

	std::cout << "Naive method work duration: " << duration << "\n\n";

	global_var = 0;


	// 2. Mutex:

	start = std::chrono::steady_clock::now();

	for (int i = 0; i < threads_amount; ++i)
		threads_vector.emplace_back(mutex_increment);

	finish = std::chrono::steady_clock::now();
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);

	for (auto& it : threads_vector)
		it.join();

	std::cout << "Mutex method work duration: " << duration << "\n\n";

	global_var = 0;

	threads_vector.clear();


	// 3. CAS:

	start = std::chrono::steady_clock::now();

	for (int i = 0; i < threads_amount; ++i)
		threads_vector.emplace_back(cas_increment);

	finish = std::chrono::steady_clock::now();
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);

	for (auto& it : threads_vector)
		it.join();

	std::cout << "CAS method work duration: " << duration << "\n\n";

	return 0;
}