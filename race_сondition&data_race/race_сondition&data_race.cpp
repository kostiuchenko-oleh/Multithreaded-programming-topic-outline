#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

const int steps = 50000;
int arr[10] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };

void add_numbers()
{
    for (int i = 0; i < steps; ++i)
    {
        int index = rand() % 10;
        arr[index] += 5;
    }
}

void subtract_numbers()
{
    for (int i = 0; i < steps; ++i)
    {
        int index = rand() % 10;
        arr[index] -= 5;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    auto start = std::chrono::high_resolution_clock::now();

    //add_numbers();
    //subtract_numbers();

	std::thread tadd_numbers(add_numbers);
	std::thread tsubtract_numbers(subtract_numbers);

	tadd_numbers.join();
	tsubtract_numbers.join();


    int final_sum = 0;
    for (int i = 0; i < 10; ++i) {
        final_sum += arr[i];
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "final sum = " << final_sum << '\n';
    std::cout << "duration = " << duration.count() << " sec\n";

    return 0;
}