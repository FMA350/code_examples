#include <dlfcn.h>
#include <string>
#include <iostream>
#include <functional>

#include "Library.hpp"

typedef void(*FunctionSignature)(void);

int main(int argc, char* argv[])
{

    
    auto greetingFunctionName = std::string("_Z9greetingsv");   // Mangled name used in our library. You can check this by running "nm Library.so"
    auto safeFunctionName = std::string("safeExp");             // Invokes a "C" function, safe
    auto mangledFunctionName = std::string("mangled");          // Invokes a C++ mangled function, it will cause a crash
    
    // Try to load the Library at runtime
    void* libraryHandle;
    auto libraryPath  = std::string("./Library.so");
    if(!(libraryHandle = dlopen(libraryPath.c_str(), RTLD_NOW | RTLD_LAZY )))
    {
        std::cerr << "Faild to open " << libraryHandle << "\n";
        std::cerr << dlerror() << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Correctly loaded library  " << libraryPath << "\n";
    }

    // This function is unsafe but will work as we are using the mangled name
    auto libraryFunction = reinterpret_cast<FunctionSignature>(dlsym(libraryHandle, greetingFunctionName.c_str()));
    libraryFunction();

    // This function is safe as it is wrapped in extern "C" within our Library, and thus its name won't be mangled.
    auto safeFunction = reinterpret_cast<FunctionSignature>(dlsym(libraryHandle, safeFunctionName.c_str()));
    safeFunction();

    std::cout << "The program will now crash due to an Address boundary error " << "\n";

    // This function is unsafe and is going to crash the program.
    auto mangledFunction = reinterpret_cast<FunctionSignature>(dlsym(libraryHandle, mangledFunctionName.c_str()));
    mangledFunction();
    
    return 0;
} 