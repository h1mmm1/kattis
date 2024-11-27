#include<bits/stdc++.h>
using namespace std;
const int N=33000;
bool a[N];
vector<int> p;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  for(int i=2;i*i<N;i++){
    if(a[i]==false){
      for(int j=i*i;j<N;j+=i){
        a[j]=true;
      }
    }
  }
  for(int i=2;i<N;i++){
    if(a[i]==false) p.push_back(i);
  }
  while(t--){
  	vector<int> q;
    int n;
    cin >> n;
    int m=n,mm=n;
    while(m>0){
      if(m%2==0){
        m/=2;
      }
      else break;
    }
    if(m==1 || n==1){
      cout << "IMPOSSIBLE"<< "\n";
      continue;
    }  
	  
    if(n%2==1){
      cout << n << " = " << n/2 << " + " << n/2+1 << "\n";
      continue;
    }

  
    for(auto e:p){
      bool chk=false;
       if(e*e>n) break;
      while(n%e==0){
        n/=e;
        chk=true;
       }
       if(chk==true){
         if(e==2) q.push_back(mm/n*2);
         else q.push_back(e);
       }
    }
    if(n>1) q.push_back(n);
    sort(q.begin(),q.end());
    int x=q[0];
    //for(auto e:q) cout << e << ' ';
    cout << mm << " = ";
    
    if(x%2==0){
      x/=2;
      mm/=x;
      x*=2;
      for(int i=mm/2-x/2+1;i<=mm/2+x/2;i++){
      	cout << i;
      	if(i!=mm/2+x/2) cout << " + ";
	  }
	  cout << "\n";
    }
    else{  
	  mm/=x;    
      for(int i=mm-x/2;i<=mm+(x/2);i++){
        cout << i;
		if(i!=mm+x/2) cout << " + ";
      }
      cout << "\n";
    }
  }
}
