#ifndef _EXTRA_ 
#define _EXTRA_ 

struct extra
{
    char ResultArgs = 'f';
    bool l = false;
    bool c = false;
    bool m = false;
    bool w = false;
    bool v = false;
    bool h = false;
    bool r = false;
};

int argcProg(int argc, char** argv, extra *Struc);
void resultOutput(extra *FlagsAndNumbers);

#endif // _EXTRA_ 