#include<cstdio>
#include<algorithm>
using namespace std;
int partSum[2003][2003];
int A[2003];
int N;
int dp[2003][2003];
int solve() {
  int i=0, j=0;
  for (int d=1; d<=N; d++) {
    for (int i=0; i<N; i++) {
      int j = i+d;
      dp[i][j] = max(dp[i+1][j]+partSum[i+1][j]+A[i],
                     dp[i][j-1]+partSum[i][j-1]+A[j-1]);
    }
  }
  return dp[0][N];
};
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  // Pre-process
  for (int i=0; i<=N; i++) {
    for (int j=i+1; j<=N; j++) {
      partSum[i][j] = partSum[i][j-1] + A[j-1];
    }
  }
  printf("%d\n", solve());
  return 0;
}
