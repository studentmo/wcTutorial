#include <MainH.hpp>

/*
    При возникновении ошибок вызывать функцию ErrorOutput()
    При отсутствии аргументов вызывать функцию DefaultOutput()
    При налиции флагов вызывать функцию Output()
*/

int main(int argc, char** argv)
{ 
    OutputSystem OpS;
    if(argc > 2)
    {OpS.Output(argv);}
    else
    {OpS.DefaultOutput(argv);}
}