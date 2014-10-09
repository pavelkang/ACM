/*
  POJ 1611 The Suspects
 */
#include<cstdio>
int parent[30005];
int sum[30005];
int n, m;
int getRoot(int x) {
  if (x==parent[x])
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
  sum[rootX] += sum[rootY];
}
int main() {
  while (true) {
    scanf("%d%d", &n, &m);
    if (n==0 && m==0) {
      break;
    }
    // Init
    for (int i=0; i<n; ++i) {
      parent[i] = i; sum[i] = 1;
    }
    while(m--) {
      int x, a;
      scanf("%d%d", &x, &a); x--;
      while(x--) {
        int b;
        scanf("%d", &b);
        merge(a, b);
      }
    }
    printf("%d\n", sum[getRoot(0)]);
  }
  return 0;
}
