# Libft
## How to use
- Clone this into your project
- `bash installer.sh` will remove `.git/` and `test/`, change the Makefile 
wildcards to plain text, and then removes itself (`installer.sh`).

## ToDo
- Make a python script able to change the documentation section in this document.
- Reprogram `t_bool ft_vdprintf(const int fd, const char *s, ...)`
  - `int`			: "%i"
  - `unsigned int`	: "%u"
  - `char`			: "%c"
  - `c string`		: "%s"
  - `float`			: "%f"
  - `hexadecimal`	: "%h" (Can be used to print a pointer)
  - `binary`		: "%b"
  - `s` or  `l` just before type delimiter : Allows precise type size (short or long). 
  - `#` : Allow numbers to show their base prefix. "0b", "0d", "0x"
  - `+` : Prefix positive numbers with a plus.
  - `^` : Shows letter in base values uppercase (if combined with `#` the prefix
    is also uppercase)
  - `<`, `{`, `}`, `>` : Pad to the left, evenly or to the right, with n spaces, 
    mentionned after the symbol. If evenly is chosen and it can't split evenly, 
	it will pad one more to the left with `{` or to the right `}`.
  - `[<value>,<value>,...]` : Allows to print an array, of n dimensions.
  - `*` : Will replace an asked value inside the string to a value inside va_list.
    Allows to write variable length outputs.
  - `%p` : Allows to pass a pointer to a print function to print following element.
    eg. ft_printf("%p", stack_print, &my_stack)
- Make print vec and matrix be printable using printf -> print double.
- Add functions to the lib :
	- `ft_rand_range(long int min, long int max)`
	- `ft_gnl(int fd)` -> `ft_gnl(int fd, t_bool bs, t_bool truncate)`
	- `long int ft_atoli(const char *ascii)`
    - `t_bool fts_atoli(t_lint *res, const char *ascii)`
    - `t_sign ft_vpuintcmp(const void *v1, const void *v2)`
    - `t_sign ft_vpchrcmp(const void *c1, const void *c2)`
    - `t_bool ft_quick_sort(void *mem, t_size unit, t_len len, t_sign (*cmp)(const void *, const void *))`
    - `t_bool ft_merge_sort(void *mem, t_size unit, t_len len, t_sign (*cmp)(const void *, const void *))`
- Make tests for every function
	- char
	- convert
	- list
	- math
	- memory
	- read
	- string
	- write

## Function code namings
- f_	: Helper functions, not mentionend by libft header, therefore not 
  callable when using libft as a lib.
- ft_	: Default functions from the lib. Generally copies vanilla functions,
  or homemade functions with a vanilla style declaration and behaviour. Those 
  functions work on "power implies responsibility" politics, which means that 
  none of those functions are protected against undefined cases. They preferably 
  crash, to avoid return colisions with non error cases, like pointers 
  being null, giving a length for an array not large enough, non null terminated
  strings, etc ... If you encouter one of those cases, consider, either check 
  before calling the function or, if it exists, call a secured version of the 
  function (explained as follows).
- fts_	: Secured version of a function, usually returning a t_bool or an error 
  code, and needs a pointer to store the result as parameter.
  
## Documentation
### Library structure
```
|- include/
|- src/
	|- char/
	|- cmp/
	|- convert/
	|- list/
	|- math/
	|- memory/
	|- read/
	|- sort
	|- string/
	|- write/
|- test/
```

### Table of contents
- Operations on characters
---
- Void pointer comparisons
---
- Data conversion
---
- Linked List structure
---
- Mathematics
---
- Memory
---
- Read
---
- Sorting algorithms
---
- Operations on c strings
---
- Write
---

### Dependency table (TODO)
Interdependent function calls, have to be avoid if possible.  
The 2nd column shows all direct and undirect libc funcion calls. No matter what depth.
| Function            | libc dependencies                    | libft dependencies                         |
|---------------------|--------------------------------------|--------------------------------------------|
| `ft_example1`       | `malloc`                             | `ft_example2`                              |
| `ft_example2`       | `malloc`                             |                                            |
