#include<bits/stdc++.h>
using namespace std;
const int N=5005;
bool dp[N][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  string str,s,c;
  cin >> str >> s >> c;
  dp[0][0]=true;
  for(int i=1;i<=s.size();i++){
    if(str[i-1]==s[i-1]) dp[0][i]=true;
    else dp[0][i]=false;
  }
  for(int i=1;i<=c.size();i++){
    if(str[i-1]==c[i-1]) dp[i][0]=true;
    else dp[i][0]=false;
  }
  for(int i=1;i<=c.size();i++){
    for(int j=1;j<=s.size();j++){
      if(dp[i][j-1]==true){
        if(str[i+j-1]==s[j-1]) dp[i][j]=true;
      }
      if(dp[i-1][j]==true){
        if(str[i+j-1]==c[i-1]) dp[i][j]=true;
      }
    }
  }
  if(dp[c.size()][s.size()]==true) cout << "yes";
  else cout << "no";
}

