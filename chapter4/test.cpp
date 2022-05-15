#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
typedef long long ll;
ll a[N];
ll n,m;
bool check(ll h)
{
    int res = 0;
    for (int i = 0 ; i < n ; i++ )
        res += (a[i] / h);      //看看每一段木头能切成几段 h 长的木段
    if(res >= m) return 1;
    else return 0;
}
int main()
{
   cin >> n >> m;
   ll l = 0, r = 0;
   for (int i = 0 ; i < n ; i++ ){
        cin >> a[i];
        r = max(a[i],r);
   }
   while(l < r)
   {
       ll mid = (l + r + 1) / 2;
        if(check(mid))
            l = mid;
        else 
            r = mid - 1;
   }
   cout<<l<<endl;
   return 0;
}
