#include <iostream>

using namespace std ;
void primefactor(int n )
{
    int cnt(0) ;
    for(int i = 2 ; i <= n ; i++)
    {
        while(n%i == 0) 
        {
            cnt++ ;
            n = n/i ;
        }
        cout << i <<"^" <<cnt <<" " ;

        cnt = 0 ;  
    }
}



int main()
{
    cout << "Enter a number for prime factorization :" ;
    int n ;
    cin >> n ;
    primefactor(n) ;

 

    return 0 ;
}