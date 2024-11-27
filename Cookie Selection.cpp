//https://open.kattis.com/problems/cookieselection
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace std;
using namespace __gnu_pbds;
using ll=long long int;

typedef tree<
   int, 
   null_type, 
   less_equal<int>, 
   rb_tree_tag,
   tree_order_statistics_node_update> ordered_multiset;


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  string str;
  ordered_multiset s;
  while(cin >> str){
    if(str=="#"){
      int x=s.size();
      if(x%2==0) {
        auto y=s.find_by_order(x/2+1-1);
        cout << *y << "\n";
        s.erase(y);
      }
      else{
        auto y=s.find_by_order((x+1)/2-1);
        cout << *y << "\n";
        s.erase(y);
      }
    }  	
    else{
      int x=stoi(str);
      s.insert(x);
    }
  }
}

