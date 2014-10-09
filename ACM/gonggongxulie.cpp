#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[2002], b[2002];
int la, lb;
int dp[2002][2002];
void solve() {
  for (int i=0; i<=lb; i++) {
    dp[0][i] = 0;
  }
  for (int j=0; j<=la; j++) {
    dp[j][0] = 0;
  }
  for (int i=1; i<=la; i++) {
    for (int j=1; j<=lb; j++) {
      if (a[i-1]==b[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];}
      else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]); }
    }
  }
}
int main() {
  scanf("%s%s", &a[0], &b[0]);
  la = strlen(a); lb = strlen(b);
  solve();
  printf("%d\n", dp[la][lb]);
  return 0;
}
