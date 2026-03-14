#include "extra.hpp"
#include <iostream>
#include <fstream>
#include <functional>
#include <thread>
#include <vector>
#include <iomanip>

void Words(std::fstream *myFile, extra *FlagsAndNumbers);
void Bytes(std::fstream *myFile, extra *FlagsAndNumbers, int Endcoding);
void Lines(std::fstream *myFile, extra *FlagsAndNumbers);

int fIleCount(std::string path, extra *FlagsAndNumbers)
{
    std::function<void(std::fstream*, extra*)> OptionCounter;

    std::fstream myFile(path, std::fstream::in | std::fstream::binary);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error\n";
    }

    int Encoding;
    char tmpChar;
    char tmpChar1;
    myFile>>tmpChar;
    myFile>>tmpChar1;
    if(tmpChar==-1 && tmpChar1==-2)Encoding=16;
    else if(tmpChar==76 && tmpChar1==97)Encoding=8;
    
    /*
    -1 -2 16
    76 97 8
    */

    /*
    for(char tempChar : tempLine)
    {
        if((tempChar & 0xc0) !=0x80) charCount++;
    }
    */

    std::cout<<std::dec;
    if(FlagsAndNumbers->c || FlagsAndNumbers->m)
    {
        Bytes(&myFile, FlagsAndNumbers, Encoding);
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

void Bytes(std::fstream *myFile, extra *FlagsAndNumbers, int Endcoding)
{
    myFile->seekp(0);
    char Btemp;
    int FlagSkip = 0;
    if(Endcoding==8)//8
    {
        while(myFile->get(Btemp))
        {
            FlagsAndNumbers->Bytes++;
            if((Btemp & 0xc0) !=0x80) FlagsAndNumbers->Chars++;
        }
    }
    if(Endcoding==16)//16
    {
        while(myFile->get(Btemp))
        {
            if(FlagSkip != 0)
            {
                FlagSkip--;
                break;
            }
            FlagsAndNumbers->Bytes++;
            if((Btemp & 0xfc) ==0xd8) 
            {
                FlagsAndNumbers->Chars++;
                FlagSkip=3;
            }
            else if((Btemp & 0xfc) ==0xdc)
            {
                std::cerr<<"Error in the structure of the suregists encoding";
            }
            else
            {
                FlagsAndNumbers->Chars++;
                FlagSkip=1;
            }
        }
    }
    myFile->clear();
}

void Lines(std::fstream *myFile, extra *FlagsAndNumbers)
{
    myFile->seekp(0);
    std::string Ltemp;
    while(getline(*myFile, Ltemp))FlagsAndNumbers->Lines++;
    myFile->clear();
}