#include<bits/stdc++.h>
using namespace std;
int a[10][10];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cin >> a[i][j];
		}
	}
	int n;
	cin >> n;
	if(n==0){
		for(int i=1;i<=4;i++){
			int x=0,y=1,tmp1=5;
			while(y<=4){
				if(a[i][y]==a[i][tmp1]){
					a[i][tmp1]*=2;
					a[i][y]=0;
					tmp1=5;
				}			
				else if(a[i][y]!=0){
					tmp1=y;
				}
				y++;
			}
		}
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				if(a[i][j]==0){
					int e=0;
					while(a[i][j+e]==0 && j+e<=4){
						e++;
					}
					a[i][j]=a[i][j+e];
					a[i][j+e]=0;
				}
			}
		}			
	}
	else if(n==1){
		for(int j=4;j<=4;j++){
			int x=0,y=1,tmp1=5;
			while(y<=4){
				if(a[y][j]==a[tmp1][j]){
					a[tmp1][j]*=2;
					a[y][j]=0;
					tmp1=5;
				}			
				else if(a[y][j]!=0){
					tmp1=y;
				}
			//	cout << tmp1 << ' ' << y << "\n";
				y++;			
			}			
		}		
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				if(a[i][j]==0){
					int e=0;
					while(a[i+e][j]==0 && i+e<=4){
						e++;
					}
					a[i][j]=a[i+e][j];
					a[i+e][j]=0;
				}
			}
		}		
	}
	else if(n==2){
		for(int i=1;i<=4;i++){
			int x=0,y=5,tmp1=0;
			while(y>=1){
				if(a[i][y]==a[i][tmp1]){
					a[i][tmp1]*=2;
					a[i][y]=0;
					tmp1=0;
				}			
				else if(a[i][y]!=0){
					tmp1=y;
				}
				y--;
			}
		}
		for(int i=1;i<=4;i++){
			for(int j=4;j>=1;j--){
				if(a[i][j]==0){
					int e=0;
					while(a[i][j-e]==0 && j-e>=1){
						e++;
					}
					a[i][j]=a[i][j-e];
					a[i][j-e]=0;
				}
			}
		}					
	}
	else if(n==3){
		for(int j=1;j<=4;j++){
			int x=0,y=5,tmp1=0;
			while(y>=1){
				if(a[y][j]==a[tmp1][j]){
					a[tmp1][j]*=2;
					a[y][j]=0;
					tmp1=0;
				}			
				else if(a[y][j]!=0){
					tmp1=y;
				}
				y--;
			}
		}
		for(int i=4;i>=1;i--){
			for(int j=1;j<=4;j++){
				if(a[i][j]==0){
					int e=0;
					while(a[i-e][j]==0 && i-e>=1){
						e++;
					}
					a[i][j]=a[i-e][j];
					a[i-e][j]=0;
				}
			}
		}					
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cout << a[i][j] << ' ';
		}
		cout << "\n";
	}
}



