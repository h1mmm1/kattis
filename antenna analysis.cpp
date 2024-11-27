#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=4e5+5;
ll a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll n,c,mx1=LLONG_MIN,mx2=LLONG_MIN;
	cin >> n >> c;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		ll x=-a[i]+c*i;
		ll y=a[i]+c*i;
		mx1=max(mx1,x);
		mx2=max(mx2,y);
		cout << max(a[i]-c*i+mx1,-a[i]-c*i+mx2) << " ";
	}
}

