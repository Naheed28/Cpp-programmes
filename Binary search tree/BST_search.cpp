#include <iostream >
#include <malloc.h>


using namespace std ;

struct node
{
    int data ;
    struct node *left ;
    struct node *right ; 
}*root ;

void insert( int value )   //non recursive process ..
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data =value ;
    newnode -> left = NULL ;
    newnode -> right = NULL ;

    if(root == NULL) 
        root = newnode ;
    else 
    {
        struct node *temp ;
        temp = root ;

        while(1)
        {
            if(newnode->data <= temp->data)
            {//for left side
                if(temp->left == NULL)
                {
                    temp->left = newnode ;
                    break;
                }
                else
                    temp = temp->left ;
            }
            else
            {//for right side..
                 if(temp->right == NULL)
                {
                    temp->right = newnode ;
                    break;
                }
                else
                    temp = temp->right ;
            }
        }
    }
}

int  preorder(struct node *r,int val) //searching an element 
{
    //root , left ,right 
    if( r == NULL)
        return 0;
    if(r ->data == val)
        return 1 ;
    int x = 0, y = 0;
    x |= preorder(r ->left, val) ;  // x = x | preorder(r -> left ,val)
    y |= preorder(r->right, val ) ; // y = y | preorder(r ->right ,val)
    return x | y;

}



int main()
{
    insert(55) ;
    insert(40) ;
    insert(80) ;
    insert(34) ;
    insert(28) ;
    insert(38) ;
    insert(60) ;
    insert(90) ;

    int x;
    cout << "Enter a number " ;
    cin >> x ;

    if(preorder( root ,x) ==1 ) 
    cout <<"YES\n" ;
    else cout << "NO\n" ;





    return 0;
}