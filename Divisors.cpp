#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=500;
bool a[N];
vector<ll> p;
ll mp[N],cnt[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=2;i*i<N;i++){
		if(a[i]==false){
			for(int j=i*i;j<N;j+=i){
				a[j]=true;
			}
		}
	}
	ll id=0;
	p.push_back(2);
	mp[2]=id++;
	for(int i=3;i<N;i+=2){
		if(a[i]==false){
			p.push_back(i);
			mp[i]=id++;
		}
	}
	ll n,k;
	while(cin >> n >> k){
		for(auto e:p){
			ll x=e;
			if(x>n) break;
			while(n>=x){
				cnt[mp[e]]+=n/x;
				x*=e;
			}
		}
		for(auto e:p){
			ll x=e;
			if(x>k) break;
			while(k>=x){
				cnt[mp[e]]-=k/x;
				x*=e;
			}
		}
		ll y=n-k;
		for(auto e:p){
			ll x=e;
			if(x>y) break;
			while(y>=x){
				cnt[mp[e]]-=y/x;
				x*=e;
			}
		}
		ll ans=1;
		for(int i=0;i<id;i++){
			if(cnt[i]!=0){
				ans*=(cnt[i]+1);
//				cout << mp[i] << " " << cnt[mp[i]] << " " << p[i] << "\n";
//				cout << i << "\n";
			}
		}
		cout << ans << "\n";
//		for(int i=0;i<id;i++){
//			cout << i << ' ' << cnt[mp[i]]<< ' ' << mp[i] << "\n";
//		}
		memset(cnt,0,sizeof cnt);		
	}
}
