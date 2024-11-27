#include<bits/stdc++.h>
using namespace std;
long long int a[210005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  sort(a+1,a+n+1,greater<long long int>());
  long long int x=a[1];
  long long int y=a[2];
  long long int cnt=1;
  if(x==y){
  	cout << y << ' ' << x;
  	return 0;
  }
  while(x%y==0){
    if(a[cnt+1]==a[cnt+2]) break;  	
    y=a[cnt+2];
    cnt++;
    //if(a[cnt+1]==a[cnt+2]) break;
  }
  cout << y << ' ' << x;
}
