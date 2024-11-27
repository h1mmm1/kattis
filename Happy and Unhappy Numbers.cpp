#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int dp[N];
int chk[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  for(int k=1;k<N;k++){
    vector<int> p;
    int cnt=k;
    bool t=false;
    if(chk[k]==2){
    	dp[k]+=dp[k-1];
    	continue;
	}
    //cout << k << ' ';
    while(cnt>=10){
      p.push_back(cnt);     	
       string s=to_string(cnt);
      if(chk[cnt]==2){
        t=true;
        break;
    }
      cnt=0; 
      for(int i=0;i<s.size();i++){
        int x=s[i]-'0';
        cnt+=x*x;
      }
      //cout << cnt << ' ';
    }
    if(t==false){
     cnt=cnt*cnt;
      while(cnt>=10){
        string s=to_string(cnt);
        p.push_back(cnt);       
        if(chk[cnt]==2) break;
        cnt=0; 
        for(int i=0;i<s.size();i++){
          int x=s[i]-'0';
          cnt+=x*x;
        }
      //cout << cnt << ' ';
      }      	
    }

    if(cnt==1 && chk[k]!=2){
      dp[k]++;
      for(auto e:p){
        chk[e]=1;
    }
  }
    else{
      for(auto e:p){
      chk[e]=2;    		
    }

  }
    dp[k]+=dp[k-1];
    //cout << "\n";
//    cout << k << ' ';
//    for(auto e:p){
//    	cout << e << ' ';
//	}
//	cout << "\n";
  }
  int q;
  cin >> q;
  while(q--){
    int n,m;
    cin >> n >> m;
    cout << dp[m]-dp[n-1] << "\n";
  }
//  for(int i=1;i<=100;i++){
//  	cout << i << ' '<< dp[i] << '\n';
//  }
}
