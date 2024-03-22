
## To recompile this example:

g++ -c -Wall -Werror -fPIC Library.cpp
g++ -shared -o Library.so Library.o
g++ -o example main.cpp

## To observe mangled and non-mangled names within the Library.so

nm -gD Library.so 
