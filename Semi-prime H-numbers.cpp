#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2,lim=N-1;
bool a[N];
long long int dp[N];
vector<long long int> p;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=1;4*i+1<N;i++){
		if(a[4*i+1]==false){
			for(int j=(4*i+1)*2;j<N;j+=4*i+1){
				a[j]=true;
			}
		}
	}
	for(int i=1;4*i+1<N;i++){
		if(a[4*i+1]==false) p.push_back(4*i+1);
	}
	for(int i=0;i<p.size();i++){
		for(int j=i;j<p.size();j++){
			long long int x=p[i]*p[j];
			if(x>lim) break;
			dp[x]=1;
		}
	}
	for(int i=1;i<N;i++){
		dp[i]+=dp[i-1];
	}
//	for(int i=0;i<100;i++){
//		cout << i << ' ' << p[i] << "\n";
//	}	
	int n;
	while(cin >> n){
		if(n==0) return 0;
		cout << n << ' ' << dp[n] << "\n";
	}

}