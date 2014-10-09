#include<cstdio>
#include<queue>
using namespace std;
const int MAX = 100000;
int N, K;
bool visited[MAX+5];
typedef struct p {
  int x, step;
} p;
int answer;
void BFS() {
  p i; i.x=N; i.step=0;
  queue<p> Q; Q.push(i);
  while (!Q.empty()) {
    p u = Q.front(); Q.pop();
    if (u.x*2==K || u.x-1==K || u.x+1==K) {
      answer = u.step+1; return ;
    }
    if (u.x*2<MAX && !visited[u.x*2]) {
      visited[u.x*2] = true;
      p newP; newP.x = u.x*2; newP.step = u.step+1; Q.push(newP);
    }
    if (u.x-1>-1 && !visited[u.x-1]) {
      visited[u.x-1] = true;
      p newP; newP.x = u.x-1; newP.step = u.step+1; Q.push(newP);
    }
    if (u.x+1<MAX && !visited[u.x+1]) {
      visited[u.x+1] = true;
      p newP; newP.x = u.x+1; newP.step = u.step+1; Q.push(newP);
    }
  }
}
int main() {
  scanf("%d%d", &N, &K);
  if (N==K) {
    printf("0\n");
    return 0;
  }
  visited[N] = true;
  BFS();
  printf("%d\n", answer);
  return 0;
}
