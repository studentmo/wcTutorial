#include "extra.hpp"
#include <iostream>
#include <fstream>
#include <functional>

void Lines(std::string temp, extra *FlagsAndNumbers);

int fIleCount(std::string path, extra *FlagsAndNumbers)
{
    std::fstream myFile(path, std::fstream::in);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error\n";
        return 1;
    }

    std::function<void(std::string,extra*)> OptionCounter;

    OptionCounter = Lines;

    std::string temp;
    while(myFile>>temp)
    {
        OptionCounter(temp, FlagsAndNumbers);
    }
    return 1;
}

void Lines(std::string temp, extra *FlagsAndNumbers)
{
    if (temp=="\n")FlagsAndNumbers->Lines++;
    std::cout<<temp<<"\n";
}