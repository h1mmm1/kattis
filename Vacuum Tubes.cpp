#include<bits/stdc++.h>
using namespace std;
int a[2005];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int l1,l2,n,cnt1=0,cnt2=0,mx=0;
	cin >> l1 >> l2 >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt1=0;
			cnt2=0;
			if(a[i]+a[j]<l1){
				cnt1=a[i]+a[j];
				for(int k=1;k<=n;k++){
					if(k==i || k==j) continue;
					for(int p=k+1;p<=n;p++){
						if(p==j || p==i) continue;
						if(a[k]+a[p]<l2){
							cnt2=a[k]+a[p];
							mx=max(cnt1+cnt2,mx);
						}
					}
				}				
			} 
			

		}
	}
	if(mx!=0) cout << mx;
	else cout << "Impossible";
}
