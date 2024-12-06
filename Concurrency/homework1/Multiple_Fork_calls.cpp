#include <iostream>
#include <unistd.h>

int main()
{
    std::cout << "Main process ID: " << getpid() << std::endl;

    fork();

    std::cout << "After first fork, process ID: " << getpid() << std::endl;

    fork();

    std::cout << "After second fork, process ID: " << getpid() << std::endl;

    fork();

    std::cout << "After third fork, process ID: " << getpid() << std::endl;

    return 0;
}