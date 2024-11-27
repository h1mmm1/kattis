#include<bits/stdc++.h>
using namespace std;
vector<char> p;
int a[15][15];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  for(int i=1;i<=9;i++) p.push_back(i+'0');
  int n=s.size();
  for(int i=0;i<n;i++){
   a[s[i]-'0'][s[i+1]-'0']++;
  }
  int mn=INT_MAX;
  do{
    int cnt=0,st;
    for(int i=0;i<9;i++){
      if(s[0]==p[i]) cnt+=i;
    }
    for(int i=0;i<9;i++){
      for(int j=i;j<9;j++){
        cnt+=a[p[i]-'0'][p[j]-'0']*(j-i);
        cnt+=a[p[j]-'0'][p[i]-'0']*(j-i);
      }
    }
    mn=min(mn,cnt);
  }while(next_permutation(p.begin(),p.end()));
  cout << mn+n;
}

