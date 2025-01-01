#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
/*inline __int128 read(){
    __int128 x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}*/
//dont forget to check long long
//别写重变量名
//记得判越界
//别死磕
//处理字符串删掉关流
//用__int128时记得删掉关流
int n,m,k;
int sx,sy;
int d[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
int dist[1100][1100];
std::string s[1100];
std::string t="DLRU",ans="";
struct node
{
    int x,y;
};
int mx=0;
void bfs()
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dist[i][j]=-1;
        }
    }
    //std::cout<<sx<<" "<<sy<<endl;
    std::queue<node> q;
    dist[sx][sy]=0;
    q.push({sx,sy});
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int dx=x+d[i][0];
            int dy=y+d[i][1];
            if(dx<0||dy<0||dx>=n||dy>=m||s[dx][dy]=='*'||dist[dx][dy]!=-1) continue;
            dist[dx][dy]=dist[x][y]+1;
            q.push({dx,dy});
        }
    }
    while(k)
    {
        int f=0;
        for(int i=0;i<4;i++)
        {
            int dx=sx+d[i][0];
            int dy=sy+d[i][1];
            if(dx<0||dy<0||dx>=n||dy>=m||s[dx][dy]=='*') continue;
            if(dist[dx][dy]>=k) continue;
            ans+=t[i];
            sx=dx;
            sy=dy;
            f=1;
            break;
        }
        if(!f)
        {
            std::cout<<"IMPOSSIBLE"<<endl;
            return ;
        }
        k--;
    }
    std::cout<<ans<<endl;
}
void slove()
{
    std::cin>>n>>m>>k;
    for(int i=0;i<n;i++) std::cin>>s[i];
        int f=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='X') 
            {
                sx=i;
                sy=j;
                f=1;
                break;
            }
        }
        if(f) break;
    }
    bfs();
    
}
signed main()
{
    int T=1; 
    //std::cin>>T;
    while(T--)    {
        slove();
    }

    return 0;
}
