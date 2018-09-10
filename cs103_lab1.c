#include <stdio.h>
#include <math.h>

int is_valid_triangle(double a, double b, double c);
double calculate_area(double a, double b, double c);
void print_triangle_type(double a, double b, double c);
int clean_stdin();

int main(void) {
	/* variables (a, b, c) denote the length of a traingle's sides */
	double a, b, c;
	double area;
	char ch;
	char answer;
	int cont;

	for (;;) {
		printf("Enter 3 numbers: ");
		if ((scanf("%lf %lf %lf%c", &a, &b, &c, &ch) != 4 || ch != '\n') && clean_stdin()) {}
		/* validate user input */
		if (is_valid_triangle(a, b, c)) {
			/* print triangle area and type */
			area = calculate_area(a, b, c);
			printf("Triangle area: %4.3f\n", area);
			print_triangle_type(a, b, c);
			return 1;
		} else {
			/* handle invalid input parameters */
			printf("Invalid triangle geometry. Continue? (y/n) ");
			if ((scanf("%c%c", &answer, &ch) != 2 || ch != '\n') && clean_stdin()) {}
			cont = 0;
			while (cont != 1) {	
				switch(answer) {
					case 'y' : cont = 1; break;
					case 'Y' : cont = 1; break;
					case 'n' : return 0;
					case 'N' : return 0;
					default :
						printf("invalid selection\nContinue? (y/n) ");
						if ((scanf("%c%c", &answer, &ch) != 2 || ch != '\n') && clean_stdin()) {}
				}
			}
		}
	}

	return 1;
}

int is_valid_triangle(double a, double b, double c) {
	/* Triangle Inequality Theorem */
	if (!(a + b > c && a + c > b && b + c > a)) { 
		return 0;
	}
	/* No side may be less than or equal to zero */
	else if (a <= 0 || b <= 0 || c <= 0) { 
		return 0; 
	}

	return 1;
}

double calculate_area(double a, double b, double c) {
	/* s = half of perimeter */
	double s = (a + b + c) / 2.0;
	/* Heron's Formula */
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

void print_triangle_type(double a, double b, double c) {
	if (a == b && b == c) printf("Equilateral triangle\n");                    
	else if(a == b || a == c || b == c) printf("Isosceles triangle\n");
	else printf("Scalene triangle\n");
}

int clean_stdin() {
    while (getchar()!='\n');
    return 1;
}

/*
~$ gcc -Wall -Wextra -O2 main.c
~$ ./a
Enter 3 numbers: 1.41 1.41 1.41
Triangle area: 0.861
Equilateral triangle

~$ ./a
Enter 3 numbers: 5 8 4
Triangle area: 8.182
Scalene triangle

~$ ./a
Enter 3 numbers: 5 5 8
Triangle area: 12.000
Isosceles triangle

~$ ./a
Enter 3 numbers: -1 -1 -1
Invalid triangle geometry. Continue? (y/n) n

~$ ./a
Enter 3 numbers: -1 0 0
Invalid triangle geometry. Continue? (y/n) awd
invalid selection
Continue? (y/n) awd
invalid selection
Continue? (y/n) y
Enter 3 numbers: 1.41 1.41 1.41
Triangle area: 0.861
Equilateral triangle

~$ ./a
Enter 3 numbers: a b c
Invalid triangle geometry. Continue? (y/n) n
...
*/