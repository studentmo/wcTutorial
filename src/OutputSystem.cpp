#include <OutputSystem.hpp>

std::string OutputSystem::ErrorOutput(int id)
{
    std::string ERRORS[2] = {
        "Wrong path or name of the file\n",
        "Wrong name of flag. Use -h or --help\n"
    };

    return ERRORS[id - 1];
    return "No such error id\n";
}

int OutputSystem::DefaultOutput(char **argv)
{
    std::fstream file(argv[1], std::ios::out);
    if(!file.is_open())
    {std::cout<<ErrorOutput(1);}
    else
    {
        std::cout<<"default\n";
        std::cout<<argv[1];
    }

    return 0;   
}

int OutputSystem::Output(char **argv)
{
    std::fstream file(argv[1], std::ios::out);
    if(!file.is_open())
    {std::cout<<ErrorOutput(1);}
    else
    {
        std::cout<<"main output\n";
        std::cout<<argv[1];
    }

    return 0; 
}