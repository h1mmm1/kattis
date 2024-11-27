#include<bits/stdc++.h>
using namespace std;
vector<int> p;
unordered_set<int> s;
string str;
int x;

int chk(string x){
  int ans=0;
  int cnt=1;
  for(int i=x.size()-1;i>=0;i--){
    ans+=(x[i]-'0')*cnt;
    cnt*=2;
  }
  return ans;
}
void dfs(string c){
	if(c.size()>=31) return;
  x=chk(c);
  if(x>5005000005) return;
  if(c[0]!='0') s.insert(x);
  str='1'+c+'1';
  dfs(str);
  str='0'+c+'0';
  dfs(str);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  dfs("1");
  dfs("0");
  dfs("11");
  dfs("00");
  for(auto e:s){
    p.push_back(e);
  }
  //p.push_back(0);
  sort(p.begin(),p.end());
  int n;
  cin >> n;
  cout << p[n-1];
  //for(auto e:p) cout << e << "\n";
} 
