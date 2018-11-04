/*
Stone, Spencer
Lab 2B
10/1/18
*/
#include <stdio.h>
#include <stdlib.h>

#define IN_RANGE(x) ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))

int main(void) {
	int ch;
	int old_ch = 0;
	while ((ch = getchar()) != EOF) {
		/* [A-Z] = [65, 90] 
		   [a-z] = [97, 122] 
		*/
		if (IN_RANGE(ch)) {
			putchar(ch);
		} else if (!IN_RANGE(ch) && IN_RANGE(old_ch)) {
			putchar('\n');
		}
		old_ch = ch;
	}
	return 1;
}
/*
lab2b_poem.txt:
	The Parsnip


The parsnip, children, I repeat,
Is simply an anemic beet.
Some people call the parsnip edible;
Myself, I find this 	claim incredible.
--------------------------------------------
>a.exe < lab2b_poem.txt
The
Parsnip
The
parsnip
children
I
repeat
Is
simply
an
anemic
beet
Some
people
call
the
parsnip
edible
Myself
I
find
this
claim
incredible
*/
