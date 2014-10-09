#include<cstdio>
#include<algorithm>
using namespace std;
int values[102];
int times[102];
int M, T;
int dp[102][1002]; // [i, j] means the max value use THE ith herbs within time j
void solve() {
  for (int i=0; i<=M; i++) {
    dp[i][0] = 0;
  }
  for (int j=0; j<=T; j++) {
    if (j>=times[1])
      dp[1][j] = values[1];
    else
      dp[1][j] = 0;
  }
  for (int i=2; i<=M; i++) {
    for (int j=1; j<=T; j++) {
      if (j>=times[i]) {
        int m = -1;
        for (int k=1; k<=i-1; k++) {
          m = max(m, dp[k][j-times[i]]);
        }
        dp[i][j] = m + values[i];
      }
      else {
        dp[i][j] = 0;
      }
    }
  }
}

int main() {
  scanf("%d%d", &T, &M);
  for (int i=1; i<=M; i++) {
    scanf("%d%d", &times[i], &values[i]);
  }
  solve();
  int answer = -1;
  for (int i=1; i<=M; i++) {
    answer = max(answer, dp[i][T]);
  }
  printf("%d\n", answer);
  return 0;
}
