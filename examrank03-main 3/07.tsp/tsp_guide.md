# tsp 

## concept of the problem
- finding the shortest closed path that visits all given points(cities) only once
- then return to the starting point

## how to approach
- read city coordinates(x,y) from stdin
- generate all possible permutations of cities
- calculate the shortest path of each permutation and its shortest path length
- print the shortest path length

## example
For example this should work:
$> cat square.txt
1, 1
0, 1
1, 0
0, 0
$> ./tsp < square.txt | cat -e
4.00$