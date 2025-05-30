## what i learned in CPP01

### reference vs. pointer manipulation
```
// Reference - creates an alias to message
string &stringREF = message;
// Pointer - stores the address of message
string *stringPTR = &message;

// With reference: access is direct
stringREF = "Changed"; // message is now "Changed"

// With pointer: access requires dereferencing
*stringPTR = "Changed"; // message is now "Changed"

// Display the reference: shows the value
cout << stringREF;  // "Changed"

// Display the pointer: shows the memory address
cout << stringPTR;  // e.g., 0xffffe30587f8
```

### refrence
- use &
- must be init
- can't be reassigned, ionce it refers to an obj, it can't refer to another
- can't be null
- no pointer arithmetic

### address manipulation (pointers)
- use *, &
- can be reassigned
- can be null
- use * to access the pointed-to value
- pointer arithmetic(O)

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


