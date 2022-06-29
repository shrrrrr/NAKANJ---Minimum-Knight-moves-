//NAKANJ - Minimum Knight moves !!!
  
  #include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;
char a[250][250];
vector<int>g[N];
int subtree[N];
int level[8][8];
int vis[8][8];
int get_x(string str){

return str[0]-'a';

}
int get_y(string str){

return str[1]-'1';
}
int bfs(int sx,int sy,int dx,int dy){

queue<pair<int,int>>q;
q.push({sx,sy});
vis[sx][sy]=1;
level[sx][sy]=0;
while(!q.empty()){
    pair<int,int>curr=q.front();
    q.pop();
    int dr[8][2]={{-2,-1},{-2,1},{2,1},{2,-1},{-1,-2},{-1,2},{1,2},{1,-2}};
    for(int k=0;k<8;k++){
        int cx=curr.first+dr[k][0];
        int cy=curr.second+dr[k][1];
        if(cx>=0&&cy>=0&&cx<8&&cy<8&&!vis[cx][cy]){
            q.push({cx,cy});
            vis[cx][cy]=1;
            level[cx][cy]=level[curr.first][curr.second]+1;
        }else{
        continue;
        }
    }
    if(level[dx][dy]!=INF) break;

}

return level[dx][dy];
}
void reset(){
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        vis[i][j]=0;
        level[i][j]=INF;
    }
}

}

int main(){

    int tt;
    cin>>tt;
    string str,ptr;
    while(tt--){
        //string str,ptr;
        cin>>str>>ptr;
    reset();
    int sx,sy,dx,dy;
    sx=get_x(str);
    sy=get_y(str);
    dx=get_x(ptr);
    dy=get_y(ptr);
    cout<< bfs(sx,sy,dx,dy)<<endl;
    }
}
