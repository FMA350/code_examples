#include <iostream>
#include <chrono>

int Fibo(int n)
{
    if(n <= 0) return 0; // bad input condition
    if(n == 1 || n == 2)  return 1; // first and second number of the series are 1, 1 
    return Fibo(n-1) + Fibo(n-2);
}


int main(int argc, char*argv[])
{
    if(argc < 2)
    {
        std::cout << "You must pass the fibonacci sequence you want";
        return 0;
    }
    else
    {
        auto begin = std::chrono::steady_clock::now();
        int result = Fibo(std::stoi(argv[1]));
        std::cout << "Fibo result is: " << result << "\n";
        auto end = std::chrono::steady_clock::now();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl; 
        return result;
    }
}
