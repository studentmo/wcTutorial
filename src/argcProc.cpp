#include "extra.hpp"
#include <string>
#include <iostream>

int argcProg(int argc, char** argv, extra *FlagsAndNumbers)
{
    bool STOP = false;
    for (int i = 2; i < argc; i++)
    {
        if(STOP == 1)break; 
        std::string args = argv[i];
        if (args == "--help")
        {
            STOP = true;
            FlagsAndNumbers->h = true;
            FlagsAndNumbers->ResultArgs = 'h';
            FlagsAndNumbers->l = false;
            FlagsAndNumbers->c = false;
            FlagsAndNumbers->m = false;
            FlagsAndNumbers->w = false;
            break;
        }
        else if (args == "--version")
        {
            STOP = true;
            FlagsAndNumbers->v = true;
            FlagsAndNumbers->ResultArgs = 'v';
            FlagsAndNumbers->l = false;
            FlagsAndNumbers->c = false;
            FlagsAndNumbers->m = false;
            FlagsAndNumbers->w = false;
            break;
        }
        else if (args == "--bytes")FlagsAndNumbers->c = true;
        else if (args == "--chars")FlagsAndNumbers->m = true;
        else if (args == "--lines")FlagsAndNumbers->l = true;
        else if (args == "--words")FlagsAndNumbers->w = true;
        else if (1) for (int j = 1; j < args.size(); j++)
        {
            if(args[j] == 'h')
            {
            STOP = true;
            FlagsAndNumbers->h = true;
            FlagsAndNumbers->ResultArgs = 'h';
            FlagsAndNumbers->l = false;
            FlagsAndNumbers->c = false;
            FlagsAndNumbers->m = false;
            FlagsAndNumbers->w = false;
            break;
            }
            else if (args[j] == 'v')
            {
                STOP = true;
                FlagsAndNumbers->v = true;
                FlagsAndNumbers->ResultArgs = 'v';
                FlagsAndNumbers->l = false;
                FlagsAndNumbers->c = false;
                FlagsAndNumbers->m = false;
                FlagsAndNumbers->w = false;
                break;
            }
            else if(args[j] == 'm')FlagsAndNumbers->m = true;
            else if (args[j] == 'c')FlagsAndNumbers->c = true;
            else if (args[j] == 'l')FlagsAndNumbers->l = true;
            else if (args[j] == 'w')FlagsAndNumbers->w = true;
            else
            {
                FlagsAndNumbers->Error = args;
                FlagsAndNumbers->r = true;
                FlagsAndNumbers->ResultArgs = 'r';
                FlagsAndNumbers->l = false;
                FlagsAndNumbers->c = false;
                FlagsAndNumbers->m = false;
                FlagsAndNumbers->w = false;
                STOP = true; 
                break;
            }
        }     
    }
    return 1;
}