#include<bits/stdc++.h>
using namespace std;
using ll=long long int;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll n,mod=1000;
	cin >> n;
	ll cnt=1,sum5=0,sum2=0,pw=2;
	while(n>=pw){
		sum2+=n/pw;
		pw*=2;
	}
	pw=5;
	while(n>=pw){
		sum5+=n/pw;
		pw*=5;
	}
	pw=2;
	for(int i=3;i<=n;i++){
		ll x=i;
		while(x%5==0){
			x/=5;
		}
		while(x%2==0){
			x/=2;
		}
		cnt*=x;
		cnt%=mod;
	}
	sum2-=sum5;
	while(sum2>0){
		if(sum2%2==1){
			cnt*=pw;
			cnt%=mod;
		}
		pw*=pw;
		pw%=mod;
		sum2/=2;
	}
	if(n<7){
		cout << cnt;
		return 0;
	}
	if(cnt<10){
		cout << "00" << cnt;
	}
	else if(cnt<100){
		cout << "0" << cnt;
	}
	else cout << cnt;
}
