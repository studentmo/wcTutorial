#include "extra.hpp"
#include <iostream>
#include <fstream>
#include <functional>
#include <thread>
#include <vector>
#include <iomanip>

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

    unsigned char tmpchar;
    myFile>>tmpchar;
    std::cout<<std::hex<<std::setw(2)<<static_cast<unsigned int>(tmpchar)<<" ";
        myFile>>tmpchar;
    std::cout<<std::hex<<std::setw(2)<<static_cast<unsigned int>(tmpchar)<<" ";
    int Endcoding;
    if("ff fe")Endcoding=16;
    if("23 23")Endcoding=8;

    std::cout<<std::dec;
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
    myFile->seekp(0);
    std::string temp;
    while(*myFile>>temp)
    {
        if (temp!=" ")FlagsAndNumbers->Words++;
    }
    myFile->clear();
}

void Chars(std::fstream *myFile, extra *FlagsAndNumbers)
{
    myFile->seekp(0);
    char Ctemp;
    while(myFile->get(Ctemp))FlagsAndNumbers->Chars++;
    myFile->clear();
}

void Lines(std::fstream *myFile, extra *FlagsAndNumbers)
{
    myFile->seekp(0);
    std::string Ltemp;
    while(getline(*myFile, Ltemp))FlagsAndNumbers->Lines++;
    myFile->clear();
}
void Bytes(extra *FlagsAndNumbers)
{
    FlagsAndNumbers->Bytes = FlagsAndNumbers->Chars*1;// умножаем в зависимости от кодировки
}