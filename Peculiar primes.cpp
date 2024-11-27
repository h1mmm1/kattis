#include<bits/stdc++.h>
using namespace std;
long long int a[15],x,y,n;
vector<long long int> p;

void dfs(long long int m,int i){
  if(m>y) return;
  if(m>=x) p.push_back(m);
  for(int j=i;j<=n;j++){
    dfs(m*a[j],j);
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  while(cin >> n){
  	if(n==0) return 0;
  	p.clear();
    for(int i=1;i<=n;i++){
      cin >> a[i];
    }
    cin >> x >> y;
    dfs(1,1);
    sort(p.begin(),p.end());
    if(p.size()==0){
    	cout << "none" << '\n';
    	continue;
	}
    for(int i=0;i<p.size();i++){
      cout << p[i];
      if(i!=p.size()-1) cout << ",";
    }
    cout << '\n';
  }
} 
