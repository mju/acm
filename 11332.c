#include <stdio.h>

int
main(int argc, char** argv) {
  int g;
  scanf("%d", &g);
  while (g) {
    g %= 9;
    if (g == 0) {
      g = 9;
    }
    printf("%d\n", g);
    scanf("%d", &g);
  }

  return 0;
}
