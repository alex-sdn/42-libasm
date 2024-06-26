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

void    print_tag(char *func)
{
    printf("\033[1;36m");
    printf("\n/*******************\\\n");
    printf("%s\n", func);
    printf("\\*******************/\n\n");
    write(1, "\033[1;0m", 7);
}

void    read_test()
{
    static char buf1[20];
    static char buf2[20];
    int         res1;
    int         res2;
    int         fd;
    
    // Read wrong fd
    res1 = read(-1, buf1, 15);
    
    printf("[REAL] buf='%s' res=%d errno=%d\n", buf1, res1, errno);
    errno = 0;

    res2 = ft_read(-1, buf2, 15);

    printf("[ASM]  buf='%s' res=%d errno=%d\n\n", buf2, res2, errno);
    errno = 0;

    // Read from file
    fd = open("main.c", O_RDONLY);
    res1 = read(fd, buf1, 19);

    printf("[REAL] buf='%s' res=%d errno=%d\n", buf1, res1, errno);
    errno = 0;

    close(fd);
    fd = open("main.c", O_RDONLY);
    res2 = ft_read(fd, buf2, 19);

    printf("[ASM]  buf='%s' res=%d errno=%d\n", buf2, res2, errno);
    errno = 0;
}

void    write_test()
{
    int     res1;
    int     res2;

    // Normal write
    res1 = write(1, "Hello World\n", 12);
    printf("[REAL] errno=%d  return=%d\n\n", errno, res1);
    errno = 0;

    res2 = ft_write(1, "Hello World\n", 12);
    printf("[ASM]  errno=%d  return=%d\n\n", errno, res2);
    errno = 0;

    // Wrong fd error
    printf("write in wrong fd:\n");
    res1 = write(-1, "Hello World\n", 12);
    printf("[REAL] errno=%d  return=%d\n\n", errno, res1);
    errno = 0;

    res2 = ft_write(-1, "Hello World\n", 12);
    printf("[ASM]  errno=%d  return=%d\n", errno, res2);
    errno = 0;
}

void    strcmp_test()
{
    int     res1;
    int     res2;

    res1 = strcmp("str 1", "str aaa");
    res2 = ft_strcmp("str 1", "str aaa");

    printf("[REAL] return=%d\n", res1);
    printf("[ASM]  return=%d\n", res2);
}

void    strcpy_test()
{
    char    str1[12] = "Hello World";
    char    str2[12];
    char    str3[12];

    char    *ret1 = strcpy(str2, str1);
    char    *ret2 = ft_strcpy(str3, str1);

    printf("[REAL] %s\n", str2);
    printf("[ASM]  %s\n\n", str3);

    printf("[REAL] %s\n", ret1);
    printf("[ASM]  %s\n", ret2);
}

void    strlen_test()
{
    char    str1[12] = "Hello World";
    int     res1;
    int     res2;

    res1 = strlen(str1);
    res2 = ft_strlen(str1);

    printf("[REAL] return=%d\n", res1);
    printf("[ASM]  return=%d\n", res2);
}

void    strdup_test()
{
    char    str1[12] = "Hello World";
    char    *str2 = NULL;
    char    *str3 = NULL;

    str2 = strdup(str1);
    str3 = ft_strdup(str1);

    printf("[REAL] %s\n", str2);
    printf("[ASM]  %s\n", str3);

    if (str2)
        free(str2);
    if (str3)
        free(str3);
}

int main(void)
{
    print_tag("        READ         ");
    read_test();

    print_tag("       WRITE         ");
    write_test();

    print_tag("       STRCMP       ");
    strcmp_test();

    print_tag("       STRCPY        ");
    strcpy_test();

    print_tag("       STRLEN        ");
    strlen_test();

    print_tag("       STRDUP        ");
    strdup_test();

    return 0;
}