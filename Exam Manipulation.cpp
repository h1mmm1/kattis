#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
string s;
string str[1200];
int cnt=1;

void rec(int n){
	if(n==0){
		str[cnt]=s;
		cnt++;
		//cout << s << "\n";
		return;
	}
	s+='T';
	rec(n-1);
	s.pop_back();
	s+='F';
	rec(n-1);
	s.pop_back();
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,sum=0,mx=INT_MIN,mn=INT_MAX;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	rec(m);
	int x=pow(2,m);
	for(int k=1;k<=x;k++){
		mn=INT_MAX;
		for(int i=1;i<=n;i++){			
			sum=0;
			for(int j=1;j<=m;j++){
				if(str[k][j-1]==a[i][j]) sum++;
			}
			mn=min(mn,sum);
		}
		mx=max(mx,mn);
	}
	cout << mx;
//	for(int i=1;i<=x;i++){
//		cout << str[i] << '\n';
//	}
}
// 660

