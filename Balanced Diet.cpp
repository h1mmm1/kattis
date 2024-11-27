#include<bits/stdc++.h>
using namespace std;
int a[150];
int dp[12005];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin >> n){
		if(n==0) return 0;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			sum+=a[i];
		}
		memset(dp,0,sizeof dp);
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=12001;j>=a[i];j--){
				dp[j]|=dp[j-a[i]];
			}
		}
//		for(int i=1300;i<1350;i++){
//			cout << dp[i] << ' ';
//		}
		int x;
		if(sum%2==1) x=sum/2+1;
		else x=sum/2;
		for(int i=x;i<=sum;i++){
			if(dp[i]==1 && dp[sum-i]==1){
				cout << i << ' ' << sum-i << '\n'; break;
			}
		}
	}
}
