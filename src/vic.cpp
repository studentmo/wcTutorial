#include <fstream>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
    int version_major = 0;
    int version_minor = 0;

    std::streampos version_major_inc;
    std::streampos version_minor_inc;

    std::fstream myFile("./include/common.hpp", std::ios::in | std::ios::out | std::ios::binary);

    std::string temp;
    while(myFile>>temp)
    {
        if(temp == "VERSION_MAJOR")
        {
            myFile.get(); // skipping char 32
            version_major_inc = myFile.tellg();
            myFile>>version_major;
        }
        if(temp == "VERSION_MINOR")
        {
            myFile.get(); // skipping char 32
            version_minor_inc = myFile.tellg();
            myFile>>version_minor;
        }
    }
    myFile.clear();
    
    ++version_major;
    ++version_minor;
    
    myFile.seekp(version_major_inc);
    myFile<<version_major;
    myFile.seekp(version_minor_inc);
    myFile<<version_minor;
    myFile.close();
}