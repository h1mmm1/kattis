#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int kmp[N];

void KMP(string p){
	int m=p.size();
  	for(int i=1,j=0;i<m;i++){
    	while(j>0 && p[j]!=p[i]) j=kmp[j-1];
   		if(p[j]==p[i]) kmp[i]=++j;
	}
}
int KMP_1(string s,string p){
	int n=s.size();
	int m=p.size();
 		for(int i=1,j=0;i<n;i++){
    		while(j>0 && p[j]!=s[i]) j=kmp[j-1];
    		if(p[j]==s[i]) ++j;
    		if(j==m) return i-j+1;
  		}
  	return -1;	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string p;
	while(cin >> p){
		if(p==".") return 0;
		memset(kmp,0,sizeof kmp);
		string s=p+p;
		KMP(p);
		cout <<  p.size()/KMP_1(s,p) << "\n";
		
	}
}
