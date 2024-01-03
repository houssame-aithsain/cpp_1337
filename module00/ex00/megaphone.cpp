#include <iostream>
#include <cstdlib>
#include <cctype>

int main(int ac, char **av)
{
    std::string str;
    int i;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    for (int j = 1; j < ac; j++)
    {
        i = 0;
        str = av[j];
        for (; str[i]; i++){
            str[i] = std::toupper(str[i]);
        }
        std::cout << str;
    }
    return (EXIT_SUCCESS);
}
