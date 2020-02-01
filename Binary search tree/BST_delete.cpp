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


void inorder(struct node *r)
{
    //left ,root ,right ;
    if(r== NULL) 
    return ;
    inorder(r ->left) ;
    cout << r->data << " " ;
    inorder(r ->right) ; 
}
node* findmin(node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct node* Delete(struct node *root , int data)
{
    if(root == NULL) return root ;
    else if(data < root ->data )
        root ->left = Delete(root -> left ,data ) ;
    else if(data > root ->data)
        root ->right = Delete(root->right , data) ;
    //I found you and get ready to be deleted
    else 
    {
        //case 1: NO child
        if(root ->left == NULL && root ->right == NULL)
        {
            delete root ;
            root = NULL ;
            return root ;
        }
        //case 2: one child
        else if(root -> left == NULL)
        {
            struct node *temp = root ;
            root = root ->right ;
            delete temp ;
            return root ;
        }
        else if(root -> right == NULL )
        {
            struct node *temp= root ;
            root = root -> left ;
            delete temp ;
            return root ;
        }

        //case 3: two child
        else 
        {
            struct node *temp = findmin(root ->right) ;
            root ->data = temp ->data ;
            root ->right= Delete(root ->right ,temp ->data) ;
            return root ;
        }
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
  
    inorder(root) ;
    cout << endl ;
    node * r = Delete( root , 80) ;

    inorder(r) ;
    cout << endl ;
    
    return 0;
}