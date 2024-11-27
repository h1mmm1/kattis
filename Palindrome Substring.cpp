#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	while(cin >> s){
		set<string> p;

		int n=s.size();		
		for(int i=0;i<n;i++){
			if(i+1<n){
				int l=i,r=i+1;
				while(l>=0 && r<n){
					if(s[l]==s[r]){
				p.insert(s.substr(l,r-l+1));						
						l--;
						r++;
					}
					else break;
				}
			}	
			if(i+2<n){
				int l=i,r=i+2;
				while(l>=0 && r<n){
					if(s[l]==s[r]){
				p.insert(s.substr(l,r-l+1));						
						l--;
						r++;
					}
					else break;
				}				
			}					
		}
		for(auto e:p){
			cout << e << "\n";
		}
		cout << "\n";
	}
}
//sis 0
//isi 1
//AAA 2
