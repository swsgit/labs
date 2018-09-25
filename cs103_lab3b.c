/*
	Stone, Spencer
	Lab 3B
	10/15/18
	Description: A calculator that accepts input from user's stdin
	Compile: gcc main.c -Wall -Werror -std=gnu11 -o main
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define IS_INT(x) (x >= 48 && x <= 57)
#define IS_ADD(x) (x == '+')
#define IS_SUB(x) (x == '-')
#define IS_MUL(x) (x == '*')
#define IS_DIV(x) (x == '/')
#define IS_MOD(x) (x == '%')
#define IS_NWL(x) (x == '\n')
#define IS_OPR(x) (IS_ADD(x) || IS_SUB(x) || IS_MUL(x) || IS_DIV(x) || IS_MOD(x))
#define IS_VAL(x) (IS_INT(x) || IS_OPR(x))

int8_t get_number(int32_t *num);
int32_t add(int32_t a, int32_t b);
int32_t subtract(int32_t a, int32_t b);
int32_t multiply(int32_t a, int32_t b);
int32_t divide(int32_t a, int32_t b);
int32_t mod(int32_t a, int32_t b);

int main(void) {
	int8_t op = 0;
	int32_t num = 0;
	int32_t total = 0;
	int32_t first_number = 1;
	printf("Enter numbers: ");
	while (1) {
		if (IS_NWL(op)) {
			printf(" = %"PRIi32"\n", total);
			printf("Enter numbers: ");
			total = 0;
			op = 0;
			first_number = 1;
		} 
		else if (IS_ADD(op)) { op = get_number(&num); total = add(total, num); } 
		else if (IS_SUB(op)) { op = get_number(&num); total = subtract(total, num); } 
		else if (IS_MUL(op)) { op = get_number(&num); total = multiply(total, num); } 
		else if (IS_DIV(op)) { op = get_number(&num); total = divide(total, num); }
		else if (IS_MOD(op)) { op = get_number(&num); total = mod(total, num); } 
		else {
			op = get_number(&num);
			if (first_number) {
				total = num;
				first_number = 0;
			}
		}
	}
	return 1;
}

int8_t get_number(int32_t *num) {
	int32_t first_run = 1;
	int8_t ch;
	int32_t tmp;
	*num = 0;
	while ((ch = getchar())) {
		if (IS_NWL(ch)) { return ch; }
		if (IS_OPR(ch)) { putchar(ch); return ch; }
		if (!IS_VAL(ch)) { putchar(ch); continue; }
		putchar(ch);
		if (first_run) {
			tmp = ch - '0';
			*num = tmp;
			first_run = 0;
			continue;
		}
		if(!first_run) {
			tmp = ch - '0';
			*num = multiply(*num, 10);
			*num = add(*num, tmp);
			continue;
		}
	}
	return ch;
}

int32_t add(int32_t a, int32_t b) {
	if ((b > 0) && (a > INT32_MAX - b)) {
		printf("\nError: integer overflow (%d + %d)\n", a, b);
		exit(EXIT_FAILURE);
	} else if ((b < 0) && (a < INT32_MIN - b)) {
		printf("\nError: integer underflow (%d + %d)\n", a, b);
		exit(EXIT_FAILURE);
	} else { return a + b; }
}
int32_t subtract(int32_t a, int32_t b) {
	if ((b < 0) && (a > INT32_MAX + b)) {
		printf("\nError: integer overflow (%d - %d)\n", a, b);
		exit(EXIT_FAILURE);
	} else if ((b > 0) && (a < INT32_MIN + b)) {
		printf("\nError: integer underflow (%d - %d)\n", a, b);
		exit(EXIT_FAILURE);
	} else { return a - b; }
}
int32_t multiply(int32_t a, int32_t b) {
	if (a > INT32_MAX / b) {
		printf("\nError: integer overflow (%d * %d)\n", a, b);
		exit(EXIT_FAILURE);
	} else if (a < INT32_MIN / b) {
		printf("\nError: integer underflow (%d * %d)\n", a, b);
		exit(EXIT_FAILURE);
	} else if ((a == -1) && (b == INT32_MIN)) {
		printf("\nError: possible integer overflow (%d * %d)\n", a, b);
		exit(EXIT_FAILURE);
	} else if ((b == -1) && (a == INT32_MIN)) {
		printf("\nError: possible integer overflow (%d * %d)\n", a, b);
		exit(EXIT_FAILURE);
	} else { return a * b; }
}
int32_t divide(int32_t a, int32_t b) { 
	if (b == 0) {
		printf("\nError: cannot divide by zero (%d / %d)", a, b);
		exit(EXIT_FAILURE);
	} else if ((a == -1) && (b == INT32_MIN)) {
		printf("\nError: possible integer overflow (%d / %d)\n", a, b);
		exit(EXIT_FAILURE);
	} else if ((b == -1) && (a == INT32_MIN)) {
		printf("\nError: possible integer overflow (%d / %d)\n", a, b);
		exit(EXIT_FAILURE);
	} else { return a / b; }
}
int32_t mod(int32_t a, int32_t b) { return a % b; }
/*
Enter numbers: 10 + 2
10 + 2 = 12
Enter numbers: 230 - 4 / 6
230 - 4 / 6 = 37
Enter numbers: 10 % 3
10 % 3 = 1
Enter numbers: 10 * 10 / 10 % 10
10 * 10 / 10 % 10 = 0
Enter numbers: 5 / 10 / 0
5 / 10 / 0
Error: cannot divide by zero (0 / 0)
Enter numbers: 5 + -3
5 + -3 = 2
Enter numbers: 121323 * 232323
121323 * 232323
Error: integer overflow (121323 * 232323)
Enter numbers: -20000000 * 200
-20000000 * 200
Error: integer underflow (-20000000 * 200)
*/