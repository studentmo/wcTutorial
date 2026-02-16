#include <fstream>
#include <iostream>

int main()
{
    int VERSION_MAJOR = 0, VERSION_MINOR = 0; 
    std::streampos VERSIONMAJORITERATOR;
    std::streampos VERSIONMINORITERATOR;

    std::fstream file("./include/MainH.hpp", std::ios::in | std::ios::out);
    if(!(file.is_open()))
    {
        std::cout<<"Error\n";
        return 1;
    }

    std::string temp;
    while(file>>temp)
    {
        if(temp == "VERSION_MAJOR")
        {
            VERSIONMAJORITERATOR = file.tellg();
            file>>VERSION_MAJOR;
        }
        if(temp == "VERSION_MINOR")
        {
            VERSIONMINORITERATOR = file.tellg();
            file>>VERSION_MINOR;
        }
    }
    file.clear();

    ++VERSION_MAJOR; ++VERSION_MINOR;

    file.seekp(VERSIONMAJORITERATOR);
    file<<VERSION_MAJOR;
    file.seekp(VERSIONMINORITERATOR);
    file<<VERSION_MINOR;
    return 0;
}