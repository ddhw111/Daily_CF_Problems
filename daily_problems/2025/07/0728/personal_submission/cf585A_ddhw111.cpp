#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
void slove()
{
    int n;
    std::cin>>n;
    std::vector<std::array<int,3>> a(n+1);
    for(int i=1;i<=n;i++) std::cin>>a[i][0]>>a[i][1]>>a[i][2];
    std::vector<int> vis(n+1);
    std::vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            ans.push_back(i);
            int x=a[i][0];
            for(int j=i+1;j<=n&&x>0;j++)
            {
                if(!vis[j])
                {
                    a[j][2]-=x;
                    x--;
                }
            }
            int cur=0;
            for(int j=i+1;j<=n;j++)
            {
                a[j][2]-=cur;
                if(!vis[j]&&a[j][2]<0)
                {
                    vis[j]=1;
                    cur+=a[j][1];
                }
            }
        }
    }
    std::cout<<ans.size()<<endl;
    for(auto i:ans) std::cout<<i<<" ";
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1; 
    //std::cin>>T;
    while(T--)    {
        slove();
    }

    return 0;
}
