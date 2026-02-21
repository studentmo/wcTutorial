#ifndef _EXTRA_ 
#define _EXTRA_ 
#include <string>

#define VERSION_MAJOR 7
#define VERSION_MINOR 8

struct extra
{
    char ResultArgs = 'f';
    std::string Error;
    bool l = false;
    bool c = false;
    bool m = false;
    bool w = false;
    bool v = false;
    bool h = false;
    bool r = false;
    int Lines;
    int Bytes;
    int Chars;
    int Words;
};

int FIleCount(std::string argv ,extra *FlagsAndNumbers);
int argcProg(int argc, char** argv, extra *Struc);
void resultOutput(extra *FlagsAndNumbers);

#endif // _EXTRA_ 