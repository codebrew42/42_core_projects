# 241118
## what to do?
- write main, .h, plan

## remember
- open -> read (in gnl) -> close

## what i did
- writing main, get_next_lin.c

## to do
- gnl.c/extract_line{}
- check: exam03 
- check: errno

# 241119
## what I did
- writing: get_next_line.c
	- open -> read -> update(stash) & extract line
- rewrite: ft_strchr, ft_memcpy 

## to do
- fix seg fault
- practice: Makefile + re-link(learn)

## remember
### ft_memcpy
```c
ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char 		*temp_dest;
	const unsigned char	*temp_src;

	//copy byte by byte
	return (dest);
}
```
- to copy byte by byte, create (const) unsigned char *
- and return (dest) itself