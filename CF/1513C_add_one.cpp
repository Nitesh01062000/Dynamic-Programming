#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string.h>
#include <cmath>
#include <iomanip> 
#include <ios> 
#include <sstream>
#include <stack>
#include <numeric>
#include <limits.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

vector<vector<ll> >dp(10,vector<ll>(200001));

void solve()
{
	ll n,k;
	scanf("%lld %lld",&n,&k);
	ll ans=0;
	while(n)
	{
		ll tmp=n%10;
		ans+=(dp[tmp][k]);
		ans%=mod;
		n/=10;
	}
	printf("%lld\n",ans);
}




int main(void)
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ll t=1;
	scanf("%lld",&t);
	for(ll i=0;i<=9;i++)
	{
		map<ll,ll>m;
		m[i]++;
		ll k=200000;
		ll sum=1;
		for(ll j=1;j<=k;j++)
		{
			ll tmp=m[9];
			for(ll p=9;p>=2;p--)
				m[p]=(m[p-1]%mod);
			m[1]=(m[0]+tmp)%mod;
			m[0]=tmp%mod;
			sum+=tmp;
			dp[i][j]=sum;
		}
	}
	for(ll i=1;i<=t;i++)
	{
		// printf("Case #%lld: %lld\n",i,solve());
		// cout<<"Case #"<<i<<": "<<solve()<<endl;
		solve();
	}
}


 
