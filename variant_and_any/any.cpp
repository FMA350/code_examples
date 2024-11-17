#include <cassert>
#include <exception>
#include <vector>
#include <memory>
#include <string>
#include <any>


struct A
{
    // An example class  
};

struct Concept
{};

template<class T>
struct Model : Concept
{
    Model( const T& t ) : object( t ) {}
    private:
    T object;
};

struct Container
{
    std::shared_ptr<Concept> object;

    template< class T >
    Container(const T& obj ) : object(std::make_shared<Model<T>>(obj)){}
};

int main(int argc, char* argv[])
{
    // Heterogeneous vector using Container
    std::vector<Container> v;
    v.push_back(Container(5));
    v.push_back(Container(std::string("TEST")));
    v.push_back(Container(A()));

    // Or using std::any
    std::vector<std::any> vectorOfAny;
    vectorOfAny.push_back(std::any(5));
    vectorOfAny.push_back(std::any(std::string("TEST")));
    vectorOfAny.push_back(std::any(A()));

    try 
    {
        // cast down
        auto conceptInt = (*(int*)v[0].object.get());
        auto conceptString = (*(std::string*)v[1].object.get());

        auto anyInt = std::any_cast<int>(vectorOfAny[0]);
        auto anyString = std::any_cast<std::string>(vectorOfAny[1]);
        // and compare
        assert(conceptInt == anyInt);
        assert(conceptString == anyString);
    }
    catch (const std::exception& e)
    {
        //badness
    }

    return 0;
}