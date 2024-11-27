#include<bits/stdc++.h>
using namespace std;
string s="";
int a,b,c,d;
bool chk=false;

void rec(int n,int m){
	if(n==0 && m==0){
		int e=0,r=0;
		for(int i=0;i<s.size();i++){
			for(int j=i+1;j<s.size();j++){
				if(s[i]!=s[j] && s[i]=='1') e++;
				else if(s[i]!=s[j] && s[i]=='0') r++; 
			}
		}
		//cout << s << ' ' << r << ' ' << e << "\n";
		if(b==r && c==e && chk==false){
			cout << s;
			chk=true;
		}
		return ;
	}
	if(m>0){
		s+='1';
		rec(n,m-1);
		s.pop_back();
	}	
	if(n>0){
		s+='0';
		rec(n-1,m);
		s.pop_back();
	}

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	long long int cnt1=0,st1,st2;
	cin >> a >> b >> c >> d;
	for(int i=1; ;i++){
		cnt1+=i;
		if(cnt1==a){
			st1=i;
			break;
		}
		if(cnt1>a){
			cout << "impossible";
			return 0;
		}
	}
	cnt1=0;
	for(int i=1; ;i++){
		cnt1+=i;
		if(cnt1==d){
			st2=i;
			break;
		}
		if(cnt1>d){
			cout << "impossible";
			return 0;
		}		
	}	
	rec(st1+1,st2+1);
	if(chk==false) cout << "impossible";
}
