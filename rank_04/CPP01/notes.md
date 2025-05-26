## what i know about...

### heap vs. stack alloc

#### heap allocation
- need 'new' and 'delete'
- creating ptr?

#### stack allocation
- has more (+)
	- no need to 'delete' or call 'deconstructor'
- creating arr


### creating methods zombie

- can create two diff types for construction
```
class {
	public:
		Zombie();				//for alloc mem and init with null
		Zombie(string name);	//for assigining val 
};
```

### how to create N-Zombies
```
//alloc
Zombies *z = new Zombie[N];

//assiginig val (name) -> N Zombies named after "name"
while (1->N)
	Zombie("name")

```