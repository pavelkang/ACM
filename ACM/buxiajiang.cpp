#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[5003];
int dp[5003];
void solve() {
  dp[0] = 1;
  for (int i=1; i<=n; i++) {
    int best = 1;
    for (int j=1; j<i; j++) {
      if (a[j]<=a[i])
        best = max(best, dp[j]+1);
    }
    dp[i] = best;
  }
}
int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    scanf("%d", &a[i]);
  }
  solve();
  int ax = -1;
  for (int i=1; i<=n; i++) {
    ax = max(ax, dp[i]);
  }
  printf("%d\n", ax);
  return 0;
}
