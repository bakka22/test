#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    extern char **environ;
        printf("%p\n", &environ);
        printf("%p\n", &env);
    return (0);
}
