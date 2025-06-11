#include "includes/libft.h"
/**
 * @brief	Copies `n` bytes(copy bytes by bytes) from the source memory area to the destination memory area.
 * 
 * when the source and destination memory areas don't overlap. If so, use 'memmove'
 *
 * @pre		The function does not check whether dest has enough allocated memory for  the n bytes. 
 * @pre		It only checks if dest or src is NULL. 
 * @pre		Therefore, it is the responsibility of the caller to ensure that dest has enough space. 
 * @param	dst Pointer to the destination memory area.
 * @param	src Pointer to the source memory area.
 * @param	n Number of bytes to copy.
 * @return	a pointer to the destination memory area (`dst`).
 * @return	NULL,  If either `dst` or `src` is NULL
 * @note	why using (const)unsigned char *? : just to move pointer byte by byte
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	if (!dest || !src)
		return (NULL); //check: return (dest)?
	temp_dest = (unsigned char *)dest;
	temp_src = (const unsigned char *)src;
	while (n--)
	{
		*temp_dest++ = *temp_src++;
	}
	return (dest);
}