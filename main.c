#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "libft.h"
#include "unity.h"

static void tests_ft_isalpha(void)
{
    TEST_ASSERT_FALSE(ft_isalpha('5'));
    TEST_ASSERT_TRUE(ft_isalpha('a'));
    TEST_ASSERT_TRUE(ft_isalpha('A'));
    TEST_ASSERT_EQUAL(isalpha('1'), ft_isalpha('1'));
    TEST_ASSERT_TRUE(ft_isalpha('A'));
    //TODO teste foi comentado devido retorno divergente
    // assert((ft_isalpha('a') == isalpha('a')));
}

static void tests_ft_isdigit(void)
{
    TEST_ASSERT_TRUE(ft_isdigit('5'));
    TEST_ASSERT_FALSE(ft_isdigit('A'));
    TEST_ASSERT_EQUAL(isdigit(-1), ft_isdigit(-1));
//  TODO teste foi comentado devido retorno divergente
//   printf("%d \n", isdigit('5'));
//   assert((ft_isdigit('5') == isdigit('5')))    
}

static void tests_ft_isalnum(void)
{
    TEST_ASSERT_TRUE(ft_isalnum('5'));
    TEST_ASSERT_TRUE(ft_isalnum('A'));
    TEST_ASSERT_FALSE(ft_isalnum('/'));
    TEST_ASSERT_EQUAL(isalnum('/'), ft_isalnum('/'));
    //TODO teste foi comentado devido retorno divergente
    //printf("%d \n", isalnum('a'));
    //assert((ft_isalnum('a') == isalnum('a')));  
}

static void tests_ft_isascii(void)
{
    TEST_ASSERT_TRUE(ft_isascii('5'));
    TEST_ASSERT_TRUE(ft_isascii('A'));
    TEST_ASSERT_TRUE(ft_isascii('/'));
    TEST_ASSERT_FALSE(ft_isascii(128));
    TEST_ASSERT_EQUAL(isascii(127), ft_isascii(127));
}

static void tests_ft_isprint(void)
{
    TEST_ASSERT_TRUE(ft_isprint(50));
    TEST_ASSERT_TRUE(ft_isprint(126));
    TEST_ASSERT_FALSE(ft_isprint(10));
    TEST_ASSERT_EQUAL(isprint(127), ft_isprint(127));  
}

static void tests_ft_strlen(void)
{
    TEST_ASSERT_EQUAL_INT32(5, ft_strlen("paula"));
    TEST_ASSERT_NOT_EQUAL(4, ft_strlen("paula"));
    TEST_ASSERT_EQUAL(strlen("paula"), ft_strlen("paula"));
}

static void tests_ft_memset(void)
{
    char str[] = "paula";
    char str2[] = "paula";

    TEST_ASSERT_EQUAL_STRING(memset(str, '.', 2), ft_memset(str, '.', 2));
    TEST_ASSERT_EQUAL_MEMORY(memset(str, '.', 2), ft_memset(str2, '.', 2), 5);
}

static void tests_ft_bzero(void)
{
    char str[] = {1, 2, 3};
    char expected[] = {0, 0, 3};
    
    ft_bzero(str, 2); 
    TEST_ASSERT_EQUAL_MEMORY(expected, str, 3);  
}

static void tests_ft_memcpy(void)
{
    char    str[] = "this is a test";
    char    dest[14];
    char    dest2[14];

    TEST_ASSERT_EQUAL_MEMORY(memcpy(dest, str, 14), ft_memcpy(dest2, str, 14), 14);
}

static void tests_ft_memmove(void)
{
    char    src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char    src2[] = {-1, -2, -3, 4, 5, 6, 7, 8, 9, 10};
    char    dest[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char    dest2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char    *dest3 = NULL;
    char    dest4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char    expected1[] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0};
    char    expected2[] = {0, 0, 0, 0, 0, 6, 7, 8, 9, 10};
    char    expected3[] = {-1, -2, -3, 4, 5, 0, 0, 0, 0, 0};

    char *ret = ft_memmove(dest, src, 5);
    TEST_ASSERT_EQUAL_PTR(dest, ret);
    TEST_ASSERT_EQUAL_MEMORY(expected1, dest, 10);

    char *ret2 = ft_memmove(dest2 + 5, src + 5, 5);
    TEST_ASSERT_EQUAL_PTR(dest2 + 5, ret2);
    TEST_ASSERT_EQUAL_MEMORY(expected2, dest2, 10);

    TEST_ASSERT_EQUAL(NULL, ft_memmove(dest3, src, 10));
    
    char *ret3 = ft_memmove(dest4, src2, 5);
    TEST_ASSERT_EQUAL_PTR(dest4, ret3);
    TEST_ASSERT_EQUAL_MEMORY(expected3, dest4, 10);
}

static void tests_ft_strlcpy(void)
{
    char    str[] = "this is a test";
    char    dest[10];
    char    expeted[] = "this";

    TEST_ASSERT_EQUAL(14, ft_strlcpy(dest, str, 5));
    TEST_ASSERT_EQUAL_MEMORY(expeted, dest, 5);
}

static void tests_ft_strlcat(void)
{
    const char  str[] = "this is a test";
    char        dest[] = "Hello! \0\0\0\0\0\0\0\0\0\0\0\0\0";
    char        expected[] = "Hello! this";

    ft_strlcat(dest, str, 12);
    TEST_ASSERT_EQUAL_MEMORY(expected, dest, 12);
}

static void tests_ft_toupper(void)
{
    TEST_ASSERT_EQUAL('A', ft_toupper('a'));
    TEST_ASSERT_EQUAL('A', ft_toupper('A'));
    TEST_ASSERT_EQUAL('/', ft_toupper('/'));
    TEST_ASSERT_EQUAL(toupper('z'), ft_toupper('z'));
    TEST_ASSERT_EQUAL(toupper('Z'), ft_toupper('Z'));
    TEST_ASSERT_EQUAL(toupper('/'), ft_toupper('/'));
}

static void tests_ft_tolower(void)
{
    TEST_ASSERT_EQUAL('a', ft_tolower('a'));
    TEST_ASSERT_EQUAL('a', ft_tolower('A'));
    TEST_ASSERT_EQUAL('/', ft_tolower('/'));
    TEST_ASSERT_EQUAL(tolower('z'), ft_tolower('z'));
    TEST_ASSERT_EQUAL(tolower('Z'), ft_tolower('Z'));
    TEST_ASSERT_EQUAL(tolower('/'), ft_tolower('/'));
}

static void tests_ft_strchr(void)
{
    const char  str[] = "paula";

    TEST_ASSERT_EQUAL(strchr(str, 'z'), ft_strchr(str, 'z'));
    TEST_ASSERT_EQUAL(strchr(str, 'a'), ft_strchr(str, 'a'));
    TEST_ASSERT_EQUAL_PTR(str + 1, ft_strchr(str, 'a'));
    TEST_ASSERT_EQUAL_PTR(str, ft_strchr(str, 'p'));
    TEST_ASSERT_EQUAL_PTR(NULL, ft_strchr(str, 'z'));

}

static void tests_ft_strrchr(void)
{
    const char  str[] = "paula";

    TEST_ASSERT_EQUAL_PTR(str + 4, ft_strrchr(str, 'a'));
    TEST_ASSERT_EQUAL_PTR(str, ft_strrchr(str, 'p'));
    TEST_ASSERT_EQUAL(strrchr(str, 'a'), ft_strrchr(str, 'a'));
    TEST_ASSERT_EQUAL(strrchr(str, 'z'), ft_strrchr(str, 'z'));
    TEST_ASSERT_EQUAL(NULL, ft_strrchr(str, 'j'));
}

static void tests_ft_strncmp(void)
{
    const char  s1[] = "just";
    const char s2[] = "jUst";

    TEST_ASSERT_EQUAL(0, ft_strncmp(s1, s2, 1));
    TEST_ASSERT_EQUAL(32, ft_strncmp(s1, s2, 2));
    //printf("strncmp %d \n", strncmp(s1, s2, 4));
    TEST_ASSERT_EQUAL(strncmp(s1, s2, 4) > 0, ft_strncmp(s1, s2, 4) > 0);
    TEST_ASSERT_EQUAL(strncmp(s1, s2, 1), ft_strncmp(s1, s2, 1));
}

static void tests_ft_memchr(void)
{
   unsigned char    s[] = "test";
   unsigned char    c = 'e';
   unsigned char    d = 'j';

   TEST_ASSERT_EQUAL(memchr(s, c, 3), ft_memchr(s, c, 3));
   TEST_ASSERT_EQUAL(NULL, ft_memchr(s, d, 4));
}

static void tests_ft_memcmp(void)
{
    const char  s1[] = "just";
    const char s2[] = "jUst";
    const char  s3[] = "just";

   TEST_ASSERT_EQUAL(32, ft_memcmp(s1, s2, 2));
   TEST_ASSERT_EQUAL(0, ft_memcmp(s1, s3, 4));
   TEST_ASSERT_EQUAL(memcmp(s1, s2, 4) > 0, ft_memcmp(s1, s2, 4) > 0);
   TEST_ASSERT_TRUE(ft_memcmp(s1, s2, 2) > 0 && memcmp(s1, s2, 2) > 0);
}

static void tests_ft_strnstr(void)
{
    char    str[] = "I will test this function";
    char    *result = &str[12];
    char    find[] = "this";
    char    find2[] = "paula";
    char    find3[] = "";

    TEST_ASSERT_EQUAL_PTR(result, ft_strnstr(str, find, 30));
    TEST_ASSERT_EQUAL_PTR(NULL, ft_strnstr(str, find2, 30));
    TEST_ASSERT_EQUAL_PTR(str, ft_strnstr(str, find3, 30));
    TEST_ASSERT_EQUAL_PTR(strnstr(str, find3, 30), ft_strnstr(str, find3, 30));
    
}

void    tests_ft_atoi(void)
{
    TEST_ASSERT_EQUAL_INT32(5, atoi("5"));
    TEST_ASSERT_EQUAL_INT32(5, ft_atoi("5"));
    TEST_ASSERT_EQUAL_INT32(-5, ft_atoi("-5"));
    TEST_ASSERT_EQUAL_INT32(15, ft_atoi("15"));
    TEST_ASSERT_EQUAL_INT32(0, ft_atoi("0"));
    TEST_ASSERT_EQUAL_INT32(-109875, ft_atoi("-109875"));
    TEST_ASSERT_EQUAL_INT32(-109875, ft_atoi("      -109875"));
}

void    tests_ft_calloc(void)
{
    int     expected[] = {0, 0, 0, 0};
    int     *array = (int *) ft_calloc(4, sizeof(int));
    int     *array2 = (int *) ft_calloc(0, sizeof(int));

    TEST_ASSERT_EQUAL_MEMORY(expected, array, 4);
    free(array);
    TEST_ASSERT_EQUAL_PTR(NULL, array2);
    free(array2);

    // char test[] = {0b11111111, 1, 0, 1};// 00000000 00000001 = 0000000111111111 
    // printf("char: %d\n", *test);
    // printf("unsigned char: %d\n", *((unsigned char *) test));
    // printf("short int: %d\n", *((short int *) test));
    // printf("int: %d\n", *((int *) test));
}

void    tests_ft_strdup(void)
{
    char    s[] = "I will test this!";
    char    *dest;

    dest = ft_strdup(s);
    TEST_ASSERT_EQUAL_MEMORY(s, dest, 18);
    free(dest);
}

void    tests_ft_substr(void)
{
    char    str[] = "abcdefghij";
    char    *sub;
    char    *sub2;
    char    *sub3;
    char    *sub4;
    char    expected[] = "abc";
    char    expected2[] = "hij";

    sub = ft_substr(str, 0, 3);
    TEST_ASSERT_EQUAL_STRING(expected, sub);
    free(sub);
    sub2 = ft_substr(str, 7, 3);
    TEST_ASSERT_EQUAL_STRING(expected2, sub2);
    free(sub2);
    sub3 = ft_substr(str, 20, 3);
    TEST_ASSERT_EQUAL_STRING(0, sub3);
    free(sub3);

    sub4 = ft_substr(str, 0, 50);
    TEST_ASSERT_EQUAL_STRING(str, sub4);
    TEST_ASSERT_EQUAL(ft_strlen(sub4), ft_strlen(str));
    free(sub4);
}

void tests_ft_strjoin(void)
{
    char    s1[] = "test ";
    char    s2[] = "this!";
    char    expected[] = "test this!";
    char    *copy;

    copy = ft_strjoin(s1, s2);
    TEST_ASSERT_EQUAL_STRING(expected, copy);
    free(copy);
}

void    tests_ft_strtrim(void)
{
    char    s1[] = "t ";
    char    s2[] = "abcdefghijkl";
    char    expected[] = "t";
    
    char    *temp = ft_strtrim(s1, " ");
    TEST_ASSERT_EQUAL_STRING(expected, temp);
    free(temp);
    char    *temp2 = ft_strtrim(s2, " ");
    TEST_ASSERT_EQUAL_STRING(s2, temp2);
    free(temp2);
}

void    tests_ft_putchar(void)
{
    FILE    *file;
    char    buff;

    file = fopen("teste.txt", "w");
    ft_putchar_fd('T', file->_fileno);
    fclose(file);
    file = fopen("teste.txt", "r");
    fread(&buff, 1, 1, file);
    TEST_ASSERT_EQUAL_CHAR('T', buff);
    fclose(file);
}

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(tests_ft_isalpha);
    RUN_TEST(tests_ft_isdigit);
    RUN_TEST(tests_ft_isalnum);
    RUN_TEST(tests_ft_isascii);
    RUN_TEST(tests_ft_isprint);
    RUN_TEST(tests_ft_strlen);
    RUN_TEST(tests_ft_memset);
    RUN_TEST(tests_ft_bzero);
    RUN_TEST(tests_ft_memcpy);
    RUN_TEST(tests_ft_memmove);
    RUN_TEST(tests_ft_strlcpy);
    RUN_TEST(tests_ft_strlcat);
    RUN_TEST(tests_ft_toupper);
    RUN_TEST(tests_ft_tolower);
    RUN_TEST(tests_ft_strchr);
    RUN_TEST(tests_ft_strrchr);
    RUN_TEST(tests_ft_strncmp);
    RUN_TEST(tests_ft_memchr);
    RUN_TEST(tests_ft_memcmp);
    RUN_TEST(tests_ft_strnstr);
    RUN_TEST(tests_ft_atoi);
    RUN_TEST(tests_ft_calloc);
    RUN_TEST(tests_ft_strdup);
    RUN_TEST(tests_ft_substr);
    RUN_TEST(tests_ft_strjoin);
    RUN_TEST(tests_ft_strtrim);
    RUN_TEST(tests_ft_putchar);
    return UNITY_END();
}

