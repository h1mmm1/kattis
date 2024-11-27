//https://open.kattis.com/problems/stringmatching
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int P=53,MOD=1e9+7,N=2e6+6;
ll p[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  p[0]=1;
  for(int i=1;i<N;i++){
    p[i]=p[i-1]*P;
    p[i]%=MOD;
  }
    
  string s,str;
  while(getline(cin,s)){
    getline(cin,str);
    ll n=s.size(),m=str.size();
    ll x=max(n,m);
    ll h[x+5];
    memset(h,0,sizeof h);
    for(int i=1;i<=m;i++){
      h[i]=h[i-1]+str[i-1]*p[i];
      h[i]%=MOD;
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
      cnt+=s[i-1]*p[i];
      cnt%=MOD;
    }
    for(int i=0;i<=m-n;i++){
      x= (h[i+n]-h[i]+MOD)%MOD;
      if(x==cnt) cout << i << ' ';
      cnt*=P;
      cnt%=MOD;
    }
    cout << "\n";
  }

//  h0 h1 h2 h3
  
  
//   s1*p1+s2*p2+s3*p3+s4*p4+s5*p5
// h[0]=0
// h[1]=s1p1
// h[2]=s1p1+s2p2
// h[3]=s1p1+s2p2+s3p3
// h[4]=s1p1+s2p2+s3p3+s4p4
// h[5]=s1p1+s2p2+s3p3+s4p4+s5p5

//        s3p3+s4p4+s5p5
//        s3p1+s4p2+s5p3
  
}
