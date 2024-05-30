#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void *s21_memchr(const void *str, int c, s21_size_t n) {
  int result = 0;
  char *s;
  if (n != 0) {
    const unsigned char *p = str;
    do {
      if (*p == c) {
        s = ((void *)(p));
        result = 1;
        break;
      } else {
        p++;
        n--;
      }
    } while (n != 0);
  }
  return (result == 1) ? s : s21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *p1 = str1, *p2 = str2;
  int res = 0;
  for (s21_size_t i = 0; i < n && res == 0; i++) {
    if (p1[i] != p2[i]) {
      res = p1[i] - p2[i];
    }
  }
  return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const char *s = (char *)src;
  while (n--) *d++ = *s++;
  return (dest);
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  if (dest < src) {
    char *s = (char *)src;
    char *d = (char *)dest;
    for (unsigned int i = 0; i < n; i++) {
      *(d + i) = *(s + i);
    }
  } else {
    char *s = (char *)src + n;
    char *d = (char *)dest + n;
    for (int i = n - 1; i >= 0; i--) {
      *--d = *--s;
    }
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; ++i) *((char *)str + i) = c;
  return (char *)str;
}

char *s21_strcat(char *dest, const char *src) {
  char *p = dest;
  s21_size_t i, j;
  if ((dest != s21_NULL) && (src != s21_NULL)) {
    for (i = 0; dest[i] != '\0'; i++) {
    }
    for (j = 0; src[j] != '\0'; j++) dest[i + j] = src[j];
    dest[i + j] = '\0';
  } else {
    p = s21_NULL;
  }
  return p;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *err = dest;
  if ((dest != s21_NULL) && (src != s21_NULL)) {
    unsigned int i = 0, j = 0;
    while (dest[i] != '\0') i++;
    for (j = 0; (j < n) && src[j] != '\0'; j++) dest[i + j] = src[j];
    dest[i + j] = '\0';
  } else {
    err = s21_NULL;
  }
  return err;
}

char *s21_strchr(const char *str, int c) {
  char *res = '\0';
  c = (char)c;
  for (int i = 0; i < (int)s21_strlen(str) + 1; i++) {
    if (str[i] == c) {
      res = (char *)&str[i];
      break;
    }
  }
  return res;
}

int s21_strcmp(const char *str1, const char *str2) {
  int count = 0;
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
    while (*str1 && *str1 == *str2) {
      str1++;
      str2++;
    }
    count = *str1 - *str2;
  }
  return count;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n - 1; i++) {
    if (str1[i] != str2[i]) break;
  }
  return str1[i] - str2[i];
}

char *s21_strcpy(char *dest, const char *src) {
  char *p = dest;
  s21_size_t i;
  if ((dest != s21_NULL) && (src != s21_NULL)) {
    for (i = 0; src[i] != '\0'; i++) dest[i] = src[i];
    dest[i] = '\0';
  } else {
    p = s21_NULL;
  }
  return p;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *flag = dest;
  unsigned int i = 0;
  if ((dest != s21_NULL) && (src != s21_NULL)) {
    for (i = 0; src[i] != '\0' && i < n; i++) {
      dest[i] = src[i];
    }
    dest[i] = '\0';
  } else {
    flag = s21_NULL;
  }
  return flag;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *temp;
  size_t x = 0;
  size_t size = 0;
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
    while (*str1 != '\0') {
      for (temp = str2; *temp != '\0'; temp++) {
        if (*str1 == *temp) {
          x = size;
          break;
        }
      }
      if (*str1 == *temp) {
        break;
      }
      size++;
      str1++;
      x++;
    }
  }
  return x;
}

char *s21_strerror(int errnum) {
  char *resnum[] = S21_ERRLIST;
  int n = sizeof(resnum) / sizeof(resnum[0]);
  static char res[100] = "";
  if (errnum >= 0 && errnum < n) {
    s21_memmove(res, resnum[errnum], 100);
  } else {
    char ebuf[100] = UNK_ERR;
    char buf[100] = "\0";
    s21_itoa(errnum, BASE, buf);
    s21_strcat(ebuf, buf);
    s21_memmove(res, ebuf, 100);
  }
  return res;
}

char *s21_convert(unsigned int num, int base) {
  const char Representation[] = "0123456789ABCDEF";
  static char buffer[50];
  char *ptr;
  ptr = &buffer[49];
  *ptr = '\0';
  do {
    *--ptr = Representation[num % base];
    num /= base;
  } while (num != 0);
  return ptr;
}

void s21_itoa(int n, int base, char *buf) {
  char *str;
  if (n < 0) {
    n = -n;
    *buf = '-';
    buf++;
  }
  str = s21_convert(n, base);
  while (*str != '\0') {
    *buf = *str;
    str++;
    buf++;
  }
  *buf = '\0';
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  s21_size_t i;
  for (i = 0; i != 4294967295 && str[i] != '\0'; i++) length = i + 1;
  return length;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int len = 0, i;
  char *res = s21_NULL;
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
    while (str1[len] != '\0') len++;
    i = len - 1;
    while (i >= 0) {
      for (int j = 0; str2[j] != '\0'; j++) {
        if (str1[i] == str2[j]) res = (char *)&str1[i];
      }
      i--;
    }
  }
  return res;
}

char *s21_strrchr(const char *str, int c) {
  s21_size_t strlen = s21_strlen(str);
  char *res = s21_NULL;

  for (s21_size_t i = 0; i < strlen + 1; i++) {
    if (str[i] == c) {
      res = (char *)&str[i];
    }
  }
  return res;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  size_t x = 0;
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {
    for (x = 0; str1[x] != '\0'; x++) {
      int fl = 0;
      for (int i = 0; str2[i] != '\0'; i++) {
        if (str1[x] == str2[i]) {
          fl++;
        }
      }
      if (fl == 0) break;
    }
  }
  return x;
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t lens1, lens2;
  lens2 = s21_strlen(needle);
  if (!lens2) {
    return (char *)haystack;
  }
  lens1 = s21_strlen(haystack);
  while (lens1 >= lens2) {
    lens1--;
    if (!s21_memcmp(haystack, needle, lens2)) {
      return (char *)haystack;
    }
    haystack++;
  }
  return s21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
  static char *str_temp = NULL;
  char *str_out;
  if (str != NULL) {
    str_temp = str;
    str_out = str;
  } else {
    str_out = str_temp;
    if (str_temp != NULL) {
      str_temp = str_temp + 1;
    }
  }
  if (str_temp != NULL) {
    char *buf_ptr = s21_strpbrk(str_temp, delim);
    if ((buf_ptr != NULL) || (*str_temp == 0)) {
      str_temp = buf_ptr;
    }
  }
  if (str_temp != NULL) {
    while ((s21_strchr(delim, *str_temp) != NULL) && (*str_temp != 0)) {
      *str_temp = 0;
      str_temp = str_temp + 1;
    }
    if ((s21_strchr(delim, *str_out) != NULL)) {
      if (*str_temp != 0) {
        str_out = str_temp;
      } else {
        str_out = NULL;
      }
    }
  } else {
    str_out = str_temp;
  }
  return str_out;
}

void *s21_to_upper(const char *str) {
  char *str2 = s21_NULL;
  if (str) {
    str2 = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
    if (str2) {
      s21_strcpy(str2, str);
      for (char *temp = str2; *temp; temp++) {
        if (*temp >= 'a' && *temp <= 'z') {
          *temp -= 32;
        }
      }
    }
  }
  return (void *)str2;
}

void *s21_to_lower(const char *str) {
  char *str2 = s21_NULL;
  int len = 0;
  if (str) {
    while (str[len] != '\0') len++;
    str2 = (char *)malloc((len + 1) * sizeof(char));
    if (str2) {
      s21_strncpy(str2, str, len + 1);
      for (char *temp = str2; *temp; temp++) {
        if (*temp >= 'A' && *temp <= 'Z') {
          *temp += 32;
        }
      }
    }
  }
  return (void *)str2;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *pointer = s21_NULL;
  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t src_length = s21_strlen(src);
    s21_size_t str_length = s21_strlen(str);
    s21_size_t memory_size = src_length + str_length + 1;
    if (start_index <= src_length) {
      pointer = calloc(memory_size, sizeof(char));
      if (pointer != s21_NULL) {
        for (s21_size_t i = 0; i < start_index; i++) {
          pointer[i] = src[i];
        }
        for (s21_size_t i = 0; i < str_length; i++) {
          pointer[i + start_index] = str[i];
        }
        for (s21_size_t i = 0; i < src_length - start_index; i++) {
          pointer[i + start_index + str_length] = src[i + start_index];
        }
        pointer[memory_size - 1] = '\0';
      }
    }
  }
  return pointer;
}

s21_size_t s21_trim_strspn_reverse(const char *str1, const char *str2) {
  s21_size_t str1len = s21_strlen(str1);
  s21_size_t str2len = s21_strlen(str2);
  int is_continue = 0;
  int res = 0;

  for (int i = (int)str1len - 1; i > -1 && is_continue == 0; i--) {
    int inner_res = 0;

    for (s21_size_t j = 0; j < str2len && inner_res == 0; j++) {
      if (str1[i] == str2[j]) {
        inner_res++;
      }
    }

    if (inner_res == 0) {
      is_continue++;
      res--;
    }

    res++;
  }

  return res;
}
void *s21_trim(const char *src, const char *trim_chars) {
  int i = 0;
  const char *start_position;
  const char *end_position;
  int src_size = s21_strlen(src);
  while ((s21_strchr(trim_chars, *(src + i)) != NULL) && (src_size > i)) {
    i++;
  }
  start_position = (const char *)(src + i);
  while ((s21_strchr(trim_chars, *(src + src_size - 1)) != NULL) &&
         (src_size > 1)) {
    src_size--;
  }
  end_position = src + src_size;
  char *new_str;
  if (end_position > start_position) {
    src_size = src_size - i;
  } else {
    src_size = 1;
  }
  new_str = calloc(src_size, sizeof(char));
  if (new_str != NULL) {
    s21_strncpy(new_str, start_position, src_size);
  }
  return new_str;
}
