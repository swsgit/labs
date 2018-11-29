/*
        Stone, Spencer
        11/26/18
        Lab 8
        Description: Sort a list of contacts by zip code
                     in ascending order.
*/
#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  size_t size;
  FILE *fp_in, *fp_out;
  errno_t err;

  if (argc != 3) {
    printf("Usage: %s infile outfile", argv[0]);
    return 0;
  }

  err = fopen_s(&fp_in, argv[1], "r");
  if (err) {
    perror("fopen() failed");
    return EXIT_FAILURE;
  }
  err = fopen_s(&fp_out, argv[2], "w+");
  if (err) {
    perror("fopen() failed");
    return EXIT_FAILURE;
  }

  contact **c = alloc_contacts(MAX_CONTACTS);
  size = get_contacts(c, fp_in);
  if (size == 0)
    perror("get_contacts failed");
  sort_contacts(c, size);
  print_contacts(c, size, fp_out);
  free_alloc(c, size);

  if (fp_in) {
    err = fclose(fp_in);
    if (err) {
      perror("fclose() failed");
      return EXIT_FAILURE;
    }
  }

  if (fp_out) {
    err = fclose(fp_out);
    if (err) {
      perror("fclose() failed");
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}

/*
cs539> cs539_lab8.exe address.txt address_sorted.txt
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