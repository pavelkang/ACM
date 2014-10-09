#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int N, M;
const int MAX_N = 3402;
const int MAX_M = 12880;
int W[MAX_N+3];
int D[MAX_N+3];

int work() {
  int dp[M+3];
  memset(dp, 0, sizeof(dp));
  for (int i=1; i<=N; i++) {
    for (int j=M; j>=W[i]; j--) {
      if(dp[j]<dp[j-W[i]]+D[i]) {
        dp[j] = dp[j-W[i]] + D[i];
      }
    }
  }
  return dp[M];
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i=1; i<=N; i++) {
    scanf("%d%d", &W[i], &D[i]);
  }
  printf("%d\n", work());
  return 0;
}
