#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		deque<int> q;
		string str,s;
		int n;
		cin >> str >> n >> s;
		int cnt=0;
		for(int i=0+1;i<s.size()-1;i++){
			if(s[i]!=','){
				cnt=cnt*10+s[i]-'0';
			}
			else{
				q.push_back(cnt);
				cnt=0;
			}
		}
		if(n>0) q.push_back(cnt);
		bool chk=true,ok=true;
		for(auto e:str){
			if(e=='R') chk=!chk;
			else if(e=='D'){
				if(q.empty()){
					cout << "error" << "\n";
					ok=false;
					break;					
				}
				else{
					if(chk==false){
						q.pop_back();
					}
					else{
						q.pop_front();
					}
				}
			}
		}
		if(ok==true){
			cout << "[";
			if(chk==true){
				for(int i=0;i<q.size();i++){
					cout << q[i];
					if(i!=q.size()-1) cout << ',';
				}
			}
			else{
				for(int i=q.size()-1;i>=0;i--){
					cout << q[i];
					if(i!=0) cout << ",";
				}	
			}
			cout << "]" << "\n";
		}
//		for(int e:q){
//			cout << e << " ";
//		}
	}
}
/*
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]
*/
