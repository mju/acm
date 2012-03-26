#include <stdio.h>

#define MAX_N 40

unsigned long long
n_choose_m(unsigned n, unsigned m) {
  if (m > n) {
    return 0;
  }
  if (m == 0) {
    return 1;
  }
  if (m > (n >> 1)) {
    return n_choose_m(n, n - m);
  }
  unsigned long long r = 1;
  unsigned i;
  for (i = 1; i <= m; i++) {
    r *= n--;
    r /= i;
  }
  return r;
}

int
main(int argc, char** argv) {
  unsigned i;
  unsigned j;
  unsigned long long solutions[MAX_N];
  for (i = 0; i < MAX_N; i++) {
    solutions[i] = 0;
    for (j = 0; j <= ((i + 1) >> 1); j++) {
      solutions[i] += n_choose_m((i + 1) - j, j) << (j << 1);
    }
  }

  for (scanf("%u", &j); j > 0; j--) {
    scanf("%u", &i);
    printf("%llu\n", solutions[i - 1]);
  }

  return 0;
}
