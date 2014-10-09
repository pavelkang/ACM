#include<cstdio>
int C, G;
int Cs[23];
int Gs[23];

int solve() {
  int dp[G][7000];
  // dp[i][j] is # of ways for the first i weights to get j

}

int main() {
  scanf("%d%d", &C, &G);
  for (int i=0; i<C; i++) {
    scanf("%d", &C[i]);
  }
  for (int i=0; i<G; i++) {
    scanf("%d", &G[i]);
  }
  printf("%d\n", solve());
  return 0;
}
