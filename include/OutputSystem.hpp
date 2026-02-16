#ifndef _OutputSystem_
#define _OutputSystem_
#include <MainH.hpp>
#include <fstream>

class OutputSystem
{
    ///*Функции*///
    /*Ошибки:
    */
    private:
    std::string ErrorOutput(int id);

    public:
    int DefaultOutput(char **argv);

    int Output(char **argv);
};

#endif