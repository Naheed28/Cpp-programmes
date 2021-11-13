
## Getting the right most set bit


## Get rightmost set bit:
```
x & -x
// or
x & (~x + 1)
```
## Unset rightmost set bit:
```
x &= x - 1
// or
x -= x & -x  // rhs is rightmost set bit
```
## Why it works
```
x:                     leading bits  1  all 0
~x:           reversed leading bits  0  all 1
~x + 1 or -x: reversed leading bits  1  all 0
x & -x:                       all 0  1  all 0
```
eg, let x = 112, and choose 8-bit for simplicity, though the idea is same for 
all size of integer.
```
// example for get rightmost set bit
x:             01110000
~x:            10001111
-x or ~x + 1:  10010000
x & -x:        00010000

// example for unset rightmost set bit
x:             01110000
x-1:           01101111
x & (x-1):     01100000
```

One can use the property of 2s-complement here.
Fastest way to find 2s-complement of a number is to get the rightmost set bit and 
flip everything to the left of it.
eg: consider a 4 bit system
4=0100
2s complement of 4 = 1100, which nothing but -4
4&(-4)=0100.
Notice that there is only one set bit and its at rightmost set bit of 4
Similarly we can generalise this for n.
n&(-n) will contain only one set bit which is actually at the rightmost set bit 
position of n.
since there is only one set bit in n&(-n) , it is a power of 2.
So finally we can get the bit position by:

### log2(n&(-n))
