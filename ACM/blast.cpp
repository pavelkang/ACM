#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char A[2003], B[2003];
int K, la, lb;
int dp[2003][2003];
int solve() {
  for (int i=0; i<=lb; i++) {dp[0][i] = i*K;}
  for (int i=0; i<=la; i++) {dp[i][0] = i*K;}
  for (int i=1; i<=la; i++) {
    for (int j=1; j<=lb; j++) {
      int best = min(dp[i-1][j]+K, dp[i][j-1]+K);
      best = min(best, dp[i-1][j-1]+abs((int)(A[i-1]-B[j-1])));
      dp[i][j] = best;
    }
  }
  return dp[la][lb];
}

int main() {
  scanf("%s%s", &A[0], &B[0]);
  la = strlen(A); lb = strlen(B);
  scanf("%d", &K);
  printf("%d\n", solve());
  return 0;
}
