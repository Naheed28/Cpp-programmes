#include <iostream>

using namespace std;
int arr[10] ;

void merge(int arr[], int s ,int e);
void merge_sort(int arr[],int s ,int e)
{
    if(s >= e) return  ;
    int mid = (s + e)/2;
    merge_sort(arr ,s ,mid) ;
    merge_sort(arr ,mid+1 ,e) ;
    merge( arr , s , e) ;
}
void merge(int arr[], int s ,int e)
{
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1 ;
    int k = s ;

    int temp [100];

    while(i <= mid && j <=e )
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++ ;
            i++ ;
        }
        else 
        {
            temp[k] = arr[j];
            k++ ;
            j++ ;
        }
    }
    while(i <= mid)
    {
        temp[k] = arr[i] ;
        i++ ;
        k++ ;
    }
    
    while(j <= e)
    {
        temp[k] = arr[j] ;
        j++ ;
        k++ ;
    }
    for(int i = s ; i<= e ; i++)
    {
        arr[i] = temp[i];
    }
}


int main()
{
    for(int i=0 ; i<10 ;i++)
        cin >> arr[i];
    int s = 0 , e = 9 ;

    merge_sort(arr, s , e) ;
    for(int i=0 ;i<10 ;i++)
    cout << arr[i] << " ";
    return 0;
}