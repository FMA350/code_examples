/*
 * Created on Sun Jul 21 2024
 *
 * Copyright (c) 2024 Moneta Software
 */

#include <string>
#include <sstream>
#include <vector>
#include <map>

#include <ParserInterface.hpp>
// in charge of loading and saving a file

class ConfigurationFile
{
    private:
        std::string _path;
        std::stringstream _data;    // flat

        std::vector<std::string> _insertionMetaMap;
        mapofmaps _internalRepresentation;

    public:
        ConfigurationFile(std::string p) : _path(p){};
        void read();
        void write();
};