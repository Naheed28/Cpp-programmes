
# Comparator

Lets make a bubble sort first to understand the working of a comparator function.


```cpp
#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    vector<int>arr(n) ;

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i] ;

    

    for(int i = 0 ; i < n ; i++ )
    {
        for(int j = i + 1 ; j < n  ;j++)
        {
            if(arr[i] > arr[j])
                swap(arr[i] , arr[j]);
        }
    }


    for(int i = 0 ; i < n ; i ++)
        cout << arr[i] << " " ;

    return 0;
}

```


input:
```
5
5 8 6 2 1
```

output:
```
1 2 5 6 8
```


here ``if(arr[i] > arr[j])`` is the comparator logic. Now lets make it abstract by using a custom function.



```cpp
#include<bits/stdc++.h>

using namespace std ;

// custom comparator
bool should_i_swap(int a , int b){
    if(a > b)
        return true;
    return false;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int>arr(n) ;

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i] ;

    

    for(int i = 0 ; i < n ; i++ )
    {
        for(int j = i + 1 ; j < n  ;j++)
        {
            // custom comparator logic
            if(should_i_swap(arr[i] , arr[j]))
                swap(arr[i] , arr[j]);
        }
    }

    for(int i = 0 ; i < n ; i ++)
        cout << arr[i] << " " ;


    return 0;
}
```
The ``should_i_swap`` function is defining the sorting behavior.If we run the code the output remains the same.

input:
```
5
5 8 6 2 1
```

output:
```
1 2 5 6 8
```


Now lets say we want to sort the vector array in decreasing order. So we will change the ``if(a>b)`` inside the ``should_i_swap`` function to ``if(a<b)``.

<br>

## Now lets take an example with pairs

```cpp
#include<bits/stdc++.h>

using namespace std ;

// custom comparator
bool should_i_swap(pair<int,int> a ,pair<int,int> b){
    if(a > b)
        return true;
    return false;
}

int main()
{
    int n ;
    cin >> n ;
    vector<pair<int,int> >arr(n) ;

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i].first >> arr[i].second ;

    

    for(int i = 0 ; i < n ; i++ )
    {
        for(int j = i + 1 ; j < n  ;j++)
        {
            // custom comparator logic
            if(should_i_swap(arr[i] , arr[j]))
                swap(arr[i] , arr[j]);
        }
    }

    for(int i = 0 ; i < n ; i ++)
        cout << arr[i].first << " " << arr[i].second << endl;


    return 0;
}
```

Input:
```
6
4 3 
5 5
5 3
25 6
7 9
8 5
```
Output:
```
4 3
5 3
5 5
7 9
8 5
25 6
```


Now everything is working fine.But lets say we wanna sort the second element in the pair indecending order when the first element is the same.

```
5 5
5 3
```
So what can we do?
Lets change the code again.

```cpp
#include<bits/stdc++.h>

using namespace std ;

// custom comparator
bool should_i_swap(pair<int,int> a ,pair<int,int> b){

    if(a.first != b.first)
    {
        if(a.first > b.first)
            return true;
        return false;
    }
    else{
        if(a.second < b.second) 
            return true ;
        return false;
    }
}

int main()
{
    int n ;
    cin >> n ;
    vector<pair<int,int> >arr(n) ;

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i].first >> arr[i].second ;

    

    for(int i = 0 ; i < n ; i++ )
    {
        for(int j = i + 1 ; j < n  ;j++)
        {
            // custom comparator logic
            if(should_i_swap(arr[i] , arr[j]))
                swap(arr[i] , arr[j]);
        }
    }

    for(int i = 0 ; i < n ; i ++)
        cout << arr[i].first << " " << arr[i].second << endl;


    return 0;
}
```

Now the output is what we want.

Input:
```
6
4 3 
5 5
5 3
25 6
7 9
8 5
```
Output:
```
4 3
5 5
5 3
7 9
8 5
25 6
```

<br>
<br>
<br>

## Comparator usage in STL

One thing to remember when using in-built sort and passing custom comparator that the operation is opposite to what we have done so far. If we want to swap then we have to pass ``false`` instead of true and vice versa.

```cpp
#include<bits/stdc++.h>

using namespace std ;

// custom comparator
bool should_i_swap(pair<int,int> a ,pair<int,int> b){

    if(a.first != b.first)
    {
        //if we want to swap return false
        if(a.first > b.first)
            return false;
        return true;
    }
    else{
        if(a.second < b.second) 
            return false ;
        return true;
    }
}

int main()
{
    int n ;
    cin >> n ;
    vector<pair<int,int> >arr(n) ;

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i].first >> arr[i].second ;

    

    // using stl sort
    sort(arr.begin(), arr.end() , should_i_swap);

    for(int i = 0 ; i < n ; i ++)
        cout << arr[i].first << " " << arr[i].second << endl;


    return 0;
}
```

<br>
<br>




## Comparator for string in lexicographical order :

```cpp
bool cmp(string x,string y) 
{
	return x+y<y+x;
}
```


## Sample Uses:
## Sorting An Array In Reverse Order

``Method 1:``

```cpp
vector a;
sort(a.rbegin(), a.rend());
```

<br>

``Method 2:``

```cpp
//For an vector
bool cmp(int a,int b) {
    return a <= b;
}

int main() {
    int n;
    cin >> n;

    vector a;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort (a.begin(), a.end(), cmp);

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    
    return 0;
}
```
## For an array now.

<br>

```cpp
bool cmp(int a,int b) {
    return a <= b;
}

int a[100];

int main() {
    int n;
    cin &>> n;

    for (int i = 0; i < n; i++) {
       cin >> a[i];
    }

    sort (a, a + n, cmp);

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";

    return 0;
}
```

<br>

# The End
