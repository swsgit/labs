/*
        Stone, Spencer
        11/26/18
        Lab 6B & 7B
        Description: Sort a list of contacts by zip code
                     in ascending order.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTACTS 50
#define MAX_BUF 50

typedef struct {
  char name[MAX_BUF];
  char address[MAX_BUF];
  char locale[MAX_BUF];
  unsigned int zip;
} contact;

contact **alloc_contacts(size_t n);
size_t get_contacts(contact **c);
void print_contacts(contact **c, size_t size);
void sort_contacts(contact **c, size_t n);
void swap(contact *a, contact *b);
void free_alloc(contact **c, size_t size);

int main(void) {
  size_t size;
  contact **c = alloc_contacts(MAX_CONTACTS);
  size = get_contacts(c);
  if (size == 0)
    perror("get_contacts failed");
  sort_contacts(c, size);
  print_contacts(c, size);
  free_alloc(c, size);

  return 1;
}

/* Allocate space for n number of contacts.
   Then return a pointer to the array */
contact **alloc_contacts(size_t n) {
  contact **c = malloc(n * sizeof(contact *));
  if (c == NULL)
    perror("Malloc failed");

  return c;
}

/* Populate contact array with values from stdin */
size_t get_contacts(contact **c) {
  char zip[64];
  size_t size = 0;
  for (size_t i = 0; i < MAX_CONTACTS; i++, size++) {
    /* allocate contact struct as needed */
    c[i] = malloc(sizeof(contact));
    if (c[i] == NULL)
      perror("Malloc failed");
    fgets(c[i]->name, MAX_BUF, stdin);
    fgets(c[i]->address, MAX_BUF, stdin);
    fgets(c[i]->locale, MAX_BUF, stdin);
    fgets(zip, sizeof(zip), stdin);
    c[i]->zip = atoi(zip);
    /* if EOF reached, break loop to avoid more allocs */
    if (feof(stdin))
      break;
  }

  return c ? size : 0;
}

void swap(contact *a, contact *b) {
  contact temp = *b;
  *b = *a;
  *a = temp;
}

/* Bubble sort O(n^2) */
void sort_contacts(contact **c, size_t n) {
  int i, j = n, s = 1;
  while (s) {
    s = 0;
    for (i = 1; i < j; i++) {
      if (c[i]->zip < c[i - 1]->zip) {
        swap(c[i], c[i - 1]);
        s = 1;
      }
    }
    j--;
  }
}

/* Loop over contact array printing each contact element */
void print_contacts(contact **c, size_t size) {
  for (size_t i = 0; i < size; i++)
    printf("%s%s%s%d\n", c[i]->name, c[i]->address, c[i]->locale, c[i]->zip);
}

void free_alloc(contact **c, size_t size) {
  for (size_t i = 0; i < size; i++) {
    free(c[i]);
  }
  free(c);
}

/*
cs539> cs539_lab6b_7b.exe < address.txt > address_sorted.txt
--------------------- address.txt ---------------------
A1, A2
20294 Lorenzana Dr
Woodland Hills, CA
91364
B1, B2
19831 Henshaw St
Culver City, CA
94023
C1, C2
5142 Dumont Pl
Azusa, CA
91112
D1, D2
20636 De Forest St
Woodland Hills, CA
91364
A1, A2
20294 Lorenzana Dr
Woodland Hills, CA
91364
E1, E2
4851 Poe Ave
Woodland Hills, CA
91364
F1, F2
20225 Lorenzana Dr
Los Angeles, CA
91111
G1, G2
20253 Lorenzana Dr
Los Angeles, CA
90005
H1, H2
5241 Del Moreno Dr
Los Angeles, CA
91110
I1, I2
5332 Felice Pl
Stevenson Ranch, CA
94135
J1, J2
5135 Quakertown Ave
Thousand Oaks, CA
91362
K1, K2
720 Eucalyptus Ave 105
Inglewood, CA
89030
L1, L2
5021 Dumont Pl
Woodland Hills, CA
91364
M1, M2
4819 Quedo Pl
Westlake Village, CA
91362
I1, I2
5332 Felice Pl
Stevenson Ranch, CA
94135
I1, I2
5332 Felice Pl
Stevenson Ranch, CA
94135
N1, N2
20044 Wells Dr
Beverly Hills, CA
90210
O1, O2
7659 Mckinley Ave
Los Angeles, CA
90001
------------------ address_sorted.txt -----------------
K1, K2
720 Eucalyptus Ave 105
Inglewood, CA
89030
O1, O2
7659 Mckinley Ave
Los Angeles, CA
90001
G1, G2
20253 Lorenzana Dr
Los Angeles, CA
90005
N1, N2
20044 Wells Dr
Beverly Hills, CA
90210
H1, H2
5241 Del Moreno Dr
Los Angeles, CA
91110
F1, F2
20225 Lorenzana Dr
Los Angeles, CA
91111
C1, C2
5142 Dumont Pl
Azusa, CA
91112
J1, J2
5135 Quakertown Ave
Thousand Oaks, CA
91362
M1, M2
4819 Quedo Pl
Westlake Village, CA
91362
A1, A2
20294 Lorenzana Dr
Woodland Hills, CA
91364
D1, D2
20636 De Forest St
Woodland Hills, CA
91364
A1, A2
20294 Lorenzana Dr
Woodland Hills, CA
91364
E1, E2
4851 Poe Ave
Woodland Hills, CA
91364
L1, L2
5021 Dumont Pl
Woodland Hills, CA
91364
B1, B2
19831 Henshaw St
Culver City, CA
94023
I1, I2
5332 Felice Pl
Stevenson Ranch, CA
94135
I1, I2
5332 Felice Pl
Stevenson Ranch, CA
94135
I1, I2
5332 Felice Pl
Stevenson Ranch, CA
94135

*/