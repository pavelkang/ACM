#include<cstdio>
#include<algorithm>
#include<limits.h>
using namespace std;
int N;
int H;
int heights[23];

int find() {
  int dp[N+3][H+3];
  int best = 0;
  for (int i=1; i<N+1; i++) {
    for (int j=heights[i]; j<H+1; j++) {
      dp[i][j] = max(dp[N-1][j], dp[N-1][j-heights[i]]+heights[i]);
      if (dp[i][j] > best) {
        best = dp[i][j];
      }
    }
  }
  return best;
}

int main() {
  scanf("%d%d", &N, &H);
  for (int i=1; i<=N; i++) {
    scanf("%d", &heights[i]);
  }
  printf("%d\n", H - find());
}
