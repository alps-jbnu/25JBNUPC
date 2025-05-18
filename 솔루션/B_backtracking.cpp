#include <bits/stdc++.h>    
using namespace std;

int dx[2]={1,0};
int dy[2]={0,1};

int arr[9][9];
int ret;

void func(int x,int y,int maxX,int maxY,int res){
    if(x==7&&y==7){
        ret+=res;
        return;
    }
    
    for(int i=0;i<2;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||ny<0||nx>maxX||ny>maxY) continue;
        func(nx,ny,maxX,maxY,res+arr[nx][ny]);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
        cin>>arr[i][j];
    func(0,0,7,7,arr[0][0]);
    cout<<ret;
}