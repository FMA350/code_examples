#include <ConfigurationFile.hpp>
#include <fstream>
#include <exception>
#include <stdexcept>

void ConfigurationFile::read()
{
    // open file
    _data.clear();
    std::ifstream f (_path);
    if(f.is_open())
    {
        std::string line;
        while ( std::getline (f,line) )
        {
            _data << line << std::endl;
        }
        f.close();
    }
    else
    {
        throw std::runtime_error(std::string("File at " + _path + " could not be opened for reading"));
    }
}

void ConfigurationFile::write()
{
    std::ofstream f(_path);
    if(f.is_open())
    {
        std::string l;
        while( std::getline(_data,l))
        {
            f << l;
            if(_data.peek() != EOF)
            {
                f << std::endl;
            }
        }
        f.close();
    }
    else
    {
        throw std::runtime_error(std::string("File at " + _path + " could not be opened for writing"));
    }
}

