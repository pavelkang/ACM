#include<cstdio>
#include<algorithm>
using namespace std;
int pyramid[27][27];
int n;
int maxSum[27];
int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    for (int j=0; j<=i; j++) {
      scanf("%d", &pyramid[i][j]);
    }
  }
  for (int i=0; i<n; i++) {
    maxSum[i] = pyramid[n-1][i];
  }
  for (int i=n-2; i>=0; i--) {
    for (int j=0; j<=i; j++) {
      maxSum[j] = pyramid[i][j] + max(maxSum[j], maxSum[j+1]);
    }
  }
  printf("%d\n", maxSum[0]);
  return 0;
}
