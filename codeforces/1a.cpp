#include<cstdio>
#include<math.h>
#include<iostream>
using namespace std;
int main() {
  int w, h, a;
  scanf("%d %d %d", &w, &h, &a);
  cout << (long long)(ceil((double)w/(double)a)*ceil((double)h/(double)a));
  //printf("%I64d\n", );
  return 0;
}
