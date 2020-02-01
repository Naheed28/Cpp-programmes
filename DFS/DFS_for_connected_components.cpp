#include <iostream >
#include <vector>


using namespace std ;

const int SIZE = 1e5 + 7 ;

vector <int> V[SIZE] ;
bool visited[SIZE] ;
int cnt = 0 ;
int components[SIZE] ;


void add_edge(int u , int v )
{
    V[u].push_back(v) ;
    V[v].push_back(u) ;
}
void DFS(int i )
{
    visited[i] = true ;
    components[i] = cnt ;
    //cout << "YES\n" ;
    for(int j = 0 ; j < V[i].size() ;j++)
    {
        int v = V[i][j] ;
        if(visited[v] == false) 
            DFS(v) ;
    }
}



void findcomponets()
{
    for(int i = 0 ; i < 18; i++) 
    {
        if(visited[i] == false)
        {
            cnt++ ;
            //cout << cnt ;

            DFS(i) ;
        }
    }

}



int main()
{
    add_edge(4, 0);
    add_edge(0 ,13);
    add_edge(8 ,0);
    add_edge(0 ,14);
    
    add_edge( 6, 7);
    add_edge(7 , 11);
    add_edge(11 ,6);
    
    add_edge(15 ,10);
    add_edge(15 , 2);
    add_edge(15 , 9);
    add_edge(9 , 3);
    
    add_edge(12 , 12);

    add_edge(1 , 5);
    add_edge(5 , 16);
    add_edge(5 , 17);
    findcomponets() ;
    
    cout << cnt << endl;
    for(int i = 0 ; i < 18 ; i++) 
    {
        //cout << visited[i] << endl ;
    }



    return 0 ;
}