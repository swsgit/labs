#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>

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