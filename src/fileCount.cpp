#include "extra.hpp"
#include <iostream>
#include <fstream>
#include <functional>

void Words(std::string temp, extra *FlagsAndNumbers);
void Chars(char Ctemp, extra *FlagsAndNumbers);
void Lines(std::string Ltemp, extra *FlagsAndNumbers);

int fIleCount(std::string path, extra *FlagsAndNumbers)
{
    std::fstream myFile(path, std::fstream::in | std::fstream::binary);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error\n";
        return 1;
    }

    std::function<void(std::string,extra*)> OptionCounter;

    OptionCounter = Words;

    std::string temp;
    while(myFile>>temp)
    {
        OptionCounter(temp, FlagsAndNumbers);
    }
    myFile.clear();
    myFile.seekg(0);

    char Ctemp;
    std::function<void(char,extra*)> COptionCounter;
    COptionCounter = Chars;
    while(myFile.get(Ctemp))
    {
        COptionCounter(Ctemp, FlagsAndNumbers);
    }
    
    myFile.clear();
    myFile.seekg(0);

    std::string Ltemp;
    OptionCounter = Lines;
    while(getline(myFile, Ltemp))
    {
        OptionCounter(Ltemp, FlagsAndNumbers);
    }

    myFile.close();
    return 1;
}

void Words(std::string temp, extra *FlagsAndNumbers)
{
    if (temp!=" ")
    {
    FlagsAndNumbers->Words++;
    std::cout<<temp<<"\n";
    }
}

void Chars(char Ctemp, extra *FlagsAndNumbers)
{
    std::cout<<Ctemp;
    FlagsAndNumbers->Chars++;
}

void Lines(std::string Ltemp, extra *FlagsAndNumbers)
{
    std::cout<<Ltemp;
    FlagsAndNumbers->Lines++;
}