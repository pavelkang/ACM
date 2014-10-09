#include<cstdio>
#include<algorithm>
using namespace std;
int N, M;
int a[103];
int answer = 0;
void dfs(int step, int sum) {
  if (sum==M) { answer++; }
  if (sum>=M) { return; }
  if (step>=N) { return; }
  dfs(step+1, sum);
  dfs(step+1, sum+a[step+1]);
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i=1; i<=N; i++) {
    scanf("%d", &a[i]);
  }
  dfs(1, 0);
  dfs(1, a[1]);
  printf("%d\n", answer);
  return 0;
}
