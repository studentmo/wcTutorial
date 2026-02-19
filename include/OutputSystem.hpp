#ifndef _OutputSystem_
#define _OutputSystem_
#include <MainH.hpp>
#include <fstream>

class OutputSystem
{
    private:
    int FLAGS[6] = {0, 0, 0, 0, 0, 0}; // {h, l, w, s, b, v}

    ///*Функции*///
    void Flags(int argc, char **argv);
    void ErrorOutput(int id, int pos = 0, int argc = 0, char **argv = {});

    public:
    int DefaultOutput(char **argv);
    int Output(int *argc, char **argv);
};

#endif