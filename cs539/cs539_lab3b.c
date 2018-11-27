/*
        Stone, Spencer
        Lab 3B
        10/15/18
        Description: A calculator that accepts input from user's stdin
        Compile: gcc main.c -Wall -Werror -Wextra -O2 -std=gnu11 -o main
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define IS_INT(x) (x >= 48 && x <= 57)
#define IS_ADD(x) (x == '+')
#define IS_SUB(x) (x == '-')
#define IS_MUL(x) (x == '*')
#define IS_DIV(x) (x == '/')
#define IS_MOD(x) (x == '%')
#define IS_NWL(x) (x == '\n')
#define IS_EOF(x) (x == EOF)
#define IS_OPR(x)                                                              \
  (IS_ADD(x) || IS_SUB(x) || IS_MUL(x) || IS_DIV(x) || IS_MOD(x))
#define IS_VAL(x) (IS_INT(x) || IS_OPR(x))

void reset(int *total, char *op, int *first_number, int *num);
char get_number(int *num);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int mod(int a, int b);

int main(void) {
  char op = 0;
  int num = 0;
  int total = 0;
  int first_number = 1;
  printf("calc> ");
  while (1) {
    if (IS_EOF(op)) {
      printf(" = %d\n", total);
      exit(EXIT_SUCCESS);
    } else if (IS_NWL(op)) {
      printf(" = %d\n", total);
      printf("calc> ");
      reset(&total, &op, &first_number, &num);
    } else if (IS_ADD(op)) {
      op = get_number(&num);
      printf("%d + %d", total, num);
      if (!IS_NWL(op)) {
        printf("\nInvalid syntax...\ncalc> ");
        reset(&total, &op, &first_number, &num);
        continue;
      }
      total = add(total, num);
      printf(" = %d\n", total);
      printf("calc> ");
      reset(&total, &op, &first_number, &num);
      continue;
    } else if (IS_SUB(op)) {
      op = get_number(&num);
      printf("%d - %d", total, num);
      if (!IS_NWL(op)) {
        printf("\nInvalid syntax...\ncalc> ");
        reset(&total, &op, &first_number, &num);
        continue;
      }
      total = subtract(total, num);
      printf(" = %d\n", total);
      printf("calc> ");
      reset(&total, &op, &first_number, &num);
    } else if (IS_MUL(op)) {
      op = get_number(&num);
      total = multiply(total, num);
      printf("%d * %d", total, num);
      if (!IS_NWL(op)) {
        printf("\nInvalid syntax...\ncalc> ");
        reset(&total, &op, &first_number, &num);
        continue;
      }
      printf(" = %d\n", total);
      printf("calc> ");
      reset(&total, &op, &first_number, &num);
    } else if (IS_DIV(op)) {
      op = get_number(&num);
      printf("%d / %d", total, num);
      if (!IS_NWL(op)) {
        printf("\nInvalid syntax...\ncalc> ");
        reset(&total, &op, &first_number, &num);
        continue;
      }
      total = divide(total, num);
      printf(" = %d\n", total);
      printf("calc> ");
      reset(&total, &op, &first_number, &num);
    } else if (IS_MOD(op)) {
      op = get_number(&num);
      printf("%d %% %d", total, num);
      if (!IS_NWL(op)) {
        printf("\nInvalid syntax...\ncalc> ");
        reset(&total, &op, &first_number, &num);
        continue;
      }
      total = mod(total, num);
      printf(" = %d\n", total);
      printf("calc> ");
      reset(&total, &op, &first_number, &num);
    } else {
      op = get_number(&num);
      if (first_number) {
        total = num;
        first_number = 0;
      }
    }
  }
  return 1;
}

char get_number(int *num) {
  int first_run = 1;
  char ch;
  int tmp;
  *num = 0;
  while ((ch = getchar()) != EOF) {
    if (IS_NWL(ch)) {
      return ch;
    }
    if (IS_OPR(ch)) {
      return ch;
    }
    if (!IS_VAL(ch)) {
      continue;
    }
    if (first_run) {
      tmp = ch - '0';
      *num = tmp;
      first_run = 0;
      continue;
    }
    if (!first_run) {
      tmp = ch - '0';
      *num = multiply(*num, 10);
      *num = add(*num, tmp);
      continue;
    }
  }
  return ch;
}

void reset(int *total, char *op, int *first_number, int *num) {
  fseek(stdin, 0, SEEK_END);
  *total = 0;
  *op = 0;
  *first_number = 1;
  *num = 0;
}

int add(int a, int b) {
  if ((b > 0) && (a > INT_MAX - b)) {
    printf("\nError: integer overflow (%d + %d)\n", a, b);
  } else if ((b < 0) && (a < INT_MIN - b)) {
    printf("\nError: integer underflow (%d + %d)\n", a, b);
  }
  return a + b;
}
int subtract(int a, int b) {
  if ((b < 0) && (a > INT_MAX + b)) {
    printf("\nError: integer overflow (%d - %d)\n", a, b);
  } else if ((b > 0) && (a < INT_MIN + b)) {
    printf("\nError: integer underflow (%d - %d)\n", a, b);
  }
  return a - b;
}
int multiply(int a, int b) {
  if (a > INT_MAX / b) {
    printf("\nError: integer overflow (%d * %d)\n", a, b);
  } else if (a < INT_MIN / b) {
    printf("\nError: integer underflow (%d * %d)\n", a, b);
  } else if ((a == -1) && (b == INT_MIN)) {
    printf("\nError: possible integer overflow (%d * %d)\n", a, b);
  } else if ((b == -1) && (a == INT_MIN)) {
    printf("\nError: possible integer overflow (%d * %d)\n", a, b);
  }
  return a * b;
}
int divide(int a, int b) {
  if (b == 0) {
    printf("\nError: cannot divide by zero (%d / %d)", a, b);
    return 0;
  } else if ((a == -1) && (b == INT_MIN)) {
    printf("\nError: possible integer overflow (%d / %d)\n", a, b);
  } else if ((b == -1) && (a == INT_MIN)) {
    printf("\nError: possible integer overflow (%d / %d)\n", a, b);
  }
  return a / b;
}
int mod(int a, int b) {
  if (b == 0) {
    printf("\nError: cannot do modulo division by zero (%d %% %d)", a, b);
    return 0;
  }
  return a % b;
}
/*
# ./main
calc> 100 - 1
100 - 1 = 99
calc> 100 + 1
100 + 1 = 101
calc> 100 * 10
1000 * 10 = 1000
calc> 1000 / 10
1000 / 10 = 100
calc> 1001 % 10
1001 % 10 = 1
calc> 10 / 0
10 / 0
Error: cannot divide by zero (10 / 0) = 0
calc> 10 % 0
10 % 0
Error: cannot do modulo division by zero (10 % 0)= 0
calc> 10000000 * 100000000
Error: integer overflow (10000000 * 100000000)
-1530494976 * 100000000 = -1530494976
calc> 10 + 10 + 10
10 + 10
Invalid syntax...
calc> 10 - 10 - 10
10 - 10
Invalid syntax...
calc> -10
0 - 10 = -10
calc> +10
0 + 10 = 10
calc>
*/
