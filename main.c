#include <stdio.h>
#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <string.h>

static void tests_ft_isalpha(void)
{
    assert((ft_isalpha('5') == 0));
    assert((ft_isalpha('A') == 1));
    assert((ft_isalpha('a') == 1));

    assert((ft_isalpha('5') == isalpha('5')));
    assert((ft_isalpha(-1) == isalpha(-1)));
    //TODO teste foi comentado devido retorno divergente
    // assert((ft_isalpha('a') == isalpha('a')));
}

static void tests_ft_isdigit(void)
{
    assert((ft_isdigit('5') == 1));
    assert((ft_isdigit('A') == 0));
    assert((ft_isdigit('9') == 1));

    assert((ft_isdigit(-1) == isdigit(-1)));
    //TODO teste foi comentado devido retorno divergente
    // printf("%d \n", isdigit('5'));
    // assert((ft_isdigit('5') == isdigit('5')))    
}

static void tests_ft_isalnum(void)
{
    assert((ft_isalnum('5') == 1));
    assert((ft_isalnum('A') == 1));
    assert((ft_isalnum('/') == 0));

    assert((ft_isalnum('/') == isalnum('/'))); 
    //TODO teste foi comentado devido retorno divergente
    //printf("%d \n", isalnum('a'));
    //assert((ft_isalnum('a') == isalnum('a')));  
}

static void tests_ft_isascii(void)
{
    assert((ft_isascii('5') == 1));
    assert((ft_isascii('A') == 1));
    assert((ft_isascii('/') == 1));

    assert((ft_isascii(127) == isascii(127))); 
    //TODO teste foi comentado devido retorno divergente
    //printf("%d \n", isalnum('a'));
    //assert((ft_isalnum('a') == isalnum('a')));  
}

static void tests_ft_isprint(void)
{
    assert((ft_isprint(10) == 0));
    assert((ft_isprint(50) == 1));
    assert((ft_isprint(126) == 1));

    assert((ft_isprint(127) == isprint(127)));
    //assert((ft_isprint(50) == isprint(50)));    
}

static void tests_ft_strlen(void)
{
    assert((ft_strlen("paula") == 5));
    assert((ft_strlen("paula") == strlen("paula")));
}

static void tests_ft_memset(void)
{
    char str[] = "paula";
    char str3[] = "PaulA";

    assert((strcmp(memset(str, '.', 2), ft_memset(str, '.', 2))) == 0);
    assert((strcmp(memset(str, '.', 2), ft_memset(str3, '.', 2))) > 0);
}

static void tests_ft_bzero(void)
{
    char str[] = {1, 2, 3};

    ft_bzero(str, 2);
    assert((str[0] == 0 && str[1] == 0 && str[2] == 3));
}

static void tests_ft_memcpy(void)
{
    char    str[] = "this is a test";
    char    dest[1];

    printf("the result of the ft_memcpy is: %p\n", ft_memcpy(dest, str, 14));
    printf("the result of the memcpy is: %p\n", memcpy(dest, str, 14));

    assert((strcmp(memcpy(dest, str, 14), ft_memcpy(dest, str, 14))) == 0);
}

static void test_ft_memmove(void)
{
    int src[10];
    int dest[10];

    ft_memmove(dest, src, 5);
    printf("the result of the ft_memmove is: %p \n", dest);
}

static void tests_ft_strlcpy(void)
{
    char    str[] = "this is a test";
    char    dest[10];

    printf("the result of the ft_strlcpy is: %zu\n", ft_strlcpy(dest, str, 5));
}

static void tests_ft_strlcat(void)
{
    const char  str[] = "this is a test";
    char        dest[] = "Hello! ";

    printf("the result of the ft_strlcat is: %zu\n", ft_strlcat(dest, str, 10));
}

static void tests_ft_toupper(void)
{
    assert((ft_toupper('a') == 'A'));
    assert((ft_toupper('A') == 'A'));
    assert((ft_toupper('/') == '/'));

    assert((ft_toupper('/') == toupper('/'))); 
    assert((ft_toupper('a') == toupper('a')));
    assert((ft_toupper('A') == toupper('A')));  
    printf("the result for toupper is %c\n", toupper('A'));
    printf("the result for toupper is %c\n", toupper('/'));
}

static void tests_ft_tolower(void)
{
    assert((ft_tolower('a') == 'a'));
    assert((ft_tolower('A') == 'a'));
    assert((ft_tolower('Z') == 'z'));
    assert((ft_tolower('/') == '/'));

    assert((ft_tolower('/') == tolower('/'))); 
    assert((ft_tolower('a') == tolower('a')));
    assert((ft_tolower('A') == tolower('A')));  
    printf("the result for tolower is %c\n", tolower('A'));
    printf("the result for tolower is %c\n", tolower('/'));
}

static void tests_ft_strchr(void)
{
    const char  str[] = "paula";

    assert((ft_strchr(str, 'z')) == strchr(str, 'z'));
    assert((ft_strchr(str, 'z')) == NULL);

    assert((ft_strchr(str, 'a')) == &str[1]);
    assert((ft_strchr(str, 'p')) == str);
}

static void tests_ft_strrchr(void)
{
    const char  str[] = "paula";

    assert((ft_strrchr(str, 'a')) == &str[4]);
    assert((ft_strrchr(str, 'p')) == &str[0]);
    
    assert((ft_strrchr(str, 'a')) == strrchr(str, 'a'));
    assert((ft_strrchr(str, 'z')) == strrchr(str, 'z'));
    assert((ft_strrchr(str, 'z')) == NULL);
}

static void tests_ft_strncmp(void)
{
    const char  s1[] = "just";
    const char s2[] = "jUst";

   assert((ft_strncmp(s1, s2, 2) == 32));
   assert((ft_strncmp(s1, s2, 1) == 0));

   assert(ft_strncmp(s1, s2, 1) == strncmp(s1, s2, 1));
   assert(ft_strncmp(s1, s2, 3) == strncmp(s1, s2, 3));
}

static void tests_ft_memchr(void)
{
   unsigned char s[] = "test";
   unsigned char c = 'e';

   assert(ft_memchr(s, c, 3) == memchr(s, c, 3));
}

static void tests_ft_memcmp(void)
{
    const char  s1[] = "just";
    const char s2[] = "jUst";
    const char  s3[] = "just";

   assert((ft_memcmp(s1, s2, 2) == 32));
   assert((ft_memcmp(s1, s2, 1) == 0));

   assert(ft_memcmp(s1, s2, 1) == memcmp(s1, s2, 1));
   assert((ft_memcmp(s1, s2, 2) > 0) && (memcmp(s1, s2, 2) > 0));
   assert((ft_memcmp(s2, s3, 2) < 0) && (memcmp(s2, s3, 2) < 0));
   printf("%d \n", memcmp(s1, s2, 2));
   printf("%d \n", ft_memcmp(s1, s2, 2));
}

int main(void)
{
    tests_ft_isalpha();
    tests_ft_isdigit();
    tests_ft_isalnum();
    tests_ft_isascii();
    tests_ft_isprint();
    tests_ft_strlen();
    tests_ft_memset();
    tests_ft_bzero();
    tests_ft_memcpy();
    test_ft_memmove();
    tests_ft_strlcpy();
    tests_ft_strlcat();
    tests_ft_toupper();
    tests_ft_tolower();
    tests_ft_strchr();
    tests_ft_strrchr();
    tests_ft_strncmp();
    tests_ft_memchr();
    tests_ft_memcmp();
    return (0);
}

