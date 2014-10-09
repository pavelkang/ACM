/*
  POJ 1182 Food Chain
 */
#include<cstdio>
using namespace std;
int parent[50005];
int eat[50005];
int eaten[50005];
int N, K;

int getRoot(int x) {
  if (x == parent[x])
    return x;
  parent[x] = getRoot(parent[x]);
  return parent[x];
}

void merge(int x, int y) {
  int rootX = getRoot(x);
  int rootY = getRoot(y);
  if (rootX == rootY)
    return ;
  parent[rootY] = rootX;
}

bool find(int x, int y) {
  return (getRoot(x) == getRoot(y));
}

int main() {
  int cmd, x, y; int noOfLies = 0;
  scanf("%d%d", &N, &K);
  // Init
  for (int i=1; i<=N; i++) {
    parent[i] = i; eat[i] = 0; eaten[i] = 0;
  }
  while (K--) {
    scanf("%d%d%d", &cmd, &x, &y);
    if (x>N || y>N) {
      noOfLies++;
      continue;
    }
    if (cmd == 1) {
      // same species
      // check for consistency
      if (eat[x]!=0 || eaten[x]!=0) {
        if (find(eat[x], y) || find(eaten[x],y)) {
          noOfLies++;
          continue;
        }
        if (eat[eat[x]]!=0 || eaten[eaten[x]]!=0) {
          if (find(eat[eat[x]],y) || find(eaten[eaten[x]], y)) {
            noOfLies++;
            continue;
          }
        }
      }
      // union
      merge(x, y);
    }
    else {
      if (x==y) {
        noOfLies++;
        continue;
      }
      // x eats y
      if (eat[x]!=0||eaten[x]!=0) {
        if (!find(eat[x], y)) {
          noOfLies++; continue;
        }
      }
      if (eat[x]==0) eat[x] = y;
      if (eaten[y]==0) eaten[y] = x;
      merge(eat[x], y);
      merge(eaten[y], x);
    }
  }
  printf("%d\n", noOfLies);
  return 0;
}
