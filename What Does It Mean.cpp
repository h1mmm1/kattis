#include<bits/stdc++.h>
using namespace std;
const int N=1005,MOD=1e9+7;
vector<pair<int,int>> p[N];
long long int dp[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for(int i=1;i<=n;i++){
    string str;
    int x;
    cin >> str >> x;
    int y=str.size();
    int sum=s.find(str);
    while(sum!=-1){
      p[sum+y].push_back({x,y});
      sum=s.find(str,sum+1);
    }
  }
  dp[0]=1;
  for(int i=1;i<=s.size();i++){
    for(auto e:p[i]){
      int x=e.first;
      int y=e.second;
//      cout <<i << ' ' << x << ' ' << y << "\n";
      dp[i]+=dp[i-y]*x;
      dp[i]%=MOD;
    }
  }
//  for(int i=0;i<=n;i++) cout << dp[i] << ' ';
  cout << dp[s.size()];
}

