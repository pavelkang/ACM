/*
  POJ 2524 Ubiquitous Religions
 */
#include<cstdio>
#include<algorithm>
using namespace std;
int parent[50010];
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
void printIntArray(int *A, int start, int end);
int main() {
  int noOfCase = 0;
  while (true) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n==0 && m==0)
      break;
    noOfCase++;
    // Init parent
    for (int i=1; i<=n; ++i) {
      parent[i] = i;
    }
    while(m--) {
      int x, y;
      scanf("%d%d", &x, &y);
      merge(x, y);
    }
    int cnt = 0;
    for (int i=1; i<=n; ++i) {
      if (getRoot(i) == i)
        cnt++;
    }
    //printIntArray(parent, 1, n+1);
    printf("Case %d: %d\n", noOfCase, cnt);
  }
  return 0;
}

void printIntArray(int *A, int start, int end) {
  for (int i = start; i<end; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}
