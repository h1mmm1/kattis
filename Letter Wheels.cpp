#include<bits/stdc++.h>
using namespace std;
bool chk[5][5005];
vector<int> p,v;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  string a,b,c;
  cin >> a >> b >> c;
  // string x=a,y=b,z=c;
  int n=a.size();
  a+=a;
  b+=b;
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      if(a[i+k]==b[i]){
        chk[0][k]=true;
        break;
      }
    }
    if(chk[0][k]==false) p.push_back(k);
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      if(a[i+k]==c[i]){
        chk[1][k]=true;
        break;

      }
    }   
    if(chk[1][k]==false) v.push_back(k);
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      if(b[i+k]==c[i]){
        chk[2][k]=true;
        break;
      }
    }    
  }    
  int mn=1e9,x,y;
  for(auto e:p){
    for(auto r:v){
      if(chk[2][(r-e+n)%n]==false){
        x=min(e,n-e);
        y=min(r,n-r);
        mn=min(mn,x+y);
        mn=min(mn,max(e,r));
        mn=min(mn,max(n-e,n-r));
//         cout << e << ' ' << r << "\n";
      }
    }
  }
  if(mn==1e9) cout << "-1";
  else cout << mn;
//  cout << "\n";
//   for(int j=0;j<3;j++){
//     for(int i=0;i<n;i++){
//       cout << chk[j][i] << ' ';
//     }
//     cout << "\n";  	
//   }
}    
