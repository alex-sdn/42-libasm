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
    fd = open("main.c", O_RDONLY);
    res1 = read(fd, buf1, 15);

    printf("[REAL] buf='%s' res=%d errno=%d\n", buf1, res1, errno);
    errno = 0;

    close(fd);
    fd = open("main.c", O_RDONLY);
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
    printf("errno=%d  return=%d\n", errno, res2);
    errno = 0;


    printf("\n/*******************\\\n");
    printf("       STRCMP         \n");
    printf("\\*******************/\n\n");

    res1 = strcmp("str 1", "str w2");
    res2 = ft_strcmp("str 1", "str w2");

    printf("[REAL] return=%d\n", res1);
    printf("[ASM]  return=%d\n", res2);


    printf("\n/*******************\\\n");
    printf("       STRCPY         \n");
    printf("\\*******************/\n\n");

    char    str1[12] = "Hello World";
    char    str2[12];
    char    str3[12];

    char    *ret1 = strcpy(str2, str1);
    char    *ret2 = ft_strcpy(str3, str1);

    printf("[REAL] %s\n", str2);
    printf("[ASM]  %s\n", str3);

    printf("[REAL] %s\n", ret1);
    printf("[ASM]  %s\n", ret2);


    printf("\n/*******************\\\n");
    printf("       STRLEN         \n");
    printf("\\*******************/\n\n");

    res1 = strlen(str1);
    res2 = ft_strlen(str1);

    printf("[REAL] return=%d\n", res1);
    printf("[ASM]  return=%d\n", res2);


    printf("\n/*******************\\\n");
    printf("       STRDUP         \n");
    printf("\\*******************/\n\n");

    char    *str4 = NULL;
    char    *str5 = NULL;

    str4 = strdup(str1);
    str5 = ft_strdup(str1);

    printf("[REAL] %s\n", str4);
    printf("[ASM]  %s\n", str5);

    if (str4)
        free(str4);
    if (str5)
        free(str5);

    return 0;
}