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
int n,ans=0;
std::string s;
void dfs(int dep,int cur,int X)
{
    if(dep==n)
    {

        if(cur%25==0&&cur!=0) 
        {
            ans++;
        }
        return ;
    }
    if(s[dep]>='0'&&s[dep]<='9') dfs(dep+1,cur*10+(s[dep]-'0'),X);
    else if(s[dep]=='_')
    {
        for(int i=0;i<10;i++)
        {
            if(dep==0&&i==0) continue;
            dfs(dep+1,cur*10+i,X);
        }
    }
    else
    {
        if(X==-1)
        {
            for(int i=0;i<10;i++)
            {
                if(i==0&&dep==0) continue;
                dfs(dep+1,cur*10+i,i);
            }
        }
        else dfs(dep+1,cur*10+X,X);
    }
}
void slove()
{
    std::cin>>s;
    n=s.length();
    if(n==1)
    {
        std::cout<<((s[0]=='0'||s[0]=='_'||s[0]=='X')?1:0)<<endl;
        return ;
    }
    if(s[0]=='0')
    {
        std::cout<<0<<endl;
        return ;
    }
    dfs(0,0,-1);
    std::cout<<ans<<endl;
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
