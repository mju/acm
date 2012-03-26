#include <stdio.h>

#define MAX 100
#define HALF_MAX_FACE 250

/*unsigned short dp_table[MAX][MAX * HALF_MAX_FACE];*/

unsigned short
solve(
  /* if the machine doesn't accept an argument large like this,
   * make the first argument a global variable
   */
  unsigned short dp_table[][MAX * HALF_MAX_FACE],
  unsigned n,
  unsigned short* coins,
  unsigned bound
) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return coins[0];
  }
  unsigned i, j;
  unsigned short tmp;
  for (i = 0; i < bound; i++) {
    if (i + 1 >= coins[0]) {
      dp_table[0][i] = coins[0];
    } else {
      dp_table[0][i] = 0;
    }
  }
  for (i = 1; i < n; i++) {
    for (j = 0; j < bound; j++) {
      if (j + 1 >= coins[i] ) {
        if (j + 1 == coins[i]) {
          tmp = coins[i];
        } else {
          tmp = dp_table[i - 1][j - coins[i]] + coins[i];
        }
        if (tmp > dp_table[i - 1][j]) {
          dp_table[i][j] = tmp;
        } else {
          dp_table[i][j] = dp_table[i - 1][j];
        }
      } else {
        dp_table[i][j] = dp_table[i - 1][j];
      }
    }
  }
  return dp_table[n - 1][bound - 1];
}

int
main(int argc, char** argv) {
  unsigned short dp_table[MAX][MAX * HALF_MAX_FACE];
  unsigned cases;
  unsigned num_coins;
  unsigned i;
  unsigned short coins[MAX];
  unsigned total;
  unsigned half_total;
  unsigned n;
  for (scanf("%u", &cases); cases > 0; cases--) {
    total = 0;
    for (scanf("%u", &num_coins), i = 0; i < num_coins; i++) {
      scanf("%hu", &coins[i]);
      total += coins[i];
    }
    half_total = total >> 1;
    for (i = 0, n = 0; i < num_coins; i++) {
      if (coins[i] <= half_total) {
        coins[n] = coins[i];
        n++;
      }
    }
    printf("%hu\n", total - (solve(dp_table, n, coins, half_total) << 1));
  }
  return 0;
}
