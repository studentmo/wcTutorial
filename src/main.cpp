#include <iostream>
#include "extra.hpp"

int main(int argc, char** argv)
{
    extra FlagsAndNumbers;

    argcProg(argc, argv, &FlagsAndNumbers);
    
    std::cout<<argc<<std::endl;
    for (int i = 0; i < argc; i++)
    {
        std::cout<<argv[i]<<std::endl;
    }
    
    std::cout<<std::endl<<std::endl<<std::endl;

    std::cout<<"h = "<<FlagsAndNumbers.h<<std::endl;
    std::cout<<"v = "<<FlagsAndNumbers.v<<std::endl;
    std::cout<<"l = "<<FlagsAndNumbers.l<<std::endl;
    std::cout<<"m = "<<FlagsAndNumbers.m<<std::endl;
    std::cout<<"c = "<<FlagsAndNumbers.c<<std::endl;
    std::cout<<"w = "<<FlagsAndNumbers.w<<std::endl;
    std::cout<<"r = "<<FlagsAndNumbers.r<<std::endl;
    
    

    return 0;
}