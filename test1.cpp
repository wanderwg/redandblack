#include<iostream>
#include<vector>
using namespace std;
int nextposition[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int ret=0;
void dfs(vector<vector<char>>& vc,int m,int n,vector<vector<int>>& book,int x,int y)
{
    book[x][y]=1;
    if(vc[x][y]==1||x<0||x>=m||y<0||y>=n)
        return;
    ++ret;
    for(int k=0;k<4;++k)
    {
        int nx=x+nextposition[k][0];
        int ny=y+nextposition[k][1];
        if(nx<0||nx>=m||ny<0||ny>=n)
            continue;
        if(vc[nx][ny]=='.'&&book[nx][ny]==0)
        {
            dfs(vc,m,n,book,nx,ny);
        }
    }
}
int numblack(vector<vector<char>>& vc)
{
    if(vc.empty())
        return 0;
    ret=0;
    int row=vc.size();
    int col=vc[0].size();
    vector<vector<int>> book;
    book.resize(row);
    for(int i=0;i<row;++i)
       book[i].resize(col,0);
    
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            if(vc[i][j]=='@'&&book[i][j]==0)
            {
                dfs(vc,row,col,book,i,j);
            }
        }
    }
    return ret;
}
int main()
{
    int m,n;
    char tmp;
    while(cin>>m>>n)
    {
        vector<vector<char>> vc;
        vc.resize(m);
        for(int i=0;i<m;++i)
        {
            vc[i].resize(n);
            for(int j=0;j<n;++j)
            {
                cin>>tmp;
                vc[i][j]=tmp;
            }
        }
        cout<<numblack(vc)<<endl;
    }
    return 0;
}