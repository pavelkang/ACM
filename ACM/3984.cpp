#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
int maze[5][5];
bool visited[5][5];
typedef struct s {
  int x,y, dx, dy;
} s;
s answers[5][5];
void BFS() {
  s i; i.x=0; i.y=0;
  queue<s> Q; Q.push(i);
  while(!Q.empty()) {
    s u = Q.front(); Q.pop();
    for (int dx=-1; dx<=1; dx++) {
      for (int dy=-1; dy<=1; dy++) {
        if (dx*dy!=0 || (dx==0&&dy==0))
          continue;
        int newX = u.x+dx; int newY = u.y+dy;
        if (newX==4&&newY==4) {
          s answer;
          answer.x = 4; answer.y = 4;
          answer.dx = dx; answer.dy=dy; answers[4][4]=answer; return;
        }
        if (0<=newX && newX<=4 && 0<=newY && newY<=4 &&
            !visited[newX][newY] && !maze[newX][newY]) {
          visited[newX][newY] = true;
          s newU; newU.x = newX; newU.y = newY;
          newU.dx = dx; newU.dy = dy;
          answers[newX][newY] = newU;
          Q.push(newU);
        }
      }
    }
  }
}
int main() {
  for (int i=0; i<5; i++) {
    for (int j=0; j<5; j++) {
      scanf("%d", &maze[i][j]);
    }
  }
  visited[0][0] = true;
  BFS();
  stack<s> S; S.push(answers[4][4]);
  while (true) {
    s u = S.top();
    if (u.x==0 && u.y==0) {
      break;
    }
    s newU = answers[u.x-u.dx][u.y-u.dy];
    S.push(newU);
  }
  while(!S.empty()) {
    s u = S.top();
    printf("(%d, %d)\n", u.x, u.y);
    S.pop();
  }
}
