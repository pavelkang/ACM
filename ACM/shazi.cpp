/*
  区间型动态规划
  dp[i, j] = dp[i, k] + dp[k, j] + sum[i, j]
 */

#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = 1<<30;
int N;
int sands[303];
int partSum[303][303];
int dp[303][303];
int solve() {
  for (int i=N-1; i>=0; i--) {
    for (int j=i+1; j<=N; j++) {
      if (j-i>=2) {
      int best = INF;
      for (int k=i+1; k<j; k++) {
        best = min(best, dp[i][k]+dp[k][j]+partSum[i][j]);
      }
      dp[i][j] = best;} else {dp[i][j]=0;}
    }
  }
  return dp[0][N];
}
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &sands[i]);
  }
  // 预处理
  partSum[0][1] = sands[0];
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<=N; j++) {
      partSum[i][j] = partSum[i][j-1] + sands[j-1];
    }
  }
  printf("%d\n", solve());
  return 0;
}
