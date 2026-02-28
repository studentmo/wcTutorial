#include <iostream>
#include "extra.hpp"

int main(int argc, char** argv)
{
    extra FlagsAndNumbers;

    argcProg(argc, argv, &FlagsAndNumbers);
    if(FlagsAndNumbers.ResultArgs == 'f')
    {
        fIleCount(argv[1], &FlagsAndNumbers);
    }
    resultOutput(&FlagsAndNumbers);
    std::cout<<std::endl;
    
    std::cout<<"argc = "<<argc<<std::endl;
    for (int i = 0; i < argc; i++)
    {
        std::cout<<"Argv "<<i<<" = "<<argv[i]<<std::endl;
    }
    std::cout<<"Result Args = "<<FlagsAndNumbers.ResultArgs<<std::endl;
    std::cout<<std::endl<<std::endl;

    std::cout<<"h = "<<FlagsAndNumbers.h<<std::endl;
    std::cout<<"v = "<<FlagsAndNumbers.v<<std::endl;
    std::cout<<"l = "<<FlagsAndNumbers.l<<"\tlines = "<<FlagsAndNumbers.Lines<<std::endl;
    std::cout<<"m = "<<FlagsAndNumbers.m<<std::endl;
    std::cout<<"c = "<<FlagsAndNumbers.c<<std::endl;
    std::cout<<"w = "<<FlagsAndNumbers.w<<std::endl;
    std::cout<<"r = "<<FlagsAndNumbers.r<<std::endl;
    std::cout<<"Lines = "<<FlagsAndNumbers.Lines<<std::endl;
    std::cout<<"Chars = "<<FlagsAndNumbers.Chars<<std::endl;
    std::cout<<"Bytes = "<<FlagsAndNumbers.Bytes<<std::endl;
    std::cout<<"Words = "<<FlagsAndNumbers.Words<<std::endl;

    return 0;
}