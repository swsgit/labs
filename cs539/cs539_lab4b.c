/*
        Stone, Spencer
        11/10/18
        Lab 4B
        Description: Replace the contents of a string
                     with the contents of another string.
                     Using a replacement character.
        Compile: gcc main.c -O2 -Wall -Werror -std=gnu11 -o main
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VALID_INPUT(x) ((x >= 'A' && x <= 'Z') || x == '\n' || x == '\0')

void generate_s1(char s1[]);
void generate_s2(char s2[], char *c);
void strfilter(char fs1[], char s1[], char s2[], char c);
size_t _strlen(char str[]);

int main(void) {
  char c;
  char s1[41];
  char s2[23];
  char fs1[41];

  generate_s1(s1);

  for (;;) {
    generate_s2(s2, &c);
    strfilter(fs1, s1, s2, c);

    printf("s1          = {\"%s\"}\n", s1);
    printf("s2          = {\"%s\"}\n", s2);
    printf("c           = {\"%c\"}\n", c);
    printf("filtered s1 = {\"%s\"}\n", fs1);
  }

  return 1;
}

void generate_s1(char s1[]) {
  /* seed rand() so it produces unique results each run
     cast to unsigned int to avoid compiler warning */
  srand((unsigned int)time(NULL));
  for (int i = 0; i < 40; i++) {
    /* return random number between [M, N]
       M + rand() / (RAND_MAX / (N - M + 1) + 1) */
    s1[i] = 65 + rand() / (RAND_MAX / (90 - 65 + 1) + 1);
  }
  /* finalize the string a with null terminator */
  s1[40] = '\0';
}

void generate_s2(char s2[], char *c) {
  bool done = false;
  size_t len;
  size_t i;
  int ch;
  int count = 0;
  int old_ch = 0;

  while (!done) {
    /* get s2 from user then clear stdin */
    printf("Enter uppercase characters [A, Z]: ");
    char *ret = fgets(s2, 23, stdin);
    if (ret == NULL) {
      exit(EXIT_FAILURE);
    }
    fseek(stdin, 0, SEEK_END);
    /* find newline character and replace it with null terminator */
    for (i = 0; i < 23; i++) {
      if (s2[i] == '\n') {
        s2[i] = '\0';
      }
    }
    /* check if string meets requirements:
       minimum 2 chars, max 20 chars, [A-Z] */
    len = _strlen(s2);
    if (len < 2 || len > 20) {
      printf("String length must be bewtween [2, 20]\n");
      continue;
    }
    i = 0;
    while (!done) {
      if (!VALID_INPUT(s2[i])) {
        printf("String must contain uppercase letters [A-Z]\n");
        break;
      } else if (i == len) {
        done = true;
        break;
      }
      i++;
    }
  }

  /* get replacement character from stdin,
       replacement char must be a single char */
  done = false;
  printf("Enter replacement character: ");
  while (!done && (ch = getchar())) {
    if (count > 1) {
      fseek(stdin, 0, SEEK_END);
      printf("Replacement character must be a single character\n");
      printf("Enter replacement character: ");
      count = 0;
      old_ch = 0;
      continue;
    } else if (ch == '\n' && old_ch != '\n') {
      *c = old_ch;
      done = true;
    }
    count++;
    old_ch = ch;
  }
  fseek(stdin, 0, SEEK_END);
}

void strfilter(char fs1[], char s1[], char s2[], char c) {
  size_t s1_len = _strlen(s1);
  size_t s2_len = _strlen(s2);
  size_t fs1_len = s1_len;

  /* copy contents of s1 into fs1 */
  for (size_t i = 0; i < s1_len; i++) {
    fs1[i] = s1[i];
  }

  for (size_t i = 0; i < s2_len; i++) {
    for (size_t j = 0; j < fs1_len; j++) {
      if (fs1[j] == s2[i]) {
        fs1[j] = c;
      }
    }
  }
}

size_t _strlen(char str[]) {
  size_t i = 0;
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
----------------------------------------------------------------
Enter uppercase characters [A, Z]: ABC
Enter replacement character: ./
Replacement character must be a single character
Enter replacement character: .
s1          = {"LSCZMOOQQUOAKXHLJELCODQNFJNMBLVMGNXRSTQK"}
s2          = {"ABC"}
c           = {"."}
filtered s1 = {"LS.ZMOOQQUO.KXHLJEL.ODQNFJNM.LVMGNXRSTQK"}
Enter uppercase characters [A, Z]:
*/
