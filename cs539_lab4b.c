/*
        Stone, Spencer
        11/10/18
        Lab 4B
        Description:
        Compile: gcc main.c -O2 -Wall -Werror -std=gnu11 -o main
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define VALID_INPUT(x) ((x >= 'A' && x <= 'Z') || x == '\n' || x == '\0')

char *generate_s1(void);
char *generate_s2(char *c);
char *strfilter(char s1[], char s2[], char c);
size_t _strlen(char str[]);

int main(void) {
  char c;

  char *s1 = generate_s1();
  char *s2 = generate_s2(&c);
  char *fs1 = strfilter(s1, s2, c);

  printf("s1          = {\"%s\"}\n", s1);
  printf("s2          = {\"%s\"}\n", s2);
  printf("c           = {\"%c\"}\n", c);
  printf("filtered s1 = {\"%s\"}\n", fs1);

  return 1;
}

char *generate_s1(void) {
  static char str[41];
  /* seed rand() so it produces unique results each run
     cast to unsigned int to avoid compiler warning */
  srand((unsigned int)time(NULL));
  for (size_t i = 0; i < 40; i++) {
    /* return random number between [0, 26] then
       rebase integer by adding 65, putting it between [A, Z] */
    str[i] = (rand() / ((RAND_MAX / 26) + 1)) + 65;
  }
  /* finalize the string a with null terminator */
  str[40] = '\0';

  return str;
}

char *generate_s2(char *c) {
  static char str[23];
  size_t len;
  size_t i;
  bool done = false;
  int ch;

  while (!done) {
    /* get s2 from user then clear stdin */
    printf("Enter uppercase characters [A, Z]: ");
    char *ret = fgets(str, sizeof str, stdin);
    if (ret == NULL) {
      exit(EXIT_FAILURE);
    }
    fseek(stdin, 0, SEEK_END);
    /* find newline character and replace it with null terminator */
    for (i = 0; i < sizeof str; i++) {
      if (str[i] == '\n') {
        str[i] = '\0';
      }
    }
    /* check if string meets requirements:
       minimum 2 chars, max 20 chars, [A-Z] */
    len = _strlen(str);
    i = 0;
    while (!done) {
      if (len < 2 || len > 20) {
        printf("String length must be bewtween [2, 20]\n");
        break;
      } else if (!VALID_INPUT(str[i])) {
        printf("String must contain uppercase letters [A-Z]\n");
        break;
      } else if (i == len) {
        done = true;
        break;
      }
      i++;
    }
  }

  printf("Enter replacement character: ");
  ch = getchar();
  *c = ch;
  return str;
}

char *strfilter(char s1[], char s2[], char c) {
  static char str[41];
  size_t s1_len = _strlen(s1);
  size_t s2_len = _strlen(s2);

  /* copy contents of s1 into str */
  for (size_t i = 0; i < s1_len; i++) {
    str[i] = s1[i];
  }

  size_t str_len = _strlen(str);
  for (size_t i = 0; i < s2_len; i++) {
    for (size_t j = 0; j < str_len; j++) {
      if (s2[i] == str[j]) {
        str[j] = c;
      }
    }
  }

  return str;
}

size_t _strlen(char str[]) {
  size_t i = 0;
  while (str[i] != '\0')
    i++;
  return i;
}
