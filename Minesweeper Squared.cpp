#include<bits/stdc++.h>
using namespace std;
int n,st;
bool chk[4005];
vector<int> p,v;
void rec(int i){
  if(i>4*n+4){
    if(i==4*n+4+st){
      p.back()=st;
      for(auto e:p){
        chk[e]=true;
      }
    }
    return;
  }
  if(i==n-1 || i==2*n || i==3*n+1 || i==4*n+2){
    p.push_back(i+3);
    rec(i+3);
    p.pop_back();
    p.push_back(i+4);
    rec(i+4);
    p.pop_back();
    p.push_back(i+5);
    rec(i+5);
    p.pop_back();
  }
  else if(i==n || i==2*n+1 || i==3*n+2 || i==4*n+3){
    p.push_back(i+5);
    rec(i+5);
    p.pop_back();
  }
  else if(i==n+1 || i==2*n+2 || i==3*n+3 || i==4*n+4){
    p.push_back(i+4);
    rec(i+4);
    p.pop_back();
  }
  else{
    p.push_back(i+3);
    rec(i+3);
    p.pop_back();
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  if(n==1){
  	cout << '0';
  	return 0;
  }
  st=1;
  rec(st);
  st=2;
  rec(st);
  st=3;
  rec(st);
  st=4;
  rec(st);
  int cnt=0;
  for(int i=1;i<=4*n+4;i++){
    if(chk[i]==false){
      v.push_back(i);
    }
  }
  cout << v.size() << '\n';
  for(int e:v) cout << e << ' ';
}

