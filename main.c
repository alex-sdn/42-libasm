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

    char    buf1[20];
    char    buf2[20];
    int     res1;
    int     res2;
    int     fd;
    
    // Read wrong fd
    res1 = read(-1, buf1, 15);
    
    printf("[REAL] buf='%s' res=%d errno=%d\n", buf1, res1, errno);
    errno = 0;

    res2 = ft_read(-1, buf2, 15);

    printf("[ASM]  buf='%s' res=%d errno=%d\n\n", buf2, res2, errno);
    errno = 0;

    // Read from file
    fd = open("text.txt", O_RDONLY);
    res1 = read(fd, buf1, 15);

    printf("[REAL] buf='%s' res=%d errno=%d\n", buf1, res1, errno);
    errno = 0;

    close(fd);
    fd = open("text.txt", O_RDONLY);
    res2 = ft_read(fd, buf2, 15);

    printf("[ASM]  buf='%s' res=%d errno=%d\n", buf2, res2, errno);
    errno = 0;

    printf("\n/*******************\\\n");
    printf("       WRITE          \n");
    printf("\\*******************/\n\n");

    // Normal write
    printf("[REAL]\n");
    res1 = write(1, "Hello World\n", 12);
    printf("errno=%d  return=%d\n\n", errno, res1);
    errno = 0;

    printf("[ASM]\n");
    res2 = ft_write(1, "Hello World\n", 12);
    printf("errno=%d  return=%d\n\n", errno, res2);
    errno = 0;

    // Wrong fd error
    printf("[REAL]\n");
    res1 = write(-1, "Hello World\n", 12);
    printf("errno=%d  return=%d\n\n", errno, res1);
    errno = 0;

    printf("[ASM]\n");
    res2 = ft_write(-1, "Hello World\n", 12);
    printf("errno=%d  return=%d\n\n", errno, res2);
    errno = 0;

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