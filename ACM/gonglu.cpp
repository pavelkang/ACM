#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = 1<<30;
int prices[12];
int s;
int dp[103];
void solve() {
  dp[0] = 0;
  dp[1] = prices[1];
  for (int i=2; i<=s; i++) {
    int best = INF;
    if (i<11) {
      best = prices[i];
    }
    for (int a=1; a<=i/2; a++) {
      best = min(best, dp[a]+dp[i-a]);
    }
    dp[i] = best;
  }
}
int main() {
  for (int i=1; i<11; i++) {
    scanf("%d", &prices[i]);
  }
  scanf("%d", &s);
  solve();
  printf("%d\n", dp[s]);
  return 0;
}
