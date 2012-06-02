#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_CUTS 49

int
main(int argc, char** argv) {
  int length;
  int num_cuts;
  int cuts[MAX_NUM_CUTS + 2];
  int dp_tbl[MAX_NUM_CUTS + 1][MAX_NUM_CUTS + 2];
  int cost;
  int min_cost;
  int i, j, k;

  while (scanf("%d", &length) && length) {
    scanf("%d", &num_cuts);
    cuts[0] = 0;
    for (i = 1; i < num_cuts + 1; i++) {
      scanf("%d", cuts + i);
    }
    cuts[i] = length;
    if (num_cuts == 0) {
      printf("The minimum cutting is 0.\n");
      continue;
    }
    for (i = 0; i < num_cuts + 2 - 1; i++) {
      dp_tbl[i][i + 1] = 0;
    }
    for (i = 2; i <= num_cuts + 2 - 1; i++) {
      for (j = 0; j + i < num_cuts + 2; j++) {
        min_cost = -1;
        for (k = j + 1; k < j + i; k++) {
          cost = dp_tbl[j][k] + dp_tbl[k][j + i];
          if (min_cost == -1 || cost < min_cost) {
            min_cost = cost;
          }
        }
        dp_tbl[j][j + i] = cuts[j + i] - cuts[j] + min_cost;
      }
    }
    printf("The minimum cutting is %d.\n", dp_tbl[0][num_cuts + 2 - 1]);
  }

  return EXIT_SUCCESS;
}
