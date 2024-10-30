updeated: 24.10.30

# to fix
## checker's prob

### (1) valid parameters & invalid operations

	valgrind ./checker 1 2 3 
	rrrrrr

	- causes mem leak
	- after Error -> should be terminated

