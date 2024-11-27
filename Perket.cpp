#include<bits/stdc++.h>
using namespace std;
int a[15];
int b[15];
int n,mn=INT_MAX;
void rec(int mul,int sum,int i){
  if(i==n){
    return;
  }
  rec(mul,sum,i+1);
  mn=min(mn,abs(mul*a[i+1]-(sum+b[i+1])));
  rec(mul*a[i+1],sum+b[i+1],i+1);

}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i] >> b[i]; 
  }
  rec(1,0,0);
  cout << mn;
}
