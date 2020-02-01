 #include <iostream >
#include <malloc.h>
#include <queue>

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

void preorder(struct node *r)
{
    //root , left ,right 
    if( r == NULL)
        return ;
    cout<< r->data << " " ;
    preorder(r ->left) ;
    preorder(r->right) ;

}
void inorder(struct node *r)
{
    //left ,root ,right ;
    if(r== NULL)
    return ;
    inorder(r ->left) ;
    cout << r->data << " " ;
    inorder(r ->right) ; 
}
void postorder(struct node *r)
{
    //left ,right ,root
    if(r == NULL)
    return ;
    postorder( r->left) ;
    postorder(r ->right) ;
    cout << r->data << " " ;

}
void level_order(node *root)
{
    if(root == NULL)
        return ;
    queue<node* > Q ;
    Q.push(root) ; 

    //While there is at least one discovered node
    while(!Q.empty())
    {
        node* current = Q.front() ;
        cout << current ->data << " " ;
        if(current ->left != NULL)Q.push(current->left) ;
        if(current ->right != NULL)Q.push(current->right) ;
        Q.pop();//removing element from front
    }
    
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

    /*
                    55
                   /  \
                 40    80 
                /    /    \
               34   60    90 
             /   \
            28   38

    
    */
    preorder(root) ;
    cout << endl ;
    inorder(root) ;
    cout << endl ;
    postorder(root) ;
    cout<<endl ;
    level_order(root) ;





    return 0;
}