#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

char test1[40] = "Hell0 world\0";
char test2[40] = "Hell0 world\n\0";
char test3[15] = "a\n\0";
char test4[15] = " \n\0";
char test5[15] = " \0";
char test6[15] = "\n\0";
char test7[15] = "\0";
char *str_NULL = NULL;
char s1[40] = "Hello world\0";
char s2[40] = "Hello world\n\0";
char s3[15] = "a\n\0";
char s4[15] = " \n\0";
char s5[15] = " \0";
char s6[15] = "\n\0";
char s7[15] = "\0";
char s8[40] = "Hello world\0";
char s9[15] = "wo";

START_TEST(s21_memcpy_test) {
  char destination[] = "Here w0 are\0";
  char result[] = "Here w0 are\0";
  ck_assert_str_eq(s21_memcpy(destination, test1, 8), memcpy(result, test1, 8));

  char destination2[] = "Here w0 are\n\0";
  char result2[] = "Here w0 are\n\0";
  ck_assert_str_eq(s21_memcpy(destination2, test2, 8),
                   memcpy(result2, test2, 8));

  char destination3[] = "a\n\0";
  char result3[] = "a\n\0";
  ck_assert_str_eq(s21_memcpy(destination3, test3, 2),
                   memcpy(result3, test3, 2));

  char destination4[] = " \n\0";
  char result4[] = " \n\0";
  ck_assert_str_eq(s21_memcpy(destination4, test4, 2),
                   memcpy(result4, test4, 2));

  char destination5[] = " \0";
  char result5[] = " \0";
  ck_assert_str_eq(s21_memcpy(destination5, test5, 2),
                   memcpy(result5, test5, 2));

  char destination6[] = "\n\0";
  char result6[] = "\n\0";
  ck_assert_str_eq(s21_memcpy(destination6, test6, 2),
                   memcpy(result6, test6, 2));

  char destination7[] = "\0";
  char result7[] = "aaa\0";
  ck_assert_str_eq(s21_memcpy(destination7, test7, 2),
                   memcpy(result7, test7, 2));
}
END_TEST

START_TEST(s21_memmove_test) {
  char str1[30] = "teststring";
  //   char str2[30] = "teststring";
  ck_assert_str_eq(s21_memmove(str1 + 2, str1, 10),
                   memmove(str1 + 2, str1, 10));

  char destination2[] = "Here w0 are\n\0";
  // char result2[] = "Here w0 are\n\0";
  ck_assert_str_eq(s21_memmove(destination2, test2, 8),
                   memmove(destination2, test2, 8));

  char destination3[] = "a\n\0";
  char result3[] = "a\n\0";
  ck_assert_str_eq(s21_memmove(destination3, test3, 2),
                   memmove(result3, test3, 2));

  char destination4[] = " \n\0";
  char result4[] = " \n\0";
  ck_assert_str_eq(s21_memmove(destination4, test4, 2),
                   memmove(result4, test4, 2));

  char destination5[] = " \0";
  char result5[] = " \0";
  ck_assert_str_eq(s21_memmove(destination5, test5, 2),
                   memmove(result5, test5, 2));

  char destination6[] = "\n\0";
  char result6[] = "\n\0";
  ck_assert_str_eq(s21_memmove(destination6, test6, 2),
                   memmove(result6, test6, 2));

  char destination7[] = "\0";
  char result7[] = "\0";
  ck_assert_str_eq(s21_memmove(destination7, test7, 2),
                   memmove(result7, test7, 2));

  ck_assert_str_eq(s21_memmove(test1, test2, 3), memmove(test1, test2, 3));
}
END_TEST

START_TEST(s21_memset_test) {
  char destination[] = "Here w0 are123\0";
  char origin[] = "Here w0 are123\0";
  ck_assert_str_eq(s21_memset(destination, '-', 4), memset(origin, '-', 4));

  char destination2[] = "Here w0 are\n\0";
  char origin2[] = "Here w0 are\n\0";
  ck_assert_str_eq(s21_memset(destination2, '-', 4), memset(origin2, '-', 4));

  char destination3[] = "a\n\0";
  char origin3[] = "a\n\0";
  ck_assert_str_eq(s21_memset(destination3, '-', 2), memset(origin3, '-', 2));

  char destination4[] = " \n\0";
  char origin4[] = " \n\0";
  ck_assert_str_eq(s21_memset(destination4, '-', 2), memset(origin4, '-', 2));

  char destination5[] = " \0";
  char origin5[] = " \0";
  ck_assert_str_eq(s21_memset(destination5, '-', 1), memset(origin5, '-', 1));

  char destination6[20] = "\n\0";
  char origin6[20] = "\n\0";
  ck_assert_str_eq(s21_memset(destination6, '-', 1), memset(origin6, '-', 1));

  char origin7[] = "\0";
  char destination7[] = "\0";
  ck_assert_str_eq(s21_memset(destination7, '-', 1), memset(origin7, '-', 1));
}
END_TEST

START_TEST(s21_strcpy_test) {
  char destination[14];
  char result[14];
  ck_assert_str_eq(s21_strcpy(destination, test1), strcpy(result, test1));

  char destination2[20] = "Here w0 are\n\0";
  char result2[20] = "Here w0 are\n\0";
  ck_assert_str_eq(s21_strcpy(destination2, test2), strcpy(result2, test2));

  char destination3[20] = "a\n\0";
  char result3[20] = "a\n\0";
  ck_assert_str_eq(s21_strcpy(destination3, test3), strcpy(result3, test3));

  char destination4[20] = " \n\0";
  char result4[20] = " \n\0";
  ck_assert_str_eq(s21_strcpy(destination4, test4), strcpy(result4, test4));

  char destination5[] = " \0";
  char result5[] = " \0";
  ck_assert_str_eq(s21_strcpy(destination5, test5), strcpy(result5, test5));

  char destination6[20] = "\n\0";
  char result6[20] = "\n\0";
  ck_assert_str_eq(s21_strcpy(destination6, test6), strcpy(result6, test6));

  char destination7[20] = "\0";
  char result7[20] = "\0";
  ck_assert_str_eq(s21_strcpy(destination7, test7), strcpy(result7, test7));
}
END_TEST

START_TEST(s21_strerror_test) {
  for (int n = 0; n <= 140; n++) {
    char *out1 = s21_strerror(n);
    char *out2 = strerror(n);
    ck_assert_str_eq(out1, out2);
  }
}
END_TEST

START_TEST(s21_strcat_test) {
  char str_long[100] = "Hello \n0 ware\0";
  char str[20], s21_str[20];

  for (int i = 0; i < 20; i++) {
    str[i] = '\0';
    s21_str[i] = '\0';
  }
  char *str_NULL = NULL;
  ck_assert_str_eq(s21_strcat(s21_str, "123"), strcat(str, "123"));
  ck_assert_str_eq(s21_strcat(s21_str, "Testing"), strcat(str, "Testing"));
  ck_assert_str_eq(s21_strcat(s21_str, ""), strcat(str, ""));
  ck_assert_str_eq(s21_strcat(s21_str, "hi \0"), strcat(str, "hi \0"));
  ck_assert_ptr_null(s21_strcat(str_NULL, "0"));
  ck_assert_str_eq(s21_strcat(str_long, ""), strcat(str_long, ""));
  ck_assert_str_eq(s21_strcat(str_long, "hi \0"), strcat(str_long, "hi \0"));
  ck_assert_str_eq(s21_strcat(str_long, "\n\0"), strcat(str_long, "\n\0"));
  char destination[40] = "Here w0 are123\0";
  char origin[40] = "Here w0 are123\0";
  ck_assert_str_eq(s21_strcat(destination, test1), strcat(origin, test1));

  char destination2[40] = "Here w0 are\n\0";
  char origin2[40] = "Here w0 are\n\0";
  ck_assert_str_eq(s21_strcat(destination2, test2), strcat(origin2, test2));

  char destination3[40] = "a\n\0";
  char origin3[40] = "a\n\0";
  ck_assert_str_eq(s21_strcat(destination3, test3), strcat(origin3, test3));

  char destination4[40] = " \n\0";
  char origin4[40] = " \n\0";
  ck_assert_str_eq(s21_strcat(destination4, test4), strcat(origin4, test4));

  char destination5[40] = " \0";
  char origin5[40] = " \0";
  ck_assert_str_eq(s21_strcat(destination5, test5), strcat(origin5, test5));

  char destination6[40] = "\n\0";
  char origin6[40] = "\n\0";
  ck_assert_str_eq(s21_strcat(destination6, test6), strcat(origin6, test6));

  char origin7[40] = "\0";
  char destination7[40] = "\0";
  ck_assert_str_eq(s21_strcat(destination7, test7), strcat(origin7, test7));
}
END_TEST

START_TEST(s21_strchr_test) {
  char str_String[20] = "Hello, world!";
  char *str_empty = "";
  ck_assert_ptr_eq(s21_strchr(str_String, 'e'), strchr(str_String, 'e'));
  ck_assert_ptr_eq(s21_strchr(str_String, 'q'), strchr(str_String, 'q'));
  ck_assert_ptr_eq(s21_strchr(str_String, '0'), strchr(str_String, '0'));
  ck_assert_ptr_eq(s21_strchr(str_empty, 'e'), strchr(str_empty, 'e'));
  ck_assert_ptr_null(s21_strchr(str_empty, 'w'));
  ck_assert_str_eq(s21_strchr(test1, 'e'), strchr(test1, 'e'));
  ck_assert_str_eq(s21_strchr(test2, 'e'), strchr(test2, 'e'));
  ck_assert_ptr_eq(s21_strchr(test3, 'e'), strchr(test3, 'e'));
  ck_assert_ptr_eq(s21_strchr(test4, 'e'), strchr(test4, 'e'));
  ck_assert_ptr_eq(s21_strchr(test5, 'e'), strchr(test5, 'e'));
  ck_assert_ptr_eq(s21_strchr(test6, 'e'), strchr(test6, 'e'));
  ck_assert_ptr_eq(s21_strchr(test7, 'e'), strchr(test7, 'e'));
}
END_TEST

START_TEST(s21_strncmp_test) {
  char toCompare[] = "Hell0 man";

  ck_assert_int_eq(s21_strncmp(test1, toCompare, 6), 0);
  ck_assert_int_eq(strncmp(test1, toCompare, 6), 0);
  ck_assert_int_eq(s21_strncmp(test2, toCompare, 6), 0);
  ck_assert_int_eq(strncmp(test2, toCompare, 6), 0);
  ck_assert_int_ne(s21_strncmp(test3, toCompare, 4), 0);
  ck_assert_int_ne(strncmp(test3, toCompare, 4), 0);
  ck_assert_int_ne(s21_strncmp(test4, toCompare, 4), 0);
  ck_assert_int_ne(strncmp(test4, toCompare, 4), 0);
  ck_assert_int_ne(s21_strncmp(test5, toCompare, 3), 0);
  ck_assert_int_ne(strncmp(test5, toCompare, 3), 0);
  ck_assert_int_ne(s21_strncmp(test6, toCompare, 3), 0);
  ck_assert_int_ne(strncmp(test6, toCompare, 3), 0);
  ck_assert_int_ne(s21_strncmp(test7, toCompare, 2), 0);
  ck_assert_int_ne(strncmp(test7, toCompare, 2), 0);
}
END_TEST

START_TEST(s21_strlen_test) {
  ck_assert_uint_eq(s21_strlen("123"), strlen("123"));
  ck_assert_uint_eq(s21_strlen("Testing \0 a"), strlen("Testing \0 a"));
  ck_assert_uint_eq(s21_strlen("Testing \n !"), strlen("Testing \n !"));
  ck_assert_uint_eq(s21_strlen(""), strlen(""));
  ck_assert_uint_eq(s21_strlen("a\n\0"), strlen("a\n\0"));
  ck_assert_uint_eq(s21_strlen(" \0"), strlen(" \0"));
  ck_assert_uint_eq(s21_strlen("\n\0"), strlen("\n\0"));
  ck_assert_uint_eq(s21_strlen("Testing \n !"), strlen("Testing \n !"));
  ck_assert_uint_eq(s21_strlen(test1), strlen(test1));
  ck_assert_uint_eq(s21_strlen(test2), strlen(test2));
  ck_assert_uint_eq(s21_strlen(test3), strlen(test3));
  ck_assert_uint_eq(s21_strlen(test4), strlen(test4));
  ck_assert_uint_eq(s21_strlen(test5), strlen(test5));
  ck_assert_uint_eq(s21_strlen(test6), strlen(test6));
  ck_assert_uint_eq(s21_strlen(test7), strlen(test7));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char str_String[7] = "Testing";
  char *str_empty = "";
  ck_assert_ptr_eq(s21_strrchr(str_String, 'e'), strrchr(str_String, 'e'));
  ck_assert_ptr_eq(s21_strrchr(str_String, 'q'), strrchr(str_String, 'q'));
  ck_assert_ptr_eq(s21_strrchr(str_String, '0'), strrchr(str_String, '0'));
  ck_assert_ptr_eq(s21_strrchr(str_empty, 'e'), strrchr(str_empty, 'e'));
  ck_assert_ptr_null(s21_strrchr(str_empty, 'w'));
  ck_assert_ptr_eq(s21_strrchr(test1, 'o'), strrchr(test1, 'o'));
  ck_assert_ptr_eq(s21_strrchr(test2, 'l'), strrchr(test2, 'l'));
  ck_assert_str_eq(s21_strrchr(test3, '\n'), strrchr(test3, '\n'));
  ck_assert_str_eq(s21_strrchr(test4, ' '), strrchr(test4, ' '));
  ck_assert_str_eq(s21_strrchr(test5, ' '), strrchr(test5, ' '));
  ck_assert_str_eq(s21_strrchr(test6, '\0'), strrchr(test6, '\0'));
  ck_assert_ptr_eq(s21_strrchr(test7, ' '), strrchr(test7, ' '));
}

END_TEST

START_TEST(s21_to_upper_test) {
  char *UP;
  UP = s21_to_upper("");
  ck_assert_str_eq(UP, "");
  free(UP);
  UP = s21_to_upper("Testing");
  ck_assert_str_eq(UP, "TESTING");
  free(UP);
  UP = s21_to_upper("TESTING");
  ck_assert_str_eq(UP, "TESTING");
  free(UP);
  UP = s21_to_upper(NULL);
  ck_assert_ptr_null(UP);
  free(UP);
  char destination[] = "Here w0 are123\0";
  char *test01 = s21_to_upper(destination);
  ck_assert_str_eq(test01, "HERE W0 ARE123");
  free(test01);

  char destination2[] = "Here w0 are\n\0";
  char *test02 = s21_to_upper(destination2);
  ck_assert_str_eq(test02, "HERE W0 ARE\n");
  free(test02);

  char destination3[] = "a\n\0";
  char *test03 = s21_to_upper(destination3);
  ck_assert_str_eq(test03, "A\n");
  free(test03);

  char destination4[] = " \n\0";
  char *test04 = s21_to_upper(destination4);
  ck_assert_str_eq(test04, " \n");
  free(test04);

  char destination5[] = " \0";
  char *test05 = s21_to_upper(destination5);
  ck_assert_str_eq(test05, " ");
  free(test05);

  char destination6[] = "\n\0";
  char *test06 = s21_to_upper(destination6);
  ck_assert_str_eq(test06, "\n");
  free(test06);

  char destination7[] = "\0";
  char *test07 = s21_to_upper(destination7);
  ck_assert_str_eq(test07, "");
  free(test07);
}
END_TEST

START_TEST(s21_strstr_test) {
  char sth[] = "el\0";
  char test11[20] = "Hell0 world\0";
  char test12[20] = "Hell0 world\n\0";
  char test13[10] = "a\n\0";
  char test14[10] = " \n\0";
  char test15[10] = " \0";
  char test16[10] = "\n\0";
  char test17[10] = "\0";
  ck_assert_str_eq(s21_strstr(test11, sth), strstr(test11, sth));
  ck_assert_str_eq(s21_strstr(test12, sth), strstr(test12, sth));
  ck_assert_ptr_eq(s21_strstr(test13, sth), strstr(test13, sth));
  ck_assert_ptr_eq(s21_strstr(test14, sth), strstr(test14, sth));
  ck_assert_ptr_eq(s21_strstr(test15, sth), strstr(test15, sth));
  ck_assert_ptr_eq(s21_strstr(test16, sth), strstr(test16, sth));
  ck_assert_ptr_eq(s21_strstr(test17, sth), strstr(test17, sth));
  ck_assert_str_eq(s21_strstr(s1, s9), strstr(s1, s9));
  ck_assert_pstr_eq(s21_strstr(s2, s3), strstr(s2, s3));
  ck_assert_pstr_eq(s21_strstr(s3, s4), strstr(s3, s4));
  ck_assert_pstr_eq(s21_strstr(s5, s6), strstr(s5, s6));
  ck_assert_pstr_eq(s21_strstr(s6, s7), strstr(s6, s7));
  ck_assert_pstr_eq(s21_strstr(s7, s8), strstr(s7, s8));
}
END_TEST

//
START_TEST(s21_strtok_test) {
  char dest[] = "Hell0 world\0";
  char orig[] = "Hell0 world\0";
  ck_assert_str_eq(s21_strtok(dest, " "), strtok(orig, " "));
  ck_assert_str_eq(s21_strtok(s21_NULL, " "), strtok(s21_NULL, " "));
  char dest2[] = "Hell0 world\n\0";
  char orig2[] = "Hell0 world\n\0";
  ck_assert_str_eq(s21_strtok(dest2, " "), strtok(orig2, " "));

  char dest3[] = "a\n\0";
  char orig3[] = "a\n\0";
  ck_assert_str_eq(s21_strtok(dest3, " "), strtok(orig3, " "));

  char dest4[] = " s\0";
  char orig4[] = " s\0";
  ck_assert_str_eq(s21_strtok(dest4, " "), strtok(orig4, " "));

  char dest5[] = " \0";
  char orig5[] = " \0";
  ck_assert_ptr_eq(s21_strtok(dest5, " "), strtok(orig5, " "));

  char dest6[] = "\n\0";
  char orig6[] = "\n\0";
  ck_assert_str_eq(s21_strtok(dest6, " "), strtok(orig6, " "));

  char dest7[] = "\0";
  char orig7[] = "\0";
  ck_assert_ptr_eq(s21_strtok(dest7, " "), strtok(orig7, " "));
}
END_TEST

START_TEST(s21_trim_test) {
  char dest[] = "-=Hello=-\0";
  char *test01 = s21_trim(dest, "-");
  ck_assert_str_eq(test01, "=Hello=\0");
  free(test01);

  char dest2[] = "-Hello\n\0";
  char *test02 = s21_trim(dest2, "-");
  ck_assert_str_eq(test02, "Hello\n\0");
  free(test02);

  char dest3[] = "a\0";
  char *test03 = s21_trim(dest3, "a");
  ck_assert_str_eq(test03, "");
  free(test03);

  char dest4[] = " \n\0";
  char *test04 = s21_trim(dest4, "\n");
  ck_assert_str_eq(test04, " ");
  free(test04);

  char dest5[] = "\n\0";
  char *test05 = s21_trim(dest5, "\0");
  ck_assert_str_eq(test05, "\n");
  free(test05);

  char dest6[] = " \0";
  char *test06 = s21_trim(dest6, " ");
  ck_assert_str_eq(test06, "");
  free(test06);
}
END_TEST

START_TEST(s21_insert_test) {
  char dest[] = "Hello\0";
  char insert[] = "Man\0";
  char *test01 = s21_insert(dest, insert, 2);
  ck_assert_str_eq(test01, "HeManllo\0");
  free(test01);

  char dest2[] = "Hello\n\0";
  char insert2[] = "Man\n\0";
  char *test02 = s21_insert(dest2, insert2, 1);
  ck_assert_str_eq(test02, "HMan\nello\n\0");
  free(test02);

  char dest3[] = "a\0";
  char insert3[] = "man\0";
  char *test03 = s21_insert(dest3, insert3, 1);
  ck_assert_str_eq(test03, "aman");
  free(test03);

  char dest4[] = " s\0";
  char insert4[] = " s\0";
  char *test04 = s21_insert(dest4, insert4, 1);
  ck_assert_str_eq(test04, "  ss");
  free(test04);

  char dest5[] = "\n\0", insert5[] = "\n\0";
  char *test05 = s21_insert(dest5, insert5, 2);
  ck_assert_ptr_eq(test05, NULL);
  free(test05);

  char dest6[] = " \0", insert6[] = " \0";
  char *test06 = s21_insert(dest6, insert6, 2);
  ck_assert_ptr_eq(test06, NULL);
  free(test06);

  char dest7[] = "\0", insert7[] = "\0";
  char *test07 = s21_insert(dest7, insert7, 2);
  ck_assert_ptr_eq(test07, NULL);
  free(test07);
}
END_TEST

START_TEST(s21_strncat_test) {
  ck_assert_str_eq(s21_strncat(test1, "123", 1), strncat(test1, "123", 1));
  ck_assert_str_eq(s21_strncat(test2, "Testing", 1),
                   strncat(test2, "Testing", 1));
  ck_assert_str_eq(s21_strncat(test3, "", 2), strncat(test3, "", 2));
  ck_assert_str_eq(s21_strncat(test4, "hi \0", 5), strncat(test4, "hi \0", 5));
  ck_assert_ptr_null(s21_strncat(str_NULL, "0", 5));
  ck_assert_str_eq(s21_strncat(test5, "", 5), strncat(test5, "", 5));
  ck_assert_str_eq(s21_strncat(test6, "hi \0", 5), strncat(test6, "hi \0", 5));
  ck_assert_str_eq(s21_strncat(test7, "\n\0", 5), strncat(test7, "\n\0", 5));
}
END_TEST

//
START_TEST(s21_strcmp_test) {
  char toCompare[] = "Hell0 man";

  ck_assert_int_ne(s21_strcmp(test1, toCompare), 0);
  ck_assert_int_ne(strcmp(test1, toCompare), 0);
  ck_assert_int_ne(s21_strcmp(test2, toCompare), 0);
  ck_assert_int_ne(strcmp(test2, toCompare), 0);
  ck_assert_int_ne(s21_strcmp(test3, toCompare), 0);
  ck_assert_int_ne(strcmp(test3, toCompare), 0);
  ck_assert_int_ne(s21_strcmp(test4, toCompare), 0);
  ck_assert_int_ne(strcmp(test4, toCompare), 0);
  ck_assert_int_ne(s21_strcmp(test5, toCompare), 0);
  ck_assert_int_ne(strcmp(test5, toCompare), 0);
  ck_assert_int_ne(s21_strcmp(test6, toCompare), 0);
  ck_assert_int_ne(strcmp(test6, toCompare), 0);
  ck_assert_int_ne(s21_strcmp(test7, toCompare), 0);
  ck_assert_int_ne(strcmp(test7, toCompare), 0);
}
END_TEST

START_TEST(s21_strncpy_test) {
  ck_assert_str_eq(s21_strncpy(test1, test2, 2), strncpy(test1, test2, 2));
  ck_assert_str_eq(s21_strncpy(test2, test7, 10), strncpy(test2, test7, 10));
  ck_assert_str_eq(s21_strncpy(test3, test6, 2), strncpy(test3, test6, 2));
  ck_assert_str_eq(s21_strncpy(test4, test5, 2), strncpy(test4, test5, 2));
  ck_assert_ptr_null(s21_strncpy(str_NULL, test1, 2));
}
END_TEST

START_TEST(s21_strcspn_test) {
  ck_assert_int_eq(s21_strcspn(test7, test7), strcspn(test7, test7));
  ck_assert_int_eq(s21_strcspn(test1, test7), strcspn(test1, test7));
  ck_assert_int_eq(s21_strcspn(test2, test6), strcspn(test2, test6));
  ck_assert_int_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
  ck_assert_int_eq(s21_strcspn(test4, test3), strcspn(test4, test3));
  ck_assert_int_eq(s21_strcspn(test5, test2), strcspn(test5, test2));
  ck_assert_int_eq(s21_strcspn(str_NULL, test1), '\0');
}
END_TEST

START_TEST(s21_strpbrk_test) {
  ck_assert_ptr_eq(s21_strpbrk(test1, test3), strpbrk(test1, test3));
  ck_assert_ptr_eq(s21_strpbrk(test2, test7), strpbrk(test2, test7));
  ck_assert_ptr_eq(s21_strpbrk(test3, test6), strpbrk(test3, test6));
  ck_assert_ptr_eq(s21_strpbrk(test4, test5), strpbrk(test4, test5));
  ck_assert_ptr_eq(s21_strpbrk(test5, test1), strpbrk(test5, test1));
  ck_assert_ptr_eq(s21_strpbrk(test6, test2), strpbrk(test6, test2));
  ck_assert_ptr_eq(s21_strpbrk(test7, test3), strpbrk(test7, test3));
  ck_assert_ptr_null(s21_strpbrk(str_NULL, test1));
}
END_TEST

START_TEST(s21_strspn_test) {
  ck_assert_int_eq(s21_strspn(test7, test6), strspn(test7, test6));
  ck_assert_int_eq(s21_strspn(test1, test5), strspn(test1, test5));
  ck_assert_int_eq(s21_strspn(test2, test4), strspn(test2, test4));
  ck_assert_int_eq(s21_strspn(test1, test2), strspn(test1, test2));
  ck_assert_int_eq(s21_strspn(test4, test1), strspn(test4, test1));
  ck_assert_int_eq(s21_strspn(test5, test2), strspn(test5, test2));
  ck_assert_int_eq(s21_strspn(test6, test3), strspn(test6, test3));
}
END_TEST

START_TEST(s21_to_lower_test) {
  char *str_1 = "Test";
  char str_2[10] = "TeSt";
  char *str_3 = "TEST";
  char *str_control = "test";
  char *low = NULL;
  low = s21_to_lower(str_1);
  ck_assert_str_eq(low, str_control);
  free(low);
  low = s21_to_lower(test5);
  ck_assert_str_eq(low, " ");
  free(low);
  low = s21_to_lower(str_1);
  ck_assert_str_eq(str_control, low);
  free(low);
  low = s21_to_lower(str_2);
  ck_assert_str_eq(low, str_control);
  free(low);
  low = s21_to_lower(str_3);
  ck_assert_str_eq(low, str_control);
  free(low);
  ck_assert_ptr_null(s21_to_lower(NULL));
}
END_TEST

START_TEST(s21_memchr_test) {
  ck_assert_pstr_eq(s21_memchr(s1, 5, 5), memchr(s1, 5, 5));
  ck_assert_pstr_eq(s21_memchr(s2, 5, 2), memchr(s2, 5, 2));
  ck_assert_pstr_eq(s21_memchr(s3, 1, 1), memchr(s3, 1, 1));
  ck_assert_pstr_eq(s21_memchr(s4, 1, 1), memchr(s4, 1, 1));
  ck_assert_pstr_eq(s21_memchr(s5, 2, 2), memchr(s5, 2, 2));
  ck_assert_pstr_eq(s21_memchr(s6, 1, 1), memchr(s6, 1, 1));
  ck_assert_pstr_eq(s21_memchr(s7, '\0', 1), memchr(s7, '\0', 1));
}
END_TEST

START_TEST(s21_memcmp_test) {
  ck_assert_int_eq(s21_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
  ck_assert_int_ne(s21_memcmp(s2, s3, 5), 0);
  ck_assert_int_ne(memcmp(s2, s3, 5), 0);
  ck_assert_int_eq(s21_memcmp(s3, s4, 1), memcmp(s3, s4, 1));
  ck_assert_int_eq(s21_memcmp(s4, s5, 1), memcmp(s4, s5, 1));
  ck_assert_int_eq(s21_memcmp(s5, s6, 1), memcmp(s5, s6, 1));
  ck_assert_int_eq(s21_memcmp(s6, s7, 1), memcmp(s6, s7, 1));
  ck_assert_int_eq(s21_memcmp(s7, s1, 1), memcmp(s7, s1, 1));
}
END_TEST

START_TEST(s21_chars_f) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};
  s21_sprintf(s21_buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1, '\n',
              test2, '-', test3, test4, test5, test6, test7);
  sprintf(buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1, '\n', test2,
          '-', test3, test4, test5, test6, test7);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

// test for printf
START_TEST(s21_nums_f) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};
  s21_sprintf(s21_buffer,
              "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u", 101,
              -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
              (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
  sprintf(buffer, "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u", 101,
          -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
          (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums2_f) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};

  s21_sprintf(s21_buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
              (long int)125123123123, (short int)160, (unsigned short)101,
              (unsigned long)210, (short int)0, (long int)0, (short int)-25,
              (long int)-51);
  sprintf(buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
          (long int)125123123123, (short int)160, (unsigned short)101,
          (unsigned long)210, (short int)0, (long int)0, (short int)-25,
          (long int)-51);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums3_f) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};
  s21_sprintf(s21_buffer, "%-+6.4f %-2.2lf %5.5f %f %f", 100.0, 0.01, 0.10,
              -12.0, 0.00001);
  sprintf(buffer, "%-+6.4f %-2.2f %5.5f %f %f", 100.0, 0.01, 0.10, -12.0,
          0.00001);
  ck_assert_str_eq(s21_buffer, buffer);

  char s21_buffer2[256] = {0};
  char buffer2[256] = {0};
  s21_sprintf(s21_buffer2, "%lf %lf %lf %lf %lf %lf", 0.0 / 0.0, 1.0 / 0.0,
              0.0 / 1.0, -0.0 / 0.0, 1.0 / 0.0, -0.0 / 1.0);
  sprintf(buffer2, "%lf %lf %lf %lf %lf %lf", 0.0 / 0.0, 1.0 / 0.0, 0.0 / 1.0,
          -0.0 / 0.0, 1.0 / 0.0, -0.0 / 1.0);
  ck_assert_str_eq(s21_buffer2, buffer2);

  char s21_buffer3[256] = {0};
  char buffer3[256] = {0};
  s21_sprintf(s21_buffer3, "%lg %lG %#lg %le", 234243.234, 8427348.234, 123.0,
              155.2);
  sprintf(buffer3, "%lg %lG %#lg %le", 234243.234, 8427348.234, 123.0, 155.2);
  ck_assert_str_eq(s21_buffer3, buffer3);
}
END_TEST

START_TEST(s21_nums4_f) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "02) chisto rofl : %-+.f\n", -100.55);
  sprintf(data1, "02) chisto rofl : %-+.f\n", -100.55);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_nums5_f) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "01)SPRINTF : |%5c|\n", 'R');
  sprintf(data1, "01)SPRINTF : |%5c|\n", 'R');
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_nums6_f) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "01)SPRINTF : |%-5c|\n", 'R');
  sprintf(data1, "01)SPRINTF : |%-5c|\n", 'R');
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_nums7_f) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "01)SPRINTF : |%1c|\n", '3');
  sprintf(data1, "01)SPRINTF : |%1c|\n", '3');
  ck_assert_str_eq(data, data1);
}
END_TEST

END_TEST

START_TEST(s21_nums12_f) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "01)SPRINTF : |%s|\n", "salut");
  sprintf(data1, "01)SPRINTF : |%s|\n", "salut");
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_nums13_f) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "01)SPRINTF : |%-s|\n", "test");
  sprintf(data1, "01)SPRINTF : |%-s|\n", "test");
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_nums14_f) {
  char data[100];
  char data1[100];
  s21_sprintf(data, "01)SPRINTF : |%-s|\n", "test2");
  sprintf(data1, "01)SPRINTF : |%-s|\n", "test2");
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_o_f) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 253;
  unsigned long l = 4325234324242l;
  int r1 = sprintf(str1, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                   12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
  int r2 =
      s21_sprintf(str2, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                  12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_x_f) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 345;
  unsigned long l = 52342353242l;
  int r1 = sprintf(str1,
                   "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%20.*"
                   "x%#10.*x%*.5hx%10.25lx",
                   235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452,
                   8, 23452, 10, 34254, 3, 33334, 10, h, l);
  int r2 = s21_sprintf(str2,
                       "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%"
                       "20.*x%#10.*x%*.5hx%10.25lx",
                       235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15,
                       3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

// test for scanf

START_TEST(sscanf_test_e) {
  float e1 = 0, e2 = 0;
  int r1 = 0, r2 = 0;

  r1 = sscanf("123e34", "%e", &e1);
  r2 = s21_sscanf("123e34", "%e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e34", "%e", &e1);
  r2 = s21_sscanf("12e34", "%e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.345e-34", "%11e", &e1);
  r2 = s21_sscanf("123.345e-34", "%11e", &e2);
  ck_assert_msg(EPS > (fabs(e1 - e2)), "float not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.345e34", "%10e", &e1);
  r2 = s21_sscanf("123.345e34", "%10e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_L) {
  int r1 = 0, r2 = 0;
  long double Lf1 = 0, Lf2 = 0;

  r1 = sscanf("123.45", "%Lf", &Lf1);
  r2 = s21_sscanf("123.45", "%Lf", &Lf2);
  ck_assert_msg((int)Lf1 == (int)Lf2, "floats not equals");
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_u) {
  int r1 = 0, r2 = 0;
  unsigned u1 = 0, u2 = 0;

  r1 = sscanf("", "%u", &u1);
  r2 = s21_sscanf("", "%u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-0x123", "%u", &u1);
  r2 = s21_sscanf("-0x123", "%u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+0x123", "%2u", &u1);
  r2 = s21_sscanf("+0x123", "%2u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+123", "%u", &u1);
  r2 = s21_sscanf("+123", "%u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+z123", "%u", &u1);
  r2 = s21_sscanf("+z123", "%u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x12345", "%2u", &u1);
  r2 = s21_sscanf("0x12345", "%2u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%u", &u1);
  r2 = s21_sscanf("123.456", "%u", &u2);
  ck_assert_msg(u1 == u2, "floats not equals");
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_h) {
  int r1 = 0, r2 = 0;
  unsigned short hu1 = 0, hu2 = 0;

  r1 = sscanf("12345", "%hu", &hu1);
  r2 = s21_sscanf("12345", "%hu", &hu2);
  ck_assert_int_eq(hu1, hu2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_s) {
  int r1 = 0, r2 = 0;
  char s1[100], s2[100];

  r1 = sscanf("werty kraken", "%*s%2s", s1);
  r2 = s21_sscanf("werty kraken", "%*s%2s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("\nwerty kraken", "%*s%10s", s1);
  r2 = s21_sscanf("\nwerty kraken", "%*s%10s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("   werty kraken", "%*s%s", s1);
  r2 = s21_sscanf("   werty kraken", "%*s%s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("", "%s", s1);
  r2 = s21_sscanf("", "%s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("\0", "%s", s1);
  r2 = s21_sscanf("\0", "%s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("weartewrsthxffdtsrhdfghdfghdfghdfghdfghdfghfdgпывапывапывапы",
              "%s", s1);
  r2 = s21_sscanf(
      "weartewrsthxffdtsrhdfghdfghdfghdfghdfghdfghfdgпывапывапывапы", "%s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_f) {
  int r1 = 0, r2 = 0;
  float f1 = 0, f2 = 0;

  r1 = sscanf("12e-3", "%f", &f1);
  r2 = s21_sscanf("12e-3", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e11", "%5f", &f1);
  r2 = s21_sscanf("12e11", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12e-3", "%f", &f1);
  r2 = s21_sscanf("-12e-3", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12e-11", "%f", &f1);
  r2 = s21_sscanf("-12e-11", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e-111", "%5f", &f1);
  r2 = s21_sscanf("12e-111", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e-111", "%6f", &f1);
  r2 = s21_sscanf("12e-111", "%6f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+12e-3", "%f", &f1);
  r2 = s21_sscanf("+12e-3", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e+3", "%f", &f1);
  r2 = s21_sscanf("12e+3", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e3", "%4f", &f1);
  r2 = s21_sscanf("12e3", "%f4", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  // r1 = sscanf("12e3", "%3f", &f1);
  // r2 = s21_sscanf("12e3", "%3f", &f2);
  // ck_assert_int_eq(f1, f2);
  // ck_assert_int_eq(r1, r2);

  r1 = sscanf("2 12e3", "1 %4f", &f1);
  r2 = s21_sscanf("2 12e3", "1 %4f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-123.45", "%f", &f1);
  r2 = s21_sscanf("-123.45", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12.345", "%5f", &f1);
  r2 = s21_sscanf("-12.345", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12.345", "%5f", &f1);
  r2 = s21_sscanf("12.345", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  int i1 = -1, i2 = -1;
  char c1, c2;
  f1 = 0;
  f2 = 0;
  r1 = sscanf("z 21", "%f%c %i", &f1, &c1, &i1);
  r2 = s21_sscanf("z 21", "%f%c %i", &f2, &c2, &i2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf(".z 21", "%f%c %i", &f1, &c1, &i1);
  r2 = s21_sscanf(".z 21", "%f%c %i", &f2, &c2, &i2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf(".z 21", "%3f%c %i", &f1, &c1, &i1);
  r2 = s21_sscanf(".z 21", "%3f%c %i", &f2, &c2, &i2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0.z 21", "%3f%c %i", &f1, &c1, &i1);
  r2 = s21_sscanf("0.z 21", "%3f%c %i", &f2, &c2, &i2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  double d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0;
  r1 = sscanf("12.345 -12.345 12e3", "%5lf %5lf %3lf", &d1, &d3, &d5);
  r2 = s21_sscanf("12.345 -12.345 12e3", "%5lf %5lf %3lf", &d2, &d4, &d6);
  ck_assert_double_eq(d1, d2);
  ck_assert_double_eq(d3, d4);
  ck_assert_double_eq(d5, d6);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_o) {
  int r1 = 0, r2 = 0;
  unsigned o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0;
  long unsigned int o7 = 0, o8 = 0, o9 = 0, o10 = 0;
  short unsigned int o11 = 0, o12 = 0;

  r1 = sscanf("12345678", "%3o", &o1);
  r2 = s21_sscanf("12345678", "%3o", &o2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+12345678", "%3o", &o1);
  r2 = s21_sscanf("+12345678", "%3o", &o2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("012345678", "%3o", &o1);
  r2 = s21_sscanf("012345678", "%3o", &o2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12345678", "%3o", &o1);
  r2 = s21_sscanf("-12345678", "%3o", &o2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%o", &o1);
  r2 = s21_sscanf("123.456", "%o", &o2);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("45 011 000 041", "%o%*o %o%o", &o1, &o3, &o5);
  r2 = s21_sscanf("45 011 000 041", "%o%*o %o%o", &o2, &o4, &o6);
  ck_assert_uint_eq(o1, o2);
  ck_assert_uint_eq(o3, o4);
  ck_assert_uint_eq(o5, o6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("+36 -0123 -59", "%o %o %o", &o1, &o3, &o5);
  r2 = s21_sscanf("+36 -0123 -59", "%o %o %o", &o2, &o4, &o6);
  ck_assert_uint_eq(o1, o2);
  ck_assert_uint_eq(o3, o4);
  ck_assert_uint_eq(o5, o6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("34 -123456 055", "%2o -%3o 456%02o", &o1, &o3, &o5);
  r2 = s21_sscanf("34 -123456 055", "%2o -%3o 456%02o", &o2, &o4, &o6);
  ck_assert_uint_eq(o1, o2);
  ck_assert_uint_eq(o3, o4);
  ck_assert_uint_eq(o5, o6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x9 -0xa2 0xBa1", "%ho %lo %lo", &o11, &o7, &o9);
  r2 = s21_sscanf("0x9 -0xa2 0xBa1", "%ho %lo %lo", &o12, &o8, &o10);
  ck_assert_uint_eq(o11, o12);
  ck_assert_uint_eq(o7, o8);
  ck_assert_uint_eq(o9, o10);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("10 12345678", "%ho %lo", &o11, &o7);
  r2 = s21_sscanf("10 12345678", "%ho %lo", &o12, &o8);
  ck_assert_uint_eq(o11, o12);
  ck_assert_uint_eq(o7, o8);
  ck_assert_uint_eq(o9, o10);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_i) {
  int r1 = 0, r2 = 0;
  int i1 = -1, i2 = -1, i3 = 0, i4 = 0, i5 = 0, i6 = 0;
  short int i7, i8, i9, i10, i11, i12;
  long int i20, i21, i22, i23, i24, i25;

  // short int
  r1 = sscanf("0x9 001  777", "%hi %hi %hi", &i7, &i9, &i11);
  r2 = s21_sscanf("0x9 001  777", "%hi %hi %hi", &i8, &i10, &i12);
  ck_assert_int_eq(i7, i8);
  ck_assert_int_eq(i9, i10);
  ck_assert_int_eq(i11, i12);
  ck_assert_int_eq(r1, r2);

  // long int
  r1 = sscanf("-0x80000001 017777777777 2234234234234", "%li %li %li", &i20,
              &i22, &i24);
  r2 = s21_sscanf("-0x80000001 017777777777 2234234234234", "%li %li %li", &i21,
                  &i23, &i25);
  ck_assert_int_eq(i20, i21);
  ck_assert_int_eq(i22, i23);
  ck_assert_int_eq(i24, i25);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0z123", "%hi", &i7);
  r2 = s21_sscanf("0z123", "%hi", &i8);
  ck_assert_int_eq(i7, i8);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0z123", "%li", &i20);
  r2 = s21_sscanf("0z123", "%li", &i21);
  ck_assert_int_eq(i20, i21);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0123", "%i", &i1);
  r2 = s21_sscanf("0123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("09", "%i", &i1);
  r2 = s21_sscanf("09", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("s0123", "%i", &i1);
  r2 = s21_sscanf("s0123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0s123", "%i", &i1);
  r2 = s21_sscanf("0s123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-0123", "%i", &i1);
  r2 = s21_sscanf("-0123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x123", "%i", &i1);
  r2 = s21_sscanf("0x123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x123", "%4i", &i1);
  r2 = s21_sscanf("0x123", "%4i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x123", "%6i", &i1);
  r2 = s21_sscanf("0x123", "%6i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-123 5.     -0", "%i%2i %i", &i1, &i3, &i5);
  r2 = s21_sscanf("-123 5.     -0", "%i%2i %i", &i2, &i4, &i6);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(i5, i6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12 -10+3.5", "%3i %*i %i", &i1, &i3);
  r2 = s21_sscanf("-12 -10+3.5", "%3i %*i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-21474836481 2147483648", "%i %i", &i1, &i3);
  r2 = s21_sscanf("-21474836481 2147483648", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-2147483648 -000", "%i %i", &i1, &i3);
  r2 = s21_sscanf("-2147483648 -000", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("077 -034      089", "%i%i%i", &i1, &i3, &i5);
  r2 = s21_sscanf("077 -034      089", "%i%i%i", &i2, &i4, &i6);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(i5, i6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("077 -0234 01", "%2i 7 %i%*i", &i1, &i3);
  r2 = s21_sscanf("077 -0234 01", "%2i 7 %i%*i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("017777777777 020000000000", "%i %i", &i1, &i3);
  r2 = s21_sscanf("017777777777 020000000000", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-020000000000 -020000000001", "%i %i", &i1, &i3);
  r2 = s21_sscanf("-020000000000 -020000000001", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x9 -0xa2      0xBa1", "%*i%5i%i", &i1, &i3);
  r2 = s21_sscanf("0x9 -0xa2      0xBa1", "%*i%5i%i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x0 -0x3K0x02", "%i %i K %i", &i1, &i3, &i5);
  r2 = s21_sscanf("0x0 -0x3K0x02", "%i %i K %i", &i2, &i4, &i6);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(i5, i6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x7fffffff 0x80000000", "%i %i", &i1, &i3);
  r2 = s21_sscanf("0x7fffffff 0x80000000", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-0x80000000 -0x80000001", "%i %i", &i1, &i3);
  r2 = s21_sscanf("-0x80000000 -0x80000001", "%i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("056 y 67", "%i %i %i", &i1, &i3, &i5);
  r2 = s21_sscanf("056 y 67", "%i %i %i", &i2, &i4, &i6);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(i5, i6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-0xa2 y 02", "%i %*i %i", &i1, &i3);
  r2 = s21_sscanf("-0xa2 y 02", "%i %*i %i", &i2, &i4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(i3, i4);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_x) {
  int r1 = 0, r2 = 0;
  unsigned x1 = 0, x2 = 0;
  unsigned x3 = 0, x4 = 0;
  unsigned short x5 = 0, x6 = 0;
  unsigned long x7 = 0, x8 = 0;

  // r1 = sscanf("0x12345", "%2x", &x1);
  // r2 = s21_sscanf("0x12345", "%2x", &x2);
  // ck_assert_uint_eq(x1, x2);
  // ck_assert_int_eq(r1, r2);

  r1 = sscanf("abcdef", "%x", &x1);
  r2 = s21_sscanf("abcdef", "%x", &x2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("abcdef", "%hx", &x5);
  r2 = s21_sscanf("abcdef", "%hx", &x6);
  ck_assert_int_eq(x5, x6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("abcdef", "%lx", &x7);
  r2 = s21_sscanf("abcdef", "%lx", &x8);
  ck_assert_int_eq(x7, x8);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0gabcdef", "%hx", &x5);
  r2 = s21_sscanf("0gabcdef", "%hx", &x6);
  ck_assert_int_eq(x5, x6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0gabcdef", "%lx", &x7);
  r2 = s21_sscanf("0gabcdef", "%lx", &x8);
  ck_assert_int_eq(x7, x8);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("KRAKEN", "%X", &x1);
  r2 = s21_sscanf("KRAKEN", "%X", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("kraken", "%x", &x1);
  r2 = s21_sscanf("kraken", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x1234567890123456", "%x", &x1);
  r2 = s21_sscanf("0x1234567890123456", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x123", "%x", &x1);
  r2 = s21_sscanf("0x123", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  char t1 = '0', t2 = '0';
  r1 = sscanf("0y923", "%x%c", &x1, &t1);
  r2 = s21_sscanf("0y923", "%x%c", &x2, &t2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(t1, t2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("y123", "%x", &x1);
  r2 = s21_sscanf("y123", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  // r1 = sscanf("0xy123", "%x", &x1);
  // r2 = s21_sscanf("0xy123", "%x", &x2);
  // ck_assert_uint_eq(x1, x2);
  // ck_assert_int_eq(r1, r2);

  r1 = sscanf("+123456", "%x", &x1);
  r2 = s21_sscanf("+123456", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-123456 0x12345", "%X %x", &x1, &x3);
  r2 = s21_sscanf("-123456 0x12345", "%X %x", &x2, &x4);
  ck_assert_uint_eq(x1, x2);
  ck_assert_uint_eq(x3, x4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("bcdef", "      %x", &x1);
  r2 = s21_sscanf("bcdef", "      %x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-bcdef", "%x", &x1);
  r2 = s21_sscanf("-bcdef", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("1 2 3 0123", "1 2 3 %x", &x1);
  r2 = s21_sscanf("1 2 3 0123", "1 2 3 %x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_p) {
  int r1 = 0, r2 = 0;
  void *p1 = 0, *p2 = 0;

  r1 = sscanf("0x123", "%4p", &p1);
  r2 = s21_sscanf("0x123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0zx123", "%4p", &p1);
  r2 = s21_sscanf("0zx123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("z0x123", "%4p", &p1);
  r2 = s21_sscanf("z0x123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-z0x123", "%4p", &p1);
  r2 = s21_sscanf("-z0x123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-0x123", "%4p", &p1);
  r2 = s21_sscanf("-0x123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123", "%4p", &p1);
  r2 = s21_sscanf("123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x12345", "%p", &p1);
  r2 = s21_sscanf("0x12345", "%p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%p", &p1);
  r2 = s21_sscanf("123.456", "%p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_n) {
  int n1 = 0, n2 = 0, r1 = 0, r2 = 0;
  short int n3 = 0, n4 = 0;
  long int n5 = 0, n6 = 0;

  r1 = sscanf("123.456", "123%hn", &n3);
  r2 = s21_sscanf("123.456", "123%hn", &n4);
  ck_assert_int_eq(n3, n4);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123123.456", "123%ln", &n5);
  r2 = s21_sscanf("123123.456", "123%ln", &n6);
  ck_assert_int_eq(n5, n6);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%n", &n1);
  r2 = s21_sscanf("123.456", "%n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123123.456", "123%n", &n1);
  r2 = s21_sscanf("123123.456", "123%n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123 123.456", "123 %n", &n1);
  r2 = s21_sscanf("123 123.456", "123 %n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123 123.456", "123 %n", &n1);
  r2 = s21_sscanf("123 123.456", "123 %n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123 123.456", "123 %n", &n1);
  r2 = s21_sscanf("123 123.456", "123 %n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_memchr_test);
  tcase_add_test(tc1_1, s21_memcmp_test);
  tcase_add_test(tc1_1, s21_memcpy_test);
  tcase_add_test(tc1_1, s21_memmove_test);
  tcase_add_test(tc1_1, s21_memset_test);
  tcase_add_test(tc1_1, s21_strcat_test);
  tcase_add_test(tc1_1, s21_strncat_test);
  tcase_add_test(tc1_1, s21_strchr_test);
  tcase_add_test(tc1_1, s21_strcmp_test);
  tcase_add_test(tc1_1, s21_strncmp_test);
  tcase_add_test(tc1_1, s21_strcpy_test);
  tcase_add_test(tc1_1, s21_strncpy_test);
  tcase_add_test(tc1_1, s21_strcspn_test);
  tcase_add_test(tc1_1, s21_strerror_test);
  tcase_add_test(tc1_1, s21_strlen_test);
  tcase_add_test(tc1_1, s21_strpbrk_test);
  tcase_add_test(tc1_1, s21_strrchr_test);
  tcase_add_test(tc1_1, s21_strspn_test);
  tcase_add_test(tc1_1, s21_strstr_test);
  tcase_add_test(tc1_1, s21_strtok_test);
  tcase_add_test(tc1_1, s21_to_upper_test);
  tcase_add_test(tc1_1, s21_to_lower_test);
  tcase_add_test(tc1_1, s21_insert_test);
  tcase_add_test(tc1_1, s21_trim_test);
  tcase_add_test(tc1_1, s21_chars_f);
  tcase_add_test(tc1_1, s21_nums_f);
  tcase_add_test(tc1_1, s21_nums2_f);
  tcase_add_test(tc1_1, s21_nums3_f);
  tcase_add_test(tc1_1, s21_nums4_f);
  tcase_add_test(tc1_1, s21_nums5_f);
  tcase_add_test(tc1_1, s21_nums6_f);
  tcase_add_test(tc1_1, s21_nums7_f);
  tcase_add_test(tc1_1, s21_nums12_f);
  tcase_add_test(tc1_1, s21_nums13_f);
  tcase_add_test(tc1_1, s21_nums14_f);
  tcase_add_test(tc1_1, s21_sprintf_test_o_f);
  tcase_add_test(tc1_1, s21_sprintf_test_x_f);
  tcase_add_test(tc1_1, sscanf_test_e);
  tcase_add_test(tc1_1, sscanf_test_L);
  tcase_add_test(tc1_1, sscanf_test_u);
  tcase_add_test(tc1_1, sscanf_test_h);
  tcase_add_test(tc1_1, sscanf_test_s);
  tcase_add_test(tc1_1, sscanf_test_f);
  tcase_add_test(tc1_1, sscanf_test_o);
  tcase_add_test(tc1_1, sscanf_test_x);
  tcase_add_test(tc1_1, sscanf_test_i);
  tcase_add_test(tc1_1, sscanf_test_p);
  tcase_add_test(tc1_1, sscanf_test_n);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
