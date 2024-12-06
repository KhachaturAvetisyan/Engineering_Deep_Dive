#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    /* Create first child process */
    const int pid = fork();

    if (pid == 0) // Child process
    {
        if (execl("/bin/ls", "ls", NULL) == -1)
        {
            std::cerr << "Error executing ls:" << strerror(errno) << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else if (pid > 0) // Parent process
    {
        /* Wait for the first child process to finish */
        int status;
        wait(&status);

        /* Create second child process */
        const int pid2 = fork();

        if (pid2 == 0) // Child process
        {
            if (execl("/bin/date", "date", NULL) == -1)
            {
                std::cerr << "Error executing date:" << strerror(errno) << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else if (pid2 > 0) // Parent process
        {
            /* Wait for the second child process to finish */
            wait(&status);

            std::cout << "Parent process done" << std::endl;
        }
        else // Error forking
        {
            std::cerr << "Error forking" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else // Error forking
    {
        std::cerr << "Error forking" << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}