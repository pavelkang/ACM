#include<cstdio>
int main() {
  int N;
  scanf("%d", &N);
  if (N==2) {printf("NO\n");return 0;}
  if (N%2) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}
