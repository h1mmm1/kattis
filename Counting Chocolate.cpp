#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int a[100005];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,cnt=0;
	cin >> n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cnt+=a[i];		
	}
	if(cnt%2!=0){
		cout << "NO";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=100000;j>=a[i];j--){
			dp[j]|=dp[j-a[i]];			
		}
	}
	if(dp[cnt/2]>=1) cout << "YES";
	else cout << "NO";
//	for(int i=1;i<=30;i++){
//		cout << i << ' ' << dp[i] <<  "\n";
//	}
}

