The function memset only works with 1 if you are using an array of bool/char (or other 1-byte data type).

We usually use it like memset(A, x, sizeof(A)), where A is an array of something. This converts the value x to an unsigned char and then copies it to the first sizeof(A) bytes of the memory address indicated by A (the start of the array).

The representation of 0 is 00000000, and the representation of -1 is 11111111, and that's why it works with 0 and -1 with integers/long long too, but the representation of 1 is 00000001, so if you want to memset an array of integers to 1, you are going to end up with an array of integers equal to 00000001 00000001 00000001 00000001 = 16843009, you can actually test it out with this snippet:


```cpp
int a[100];
memset(a, 1, sizeof(a));
forn(i, 100){
    printf("%d\n", a[i]);
}

```

# fill()
The ‘fill’ function assigns the value ‘val’ to all the elements in the range [begin, end), where ‘begin’ is the initial position and ‘end’ is the last position.
NOTE : Notice carefully that ‘begin’ is included in the range but ‘end’ is NOT included. Below is an example to demonstrate ‘fill’ :

```cpp
// C++ program to demonstrate working of fill()
#include <bits/stdc++.h>
using namespace std;
  
int main ()
{
  vector<int> vect(8);
  
  // calling fill to initialize values in the
  // range to 4
  fill(vect.begin() + 2, vect.end() - 1, 4);
  
  for (int i=0; i<vect.size(); i++)
    cout << vect[i] << " ";
  
  return 0;
}

```

	Output :
	0 0 4 4 4 4 4 0
 

# fill_n()
In fill_n(), we specify beginning position, number of elements to be filled and values to be filled. The following code demonstrates the use of fill_n.


```cpp
// C++ program to demonstrate working of fil_n()
#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    vector<int> vect(8);  
  
    // calling fill to initialize first four values
    // to 7
    fill_n(vect.begin(), 4, 7);
  
    for (int i=0; i<vect.size(); i++)
        cout << ' ' << vect[i];
    cout << '\n';
  
    // calling fill to initialize 3 elements from 
    // "begin()+3" with value 4
    fill_n(vect.begin() + 3, 3, 4);
  
    for (int i=0; i<vect.size(); i++)
        cout << ' ' << vect[i];
    cout << '\n';
  
    return 0;
}

```

	Output :
	7 7 7 7 0 0 0 0
	7 7 7 4 4 4 0 0
 
