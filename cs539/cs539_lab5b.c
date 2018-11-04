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

char *generate_s1(void);
char *generate_s2(char *c);
char *strfilter(char *s1, char *s2, char c);
int _strlen(char *str);

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
  char *ptr = s1;
  /* seed rand() so it produces unique results each run,
     cast to unsigned int to avoid compiler warning */
  srand((unsigned int)time(NULL));
  for (int i = 0; i < 40; i++, ptr++) {
    /* return random number between [M, N]
       M + rand() / (RAND_MAX / (N - M + 1) + 1) */
    *ptr = 65 + rand() / (RAND_MAX / (90 - 65 + 1) + 1);
  }
  /* finalize the string a with null terminator */
  *ptr = '\0';

  return s1;
}

char *generate_s2(char *c) {
  static char s2[23];
  char *ptr = s2;
  char *ptr_start = s2;
  bool done = false;
  int s2_len;
  int i;
  int ch;
  int old_ch = '\n';
  int count = 0;

  while (!done) {
    /* get s2 from the user and store its
       length in s2_len then clear stdin */
    printf("Enter uppercase characters [A, Z]: ");
    char *ret = fgets(s2, sizeof s2, stdin);
    if (ret == NULL) {
      exit(EXIT_FAILURE);
    }
    fseek(stdin, 0, SEEK_END);
    s2_len = _strlen(s2);

    /* find the newline character and replace it with null terminator */
    for (i = 0; i < s2_len; i++, ptr++) {
      if (*ptr == '\n') {
        *ptr = '\0';
      }
    }
    /* shift ptr back to the start of the array */
    ptr = ptr_start;

    /* check if string meets requirements:
       minimum 2 chars, max 20 chars, [A-Z] */
    s2_len = _strlen(s2);
    if (s2_len < 2 || s2_len > 20) {
      printf("String length must be bewtween [2, 20]\n");
      ptr = ptr_start;
      continue;
    }
    i = 0;
    while (!done) {
      if (!VALID_INPUT(*ptr)) {
        printf("String must contain uppercase letters [A-Z]\n");
        break;
      } else if (i == s2_len) {
        done = true;
        break;
      }
      ptr++;
      i++;
    }
    /* shift ptr to the start of the
       array incase input was invalid */
    ptr = ptr_start;
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

  return s2;
}

char *strfilter(char *s1, char *s2, char c) {
  static char fs1[41];
  char *fs1_ptr = fs1;
  char *s1_ptr = s1;
  char *s2_ptr = s2;
  char *fs1_ptr_start = fs1;
  char *s1_ptr_start = s1;
  int s1_len = _strlen(s1);
  int s2_len = _strlen(s2);
  int fs1_len = s1_len;

  /* copy contents of s1 into fs1 */
  for (int i = 0; i < s1_len; i++, s1_ptr++, fs1_ptr++) {
    *fs1_ptr = *s1_ptr;
  }
  /* shift fs1_ptr and s1_ptr to start of array */
  fs1_ptr = fs1_ptr_start;
  s1_ptr = s1_ptr_start;

  /* find elements of s2 in fs1 then
     replace elements found with c */
  for (int i = 0; i < s2_len; i++, s2_ptr++) {
    for (int j = 0; j < fs1_len; j++, fs1_ptr++) {
      if (*fs1_ptr == *s2_ptr) {
        *fs1_ptr = c;
      }
    }
    /* shift fs1_ptr to start of array after every
       full loop of its contents */
    fs1_ptr = fs1_ptr_start;
  }

  return fs1;
}

int _strlen(char *str) {
  char *ptr = str;
  while (*ptr != '\0') {
    ptr++;
  }
  /* subtract the start of the memory address of str
     from the adress that stores '\0' in str
     to obtain its length as a string. 
     Example: 
         str           = 0x0001
         str+5         = 0x0006 ('\0' is stored at 0x0006)
        (str+5) - str  = 0x0005 ((int)"\x05" == 5) */
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
