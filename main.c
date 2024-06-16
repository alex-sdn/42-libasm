#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

ssize_t ft_read(int, char *, size_t);
ssize_t ft_write(int, char *, size_t);
int     ft_strcmp(const char *, const char *);
char    *ft_strcpy(char *, const char *);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *);

int main(void)
{
    printf("/*******************\\\n");
    printf("        READ          \n");
    printf("\\*******************/\n\n");

    char buf1[20];
    char buf2[20];

    int fd = open("text.txt", O_RDONLY);
    int res1 = read(fd, buf1, 15);
    
    printf("'%s' res=%d\n", buf1, res1);
    printf("ERRNO=%d\n", errno);

    close(fd);
    fd = open("text.txt", O_RDONLY);
    int res2 = ft_read(fd, buf2, 15);

    printf("'%s' res=%d\n", buf2, res2);
    printf("ERRNO=%d\n", errno);

    printf("\n/*******************\\\n");
    printf("       WRITE          \n");
    printf("\\*******************/\n\n");

    printf("\n/*******************\\\n");
    printf("       STRCMP         \n");
    printf("\\*******************/\n\n");

    printf("\n/*******************\\\n");
    printf("       STRCPY         \n");
    printf("\\*******************/\n\n");

    printf("\n/*******************\\\n");
    printf("       STRLEN         \n");
    printf("\\*******************/\n\n");

    printf("\n/*******************\\\n");
    printf("       STRDUP         \n");
    printf("\\*******************/\n\n");


    return 0;
}