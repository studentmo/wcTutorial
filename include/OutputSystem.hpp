#ifndef _OutputSystem_
#define _OutputSystem_
#include <MainH.hpp>
#include <fstream>
#include <filesystem>

class OutputSystem
{
    private:
    bool FLAGS[4] = {false, false, false, false}; // {l, w, c, b}
    int COUNTS[4] = {0, 0, 0, 0}; // {l, w, c, b}

        ///*Функции*///

    //Определение нужных флагов
    void Flags(int argc, char **argv); 
    //Подсчет нужных параметров
    void Counts(const char *path, int type = 0);
    //Вывод ошибок
    void ErrorOutput(int id, int pos = 0, int argc = 0, char **argv = {}); 

    public:
        ///*Функции*///
    //Вывод по умолчанию. Происходит при отсутствии флагов 
    void DefaultOutput(char **argv);
    //Вывод информации о програме(-h, -v)
    bool InfoOutput(const char *flag);
    //Стандартный вывод
    void Output(int *argc, char **argv);
};

#endif