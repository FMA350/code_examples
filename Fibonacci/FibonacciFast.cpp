#include <iostream>
#include <chrono>
#include <map>


std::map<int,int> solution;

int Fibo(int n)
{
    if(n <= 0) return 0; // bad input condition
    if(solution.find(n) == solution.end())
        solution[n] = Fibo(n-1) + Fibo(n-2);
    return solution[n];
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
        solution[1] = 1;
        solution[2] = 1;
        int result = Fibo(std::stoi(argv[1]));
        std::cout << "Fibo result is: " << result << "\n";
        auto end = std::chrono::steady_clock::now();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl; 
        return result;
    }

}
