#include<cstdio>
#include<math.h>
using namespace std;
const int INF = 0xffffff0; // ???
int minV = INF;
int maxV = -INF;

struct Node {
  int L, R;
  int minV, maxV;
  int mid() {
    return (L+R)/2;
  }
};

Node tree[800010];

int min(int a, int b) {
  return a<b?a:b;
}

int max(int a, int b) {
  return a<b?b:a;
}

void buildTree(int root, int L, int R) {
  tree[root].L = L;
  tree[root].R = R;
  tree[root].minV = INF;
  tree[root].maxV = -INF;
  if (L!=R) {
    buildTree(2*root+1, L, (L+R)/2);
    buildTree(2*root+2, (L+R)/2+1, R);
  }
}

/*
  Insert A_i with value i
*/
void insert(int root, int i, int v) {
  // Leave node
  if (tree[root].L == tree[root].R) {
    tree[root].minV = tree[root].maxV = v;
    return ;
  }
  tree[root].minV = min(tree[root].minV, v);
  tree[root].maxV = max(tree[root].maxV, v);
  if (i<=tree[root].mid())
    insert(root*2+1, i, v);
  else
    insert(root*2+2, i, v);
}

/*
  Query max and min from [s, e]
 */
void query(int root, int s, int e) {
  if (tree[root].minV>=minV && tree[root].maxV<=maxV)
    return ;
  if (tree[root].L == s && tree[root].R == e) {
    minV = min(minV, tree[root].minV);
    maxV = max(maxV, tree[root].maxV);
    return ;
  }
  if (e<=tree[root].mid())
    query(root*2+1, s, e);
  else if (s>tree[root].mid())
    query(root*2+2, s, e);
  else {
    query(root*2+1, s, tree[root].mid());
    query(root*2+2, tree[root].mid()+1, e);
  }
}

int main() {
  int N, Q, h;
  int i, j, k;
  scanf("%d%d", &N, &Q);
  buildTree(0, 1, N);
  for (i = 1; i<=N; i++) {
    scanf("%d", &h);
    insert(0, i, h); // Insert cow's height
  }
  for (i=0; i<Q; i++) {
    int s, e;
    scanf("%d%d", &s, &e);
    minV = INF;
    maxV = -INF;
    query(0, s, e);
    printf("%d\n", maxV-minV);
  }
  return 0;
}
