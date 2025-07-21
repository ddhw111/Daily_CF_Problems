#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
void slove()
{
   int n;
   std::cin>>n;
   std::vector<int> a(n+3),sum(n+3);
   for(int i=1;i<=n;i++) std::cin>>a[i],sum[i]=sum[i-1]+a[i];
    std::map<int, int> mp;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(j<=n&&a[j]==a[i])
        {
            mp[j]=i;
            j++;
        }
        i=j-1;
    }
    auto check=[&](int x,int p)->bool{
        int l1=std::max(1LL,p-x);
        int r1=std::max(1LL,p-1);
        int l2=std::min(p+1,n);
        int r2=std::min(n,p+x);
        int f=0;
        if((sum[r1]-sum[l1-1])>a[p]&&std::max(mp[r1],l1)!=l1) f=1;
        if((sum[r2]-sum[l2-1])>a[p]&&std::max(mp[r2],l2)!=l2) f=1;
        if(x>=1)
        {
            if(a[p-1]>a[p]||a[p+1]>a[p]) f=1;
        }
        return f;
    };
    for(int i=1;i<=n;i++)
    {
        int l=1LL,r=n;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(check(mid,i)) r=mid-1;
            else l=mid+1;
        }
        if(l>n) std::cout<<-1<<" ";
        else std::cout<<l<<" ";
    }
    std::cout<<endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1; 
    std::cin>>T;
    while(T--)    {
        slove();
    }

    return 0;
}
