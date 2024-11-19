# record
## 241119:rewrite
- ft_strchr
- ft_memcpy

# 1.ft_strchr
- char	*ft_strchr(const char *s, int c)

## is used in...
- get_next_line

## to remember
- handle this case: 'c'='\0'

# ft_memcpy vs ft_memmove
# synopsis
       #include <string.h>

       void *memcpy(void dest[restrict .n], const void src[restrict .n], size_t n);

## is used in...
- get_next_line

## to consider
### 1. diff : memcpy vs. memmove
- memcpy: Use when the source and destination memory areas do not overlap.
- memmove: Use when the source and destination memory areas may overlap, as it ensures that the copy is performed correctly.

### 2. why void *, const void *?
- for generic programming: Using void * is a common practice in C. This allows to write more reusable and adaptable code. For example, ft_memcpy can be used to copy arrays of different types without needing separate implementations for each type.

- example
```c
int main()
{
    int src_int = 42;
    int dest_int;
    ft_memcpy(&dest_int, &src_int, sizeof(int));

    char src_char = 'A';
    char dest_char;
    ft_memcpy(&dest_char, &src_char, sizeof(char));

    // Now dest_int contains 42 and dest_char contains 'A'
    return 0;
}
```

## 3: why casting to '(const) unsigned char *' within ft_memcpy?
Casting to `unsigned char` in the `ft_memcpy` function is a common practice in C programming, particularly when dealing with raw memory operations. Here’s a detailed explanation of why this casting is used:

### Reasons for Casting to `unsigned char`

1. **Byte-wise Operations**:
   - The `memcpy` function is designed to copy raw bytes from one memory location to another. Since `unsigned char` is guaranteed to represent all possible byte values (0 to 255), it is the most appropriate type for byte-wise operations. Using `unsigned char` ensures that all bits are treated as data without any sign interpretation.

2. **Avoiding Undefined Behavior**:
   - In C, the `char` type can be either signed or unsigned, depending on the implementation. If `char` is signed, values greater than 127 can be interpreted as negative numbers when cast to `int`. This can lead to unexpected behavior when copying data that may include such values. By using `unsigned char`, you avoid the risk of encountering undefined behavior due to sign extension or trap representations.

3. **Standard Compliance**:
   - The C standard specifies that functions like `memcpy` should treat each byte as if it were an `unsigned char`. This means that the behavior of `memcpy` is defined in terms of `unsigned char`, making it a best practice to use this type in your own implementations to ensure compliance with the standard.

4. **Portability**:
   - Using `unsigned char` makes your code more portable across different platforms and compilers. Since the behavior of `char` can vary, relying on `unsigned char` helps ensure that your code behaves consistently regardless of the underlying architecture.

### Example of `ft_memcpy`

Here’s a simplified version of how `ft_memcpy` might look with the casting to `unsigned char`:

```c
void *ft_memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest; // Cast destination to unsigned char*
    const unsigned char *s = (const unsigned char *)src; // Cast source to unsigned char*

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i]; // Copy byte by byte
    }
    return dest; // Return the original destination pointer
}
```

### Conclusion

Casting to `unsigned char` in memory manipulation functions like `ft_memcpy` is essential for ensuring that the function operates correctly and predictably across different systems. It avoids potential pitfalls associated with signed characters and aligns with the C standard's expectations for byte-level operations. This practice is widely adopted in the C programming community for these reasons. 

For further reading, you can refer to discussions on platforms like [Stack Overflow](https://stackoverflow.com/questions/54964262/implement-memcpy-is-unsigned-char-needed-or-just-char) that delve into the specifics of this topic.

### One step further
- C11dr §7.23.1 3 : 11 standard, under the section <string.h>
```For all functions in this subclause, each character shall be interpreted as if it had the type unsigned char (and therefore every possible object representation is valid and has a different value).
```
- meaning : each character is interpreted as if it had the type `unsigned char` (and therefore every possible object representation is valid and has a different value: 0 to 255 without any sign interpretation)

# ft_memcpy

## suggested by gpt-4o
To optimize your `ft_memcpy` function, you can consider a few improvements based on common practices and optimizations used in standard library implementations. Here are some suggestions:

1. **Return Value on NULL Pointers**: As mentioned earlier, returning `NULL` when either `dest` or `src` is `NULL` is a common practice, but it might be more consistent with standard `memcpy` to return `dest` regardless. This is because `memcpy` does not typically check for `NULL` pointers; it assumes the caller has ensured valid pointers.

2. **Optimization for Larger Data Types**: You can optimize the function by copying larger chunks of data when possible, such as using `long` or `int` types, which can be more efficient on some architectures. This is similar to how some optimized versions of `memcpy` work.

3. **Handle Small Sizes Efficiently**: For very small sizes, the overhead of checking and branching might outweigh the benefits of optimization. Ensure that the function handles small sizes efficiently.

4. **Avoid Overlapping Memory Areas**: Ensure that the function is only used when the source and destination do not overlap, as overlapping areas should use `memmove`.

Here’s an updated version of your `ft_memcpy` with some of these optimizations:

````c:42_core_projects/rank_00/libft/code_2nd_practice/ft_memcpy.c
#include "includes/libft.h"

/**
 * @brief	Copies `n` bytes from the source memory area to the destination memory area.
 * 
 * This function should only be used when the source and destination memory areas do not overlap.
 * If they might overlap, use 'memmove' instead.
 *
 * @pre		The function does not check whether dest has enough allocated memory for the n bytes. 
 * @pre		It only checks if dest or src is NULL. 
 * @pre		Therefore, it is the responsibility of the caller to ensure that dest has enough space. 
 * @param	dst Pointer to the destination memory area.
 * @param	src Pointer to the source memory area.
 * @param	n Number of bytes to copy.
 * @return	a pointer to the destination memory area (`dst`).
 * @note	Why using (const)unsigned char *? : just to move pointer byte by byte
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long		*long_dest;
	const unsigned long	*long_src;
	unsigned char		*byte_dest;
	const unsigned char	*byte_src;

	if (!dest || !src)
		return (dest); // Return dest for consistency with standard memcpy

	long_dest = (unsigned long *)dest;
	long_src = (const unsigned long *)src;

	// Copy in chunks of sizeof(unsigned long) if possible
	while (n >= sizeof(unsigned long))
	{
		*long_dest++ = *long_src++;
		n -= sizeof(unsigned long);
	}

	// Copy any remaining bytes
	byte_dest = (unsigned char *)long_dest;
	byte_src = (const unsigned char *)long_src;
	while (n--)
	{
		*byte_dest++ = *byte_src++;
	}

	return (dest);
}
````

### Key Changes:
- **Chunk Copying**: The function now attempts to copy data in chunks of `unsigned long` for efficiency, which can be faster on many architectures.
- **Return Value**: The function returns `dest` even if `src` or `dest` is `NULL`, aligning with typical `memcpy` behavior.
- **Documentation**: Updated comments to reflect the changes and clarify the function's behavior.

These changes aim to make the function more efficient while maintaining its intended functionality. However, always test thoroughly to ensure it behaves correctly in your specific use case.