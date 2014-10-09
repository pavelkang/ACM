#include<cstdio>
#include<algorithm>
using namespace std;
int vol, n;
int vols[33];
int dp[33][20002];
void solve() {
  int x;
  for (int i=0; i<=n; i++) {
    dp[i][0] = 0;
  }
  for (x=0; x<=vol; x++) {
    if (x>=vols[1])
      break;
  }
  for (int k=0; k<x; k++) {dp[1][k]=0;}
  for (int k=x; k<=vol; k++) {dp[1][k]=vols[1];}
  for (int i=2; i<=n; i++) {
    for (int j=0; j<=vol; j++) {
      if (j>=vols[i]) {
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-vols[i]] + vols[i]);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
}
int main() {
  scanf("%d%d", &vol, &n);
  for (int i=1; i<=n; i++) {
    scanf("%d", &vols[i]);
  }
  solve();
  printf("%d\n", vol-dp[n][vol]);
  return 0;
}
