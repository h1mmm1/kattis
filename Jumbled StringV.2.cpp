#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,cnt=0,st1,st2;

void X1(){
	for(int i=1; ;i++){
		cnt+=i;
		if(cnt==a){
			st1=i;
			break;
		}
		if(cnt>a){
			cout << "impossible";
			return;
		}		
	}
	cnt=0;
	for(int i=1; ;i++){
		cnt+=i;
		if(cnt==d){
			st2=i;
			break;
		}
		if(cnt>d){
			cout << "impossible";
			return;
		}		
	}	
	st1++;
	st2++;
	if(st1*st2!=b+c){
		cout << "impossible";
		return;		
	}
	string s="";
	for(int i=1;i<=st1;i++){
		s+='0';
	}
	for(int j=1;j<=st2;j++){
		s+='1';
	}
	int sum=0,x=0;
	while(c!=0){
		if(st1<=c){
//			cout << s[st1-x] << ' ' << s[0+x] << '\n';
			swap(s[st1+x],s[0+x]);
			c-=st1;
		}
		else{
//			cout << s[st1-x] << ' ' << s[c+x-1] << "\n"; 
			swap(s[st1+x],s[st1-c+x]);
			c=0;
		}
		x++;
	}
	cout << s;	
}

void X2(){
	if(b==1 && c==0) cout << "01";
	else if(b==0 && c==1) cout << "10";
	else cout << "impossible";
}

void X3(){
	for(int i=1; ;i++){
		cnt+=i;
		if(cnt==d){
			st1=i;
			break;
		}
		if(cnt>d){
			cout << "impossible";
			return;
		}		
	}	
	st1++;
	if(c==0 && b!=0){
		cout << '0';
		
		for(int i=1;i<=st1;i++){
			cout << '1';
		}
	}
	else if(c!=0 && b==0){
		for(int i=1;i<=st1;i++){
			cout << '1';
		}
		cout << '0';
	}
	else cout << "impossible";		
}

void X4(){
	for(int i=1; ;i++){
		cnt+=i;
		if(cnt==a){
			st1=i;
			break;
		}
		if(cnt>a){
			cout << "impossible";
			return;
		}		
	}	
	st1++;
	if(c==0 && b!=0){
		for(int i=1;i<=st1;i++){
			cout << '0';
		}
		cout << '1';		
	}
	else if(c!=0 && b==0){
		cout << '1';		
		for(int i=1;i<=st1;i++){
			cout << '0';
		}

	}
	else cout << "impossible";		
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> b >> c >> d;
	if(a!=0 && d!=0){
		X1();
	}
	else if(a==0 && d==0){
		X2();
	}
	else if(a==0 && d!=0){
		X3();
	}
	else if(a!=0 && d==0){
		X4();
	}
//	cout << s[st1];
//	cout << ' ' << s[0] << ' ' << s;
}


