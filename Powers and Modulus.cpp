#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  if(n%2==1) cout << "0";
  else{
    long long int ans=1;
    for(int i=1;i<=m;i++){
      ans*=(n/2);
      ans%=n;
    }
    cout << ans;
  }
}

