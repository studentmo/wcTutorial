#include "extra.hpp"
#include <fstream>
#include <string>
#include <iostream>

int FIleCount(std::string argv, extra *FlagsAndNumbers)
{
    std::fstream myFile(argv, std::fstream::in);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error\n";
        return 1;
    }
    std::string temp;
    while(myFile>>temp)
    {
        if(temp=="\n")
        FlagsAndNumbers->Lines++;
    }
}

void Lines()
{

}