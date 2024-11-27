//https://open.kattis.com/problems/manhattanmornings
#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
set<int> xx;
set<int> yy;
vector<pii> p;
vector<int> x;
vector<int> y;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,st1,st2,tp1,tp2;
  cin >> n >> st1 >> st2 >> tp1 >> tp2;

  st1++,st2++,tp1++,tp2++;
  xx.insert(st1);
  xx.insert(tp1);
  yy.insert(st2);
  yy.insert(tp2);


  for(int i=1;i<=n;i++){
    int a,b;
    cin >> a >> b;
    a++,b++;
    xx.insert(a);
    yy.insert(b);
    p.push_back({a,b});
  }
  for(auto e:xx){
    x.push_back(e);
  }
  for(auto e:yy){
    y.push_back(e);
  }
  auto s1=lower_bound(x.begin(),x.end(),st1)-x.begin()+1;
  auto s2=lower_bound(y.begin(),y.end(),st2)-y.begin()+1;
  auto t1=lower_bound(x.begin(),x.end(),tp1)-x.begin()+1;
  auto t2=lower_bound(y.begin(),y.end(),tp2)-y.begin()+1;  
  int dp[x.size()+5][y.size()+5];
  memset(dp,0,sizeof dp);
  for(int i=0;i<n;i++){
    auto v=lower_bound(x.begin(),x.end(),p[i].first)-x.begin()+1;
    auto u=lower_bound(y.begin(),y.end(),p[i].second)-y.begin()+1;
    dp[v][u]++;
  }


  if(s1>=t1 && s2>=t2){
    swap(s1,t1);
    swap(s2,t2);
    for(int i=s1+1;i<=t1;i++){
      dp[i][s2]+=dp[i-1][s2];
    }
    for(int j=s2+1;j<=t2;j++){
      dp[s1][j]+=dp[s1][j-1];
    }
    for(int i=s1+1;i<=t1;i++){
      for(int j=s2+1;j<=t2;j++){
        dp[i][j]+=max(dp[i-1][j],dp[i][j-1]);  
      }
    }  
    cout << dp[t1][t2];
  }
  else if(s1<t1 && s2>=t2){
    swap(s1,t1);
    swap(s2,t2);
    for(int i=s1-1;i>=t1;i--){
      dp[i][s2]+=dp[i+1][s2];
    }
    for(int j=s2+1;j<=t2;j++){
      dp[s1][j]+=dp[s1][j-1];
    }
    for(int i=s1-1;i>=t1;i--){
      for(int j=s2+1;j<=t2;j++){
        dp[i][j]+=max(dp[i+1][j],dp[i][j-1]);
      }
    }
    cout << dp[t1][t2];
  } 
  else if(s1>=t1 && s2<t2){
    for(int i=s1-1;i>=t1;i--){
      dp[i][s2]+=dp[i+1][s2];
    }
    for(int j=s2+1;j<=t2;j++){
      dp[s1][j]+=dp[s1][j-1];
    }
    for(int i=s1-1;i>=t1;i--){
      for(int j=s2+1;j<=t2;j++){
        dp[i][j]+=max(dp[i+1][j],dp[i][j-1]);
      }
    }
    cout << dp[t1][t2];	
//    for(int i=st1;i>=tp1;i--){
//    	for(int j=st2;j<=tp2;j++){
//    		cout << dp[i][j] << ' ';
//		}
//		cout << "\n";
//	}
  }
  else if(s1<t1 && s2<t2){
    for(int i=s1+1;i<=t1;i++){
      dp[i][s2]+=dp[i-1][s2];
    }
    for(int j=s2+1;j<=t2;j++){
      dp[s1][j]+=dp[s1][j-1];
    }
    for(int i=s1+1;i<=t1;i++){
      for(int j=s2+1;j<=t2;j++){
        dp[i][j]+=max(dp[i-1][j],dp[i][j-1]);  
      }
    }  
    cout << dp[t1][t2];
  }
//  for(int i=st1;i<=tp1;i++){
//  	for(int j=st2;j<=tp2;j++){
//  		cout << dp[i][j] << ' ';
//	  }
//	  cout << "\n";
//  }
}


