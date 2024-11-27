#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<pair<ll,ll>> p;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll x,y;
  cin >> x >> y;
  if(x==y){
    cout << x << ' ' << y;
    return 0;
  }
  ll sum=y/x;
  for(ll i=1;i*i<=sum;i++){
    if(sum%i==0){
      if(__gcd(sum/i,i)==1){
        cout << i*x << ' ' << sum/i*x << "\n";
        //if(i!=sum/i){}
        p.push_back({i*x,sum/i*x});
      }
    }
  }
  sort(p.begin(),p.end(),greater<pair<ll,ll>>());
  for(auto e:p){
    cout << e.second << ' ' << e.first << "\n";
  }
}

 
//
//
//MATH OLD
//https://open.kattis.com/problems/primesieve
//https://open.kattis.com/problems/divisorcounts
//https://open.kattis.com/problems/perfectpowers
//
//
//DP OLD
//https://open.kattis.com/problems/homework
//
//MATH PRIME FACTOR
//https://open.kattis.com/problems/productdivisors
//https://open.kattis.com/problems/divisors
//https://open.kattis.com/problems/threedigits
//
//MATH OBSERVATION
//https://open.kattis.com/problems/magical3
//
//MATH NUMBER THEORY
//https://open.kattis.com/problems/gcdandlcm
//https://open.kattis.com/problems/coprimeintegers
//
//MATH + DSU
//https://open.kattis.com/problems/numbersetshard
//
//LCS with LIS
//https://open.kattis.com/problems/princeandprincess
//
//DIGIT DP
//https://open.kattis.com/problems/hillnumbers
//https://open.kattis.com/problems/cudak
//
//DP SUBSET
//https://open.kattis.com/problems/equalsumseasy
//https://open.kattis.com/problems/perfectskyline
//https://open.kattis.com/problems/data
//
//DP KNAPSACK
//https://open.kattis.com/problems/balanceddiet
//https://open.kattis.com/problems/ninepack
//https://open.kattis.com/problems/tugofwar
//https://open.kattis.com/problems/orders
//
//DP WITH QUEUE/BOTTOM UP
//https://open.kattis.com/problems/volumeamplification
//
//RECURSIVE BACKTRACKING
//https://open.kattis.com/problems/font
//
//RECURSIVE DIVIDE & CONQUER
//https://programming.in.th/tasks/o60_oct_c2_craft
//
//STRING OLD
//https://open.kattis.com/problems/powerstrings
//
//GRAPH DAG
//https://open.kattis.com/problems/fibtour
//
//SSSP STATE
//https://programming.in.th/tasks/o58_oct_c2_routesontrees
//
//SIMULATION
//https://open.kattis.com/problems/godzilla

