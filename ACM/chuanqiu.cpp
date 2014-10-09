#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int dp[33][33]; //[i, j]: # of ways to get to i in j steps
int solve() {
  dp[0][0] = 1;
  for (int i=1; i<=n-1; i++) {
    dp[i][0] = 0;
  }
  for (int j=1; j<=m; j++) {
    for (int i=0; i<=n-1; i++) {
      dp[i][j] = dp[abs(i+1)%n][j-1] + dp[abs(i-1)%n][j-1];
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  solve();
  printf("%d\n", dp[0][m]);
  return 0;
}
