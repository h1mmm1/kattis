#include<bits/stdc++.h>
using namespace std;

int main(){
  //ios::sync_with_stdio(0); cin.tie(0);
  int n;
  while(cin >> n){
    bool chk=true;
    if(n==0) return 0;
    else if(n%4==3) cout << "4" << "\n";
    else if(n<=6) cout << "No such base" << "\n";
    else{
      for(int i=4;i<sqrt(n-3);i++){
        if(n%i==3){
          cout << i << "\n";
          chk=false;
          break;       
        }
      }
      if(chk==true) cout << (n-3)/sqrt(n-3) << "\n";
    }
  }
}

