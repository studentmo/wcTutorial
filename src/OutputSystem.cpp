#include <OutputSystem.hpp>
#include <string.h>


void OutputSystem::ErrorOutput(int id, int pos, int argc, char **argv)
{
    if(pos != 0)//показывает на первый неправильно указаный флаг
    {
        for(int i = 0; i < argc; ++i)
        {std::cout<<argv[i]<<" ";}
        std::cout<<"\n";
        for(int i = 0; i < pos; ++i)
        {std::cout<<"~";}
        std::cout<<"^\n"; 
    }

    //Возможные ошибки
    std::string ERRORS[2] = {
        "Wrong path or name of the file or flag\n",
        "Wrong name of flag. Use -h or --help\n"
    };
    std::cout<<ERRORS[id - 1];
    exit(id);
}

void OutputSystem::DefaultOutput(char **argv)
{
    Counts(argv[1]);
    std::cout<<argv[1]<<" ";
    for(int i = 0; i < 4; ++i)
    {
        if(COUNTS[i] != 0)
        std::cout<<COUNTS[i]<<" ";
    }
    std::cout<<std::endl;
}

void OutputSystem::Flags(int argc, char **argv)
{
    for(int i = 2; i < argc; ++i)
    {
        if(std::string(argv[i]) == "-l" or std::string(argv[i]) == "--lines")
        {FLAGS[0] = true;}
        else if(std::string(argv[i]) == "-w" or std::string(argv[i]) == "--words")
        {FLAGS[1] = true;}
        else if(std::string(argv[i]) == "-c" or std::string(argv[i]) == "--chars")
        {FLAGS[2] = true;}
        else if(std::string(argv[i]) == "-b" or std::string(argv[i]) == "--bytes")
        {FLAGS[3] = true;}
        else
        {
            int pos = argc - 2;
            for(int j = 0; j < i + 1; ++j)
            {pos += strlen(argv[j]);}
            ErrorOutput(2, pos, argc, argv);
        }
        //TODO STAGE 3 обработка ввода вида -fgsdaq
        //Если среди флагов есть несуществующие вызвать ErrorOutput(2)
        //в противном случаее вывести нужную информацию
    }
}

void OutputSystem::Counts(const char *path, int type)
{
    if(type == 0)
    {FLAGS[1] = true; FLAGS[2] = true;}

    std::fstream file(path, std::ios::in);
    if(!file.is_open())
    {ErrorOutput(1);}
    else
    {
        if(FLAGS[0])
        {
            char buf[256];
            file.getline(buf, 256);
            while(file)
            {COUNTS[0]++; file.getline(buf, 256);}
        }
        if(FLAGS[1])
        {
            file.clear();
            file.seekg(0, std::ios::beg);
            std::string word;
            file >> word;
            while(file)
            {COUNTS[1]++; file >> word;}
        }
        if(FLAGS[2])
        {
            file.clear();
            file.seekg(0, std::ios::end);
            COUNTS[2] = file.tellg();
        }
        if(FLAGS[3])
        {
            COUNTS[3] = std::filesystem::file_size(path);
        }
    }
    file.close();
}

void OutputSystem::Output(int *argc, char **argv)
{
    Flags(*argc, argv);
    Counts(argv[1], 1);
    std::cout<<argv[1]<<" ";
    for(int i = 0; i < 4; ++i)
    {
        if(COUNTS[i] != 0)
        std::cout<<COUNTS[i]<<" ";
    }
    std::cout<<std::endl;
}

bool OutputSystem::InfoOutput(const char *flag)
{
    if(std::string(flag) == "-h" or std::string(flag) == "--help")
    {
        std::cout<<"Usage: my_wc [FILE]... [OPTION]...\n"
                 <<"   or: my_wc [OPTION]...\n"
                 <<"Print newline, word, symbols and byte count for FILE.\n"
                 <<"A word is a non-zero-length sequence of characters delimited by white space.\n"
                 <<"With no FILE, read standard input.\n\n"
                 <<"The options below may be used to select which counts are printed, always in\n"
                 <<"the following order: newline, word, character, byte.\n"
                 <<"-l, --lines            print the newline counts\n"
                 <<"-w, --words            print the word counts\n"
                 <<"-c, --chars            print the character counts\n"
                 <<"-b, --bytes            print the byte counts\n"
                 <<"-h, --help             display this help and exit\n"
                 <<"-v, --version          output version information and exit\n\n"
                 <<"Source <https://github.com/studentmo/wcTutorial/tree/VoidRig>\n";
    }
    else if(std::string(flag) == "-v" or std::string(flag) == "--version")
    {
        std::cout<<"v."<<VERSION_RELEASE<<"."<<VERSION_MAJOR<<"."<<VERSION_MINOR<<std::endl; 
        std::cout<<"Created by VoidRig"<<std::endl;
    }
    else return false;

    return true;
}