#include<cstdio>
#include<iostream>
using namespace std;
const int MAX = 31000;
int P;
int parent[MAX];
int under[MAX]; // # of cubes under
int sum[MAX]; // # sum of the stack
int getRoot(int x) {
  if (x == parent[x])
    return x;
  int t = getRoot(x);
  under[x] += under[parent[x]];
  parent[x] = t;
  return parent[x];
  /*
  if (parent[x] != x) {
    parent[x] = getRoot(x);
    under[x] += under[parent[x]];
  }
  return parent[x];
  */
}
void stack(int x, int y) {
  int rootX = getRoot(x);
  int rootY = getRoot(y);
  if (rootX == rootY)
    return ;
  parent[rootY] = rootX;
  sum[rootY] += sum[rootX];
  under[rootY] = sum[rootX];
}
int main() {
  // Initialize
  for (int i=0; i<MAX; ++i) {
    parent[i] = i;
    under[i] = 0;
    sum[i] = 1;
  }
  // scan commands
  scanf("%d", &P);
  for(int i=0; i<P; ++i) {
    char cmd[20];
    scanf("%s", cmd);
    if (cmd[0] == 'M') {
      int X, Y;
      scanf("%d%d", &X, &Y);
      stack(Y, X);
    }
    else {
      int X;
      scanf("%d", &X);
      getRoot(X);
      printf("%d\n", under[X]);
    }
  }
  return 0;
}
