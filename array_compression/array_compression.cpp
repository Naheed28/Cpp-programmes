#include <iostream>
#include <map>
#include <bits/stdc++.h>



int arr[] ={-102,1,134565589,134565589,-102,66666668,134565589,66666668,-102,1,-2} ;
//compressed{ 0 ,1 ,   2    ,  2      ,  0 ,   3    ,  2       , 3     ,0   ,1, 4 }

/*

inside map

key_column     second column  
-102        ->      0
-2          ->      4
1           ->      1
66666668    ->      3
134565589   ->      2


*/

using namespace std ;

int main()
{
    map <int ,int >mymap ;
    int size = sizeof(arr)/sizeof(int);

    int assign = 0 ;
    int compressed[100] ;
    int c = 0 ;
    for(int i = 0 ; i < size ;i++)
    {
        int x = arr[i] ;
        if(mymap.find(x) == mymap.end())
        {
            mymap[x] =assign ;
            assign++ ;

        }
        x = mymap[x] ;
        compressed[c]= x ;
        c++ ;

    }
    for(int i = 0 ; i < size ;i++)
    cout << compressed [i] << " " ;

    return 0 ;
}