#include<bits/stdc++.h>
using namespace std;
const int N=15;
string a[N][N];
int r[N][N],c[N][N],d[N][N];
bool chk=false;

void rec(int x,int y){
//	cout << x << ' ' << y << "\n";
  if(x==6 && y==5 && !chk){
    for(int i=0;i<6;i++){
      for(int j=0;j<6;j++){
        cout << a[i][j] << " ";
      }
      cout << "\n";
    }
    chk=true;
    return;
  }	
  
  if(x==6 && !chk) rec(0,y+1);
  if(a[x][y].size()==1 && !chk){
    if(a[x][y]=="-"){
      for(int i=1;i<=9;i++){
        if(r[i][x] || c[i][y] || d[i][2*(x/2)+y/3]) continue;
        a[x][y]=i+'0';
        r[i][x]=c[i][y]=d[i][2*(x/2)+y/3]=true;
        rec(x+1,y);
        a[x][y]="-";
        r[i][x]=c[i][y]=d[i][2*(x/2)+y/3]=false;  			
    }
  }
  else{
    rec(x+1,y);
  }
  }
  
  else if(a[x][y].size()==3 && !chk){
    if(a[x][y]=="-/-"){
    for(int i=1;i<=9;i++){
      if(r[i][x] || c[i][y] || d[i][2*(x/2)+y/3]) continue;
      for(int j=i+1;j<=9;j++){
        if(r[j][x] || c[j][y] || d[j][2*(x/2)+y/3]) continue;
        a[x][y][0]='0'+i;
        a[x][y][2]='0'+j;
        r[i][x]=c[i][y]=d[i][2*(x/2)+y/3]=true;
        r[j][x]=c[j][y]=d[j][2*(x/2)+y/3]=true;
        rec(x+1,y);
        a[x][y][0]='-';
        a[x][y][2]='-';
        r[i][x]=c[i][y]=d[i][2*(x/2)+y/3]=false;
        r[j][x]=c[j][y]=d[j][2*(x/2)+y/3]=false;
      }
    }
  }
  else if(a[x][y][0]=='-'){
    for(int i=1;i<=a[x][y][2]-'0'-1;i++){
      if(r[i][x] || c[i][y] || d[i][2*(x/2)+y/3]) continue;
      a[x][y][0]=i+'0';
      r[i][x]=c[i][y]=d[i][2*(x/2)+y/3]=true;
      rec(x+1,y);
      a[x][y][0]='-';
      r[i][x]=c[i][y]=d[i][2*(x/2)+y/3]=false;			
    }
  }
  else if(a[x][y][2]=='-'){
    for(int i=a[x][y][0]-'0'+1;i<=9;i++){
      if(r[i][x] || c[i][y] || d[i][2*(x/2)+y/3]) continue;
      a[x][y][2]=i+'0';
      r[i][x]=c[i][y]=d[i][2*(x/2)+y/3]=true;
      rec(x+1,y);
      a[x][y][2]='-';
      r[i][x]=c[i][y]=d[i][2*(x/2)+y/3]=false;			
    }		
  }
  else rec(x+1,y);
  }


}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
      cin >> a[i][j];
      for(auto e:a[i][j]){
        if(e=='-' || e=='/') continue;
        r[e-'0'][i]=c[e-'0'][j]=d[e-'0'][2*(i/2)+j/3]=true;
    }
//    cout << a[i][j].size() << " ";
    }
  }
  rec(0,0);
}
