#include<functional>

struct MyStruct
{
bool isZero(int x)
{
    return x == 0;
}
};

int main(int argc, char* argv[])
{
    MyStruct s;
    std::function<bool(int)> cb;
   cb = std::bind(&MyStruct::isZero, &s, std::placeholders::_1);
    return cb(1);
}
