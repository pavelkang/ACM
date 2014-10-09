#include<cstdio>
#include<algorithm>
using namespace std;
int N, K;
int dp[10003];
typedef struct task {
  int start, dura;
} task;
task all[10003];
int taskNav[10003]; // start -> index in all[]
int solve() {
  dp[N+1] = 0;
  for (int i=N; i>0; i--) {
    if (taskNav[i]!=0) {
      int best = -1;
      int j = taskNav[i];
      while(all[j].start==i) {
        best = max(best, dp[i+all[j].dura]);
        j+=1;
      }
      dp[i] = best;
    }
    else {
      dp[i] = dp[i+1] + 1;
    }
  }
  return dp[1];
}

int main() {
  scanf("%d%d", &N, &K);
  for (int i=1; i<K+1; i++) {
    scanf("%d%d", &all[i].start, &all[i].dura);
    if (!taskNav[all[i].start])
      taskNav[all[i].start] = i;
  }
  printf("%d\n", solve());
  return 0;
}
