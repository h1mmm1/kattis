#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N];
int mp[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i=1; ;i++){
    string s;
    cin >> s;
    bool chk=false;
    int n=0,sum=1;
    for(int i=s.size()-1;i>=0;i--){
      if(s[i]==':') continue;
      n+=(s[i]-'0')*sum;
      sum*=10;
    }
    if(n==0) return 0;
    for(int i=1;i<=n;i++){
      cin >> a[i];
      mp[a[i]]=i;

    }
    for(int k=1;k<=n;k++){
      for(int i=0;i<n;i++){
        int id=i;
        if(id+k*2>=n) break;
        if(mp[id+k]>mp[id] && mp[id+k*2]>mp[id+k]){
          cout << "no\n";
          chk=true;
          break;
        }
        if(mp[id+k]<mp[id] && mp[id+k*2]<mp[id+k]){
          cout << "no\n";
          chk=true;
          break;
        }

      }
      if(chk) break;

    }
    if(chk==false) cout << "yes\n";
  }
}
