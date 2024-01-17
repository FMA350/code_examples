#include <map>
#include <any>
#include <iostream>
#include <memory>
#include <type_traits>

using any_map = std::map<std::string, std::any>;

class Node
{
private:
    any_map storage;
    std::string lastKey;
public:

    // Explicit getter
    std::any operator()()
    {
        return storage[lastKey];
    }

    // Implicit templated getter
    template<typename T>
    operator T()
    {
        try
        {
            T value = std::any_cast<T>(storage[lastKey]);
            return value;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " for key: " << lastKey << '\n';
            return T();
        }
    }

    // Setter
    void operator=(std::any value)
    {
        storage[lastKey] = value;
    }

    // Overloaded convenience accessor
    Node& operator[](const char* key)
    {
        return (*this)[std::string(key)];
    }

    // Accessor
    Node& operator[](std::string key)
    {
        lastKey = key;
        if(storage.find(key) != storage.end())
        {
            if(auto node = std::any_cast<Node*>(&storage[key]))
            {
                return **node;
            }
        }
        return *this;
    }
};

int main(int argc, char const *argv[])
{
    // Initializing our three Node objects
    Node root;
    Node branch;
    std::shared_ptr<Node> leaf = std::make_shared<Node>();

    // Simple assignment on root
    root["an_int"] = 42;
    root["branch"] = &branch;               // Can pass the address

    // Late assignment with implicit double
    branch["double"] = 25.6;
    // Late assignment with type float
    (*leaf)["float"] = float(15);

    // In depth assignment
    root["branch"]["leaf"] = leaf.get();    // Or even use a shared_ptr
    root["branch"]["leaf"]["string"] = std::string("A string value");
    root["a_char"] = "a const char value string";
    
    
    // Implicit getters
    int an_int           = root["an_int"];
    std::string a_string = root["branch"]["leaf"]["string"];
    const char* a_char   = root["a_char"];
    double a_double      = root["branch"]["double"];
    float a_float        = root["branch"]["leaf"]["float"];

    // Output
    std::cout << std::to_string(an_int) << std::endl;
    std::cout << a_string << std::endl;
    std::cout << a_char << std::endl;
    std::cout << std::to_string(a_double) << std::endl;
    std::cout << std::to_string(a_float) << std::endl;

    // Explicit getter of a missing value
    auto x = root["missing"]();
    try
    {
        int missing = std::any_cast<int>(x);                // fails since it is missing
        std::cout << std::to_string(missing) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::string(" for root[\"missing\"] to int") << '\n';
    }
    

    return 0;
}
