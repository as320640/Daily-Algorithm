/*
题目：洛谷P1359
*/

#include <bits/stdc++.h>
const int N=210;

int dp[N];//dp数组的含义：到i站最小的花费
int r[N][N];//n数组的含义：从i站到j站的花费
int n;

int main(){
scanf("%d",&n);
for(int i=1;i<n;i++){
  for(int j=i+1;j<=n;j++){
    scanf("%d",&n[i][j]);
  }
}
for(int i=2;i<=n;i++){
  dp[i]=INT_MAX;
  for(int k=1;k<i;k++){
    dp[i]=std::min(dp[k]+r[k][i],dp[i]);
  }
}
printf("%d",dp[n]);
return 0;
}
