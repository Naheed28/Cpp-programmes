#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD 10000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
int const MXN = 5e5 + 5;
 
ll  a[MXN], k, prefix[MXN], pos, n, m;
string s;
 
bool check(int length)
{
    //cout << length << endl;
    int ca = 0, cb = 0, cc = 0;
 
    for(int i = 0; i < length; i++){
        if(s[i] == 'a') ca++;
        else if(s[i] =='b') cb++;
        else cc++;
    }
 
    if(ca > 0 && cb > 0 && cc > 0) return true;
    int x = 0;
    for(int i = length; i < n; i++){
        if(s[x] == 'a') ca--;
        else if(s[x] =='b') cb--;
        else cc--;
        if(s[i] == 'a') ca++;
        else if(s[i] =='b') cb++;
        else cc++;
        x++;
 
        if(ca > 0 && cb > 0 && cc > 0) return true;
    }
 
    return false;
}
 
void solve(int cs)
{
    cin >> s;
 
    n = s.size();
 
    //cout << n << endl;
 
    int lo = 3, hi = n;
 
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
 
        if(check(mid)){
            hi = mid;
        }
        else lo = mid + 1;
    }
 
    cout << lo << endl;
    
 
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
 
#endif
    int t = 1, cs = 1;
 
    cin >> t;
 
    while (t--){
       solve(cs);
    }
}
 
