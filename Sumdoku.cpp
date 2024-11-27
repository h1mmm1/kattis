#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int R[15][15],c[15][15],d[15][15];
char pc[9][9],pr[9][9];
int a[15][15];
bool w=true;

pii find(int x,int y){
  int cc=pc[x][y],rr=pr[x][y];
  int l=1,r=9;
  if(cc=='=' && rr=='=' && 10-a[x-1][y]==10-a[x][y-1]) l=r=10-a[x-1][y]; 
  else if(cc=='=' && rr=='<' && 10-a[x][y-1]+a[x-1][y]<10) l=r=10-a[x][y-1];
  else if(cc=='=' && rr=='>' && 10-a[x][y-1]+a[x-1][y]>10) l=r=10-a[x][y-1];
  else if(cc=='<' && rr=='<') r=min(10-a[x-1][y],10-a[x][y-1])-1;
  else if(cc=='<' && rr=='=' && 10-a[x-1][y]+a[x][y-1]<10) l=r=10-a[x-1][y];
  else if(cc=='<' && rr=='>') l=10-a[x-1][y]+1,r=10-a[x][y-1]-1;
  else if(cc=='>' && rr=='>') l=max(10-a[x-1][y],10-a[x][y-1])+1;
  else if(cc=='>' && rr=='=' && 10-a[x-1][y]+a[x][y-1]>10) l=r=10-a[x-1][y]; 
  else if(cc=='>' && rr=='<') l=10-a[x][y-1]+1,r=10-a[x-1][y]-1;
  else if(cc=='=') l=r=10-a[x][y-1];
  else if(cc=='>') l=10-a[x][y-1]+1;
  else if(cc=='<') r=10-a[x][y-1]-1;
  else if(rr=='=') l=r=10-a[x-1][y];
  else if(rr=='>') l=10-a[x-1][y]+1;
  else if(rr=='<') r=10-a[x-1][y]-1;
  else if(cc==' ' && rr==' ') l=1,r=9;
  else l=9,r=1;
  return {l,r};
}

void rec(int x,int y){
  if(w==false) return;
  if(x==9 && y==8){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cout << a[i][j] << ' ';
      }
      cout << "\n";
    }
    w=false;
    return;
  }
  if(x==9) rec(0,y+1);
  int l=1,r=9;
  pii cnt=find(x,y);
  l=cnt.first,r=cnt.second;
  for(int i=l;i<=r;i++){
    if(R[i][x] || c[i][y] || d[i][3*(x/3)+y/3]) continue;
    a[x][y]=R[i][x]=c[i][y]=d[i][3*(x/3)+y/3]=i;
    rec(x+1,y);
    a[x][y]=R[i][x]=c[i][y]=d[i][3*(x/3)+y/3]=0;
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int e=0;
  memset(pc,' ',sizeof pc);
  memset(pr,' ',sizeof pr);
  cin >> pc[e][1] >> pc[e][2] >> pc[e][4] >> pc[e][5] >> pc[e][7] >> pc[e][8];
  for(int i=0;i<9;i++) cin >> pr[1][i];
  e++;
  cin >> pc[e][1] >> pc[e][2] >> pc[e][4] >> pc[e][5] >> pc[e][7] >> pc[e][8];
  for(int i=0;i<9;i++) cin >> pr[2][i];
  e++;  
  cin >> pc[e][1] >> pc[e][2] >> pc[e][4] >> pc[e][5] >> pc[e][7] >> pc[e][8];

  e++;  
  cin >> pc[e][1] >> pc[e][2] >> pc[e][4] >> pc[e][5] >> pc[e][7] >> pc[e][8];
  for(int i=0;i<9;i++) cin >> pr[4][i];
  e++;
  cin >> pc[e][1] >> pc[e][2] >> pc[e][4] >> pc[e][5] >> pc[e][7] >> pc[e][8];
  for(int i=0;i<9;i++) cin >> pr[5][i];
  e++;
  cin >> pc[e][1] >> pc[e][2] >> pc[e][4] >> pc[e][5] >> pc[e][7] >> pc[e][8];

  e++;  
  cin >> pc[e][1] >> pc[e][2] >> pc[e][4] >> pc[e][5] >> pc[e][7] >> pc[e][8];
  for(int i=0;i<9;i++) cin >> pr[7][i];
  e++;
  cin >> pc[e][1] >> pc[e][2] >> pc[e][4] >> pc[e][5] >> pc[e][7] >> pc[e][8];
  for(int i=0;i<9;i++) cin >> pr[8][i];
  e++;
  cin >> pc[e][1] >> pc[e][2] >> pc[e][4] >> pc[e][5] >> pc[e][7] >> pc[e][8];

  rec(0,0);

}

