#pragma once
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
