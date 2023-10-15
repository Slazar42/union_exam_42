
#include <unistd.h>
#include <stdio.h>
int if_exist(char *s, char c)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (0);
        i++;
    }
    return (1);
}

void ft_union(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char tab[256] = {0};

    while (s1[i])
    {
        if (if_exist(tab, s1[i]))
            tab[j++] = s1[i];
        i++;
    }
    i = 0;
    while (s2[i])
    {
        if (!if_exist(tab, s2[i]) && if_exist(s1, s2[i]))
            tab[j++] = s2[i];
        i++;
    }
    i = 0;
    while (tab[i])
    {
        write(1, &tab[i], 1);
        i++;
    }
}

int main(int ac ,char **av)
{
    if (ac == 3)
        ft_union(av[1], av[2]);
    write(1, "\n", 1);
}