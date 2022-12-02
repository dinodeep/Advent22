#include <iostream>
#include <fstream>
#include <list>

using namespace std;

bool is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end())
    {
        if (!isdigit(*it))
        {
            return false;
        }
        it++;
    }

    return !s.empty();
}

int main(int argc, char *argv[])
{
    std::string text;
    std::string filename;

    if (argc == 2 && strcmp(argv[1], "--easy") == 0)
    {
        filename = "easyinput.txt";
    }
    else if (argc == 2 && strcmp(argv[1], "--hard") == 0)
    {
        filename = "hardinput.txt";
    }
    else
    {
        std::cout << "Incorrectly formatted input"
                  << "\n";
    }

    std::cout << filename << "";
    std::ifstream MyReadFile(filename);

    list<int> l;
    int acc = 0;

    while (getline(MyReadFile, text))
    {
        // convert string to integer
        if (is_number(text))
        {
            acc += std::stoi(text);
        }
        else
        {
            l.push_front(acc);
            acc = 0;
        }
    }

    l.sort();
    l.reverse();

    int total = 0;

    std::cout << "My list contains\n";
    for (std::list<int>::iterator it = l.begin(); it != l.end() && std::distance(l.begin(), it) < 3; it++)
    {
        total += *it;
    }

    std::cout << "Top 3 Elves carrying " << total << " calories"
              << "\n";

    MyReadFile.close();
}