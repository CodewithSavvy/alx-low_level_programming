A README FILE FOR MALLOC FUNCTION DISCRIBING THE 0x0B. C - malloc, free, DIRECTORY AT THIS REPO:

TASK 0 OF THIS PROJECT IS ANSWERED IN THE FILE ; 0-create_array.c;
Which consist of the question;

-Write a function that creates an array of chars, and initializes it with a specific char.
With the requirements of:
-Prototype: char *create_array(unsigned int size, char c);
-Returns NULL if size = 0
-Returns a pointer to the array, or NULL if it fails.


TASK 1 OF THIS PROJECT IS ANSWERED IN THE FILE ;1-strdup.c;
Which consist of the question;
`
-Write a function that concatenates two strings.
With the requirements of:
-Prototype: char *str_concat(char *s1, char *s2);
-The returned pointer should point to a newly allocated space in memory which contains the contents of s1, followed by the contents of s2, and null terminated
-if NULL is passed, treat it as an empty string
-The function should return NULL on failure

TASK 2 OF THIS PROJECT IS ANSWERED IN THE FILE ;2-str_concat.c;
Which consist of the question;

-Write a function that concatenates two strings.
With the requirements of:
-Prototype: char *str_concat(char *s1, char *s2);
-The returned pointer should point to a newly allocated space in memory which contains the contents of s1, followed by the contents of s2, and null terminated
-if NULL is passed, treat it as an empty string
-The function should return NULL on failure;

TASK 3 OF THIS PROJECT IS ANSWERED IN THE FILE ; 3-alloc_grid.c;
Which consist of the question;
-Write a function that returns a pointer to a 2 dimensional array of integers.
With the requirements of:
-Prototype: int **alloc_grid(int width, int height);
--Each element of the grid should be initialized to 0
-The function should return NULL on failure
-If width or height is 0 or negative, return NULL

TASK 4 OF THIS PROJECT IS ANSWERED IN THE FILE ;4-free_grid.c;
Which consist of the question;
Write a function that frees a 2 dimensional grid previously created by your alloc_grid function.
With the requirements of:
Prototype: void free_grid(int **grid, int height);
Note that we will compile with your alloc_grid.c file. Make sure it compiles.


TASK 5 OF THIS PROJECT IS ANSWERED IN THE FILE ;100-argstostr.c;

Which consist of the question;
Write a function that concatenates all the arguments of your program.
With the requirements of:
Prototype: char *argstostr(int ac, char **av);
Returns NULL if ac == 0 or av == NULL
Returns a pointer to a new string, or NULL if it fails
Each argument should be followed by a \n in the new string

TASK 6 OF THIS PROJECT IS ANSWERED IN THE FILE ;101-strtow.c;

Write a function that splits a string into words.
With the requirements of:
Prototype: char **strtow(char *str);
The function returns a pointer to an array of strings (words)
Each element of this array should contain a single word, null-terminated
The last element of the returned array should be NULL
Words are separated by spaces
Returns NULL if str == NULL or str == ""
If your function fails, it should return NULL
