#include<bits/stdc++.h>
using namespace std;
const int N=3e4+5;
int dp[N],id[N],a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		int m;
		cin >> m;
		for(int j=m;j<=N;j++){
			if(dp[j-m]>0){
				dp[j]+=dp[j-m];
				id[j]=i;
				a[j]=j-m;
			}
		}
	}
	int q;
	cin >> q;
	for(int i=1;i<=q;i++){
		int x;
		cin >> x;
		if(dp[x]==0) cout << "Impossible\n";
		else if(dp[x]!=1) cout << "Ambiguous\n";
		else{
			vector<int> p;
			while(x>0){
				p.push_back(id[x]);
				x=a[x];
			}
			sort(p.begin(),p.end());
			for(auto e:p) cout << e << ' ';
			cout << "\n";
		}
	}
//	for(int i=1;i<=10;i++){
//		cout << dp[i]  << ' ';
//	}
}
