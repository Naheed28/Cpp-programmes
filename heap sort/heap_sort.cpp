#include <iostream>

using namespace std;

void heapify(int arr[] ,int n ,int i)
{
   int largest = i ;
   int l = 2*i + 1 ;
   int r = 2*i + 2 ;

   //if left child is larger than root
   if(l<n && arr[largest] < arr[l])
      largest = l ;
      
   //if right child is larger than root
   if(r<n && arr[largest] < arr[r])
      largest = r ;

   //if largest is not root
   if(largest != i)
   {
      swap(arr[largest] ,arr[i]);

      //recursively heapify the effected array
      heapify(arr , n , largest );
   }


}

void heap_sort(int arr[], int n)
{
   //building a heap

   for(int i=n/2 -1 ;i >= 0 ; i--)
      heapify(arr ,n ,i);

   //one by one extract an element from heap
   for(int i = n-1 ; i>=0 ; i--)
   {
      //moving root to end
      swap(arr[0] , arr[i]) ;

      //calling max heapify on the reduced heap
      heapify(arr ,i , 0 );

   }
   
}


int main()
{
   int arr[] = {121 ,10 ,130 ,57 ,36 ,17} ;
   int n = sizeof(arr)/sizeof(arr[0]) ;

   heap_sort(arr ,n) ;


   cout << "Sorted array is \n" ;

   for(int i =0 ; i < n ; i++)
   {
      cout<< arr[i] <<" " ;
   } 


   return 0;
}
