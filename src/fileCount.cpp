#include "extra.hpp"
#include <iostream>
#include <fstream>
#include <functional>
#include <thread>
#include <vector>

void Words(std::string path, extra *FlagsAndNumbers);
void Chars(std::string path, extra *FlagsAndNumbers);
void Lines(std::string path, extra *FlagsAndNumbers);
void Bytes(extra *FlagsAndNumbers);

int fIleCount(std::string path, extra *FlagsAndNumbers)
{
    std::function<void(std::string, extra*)> OptionCounter;
    std::function<void(std::string, extra*)> WordsFunThread;
    std::function<void(std::string, extra*)> LinesFunThread;
    std::function<void(extra*)> FunBytes;
    std::vector<std::thread> VecThread;
    VecThread.emplace_back(LinesFunThread, path, FlagsAndNumbers);
    VecThread.emplace_back(WordsFunThread, path, FlagsAndNumbers);
    bool MainThread = false;
    bool BoolWordsThread = false;
    bool BoolLinesThread = false;
    bool BoolBytes = false;
    bool CharsUsing = false;

    if(FlagsAndNumbers->m)
    {
        OptionCounter=Chars;
        MainThread = true;
        CharsUsing = true;
    }
    if(FlagsAndNumbers->c)
    {
        if(!CharsUsing)
        {
            MainThread =  Chars;
            MainThread = true;
            BoolBytes = true;
        }
    }
    if(FlagsAndNumbers->l)
    {
        if(!MainThread)
        {
            OptionCounter = Lines;
            MainThread = true;
        }
        else 
        {
            LinesFunThread = Lines;
            BoolLinesThread = true;
        }
    }
    if(FlagsAndNumbers->w)
    {
        if(!MainThread)
        {
            OptionCounter = Words;
            MainThread = true;
        }
        else
        {
            WordsFunThread = Words;
            BoolWordsThread = true;
        }
    }

    if(BoolLinesThread)VecThread[0];
    if(BoolWordsThread)VecThread[1];
    OptionCounter(path, FlagsAndNumbers);
    if(BoolBytes)FunBytes(FlagsAndNumbers);

    if(BoolLinesThread)VecThread[0].join();
    if(BoolWordsThread)VecThread[1].join();
    return 1;
}

void Words(std::string path, extra *FlagsAndNumbers)
{
    std::fstream myFile(path, std::fstream::in | std::fstream::binary);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error\n";
    }

    std::string temp;
    while(myFile>>temp)
    {
        if (temp!=" ")FlagsAndNumbers->Words++;
    }
    std::cout<<"Words worked \n";
    myFile.close();
}

void Chars(std::string path, extra *FlagsAndNumbers)
{
    std::fstream myFile(path, std::fstream::in | std::fstream::binary);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error\n";
    }

    char Ctemp;
    while(myFile.get(Ctemp))FlagsAndNumbers->Chars++;
    std::cout<<"Chars worked \n";
    myFile.close();
}

void Lines(std::string path, extra *FlagsAndNumbers)
{
    std::fstream myFile(path, std::fstream::in | std::fstream::binary);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error\n";
    }

    std::string Ltemp;
    while(getline(myFile, Ltemp))FlagsAndNumbers->Lines++;
    std::cout<<"Lines worked \n";
    myFile.close();
}
void Bytes(extra *FlagsAndNumbers)
{
    FlagsAndNumbers->Bytes = FlagsAndNumbers->Chars*1;// умножаем в зависимости от кодировки
    std::cout<<"Bytes worked\n";
}