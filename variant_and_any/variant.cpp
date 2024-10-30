#include <variant>
#include <iostream>

int main(int argc, char* argv[])
{
    std::variant<int, std::string> x;
    x = 42;
    std::cout << "Variant is : " << std::get<int>(x) << "\n"; 
    x = "hello variant!";
    std::cout << "Variant is : " << std::get<std::string>(x) << "\n"; 
    try
    {
        int tmp = std::get<int>(x);
        std::cout << "Variant is int \n";
    }
    catch(std::exception& e)
    {
        std::cout << "Variant was not an int \n";
    }

    return 0;
}
