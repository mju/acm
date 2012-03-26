#include <stdio.h>

#define MAX_WEIGHT 450
#define MAX_NUM_PPL 100
#define TBL_PPL MAX_NUM_PPL - (MAX_NUM_PPL >> 1)
#define TBL_WEIGHT (MAX_WEIGHT * MAX_NUM_PPL) >> 1

/**
 * in the dp_tbl, 0 denotes the weight cannot be achieved, 1 means the weight
 * can be achieved with the number of ppl.
 */
void
initialize_dp_tbl(char dp_tbl[][TBL_WEIGHT], int max_rows, int max_weight) {
  int i, j;
  for (i = 0; i < max_rows; i++) {
    for (j = 0; j < (i + 1) * max_weight; j++) {
      dp_tbl[i][j] = 0;
    }
  }
}

int
solve(
  char dp_tbl[][TBL_WEIGHT], int* ppl, int num_ppl, int half_ttl, int max_weight
) {
  int solution = 0;
  if (num_ppl == 0 || num_ppl == 1) {
    return solution;
  }
  int max_rows = num_ppl - (num_ppl >> 1);
  int is_odd_num_ppl = num_ppl & 0x1;

  /*printf("%d %d\n", max_rows, is_odd_num_ppl);*/

  int i, j, k;
  int cur_row = 0;
  for (i = 0; i < num_ppl; i++) {
    if (ppl[i] > half_ttl) {
      continue;
    }
    for (j = cur_row; j >= 0; j--) {
      if (j == 0) {
        dp_tbl[j][ppl[i] - 1] = 1;
        continue;
      }
      for (k = 0; k < j * max_weight && k < half_ttl - ppl[i]; k++) {
        if (dp_tbl[j - 1][k] == 1) {
          dp_tbl[j][k + ppl[i]] = 1;
        }
      }
    }
    cur_row++;
    if (cur_row == max_rows) {
      cur_row--;
    }
  }

  for (i = half_ttl - 1; i >= 0; i--) {
    if (dp_tbl[max_rows - 1][i] == 1) {
      solution = i + 1;
      break;
    }
  }
  if (is_odd_num_ppl == 1) {
    for (i = half_ttl - 1; i >= 0; i--) {
      if (dp_tbl[max_rows - 2][i] == 1) {
        if (i + 1 > solution) {
          solution = i + 1;
        }
        break;
      }
    }
  }

  return solution;
}

int
main(int argc, char** argv) {
  int num_cases;
  int num_ppl;
  int i;
  int ppl[MAX_NUM_PPL];
  char dp_tbl[TBL_PPL][TBL_WEIGHT];
  int ttl;
  int half_ttl;
  int solution;
  int max_weight;
  int is_first_case = 1;

  /*printf("%d %d %d %d\n", MAX_WEIGHT, MAX_NUM_PPL, TBL_PPL, TBL_WEIGHT);*/

  for (scanf("%d", &num_cases); num_cases > 0; num_cases--) {
    ttl = 0;
    max_weight = 0;
    for (scanf("%d", &num_ppl), i = 0; i < num_ppl; i++) {
      scanf("%d", &ppl[i]);
      ttl += ppl[i];
      if (ppl[i] > max_weight) {
        max_weight = ppl[i];
      }
    }
    half_ttl = ttl >> 1;

    initialize_dp_tbl(dp_tbl, num_ppl - (num_ppl >> 1), max_weight);

    solution = solve(dp_tbl, ppl, num_ppl, half_ttl, max_weight);
    if (is_first_case == 1) {
      is_first_case = 0;
    } else {
      printf("\n");
    }
    printf("%d %d\n", solution, ttl - solution);
  }

  return 0;
}
