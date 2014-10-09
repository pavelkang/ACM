#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
struct CPost {
  int L, R;
};
CPost posters[10100];
int x[10000010];
struct CNode {
  int L, R;
  bool bCovered;
  CNode *pLeft, *pRight;
};
CNode Tree[1000000];
int nNodeCount = 0;
int Mid(CNode *pRoot) {
  return (pRoot-L+pRoot->R)/2;
}
void buildTree(CNode *pRoot, int L, int R) {
  pRoot->L = L;
  pRoot->R = R;
  pRoot->bCovered = false;
  if (L==R)
    return ;
  nNodeCount++;
  pRoot->pLeft = Tree + nNodeCount;
  nNodeCount++;
  pRoot->pRight = Tree + nNodeCount;
  buildTree(pRoot->pLeft, L, (L+R)/2);
  buildTree(pRoot->pRight, (L+R)/2+1, R);
}
bool post(CNode *pRoot, int L, int R) {
  if (pRoot->bCovered) return false;
  if (pRoot->L==L && pRoot->R==R) {
    pRoot->bCovered = true;
    return true;
  }
  bool bResult;
  if (R<=Mid(pRoot))
    bResult = post(pRoot->pLeft, L, R);
  else if (L>=Mid(pRoot)+1)
    bResult = post(pRoot->pRight, L, R);
  else {
    bool b1 = post(pRoot->pLeft, L, Mid(pRoot));
    bool b2 = post(pRoot->pRight, Mid(pRoot)+1, R);
    bResult = b1 || b2;
  }
  if (pRoot->pLeft->bCovered && pRoot->pRight->bCovered)
    pRoot->bCovered = true;
  return bResult;
}
int main() {
  int t;
  int i, j, k;
  scanf("%d", &t);
  int nCaseNo = 0;
  while (t--) {
    nCaseNo ++;
    scanf("%d", &n);
    int nCount = 0;
    for (i=0; i<n; i++) {
      scanf("%d%d", &posters[i].L, &posters[i].R);
      x[nCount++] = posters[i].L;
      x[nCount++] = posters[i].R;
    }
    sort(x, x+nCount);
    // Unique
    nCount = unique(x, x+nCount) - x;
    // discretize
    int nIntervalNo = 0;
    for (i=0; i<nCount; i++) {
      hash[x[i]] = nIntervalNo;
      if (i<nCount-1) {
        if (x[i+1] - x[i] == 1)
          nIntervalNo ++;
        else
          nIntervalNo += 2;
      }
    }
    buildTree(Tree, 0, nIntervalNo);
    int nSum = 0;
    for (i=n-1; i>=0; i--) {
      if (post(tree, hash[posters[i].L], hash[posters[i], R]))
        nSum ++;
    }
    printf("%d\n", nSum);
  }
}
