#include<cstdio>
#include<algorithm>
#include<limits.h>
#include<cstring>
using namespace std;
char s1[5000];
char s2[5000];

int getCommon(int a, int b) {
  if (a==0 || b==0) {
    return 0;
  }
  int dp[a+3][b+3];
  // dp[i][j] means the longest common subsequence
  // formed by the [0...i] of a and [0...j] of b
  memset(dp, 0, sizeof(dp));
  // dynamic programming
  for (int i=1; i<=a; i++) {
    for (int j=1; j<=b; j++) {
      if (s1[i-1]==s2[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[a][b];
}

int main() {
  while (scanf("%s%s", s1, s2) != EOF) {
    printf("%d\n", getCommon((int)strlen(s1), (int)strlen(s2)));
  }
  return 0;
}
