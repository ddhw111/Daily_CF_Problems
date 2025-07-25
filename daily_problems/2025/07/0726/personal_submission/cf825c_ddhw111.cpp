#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
void slove()
{
   int n,k;
   std::cin>>n>>k;
   std::vector<int> a(n+1);
   for(int i=1;i<=n;i++) std::cin>>a[i];
    std::sort(a.begin()+1,a.end());
    int p=1;
    while(p<=n&&a[p]<=k) p++;
    if(p>n)
    {
        std::cout<<0<<endl;
        return ;
    }
    int cur=std::max(a[p-1],k);
    int ans=0;
    //std::cout<<cur<<endl;
    for(int i=p;i<=n;i++)
    {
        while(2*cur<a[i])
        {
            cur*=2;
            ans++;
        }
        cur=std::max(cur,a[i]);
    }
    //ans=std::max(ans,1LL);
    std::cout<<ans<<endl;
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
