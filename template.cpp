// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم

#include<bits/stdc++.h>
#define ll long long

using namespace std;

// for ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define TYPE int 
using namespace __gnu_pbds;
//#define ordered_set tree      < TYPE ,  null_type ,  less<TYPE>           ,  rb_tree_tag ,  tree_order_statistics_node_update >
//#define ordered_set tree      < TYPE ,  null_type ,  greater<TYPE>        ,  rb_tree_tag ,  tree_order_statistics_node_update >
//#define ordered_multiset tree < TYPE ,  null_type ,  greater_equal<TYPE>  ,  rb_tree_tag ,  tree_order_statistics_node_update >
//FIND_BY_ORDER(K)  --> VALUE AT KTH INDEX (ITERATOR)
//ORDER_OF_KEY(K)   --> INDEX OF VALUE K

// #define int long long // __int128 FOR BIG INTEGERS WITH C++ 17 (64) (UPTO 10^35 OR SOMETHING)
// #define double             long double
#define FAST               ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const double pi = 3.14159265359;
const int mod = 1000000007;
const int modc = 998244353;
const int inf = LLONG_MAX;
const int neg_inf = LLONG_MIN;
 
//SIEVE IN O(N) TIME (FOR N UPTO 1e7 OTHERWISE YOU'LL FACE MEMORY ISSUES)
/*
vector<int>lp(M);
vector<int>pr;
void sieve()
{
    lp[0] = 1; //AISE HI RANDOM , KUCHH BHI.
 
    for(int i = 2 ; i < M ; i++)
    {
        if(lp[i] == 0)
        {
            //this is a prime
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0 ; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < M; j++)
            lp[i * pr[j]] = pr[j];
    }
}
*/


void solve()
{


}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin) ;
    freopen("output.txt" , "w" , stdout) ;
#endif

    int t = 1;
    // cin >> t ;
    while(t--)
    {
        solve();
    }

    return 0;
}