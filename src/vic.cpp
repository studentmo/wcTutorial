#include <fstream>
#include <iostream>
#include <string>

int main()
{
    int VERSION_MAJOR = 0;
    int VERSION_MINOR = 0;
    std::streampos VERSION_MAJOR_POINT;
    std::streampos VERSION_MINOR_POINT;

    std::fstream myFile("./include/extra.hpp", std::fstream::out | std::fstream::in);
    if (!(myFile.is_open()))
    {
        std::cout<<"Error\n";
        return 1;
    }
    std::string temp;
    while(myFile>>temp)
    {
        if (temp=="VERSION_MAJON")
        {
            VERSION_MAJOR_POINT = myFile.tellg();
            ++VERSION_MAJOR;
            myFile>>VERSION_MAJOR;
            myFile<<VERSION_MAJOR;
        }
        if (temp=="VERSION_MINOR")
        {
            VERSION_MINOR_POINT = myFile.tellg();
            ++VERSION_MINOR;
            myFile>>VERSION_MINOR;
            myFile<<VERSION_MAJOR;
        }  
    }
    myFile.close();


}

