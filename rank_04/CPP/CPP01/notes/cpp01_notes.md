# C++ File Manipulation (CPP01/ex04)

## 1. Key C++ Features to Use

#### Opening and Reading Files
```cpp
#include <fstream>

// Open input file
std::ifstream inFile(filename);
if (!inFile.is_open()) {
    std::cerr << "Error: Cannot open file " << filename << std::endl;
    return 1;
}
```

#### Creating and Writing to Files
```cpp
std::ofstream outFile(filename + ".replace");
if (!outFile.is_open()) {
    std::cerr << "Error: Cannot create output file" << std::endl;
    return 1;
}
```

#### Reading the Entire File Content
```cpp
std::string content;
std::string line;
while (std::getline(inFile, line)) {
    content += line;
    if (!inFile.eof())
        content += '\n';
}
```

#### Custom String Replace Function (Since std::string::replace is forbidden)
```cpp
std::string replaceAll(const std::string& str, const std::string& from, const std::string& to) {
    std::string result = str;
    size_t pos = 0;
    
    while ((pos = result.find(from, pos)) != std::string::npos) {
        result = result.substr(0, pos) + to + result.substr(pos + from.length());
        pos += to.length();
    }
    
    return result;
}
```

### 3. Sample Implementation

```cpp
#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& str, const std::string& from, const std::string& to) {
    if (from.empty())
        return str;
        
    std::string result = str;
    size_t pos = 0;
    
    while ((pos = result.find(from, pos)) != std::string::npos) {
        result = result.substr(0, pos) + to + result.substr(pos + from.length());
        pos += to.length();
    }
    
    return result;
}

int main(int ac, char **av) {
    // Check arguments
    if (ac != 4) {
        std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    
    // Open input file
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return 1;
    }
    
    // Create output file
    std::ofstream outFile(filename + ".replace");
    if (!outFile.is_open()) {
        std::cerr << "Error: Cannot create output file" << std::endl;
        inFile.close();
        return 1;
    }
    
    // Read content and replace
    std::string content;
    std::string line;
    while (std::getline(inFile, line)) {
        content += line;
        if (!inFile.eof())
            content += '\n';
    }
    
    // Replace and write to output file
    std::string modifiedContent = replaceAll(content, s1, s2);
    outFile << modifiedContent;
    
    // Clean up
    inFile.close();
    outFile.close();
    
    std::cout << "File processed successfully: " << filename + ".replace" << std::endl;
    return 0;
}
```

### 4. Edge Cases to Handle

1. **Insufficient arguments**:
   - Check that exactly 3 arguments are provided

2. **File doesn't exist**:
   - Verify input file can be opened

3. **Cannot create output file**:
   - Check that output file can be created

4. **Empty s1 string**:
   - Handle this case (either return original text or show error)

5. **Large files**:
   - Consider reading and processing line by line if memory is a concern

### 5. Testing

Test your program with various inputs:
- Normal case: `./replace example.txt "hello" "world"`
- Empty s1: `./replace example.txt "" "world"`
- Empty s2: `./replace example.txt "hello" ""`
- Non-existent file: `./replace nonexistent.txt "hello" "world"`
- File with no matches: `./replace example.txt "xyz" "abc"`



### lib: <fstream>

### external library of cpp?


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


