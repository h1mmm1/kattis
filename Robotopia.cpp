#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--){
		int x1,y1,x2,y2,sum1,sum2,cnt=0,ans1,ans2;
		cin >> x1 >> y1 >> x2 >> y2 >> sum1 >> sum2;
		for(int i=1; ;i++){
			int e=x1*i;
			int r=y1*i;
			if((sum1-e)%x2==0 && (sum2-r)%y2==0 && (sum1-e)/x2==(sum2-r)/y2){
				cnt++;
				ans1=i;
				ans2=(sum1-e)/x2;
			}
			if(e>sum1 || r>sum2) break;
		}
		if(cnt!=1) cout << "?\n";
		else cout << ans1 << " " << ans2 << "\n";
	}
}
