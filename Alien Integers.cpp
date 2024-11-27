#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
bool a[15];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n,t=0,x=0,y=0;
  cin >> n;
  ll m=n;
  string s=to_string(n);
  while(m>0){
    a[m%10]=true;
    m/=10;
    t++;
  }
  bool chk=false;
  for(int i=1;i<10;i++){
    if(a[i]==false){
      chk=true;
      break;
    }
  }
  
  if(chk==false && a[0]==false){
    cout << '0';
    return 0;
  }
  if(chk==false){
    cout << "Impossible";
    return 0;
  }
  for(int i=1;i<10;i++){
    if(a[s[0]-'0'-i]==false && s[0]-'0' -i>=0){
      x=s[0]-'0'-i;
      break;
    }
  }
  for(int i=9;i>=0;i--){
    if(a[i]==false){
      for(int j=1;j<=t-1;j++){
        x*=10;
        x+=i;
      }
      break;
    }
  }
  for(int i=1;i<10;i++){
    if(s[0]-'0'+i==10){
      int sum=1;
      while(a[s[0]-'0'+i+sum-10]==true && s[0]-'0'+i+sum-10>10){
        sum++;
      }
      y=s[0]-'0'+i+sum-10;
      t++;
      break;
    }
    else if(a[s[0]-'0'+i]==false){
      y=s[0]-'0'+i;
      break;
    }
  }
  for(int i=0;i<10;i++){
    if(a[i]==false){
      for(int j=1;j<=t-1;j++){
        y*=10;
        y+=i;
      }
      break;
    }
  }
// cout << x << '\n' << y;
  if(n-x>y-n) cout << y;
  else if(n-x<y-n){
    if(x>0) cout << x;
    else cout << y;
  }
  else cout << x << ' ' << y;
}
