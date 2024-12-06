#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    const int pid = fork();

    if (pid == 0) // Child process
    {
        if (execl("/bin/echo", "echo", "Hello from the child process", NULL) == -1)
        {
            std::cerr << "Error executing echo:" << strerror(errno) << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else if (pid > 0) // Parent process
    {
        /* Wait for the child process to finish */
        int status;
        wait(&status);

        std::cout << "Parent process done" << std::endl;
    }
    else // Error forking
    {
        std::cerr << "Error forking" << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}