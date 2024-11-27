#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=2e7+5;
ll a[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int k,n;
  cin >> k >> n;
  ll sum=0;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    sum+=a[i];
  }
  if(sum%k!=0){
    cout << "NO";
    return 0;
  }
  for(int i=1;i<=n;i++){
    a[n+i]=a[i];
  }
  for(int i=1;i<=n+n;i++) a[i]+=a[i-1]; 
  sum/=k;
  for(int i=1;i<=n;i++){
    int l=i,cnt=0;
//    cout << i << "\n\n";
    for(int r=i;r<=n+i;r++){
//    cout << r << ' ' << l << ' ' << a[r] << ' ' << a[l-1] << "\n";	
      if(a[r]-a[l-1]==sum){
        l=r+1;
        cnt++;
      }
      if(a[r]-a[l-1]>sum){
        break;
      }
    }
    if(cnt==k){
      cout << "YES";
      return 0;
    }
//    cout << cnt << "\n\n";
  }
  cout << "NO";
}
