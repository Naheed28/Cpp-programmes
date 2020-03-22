#include <iostream>
#include <vector>
using namespace std;
int n,q,k,i;
int main() {
  cin.tie(0);ios_base::sync_with_stdio(0);
  
  cin >> q ; 
  while(q--)
  	{
  	  	cin>>n ;
		vector<int>A(n),B(n,1);
    	for(int &e : A )
		{
			cin >> e ;
			e--;
		}
    	for( i = 0 ; i < n ; i++)
		{
      		if(B[i]==1)
		  	{
        	for(k = A[i] ; k != i ; k = A[k])
				B[i]++;
        	for(k = A[i] ; k != i ; k = A[k])
				B[k]=B[i];
      		}
    	}
    for(auto e:B)cout<<e<<' ';
	cout<<'\n';
  }
}