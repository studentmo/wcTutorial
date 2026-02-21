#include <fstream>
#include <iostream>
#include <string>

int vic(int argc, char** argv)
{
    int VERSION_MAJOR;
    int VERSION_MINOR;
    std::streampos VERSION_MAJOR_POINT;
    std::streampos VERSION_MINOR_POINT;

    std::fstream myFile("./include/extra.hpp", std::fstream::out | std::fstream::in | std::ios::binary);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error\n";
        return 1;
    }
    std::string temp;
    while(myFile>>temp)
    {
        if (temp=="VERSION_MAJOR" && argv[1] == "Ma")
        {
            VERSION_MAJOR_POINT = myFile.tellg();
            VERSION_MAJOR_POINT+=1;
            myFile>>VERSION_MAJOR;
            
        }
        if (temp=="VERSION_MINOR" && argv[1] == "Mi")
        {
            VERSION_MINOR_POINT = myFile.tellg();
            VERSION_MINOR_POINT+=1;
            myFile>>VERSION_MINOR;
            
        }
        
    }
    myFile.clear();

    myFile.seekp(VERSION_MAJOR_POINT);
    ++VERSION_MAJOR;
    myFile<<VERSION_MAJOR;
    myFile.seekp(VERSION_MINOR_POINT);
    ++VERSION_MINOR;
    myFile<<VERSION_MINOR;
    myFile.close();


}

