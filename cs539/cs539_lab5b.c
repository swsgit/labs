/*
        Stone, Spencer
        11/10/18
        Lab 5B
        Description: Replace the contents of a string
                     with the contents of another string.
                     Using a replacement character.
        Compile: gcc main.c -O2 -Wall -Werror -std=gnu11 -o main
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define VALID_INPUT(x) ((x >= 'A' && x <= 'Z') || x == '\0')

void generate_s1(char *s1);
void generate_s2(char *s2, char *c);
void strfilter(char *fs1, char *s1, char *s2, char c);
size_t _strlen(char *str);

int main(void) {
  char c;
  char *s1 = calloc(41, sizeof(*s1));
  char *s2 = calloc(23, sizeof(*s2));

  generate_s1(s1);

  for (;;) {
    generate_s2(s2, &c);

    char *fs1 = calloc(41, sizeof(*fs1));
    strfilter(fs1, s1, s2, c);

    printf("s1          = {\"%s\"}\n", s1);
    printf("s2          = {\"%s\"}\n", s2);
    printf("c           = {\"%c\"}\n", c);
    printf("filtered s1 = {\"%s\"}\n", fs1);
    free(fs1);
  }
  free(s1);
  free(s2);

  return 1;
}

void generate_s1(char *s1) {
  /* seed rand() so it produces unique results each run,
     cast to unsigned int to avoid compiler warning */
  srand((unsigned int)time(NULL));
  for (int i = 0; i < 40; i++, s1++) {
    /* return random number between [M, N]
       M + rand() / (RAND_MAX / (N - M + 1) + 1) */
    *s1 = 65 + rand() / (RAND_MAX / (90 - 65 + 1) + 1);
  }
  /* finalize the string a with null terminator */
  *s1 = '\0';
}

void generate_s2(char *s2, char *c) {
  char *s2_start = s2;
  bool done = false;
  size_t s2_len;
  size_t i;
  int ch;
  int old_ch = '\n';
  int count = 0;

  while (!done) {
    /* get s2 from the user and store its
       length in s2_len then clear stdin */
    printf("Enter uppercase characters [A, Z]: ");
    char *ret = fgets(s2, 23, stdin);
    if (ret == NULL) {
      exit(EXIT_FAILURE);
    }
    fseek(stdin, 0, SEEK_END);
    s2_len = _strlen(s2);

    /* find the newline character and replace it with null terminator */
    for (i = 0; i < s2_len; i++, s2++) {
      if (*s2 == '\n') {
        *s2 = '\0';
      }
    }
    /* shift s2 back to the start of the array */
    s2 = s2_start;

    /* check if string meets requirements:
       minimum 2 chars, max 20 chars, [A-Z] */
    s2_len = _strlen(s2);
    if (s2_len < 2 || s2_len > 20) {
      printf("String length must be bewtween [2, 20]\n");
      s2 = s2_start;
      continue;
    }
    i = 0;
    while (!done) {
      if (!VALID_INPUT(*s2)) {
        printf("String must contain uppercase letters [A-Z]\n");
        break;
      } else if (i == s2_len) {
        done = true;
        break;
      }
      s2++;
      i++;
    }
    /* shift s2 to the start of the
       array incase input was invalid */
    s2 = s2_start;
  }

  /* get replacement character from stdin,
     replacement char must be a single char */
  done = false;
  printf("Enter replacement character: ");
  while (!done && (ch = getchar())) {
    if (count > 1) {
      printf("Replacement character must be a single character\n");
      printf("Enter replacement character: ");
      fseek(stdin, 0, SEEK_END);
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

void strfilter(char *fs1, char *s1, char *s2, char c) {
  char *fs1_start = fs1;
  char *s1_start = s1;
  size_t s1_len = _strlen(s1);
  size_t s2_len = _strlen(s2);
  size_t fs1_len = s1_len;

  /* copy contents of s1 into fs1 */
  for (size_t i = 0; i < s1_len; i++, s1++, fs1++) {
    *fs1 = *s1;
  }
  /* shift fs1 and s1 to start of array */
  fs1 = fs1_start;
  s1 = s1_start;

  /* find elements of s2 in fs1 then
     replace elements found with c */
  for (size_t i = 0; i < s2_len; i++, s2++) {
    for (size_t j = 0; j < fs1_len; j++, fs1++) {
      if (*fs1 == *s2) {
        *fs1 = c;
      }
    }
    /* shift fs1 to start of array after every
       full loop of its contents */
    fs1 = fs1_start;
  }
  fs1 = fs1_start;
}

size_t _strlen(char *str) {
  char *ptr = str;
  while (*ptr != '\0') {
    ptr++;
  }
  /* subtract the start of the memory address of str
     from the address that stores '\0' in str
     to obtain its length as a string. 
     Example: 
         str           = 0x0001
         str+5         = 0x0006 ('\0' is stored at 0x0006)
        (str+5) - str  = 0x0005 ((int)0x0005 == 5) */
  return ptr - str;
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
