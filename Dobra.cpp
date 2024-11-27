#include<bits/stdc++.h>
using namespace std;
string s;
int a[105];
long long int ans=0;

bool chk(){
	bool test=true,con=false;
	int cnt=0;
	for(char e:s){
		if(e=='L') con=true;
		if(e=='A' || e=='E' || e=='I' || e=='O' || e=='U'){
			if(test==true){
				cnt++;
			}
			else{
				test=true;
				cnt=1;
			}
		}
		else{
			if(test==true){
				test=false;
				cnt=1;
			}
			else{
				cnt++;
			}
		}
		if(cnt>=3){
			return false;
		}
	}
	return con;
}

void rec(int i){
	if(i==s.size()){
		if(chk()==true){
			long long int x=1;
			for(int j=0;j<s.size();j++){
				x*=a[j];
			}
			ans+=x;
		}
		return;
	}
	if(s[i]!='_'){
		rec(i+1);
	}
	else{
		s[i]='L';
		rec(i+1);
		
		s[i]='A';
		a[i]=5;		
		rec(i+1);
		
		s[i]='B';
		a[i]=20;//26-5-1		
		rec(i+1);
		
		s[i]='_';
		a[i]=1;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	for(int i=0;i<100;i++){
		a[i]=1;
	}
	rec(0);
	cout << ans;
}
