#include "extra.hpp"
#include <iostream>
#include <fstream>
#include <functional>
#include <thread>
#include <vector>

void Words(std::fstream *myFile, extra *FlagsAndNumbers);
void Chars(std::fstream *myFile, extra *FlagsAndNumbers);
void Lines(std::fstream *myFile, extra *FlagsAndNumbers);
void Bytes(extra *FlagsAndNumbers);

int fIleCount(std::string path, extra *FlagsAndNumbers)
{
    std::function<void(std::fstream*, extra*)> OptionCounter;

    bool CharsUsing = false;

    std::fstream myFile(path, std::fstream::in | std::fstream::binary);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error\n";
    }

    if(FlagsAndNumbers->m)
    {
        OptionCounter=Chars;
        OptionCounter(&myFile, FlagsAndNumbers);
        CharsUsing = true;
    }
    if(FlagsAndNumbers->c)
    {
        if(!CharsUsing)
        {
            OptionCounter=Chars;
            OptionCounter(&myFile, FlagsAndNumbers);
            Bytes(FlagsAndNumbers);
        }     
        Bytes(FlagsAndNumbers);   
    }
    if(FlagsAndNumbers->l)
    {
        OptionCounter = Lines;
        OptionCounter(&myFile, FlagsAndNumbers);
    }
    if(FlagsAndNumbers->w)
    {
        OptionCounter = Words;
        OptionCounter(&myFile, FlagsAndNumbers);
    }

    return 1;
}

void Words(std::fstream *myFile, extra *FlagsAndNumbers)
{
    std::string temp;
    while(*myFile>>temp)
    {
        if (temp!=" ")FlagsAndNumbers->Words++;
    }
}

void Chars(std::fstream *myFile, extra *FlagsAndNumbers)
{
    char Ctemp;
    while(myFile->get(Ctemp))FlagsAndNumbers->Chars++;
}

void Lines(std::fstream *myFile, extra *FlagsAndNumbers)
{
    std::string Ltemp;
    while(getline(*myFile, Ltemp))FlagsAndNumbers->Lines++;
}
void Bytes(extra *FlagsAndNumbers)
{
    FlagsAndNumbers->Bytes = FlagsAndNumbers->Chars*1;// умножаем в зависимости от кодировки
}