/*
  POJ 2492 A Bug's Life
*/
#include<cstdio>
#include<iostream>
using namespace std;
int noOfBugs, noOfInter;
int parent[2010];
int opp[2010];
/*
int getRoot(int x) {
  if (parent[x] == x)
    return x;
  parent[x] = getRoot(parent[x]);
  return parent[x];
  }*/
int getRoot(int x) {
  if (x!=parent[x])
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
  int noOfScen, x, y, s;
  scanf("%d", &noOfScen);
  for (s=1; s<=noOfScen; s++) {
    bool resultFound = false;
    scanf("%d %d", &noOfBugs, &noOfInter);
    // Init parent, opp
    for (int i=1; i<=noOfBugs; i++) {
      parent[i] = i; opp[i] = 0;
    }
    while (noOfInter--) {
      scanf("%d %d", &x, &y);
      if (resultFound) {
        continue;
      }
      if (getRoot(x) == getRoot(y)) {
        resultFound = true;
      }
      if (opp[x]==0 && opp[y]==0) {
        opp[x] = y; opp[y] = x;
      }
      else if (opp[x] == 0) {
        opp[x] = y;
        merge(x, opp[y]);
      }
      else if (opp[y] == 0) {
        opp[y] = x;
        merge(y, opp[x]);
      }
      else {
        merge(x, opp[y]);
        merge(y, opp[x]);
      }
    }
    printf("Scenario #%d:\n", s);
    if(resultFound)
      printf("Suspicious bugs found!\n\n");
    else
      printf("No suspicious bugs found!\n\n");
  }
  return 0;
}
