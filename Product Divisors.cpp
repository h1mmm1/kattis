#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e6+5;
bool a[N];
int sum[N],mp[N];
vector<int> p;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll dx=0,mod=1e9+7;
	for(int i=2;i*i<N;i++){
		if(a[i]==false){
			for(int j=i*i;j<N;j+=i){
				a[j]=true;
			}
		}
	}
	for(int i=2;i<N;i++){
		if(a[i]==false){
			mp[i]=dx;
			dx++;
			p.push_back(i);
		}
	}
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		for(auto e:p){
			if(e*e>x) break;
			while(x%e==0){
				sum[mp[e]]++;
				x/=e;
			}
		}
		if(x>1) sum[mp[x]]++;
	}
	ll ans=1;
	for(int i=0;i<dx;i++){
		if(sum[i]>0){
			ans*=(sum[i]+1);
			ans%=mod;
		}
	}
	cout << ans;
}
