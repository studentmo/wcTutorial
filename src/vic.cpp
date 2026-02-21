#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    int VERSION_MAJOR = 0;
    int VERSION_MINOR = 0;
    std::streampos VERSION_MAJOR_POINT;
    std::streampos VERSION_MINOR_POINT;
    std::string arg = argv[1];

    std::fstream myFile("./include/extra.hpp", std::fstream::out | std::fstream::in | std::fstream::binary);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error\n";
        return 1;
    } 

    std::string temp;
    while(myFile>>temp)
    {
        if (temp=="VERSION_MAJOR" & arg == "-Ma")
        {
            VERSION_MAJOR_POINT = myFile.tellg();
            VERSION_MAJOR_POINT+=1;
            myFile>>VERSION_MAJOR;
            
        }
        if (temp=="VERSION_MINOR")
        {
            VERSION_MINOR_POINT = myFile.tellg();
            VERSION_MINOR_POINT+=1;
            myFile>>VERSION_MINOR;
            
        }  
    }
    myFile.clear();

    if(arg == "-Ma")
    {
    ++VERSION_MAJOR;
    myFile.seekp(VERSION_MAJOR_POINT);
    myFile<<VERSION_MAJOR;
    myFile.seekp(VERSION_MINOR_POINT);
    myFile<<0;
    int ColNumbers=0;
    while (VERSION_MINOR>0)
        {
            VERSION_MINOR/=10;
            ColNumbers++;
        }
    for (int i = 0; i < ColNumbers-1; i++)
        {
            myFile<<' ';
        }
    }

    else 
    {
    ++VERSION_MINOR;
    myFile.seekp(VERSION_MINOR_POINT);
    myFile<<VERSION_MINOR;
    }

    myFile.close();
}

