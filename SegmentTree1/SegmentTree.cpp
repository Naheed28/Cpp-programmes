/*

the segment tree

         8
     /       \
    5         3
  /   \     /  \
 -5   10   1    2 
 /\   /\   /\
4 -9  3 7  1 0 

arr[] = {0 , 4 , -9 , 3 ,7, 1 ,0, 2};
tree[] = { 8 ,5 ,3 ,-5 ,10 ,1 ,2 ,4 ,-9 ,3 ,7 ,1 ,0 };


*/



#include <iostream>

using namespace std ;
int arr[] = {0 , 4 , -9 , 3 ,7, 1 ,0, 2}; //Its equivalent to { 4 , -9 , 3 ,7, 1 ,0, 2} because we are counting with 1 based index
int tree[7 * 4]; //Its better to take 4 times the size
void init(int node, int b, int e)   //making a segment tree
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j)//returning a sum inside the range b  , e 
{
    if (i > e || j < b)
        return 0; //বাইরে চলে গিয়েছে//outside the range
    if (b >= i && e <= j)
        return tree[node]; //রিলেভেন্ট সেগমেন্ট //revlavent segment //
    int Left = node * 2; //আরো ভাঙতে হবে //if partial then it has to be broken 
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2; //বাম এবং ডান পাশের যোগফল //adding
}

void update(int node, int b, int e, int i, int newvalue)//updating a tree
{
    if (i > e || i < b)
        return; //বাইরে চলে গিয়েছে
    if (b >= i && e <= i) { //রিলেভেন্ট সেগমেন্ট
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
int main()
{
    
    int n = 7; //considering arr from 1 to 7 ;    
        
    init(1, 1, n);

    update(1, 1, n, 2, 0);
    cout << query(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 2, 2);
    cout << query(1, 1, n, 2, 2) << endl;
    return 0;
}