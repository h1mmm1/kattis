#include<bits/stdc++.h>
using namespace std;
//const int N=46500;
//bool a[N];
//vector<int> p;

int main(){
//    ios::sync_with_stdio(0); cin.tie(0);
//  for(int i=2;i*i<N;i++){
//      if(a[i]==false){
//          for(int j=i*i;j<N;j+=i){
//              a[j]=true;
//          }
//      }
//  }
//  for(int i=2;i<N;i++){
//      if(a[i]==false) p.push_back(i);
//  }
    long long int n;
    long long int x,cnt=0;
    while(cin >> n){
        if(n==0) return 0;
        if(n==1 || n==-1){
            cout << "1" <<"\n";
            continue;
        }
        if(n>1){
        	x=n;
            for(int i=2;i<=sqrt(n);i++){
                x=n,cnt=0;
                while(x%i==0){
                    x/=i;
                    cnt++;
                }
                if(x==1 && cnt>1){
                	cout << cnt << "\n";
                	break;
				}   
            }
            if(x!=1) cout << "1\n"; 
        }
        else if(n<-1){
          n=-n;
          x=n;
          for(int i=2;i<=sqrt(n);i++){
              x=n,cnt=0;
              while(x%i==0){
                  x/=i;
                  cnt++;
              }
             if(x==1 && cnt>1){
                if(cnt%2==0) cout << "1\n";
                else cout << cnt << "\n";
                break;
             }              
          }
		  if(x!=1) cout << "1\n";
        }
//2-7
//3-1
    }
}
