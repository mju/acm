#include <stdio.h>

#define MAX_NUM_NODES 5
#define BN_WIDTH 9/*for int*/
#define BN_WIDTH_STR "%09d"
#define BN_DIVIDER 1000000000/*for int*/

/**
 * please use make_it_so_long() or str2so_long() to initialize a so_long.
 */
struct so_long {
  int num_nodes;/*the subscript of the Most Significant Node*/
  int nodes[MAX_NUM_NODES];
};

void
make_it_so_long(struct so_long* sl, int i) {
  sl->num_nodes = 0;
  if (i < BN_DIVIDER) {
    sl->nodes[0] = i;
    sl->num_nodes = 1;
  } else {
    sl->nodes[1] = i / BN_DIVIDER;
    sl->nodes[0] = i % BN_DIVIDER;
    sl->num_nodes = 2;
  }
}

void
print_so_long(struct so_long* sl) {
  int i;
  printf("%d", sl->nodes[sl->num_nodes - 1]);
  for (i = sl->num_nodes - 2; i >= 0; i--) {
    printf(BN_WIDTH_STR, sl->nodes[i]);
  }
}

void
make_copy(struct so_long* target, struct so_long* source) {
  target->num_nodes = source->num_nodes;
  int i;
  for (i = 0; i < source->num_nodes; i++) {
    target->nodes[i] = source->nodes[i];
  }
}

/**
 * the result will be stored in lhs
 */
void
in_place_add(struct so_long* lhs, struct so_long* rhs) {
  struct so_long* longer;
  struct so_long* shorter;
  if (lhs->num_nodes >= rhs->num_nodes) {
    longer = lhs;
    shorter = rhs;
  } else {
    longer = rhs;
    shorter = lhs;
  }

  int carry;
  int i;
  for (i = 0, carry = 0; i < shorter->num_nodes; i++) {
    carry += longer->nodes[i];
    carry += shorter->nodes[i];
    if (carry < BN_DIVIDER) {
      lhs->nodes[i] = carry;
      carry = 0;
    } else {
      lhs->nodes[i] = carry - BN_DIVIDER;
      carry = 1;
    }
  }
  if (carry == 1) {
    for (; i < longer->num_nodes; i++) {
      carry = 1 + longer->nodes[i];/* the one is carried over */
      if (carry < BN_DIVIDER) {
        lhs->nodes[i] = carry;
        break;
      } else {
        lhs->nodes[i] = carry - BN_DIVIDER;
      }
    }
    if (i == longer->num_nodes) {
      lhs->nodes[i] = 1;
      lhs->num_nodes = longer->num_nodes + 1;
      return;
    }
    /* if it gets to here, lhs->nodes[i] has been assigned in the for-loop. */
    i++;
  }
  if (shorter == lhs) {
    for (; i < longer->num_nodes; i++) {
      lhs->nodes[i] = longer->nodes[i];
    }
    lhs->num_nodes = longer->num_nodes;
  }
}

/**
 * the result will be stored in target
 */
void
intact_add(struct so_long* target, struct so_long* lhs, struct so_long* rhs) {
  make_copy(target, lhs);
  in_place_add(target, rhs);
}

/**
 * the result will be stored in target
 */
void
intact_mul(struct so_long* target, struct so_long* lhs, struct so_long* rhs) {
  long long carry;/* sizeof(long long) should be 2 * sizeof(int) */
  int i, j;

  /**
   * initializes target.  It could have lhs->num_nodes + rhs->num_nodes - 1 or
   * lhs->num_nodes + rhs->num_nodse nodes
   */
  target->num_nodes = lhs->num_nodes + rhs->num_nodes - 1;/* be conservetive */
  /* assumes it will use lhs->num_nodes + rhs->num_nodes nodes */
  for (i = 0; i <= target->num_nodes; i++) {
    target->nodes[i] = 0;
  }

  for (i = 0; i < rhs->num_nodes; i++) {
    if (rhs->nodes[i] == 0) {
      continue;
    }
    for (j = 0, carry = 0; j < lhs->num_nodes; j++) {
      carry +=
        (long long)rhs->nodes[i] * (long long)lhs->nodes[j] +
        (long long)target->nodes[i + j];
      target->nodes[i + j] = (int)(carry % BN_DIVIDER);
      carry /= BN_DIVIDER;
    }
    if (carry != 0) {
      target->nodes[i + j] = (int)carry;
      /* happens when target->num_nodes == lhs->num_nodes + rhs->num_nodes */
      if (i + j == target->num_nodes) {
        target->num_nodes++;
      }
    }
  }
}

/**
 * the result will be stored in lhs
 */
void
in_place_mul(struct so_long* lhs, struct so_long* rhs) {
  struct so_long target;
  intact_mul(&target, lhs, rhs);
  make_copy(lhs, &target);
}

void
str2so_long(struct so_long* lhs, char* str) {
  int i, j;
  int pos_left_most_digit;
  int tmp;
  int tens;
  lhs->num_nodes = 0;

  /* deals with leading zeros */
  for (i = 0; str[i] == '0' && str[i] != '\0'; i++);
  pos_left_most_digit = i;

  /* gets the position of the right-most digit */
  for (i = 0; str[i] != '\0'; i++);
  i--;

  for (j = 0, tmp = 0, tens = 1; i >= pos_left_most_digit; i--, j++) {
    if (j == BN_WIDTH) {
      j = 0;
      tens = 1;
      lhs->nodes[lhs->num_nodes++] = tmp;
      tmp = 0;
    }
    tmp += (str[i] - '0') * tens;
    tens *= 10;
  }
  if (tmp != 0) {
    lhs->nodes[lhs->num_nodes++] = tmp;
  }

  if (lhs->num_nodes == 0) {
    lhs->nodes[0] = 0;
    lhs->num_nodes = 1;
  }
}

#define N ((2 << 5) - 1)

int
main(int argc, char** argv) {
  int s, n;
  struct so_long f_of_n, n_choose_2, n_choose_4, rhs;
  int threes;
  int twos;
  int i;
  int tmp;

  for (scanf("%d", &s); s > 0; s--) {
    scanf("%d", &n);
    make_it_so_long(&f_of_n, 1);
    threes = 1;
    twos = 3;

    /**
     * f(n) = 1 + C(n, 2) + C(n, 4)
     */
    /* calculates C(n, 2) */
    if ((n & 0x1) == 0) {
      make_it_so_long(&n_choose_2, n >> 1);
      make_it_so_long(&rhs, n - 1);
      in_place_mul(&n_choose_2, &rhs);
    } else {
      make_it_so_long(&n_choose_2, n);
      make_it_so_long(&rhs, (n - 1) >> 1);
      in_place_mul(&n_choose_2, &rhs);
    }

    in_place_add(&f_of_n, &n_choose_2);

    /* calculates C(n, 4) */
    make_it_so_long(&n_choose_4, 1);
    for (i = 0; i < 4; i++) {
      tmp = n - i;
      while (twos > 0 && (tmp & 0x1) == 0) {
        tmp >>= 1;
        twos--;
      }
      while (threes > 0 && tmp % 3 == 0) {
        tmp /= 3;
        threes--;
      }
      make_it_so_long(&rhs, tmp);
      in_place_mul(&n_choose_4, &rhs);
    }

    in_place_add(&f_of_n, &n_choose_4);

    print_so_long(&f_of_n);
    printf("\n");
  }

  return 0;
}
