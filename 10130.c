#include <stdio.h>

#define MAX_WEIGHT 30
#define MAX_NUM_OBJS 1000
#define MAX_NUM_PPL 100

void
build_dp_tbl(
  unsigned short dp_tbl[][MAX_WEIGHT],
  unsigned short* prices,
  unsigned short* weights,
  int num_objs,
  int weight
) {
  int i, j;
  for (i = 0; i < weight; i++) {
    if (i + 1 < weights[0]) {
      dp_tbl[0][i] = 0;
    } else {
      dp_tbl[0][i] = prices[0];
    }
  }
  int idx;
  for (i = 1; i < num_objs; i++) {
    for (j = 0; j < weight; j++) {
      idx = j - weights[i];
      if (idx >= 0 && dp_tbl[i - 1][j] < dp_tbl[i - 1][idx] + prices[i]) {
        dp_tbl[i][j] = dp_tbl[i - 1][idx] + prices[i];
      } else if (idx == -1 && dp_tbl[i - 1][j] < prices[i]) {
        /*j + 1 == wieghts[i]*/
        dp_tbl[i][j] = prices[i];
      } else {
        dp_tbl[i][j] = dp_tbl[i - 1][j];
      }
    }
  }
}

int
main(int argc, char** argv) {
  int num_cases;
  int num_objs;
  int num_ppl;
  unsigned short prices[MAX_NUM_OBJS];
  unsigned short weights[MAX_NUM_OBJS];
  unsigned short dp_tbl[MAX_NUM_OBJS][MAX_WEIGHT];
  int ppl[MAX_NUM_PPL];
  int max_weight;

  int i;
  unsigned solution;
  for (scanf("%d", &num_cases); num_cases > 0; num_cases--) {
    solution = 0;
    max_weight = 0;
    for (scanf("%d", &num_objs), i = 0; i < num_objs; i++) {
      scanf("%hu %hu", prices + i, weights + i);
    }
    for (scanf("%d", &num_ppl), i = 0; i < num_ppl; i++) {
      scanf("%d", ppl + i);
      if (ppl[i] > max_weight) {
        max_weight = ppl[i];
      }
    }
    build_dp_tbl(dp_tbl, prices, weights, num_objs, max_weight);
    for (i = 0; i < num_ppl; i++) {
      solution += dp_tbl[num_objs - 1][ppl[i] - 1];
    }
    printf("%u\n", solution);
  }
  
  return 0;
}
