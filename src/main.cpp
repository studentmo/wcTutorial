#include <MainH.hpp>

/*
    При возникновении ошибок вызывать функцию ErrorOutput()
    При отсутствии флагов вызывать функцию DefaultOutput()
    При налиции флагов вызывать функцию Output()
*/

int main(int argc, char** argv)
{ 
    OutputSystem OpS;
    if(argc > 2)
    {OpS.Output(&argc, argv);}
    else
    {
        if(OpS.InfoOutput(argv[1])){}
        else OpS.DefaultOutput(argv);
    }
}