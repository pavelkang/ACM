#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char chart[30]; int len;
int order[200];
char inp[260];
int dp[260]; // dp[i] = longest ending with i
int findSeq(char *inp) {
  int l = strlen(inp);
  for (int i=0; i<l; i++) {dp[i] = 1;}
  int best = 1;
  for (int i=1; i<l; i++) {
    int bestSubLen = 1;
    for (int j=0; j<i; j++) {
      if (order[(int)inp[j]] <= order[(int)inp[i]])
        {bestSubLen = max(bestSubLen, dp[j]+1);}
    }
    dp[i] = bestSubLen;
    best = max(best, bestSubLen);
  }
  return best;
}
int main() {
  scanf("%s", &chart[0]);
  len = strlen(chart);
  for (int i=0; i<len; i++) {
    order[(int)chart[i]] = i;
  }
  while(scanf("%s", &inp[0])!=EOF) {
    printf("%d", findSeq(inp));
  };
  printf("\n");
  return 0;
}
