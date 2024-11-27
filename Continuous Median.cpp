//https://open.kattis.com/problems/continuousmedian
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
  int t;
  cin >> t;
  while(t--){
    ordered_multiset s;
    int n;
    ll sum=0;
    cin >> n;
    for(int i=1;i<=n;i++){
      int a;
      cin >> a;
      s.insert(a);
      int x=*s.find_by_order(i/2);
      if(i%2==0){
        int y=*s.find_by_order(i/2-1);
        sum+=(x+y)/2;
      }
      else sum+=x;
    }
    cout << sum << "\n";
//    cout << s.size();
  }
  
}

