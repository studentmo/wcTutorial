#include <OutputSystem.hpp>
#include <string.h>
#include <format>

void OutputSystem::ErrorOutput(int id, int pos, int argc, char **argv)
{
    if(pos != 0)
    {
        for(int i = 0; i < argc; ++i)
        {std::cout<<argv[i]<<" ";}
        std::cout<<"\n";
        for(int i = 0; i < pos; ++i)
        {std::cout<<"~";}
        std::cout<<"^\n"; 
    }

    std::string ERRORS[2] = {
        "Wrong path or name of the file\n",
        "Wrong name of flag. Use -h or --help\n" //Можно сделать чтобы показывало на конкретный флаг
    };
    std::cout<<ERRORS[id - 1];
    exit(id);
}

int OutputSystem::DefaultOutput(char **argv)
{
    std::fstream file(argv[1], std::ios::in);
    if(!file.is_open())
    {ErrorOutput(1);}
    else
    {
        std::cout<<"default\n";
        std::cout<<argv[1];
    }
    file.close();

    return 0;   
}

void OutputSystem::Flags(int argc, char **argv)
{
    for(int i = 2; i < argc; ++i)
    {
        if(std::string(argv[i]) == "-h" or std::string(argv[i]) == "--help")
        {FLAGS[0] = 1;}
        else if(std::string(argv[i]) == "-l" or std::string(argv[i]) == "--lines")
        {FLAGS[1] = 1;}
        else if(std::string(argv[i]) == "-w" or std::string(argv[i]) == "--words")
        {FLAGS[2] = 1;}
        else if(std::string(argv[i]) == "-s" or std::string(argv[i]) == "--symbols")
        {FLAGS[3] = 1;}
        else if(std::string(argv[i]) == "-b" or std::string(argv[i]) == "--bytes")
        {FLAGS[4] = 1;}
        else if(std::string(argv[i]) == "-v" or std::string(argv[i]) == "--version")
        {FLAGS[5] = 1;}
        else
        {
            int pos = argc - 2;
            for(int j = 0; j < i + 1; ++j)
            {pos += strlen(argv[j]);}
            ErrorOutput(2, pos, argc, argv);
        }
        //TODO обработка ввода вида -fgsdaq
        //Если среди флагов есть несуществующие вызвать ErrorOutput(2)
        //в противном случаее вывести нужную информацию
    }
}

int OutputSystem::Output(int *argc, char **argv)
{
    std::fstream file(argv[1], std::ios::in);
    if(!file.is_open())
    {ErrorOutput(1);}
    else
    {
        Flags(*argc, argv);
        std::cout<<"main output\n";
        std::cout<<argv[1];
    }
    file.close();

    return 0; 
}