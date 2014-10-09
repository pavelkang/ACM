#include<cstdio>
#include<algorithm>
using namespace std;
int N, H;
int grass[503];
int dp[503][45003];
int solve(){
  int j;
  for (int i=0; i<N; i++) {dp[i][0]=0;}
  for (j=0; j<=H; j++) {
    dp[0][j]=0;
    if (j>=grass[0])
      break;
  }
  for (int k=j; k<=H; k++) {dp[0][k]=grass[0];}
  for (int i=1; i<N; i++) {
    for (int j=1; j<=H; j++) {
      if (j-grass[i]>=0)
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-grass[i]]+grass[i]);
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[N-1][H];
}

int main() {
  scanf("%d%d", &H, &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &grass[i]);
  }
  printf("%d\n", solve());
  return 0;
}
