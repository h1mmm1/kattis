#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e7+1;
bool A[N];
vector<int> p;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i=2;i*i<N;i++){
    if(A[i]==false){
    	p.push_back(i);
      for(int j=i*i;j<N;j+=i){
        A[j]=true;
      }      
    }
  }
  A[1]=A[0]=true;
  ll cnt=0;
  int a,b,c,d;
  ll ans=0;
  cin >> a >> b >> c >> d;
  if(b-a>d-c) swap(a,c),swap(b,d);
  for(int k=a;k<=b;k++){
    int x=k;
    vector<int> s;
    if(A[k]==false){
      ans+=d-c+1-(d/k-(c-1)/k);
    }
    else{
      for(auto e:p){
        if(e*e>x) break;
        if(x%e==0){
          while(x%e==0) x/=e;
          s.push_back(e);
        }
      }          
      if(x>1) s.push_back(x);
      int E=s.size();
      if(E==1) ans+=d-c+1-(d/s[0]-(c-1)/s[0]);
      else if(E==2) ans+=d-c+1-(d/s[0]-(c-1)/s[0])-(d/s[1]-(c-1)/s[1])+(d/s[1]/s[0]-(c-1)/s[1]/s[0]);
      else{
       for(int i=1;i<(1<<E);i++){
         cnt=0;
         int tmp1=c-1; 
         int tmp2=d;
         for(int j=0;j<E;j++){
           if((1<<j)&i){
             tmp1/=s[j];
             tmp2/=s[j];
             cnt++;
           }
           if(tmp2==0) break;
         }
         if(cnt&1) ans+=(tmp1-tmp2);
         else ans-=(tmp1-tmp2);
         //cout << cnt << ' ' << ans << "\n";
       }
       ans+=d-c+1;	  	
     }
    }

    //cout << k << " " << ans << "\n";

  }
  cout << ans;
}
