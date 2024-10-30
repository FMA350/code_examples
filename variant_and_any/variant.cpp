#include <variant>
#include <iostream>


struct vA{

    void who(){
        std::cout << "I am variant A \n";
    }
};

struct vB{

    void who(){
        std::cout << "I am variant B \n";
    }
};

struct vC{

    void who(){
        std::cout << "I am variant C \n";
    }
};


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

    // Dynamic polymorphism with variants
    std::variant<vA, vB, vC> variant = vC();
    std::visit([](auto&v){v.who();},variant);
    return 0;
}
