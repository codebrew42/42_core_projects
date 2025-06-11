//part1

// std::vector example
std::vector<int> vec = {1, 2, 3, 4, 5};
size_t vecSize = vec.size();  // Returns 5

// std::string example
std::string str = "Hello";
size_t strLen = str.size();   // Returns 5

// std::array example (C++11 and later)
std::array<double, 3> arr = {1.1, 2.2, 3.3};
size_t arrSize = arr.size();  // Returns 3

// std::map example
std::map<std::string, int> dict;
dict["apple"] = 1;
dict["banana"] = 2;
size_t dictSize = dict.size(); // Returns 2// Raw array - NO .size() available
int* arr = new int[5];

//part 2
// arr.size() doesn't exist! You must track the size separately
int size = 5;

// C-style array with fixed size
int fixedArr[10];
// fixedArr.size() doesn't exist either
// Instead, you can use the sizeof trick for fixed-size arrays:
size_t fixedArrSize = sizeof(fixedArr) / sizeof(fixedArr[0]); // Returns 10