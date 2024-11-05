updated: 24.11.05

# ft_printf(const char *s, ...) 
- examples:  
	printf("%d", hi);  
	printf("hi\n");
## 1st argument: **s*
- str that specifies the *format* a
- or str that will be printed as it is

## 2nd argument: *...*(=an ellipsis)
- indicates the func can accept a variable nbr of arguments. (=variadic func)
- values to be formatted and printed according that *format*

# va_list
## def
- #include <stdarg.h> //for handling var arg lists
- allows to access the arguments passed to it after the format string

## usage
- in *va_start*, *va_arg*, *va_end* to iterate through the var arguments

## example : sum
     #include <stdarg.h>
     #include <stdio.h>

     int sum(int count, ...) {
         va_list args;
         int total = 0;

         va_start(args, count);
         for (int i = 0; i < count; i++) {
             total += va_arg(args, int);
         }
         va_end(args);
         return total;
     }

     int main() {
         printf("Sum: %d\n", sum(3, 1, 2, 3)); // Output: Sum: 6
         return 0;
     }

	//first (3) = count of nbrs

# va_arg
## def
- macro works by mving ptr to the next arg in the var arg list

## how it works?
- *va_start* : inits *va_list* var, which means it point to the 1st arg
	-> set up *va_list* (*args* this case)
	-> and point to the 1st arg after the last fixed param (*count* here)
- *va_arg* : retrieves or updates pointer to the next arg of the specified *type*, moves pointer forward by *sizeof(type)*
- *va_end* : clean up the *va_list*, for resource management