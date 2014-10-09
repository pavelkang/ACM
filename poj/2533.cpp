#include<cstdio>
#include<algorithm>
#include<limits.h>
using namespace std;
int N;
int A[1003];

int longest() {
  // dp[i] means the longest ordered subsequence
  // ending with A[i]
  int dp[1003];
  int best = 1;
  for (int i=0; i<1003; i++) {
    dp[i] = 1;
  }
  dp[0] = 1;
  for (int i=1; i<N; i++) {
    for (int j=i-1; j>=0; j--) {
      if (A[j] < A[i]) {
        dp[i] = max(dp[i], dp[j]+1);
      }
      best = max(best, dp[i]);
    }
  }
  return best;
}

int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  printf("%d\n", longest());
}
