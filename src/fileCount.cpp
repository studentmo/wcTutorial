#include "extra.hpp"
#include <iostream>
#include <fstream>
#include <functional>
#include <thread>
#include <vector>
#include <iomanip>

void Words(std::fstream *myFile, extra *FlagsAndNumbers);
void Bytes(std::fstream *myFile, extra *FlagsAndNumbers);
void Lines(std::fstream *myFile, extra *FlagsAndNumbers);
void Byte(extra *FlagsAndNumbers);

int fIleCount(std::string path, extra *FlagsAndNumbers)
{
    std::function<void(std::fstream*, extra*)> OptionCounter;

    bool BytesUsing = false;

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
    if(FlagsAndNumbers->c)
    {
        OptionCounter=Bytes;
        OptionCounter(&myFile, FlagsAndNumbers);
        BytesUsing = true;
    }
    if(FlagsAndNumbers->m)
    {
        if(!BytesUsing)
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

void Bytes(std::fstream *myFile, extra *FlagsAndNumbers)
{
    myFile->seekp(0);
    char Ctemp;
    while(myFile->get(Ctemp))
    {
        FlagsAndNumbers->Bytes++;
        if((Ctemp & 0xc0) !=0x80) FlagsAndNumbers->Chars++; //8
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
void Chars(extra *FlagsAndNumbers)
{
    for(char tempChar : tempLine)
    {
        if((tempChar & 0xc0) !=0x80) charCount++;
    }
}