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
int _strlen(char str[]);

int main(void) {
  char c;
  char *s1 = generate_s1();

  for (;;) {
    char *s2 = generate_s2(&c);
    char *fs1 = strfilter(s1, s2, c);

    printf("s1          = {\"%s\"}\n", s1);
    printf("s2          = {\"%s\"}\n", s2);
    printf("c           = {\"%c\"}\n", c);
    printf("filtered s1 = {\"%s\"}\n", fs1);
  }

  return 1;
}

char *generate_s1(void) {
  static char s1[41];
  /* seed rand() so it produces unique results each run
     cast to unsigned int to avoid compiler warning */
  srand((unsigned int)time(NULL));
  for (int i = 0; i < 40; i++) {
    /* return random number between [0, 26] then
       rebase integer by adding 65, putting it between [A, Z] */
    s1[i] = (rand() / ((RAND_MAX / 26) + 1)) + 65;
  }
  /* finalize the string a with null terminator */
  s1[40] = '\0';

  return s1;
}

char *generate_s2(char *c) {
  static char s2[23];
  bool done = false;
  int len;
  int i;
  int ch;

  while (!done) {
    /* get s2 from user then clear stdin */
    printf("Enter uppercase characters [A, Z]: ");
    char *ret = fgets(s2, sizeof s2, stdin);
    if (ret == NULL) {
      exit(EXIT_FAILURE);
    }
    fseek(stdin, 0, SEEK_END);
    /* find newline character and replace it with null terminator */
    for (i = 0; i < sizeof s2; i++) {
      if (s2[i] == '\n') {
        s2[i] = '\0';
      }
    }
    /* check if string meets requirements:
       minimum 2 chars, max 20 chars, [A-Z] */
    len = _strlen(s2);
    i = 0;
    while (!done) {
      if (len < 2 || len > 20) {
        printf("String length must be bewtween [2, 20]\n");
        break;
      } else if (!VALID_INPUT(s2[i])) {
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
  fseek(stdin, 0, SEEK_END);
  *c = ch;
  return s2;
}

char *strfilter(char s1[], char s2[], char c) {
  static char fs1[41];
  int s1_len = _strlen(s1);
  int s2_len = _strlen(s2);
  int fs1_len;

  /* copy contents of s1 into str */
  for (int i = 0; i < s1_len; i++) {
    fs1[i] = s1[i];
  }

  fs1_len = _strlen(fs1);
  for (int i = 0; i < s2_len; i++) {
    for (int j = 0; j < fs1_len; j++) {
      if (fs1[j] == s2[i]) {
        fs1[j] = c;
      }
    }
  }

  return fs1;
}

int _strlen(char str[]) {
  int i = 0;
  while (str[i] != '\0')
    i++;
  return i;
}
/*
Enter uppercase characters [A, Z]:
String length must be bewtween [2, 20]
Enter uppercase characters [A, Z]: test
String must contain uppercase letters [A-Z]
Enter uppercase characters [A, Z]: A
String length must be bewtween [2, 20]
Enter uppercase characters [A, Z]: AAAAAAAAAAAAAAAAAAAAAAAAA
String length must be bewtween [2, 20]
Enter uppercase characters [A, Z]: AL
Enter replacement character: *
s1          = {"OGXEKOMNDYZCILLTADZPMLRFTHJSKRRNRDLFLCFR"}
s2          = {"AL"}
c           = {"*"}
filtered s1 = {"OGXEKOMNDYZCI**T*DZPM*RFTHJSKRRNRD*F*CFR"}
Enter uppercase characters [A, Z]: TEST
Enter replacement character: .
s1          = {"OGXEKOMNDYZCILLTADZPMLRFTHJSKRRNRDLFLCFR"}
s2          = {"TEST"}
c           = {"."}
filtered s1 = {"OGX.KOMNDYZCILL.ADZPMLRF.HJ.KRRNRDLFLCFR"}
Enter uppercase characters [A, Z]:
*/
