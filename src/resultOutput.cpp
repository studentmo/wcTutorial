#include "extra.hpp"
#include <iostream>

void MessageError(extra FlagsAndNumbers);
void MessageHelp();
void MessageVersion();

void resultOutput(extra *FlagsAndNumbers)
{
    if (FlagsAndNumbers->ResultArgs == 'f')std::cout<<"Cout flags down\n";
    else if (FlagsAndNumbers->ResultArgs == 'h')MessageHelp();
    else if (FlagsAndNumbers->ResultArgs == 'v')MessageVersion();
    else if (FlagsAndNumbers->ResultArgs == 'r')MessageError(*FlagsAndNumbers);
}

void MessageError(extra FlagsAndNumbers)
{
    std::cout<<"wc: "<<FlagsAndNumbers.Error<<" unknown option\nTry 'wc --help' for more information."; 
}
void MessageHelp()
{
    std::cout<<"wc:\t-c,"<<"  "<<"--bytes\tprint the byte counts\n"<<"\t-m,"<<"  "<<"--chars\tprint the character counts\n";
    std::cout<<"\t-l,"<<"  "<<"--lines\tprint the newline counts\n"<<"\t-w,"<<"  "<<"--words\tprint the word counts\n";
    std::cout<<"\t-h,"<<"  "<<"--help\tdisplay this help and exit\n"<<"\t-v,"<<"  "<<"--version\toutput version information and exits\n";
}
void MessageVersion()
{
    std::cout<<"wc: version -- "<<VERSION_MAJOR<<"."<<VERSION_MINOR; 
}