C-Lists
=======

### This should compile without any error

``` c
int		main(void)
{
	t_node		*list;
	char		*it_is_what;

	// create the list by creating the first node => ("This")
	list = ft_create_node("This");

	// push an element to the list => ("This", "is", "oops")
	list = ft_push(list, "is");
	list = ft_push(list, "oops");

	// pop an element from the list => ("This", "is")
	list = ft_pop(list);

	// add an element at the beginning => ("oops", "Hey", "This", "is")
	list = ft_unshift(list, "Hey");
	list = ft_unshift(list, "oops");

	// guess what => ("Hey", "This", "is")
	list = ft_shift(list);

	// get the length => 3
	ft_putnbr(list_length(list));
	ft_putchar('\n');

	// set or replace an element => ("Hey", "this", "is", , "AWESOME")
	list = ft_list_set(list, 4, "AWESOME");
	list = ft_list_set(list, 1, "this");

	// get an element from the index => "AWESOME"
	it_is_what = ft_list_get(list, 4);
	ft_putstr(it_is_what);
	ft_putchar('\n');

	// get the index of the first occurence of a word => 2
	ft_putnbr(ft_indexOf(list, "is"));
	ft_putchar('\n');

	// test if a list contains a specific element
	if (ft_indexOf(list, "Hoora") < 0)
		ft_putstr("Sorry, it is not in the list\n");
	else
		ft_putstr("Yeah ! it exists in the list\n");
	ft_putchar('\n');

	// finally, print the list in a nice format
	ft_print_list(list);
	ft_putchar('\n');

	return (0);
}
```

### Do it yourself !
	simply make these functions so that the previous main compile

``` c
// print a character
void				ft_putchar(char c);

// print a string
void				ft_putstr(char *str);

// print a number
void				ft_putnbr(int number);

// return the length of a string
int					ft_strlen(char *str);

// return 0 if the strings are equals
int					ft_strcmp(char *s1, char *s2);

// duplicate an entire string with malloc
char				*ft_strdup(char *str);

// duplicate a string from the beginning to the first space
// example => "Hello World!" -> "Hello"
char				*ft_str_space_dup(char *str);

// print a message, then listen the file descriptor 0, to get 
// the user input (you might just take it in the "src" folder if you are weak)
char				*ft_prompt(char *message);

//Serious stuff starts here
// (if you have not done it yet, organize your code in different files and folders and write your prototypes
// in a *.h file (you might also `touch` a Makefile))

// create and returns a list element pointing to NULL
t_node				*ft_create_node(char *data);

// add an element at the end of the list ("not here", "here")
t_node				*ft_push(t_node *begin, char *data);

// add an element at the begining of the list
t_node				*ft_unshift(t_node *begin, char *data);

// remove the last element ("not this one", "that one")
t_node				*ft_pop(t_node *begin);

// remove the first element of the list
t_node				*ft_shift(t_node *begin);

// returns the length of the list
int					list_length(t_node *node);

// ("print", "the", "list", "in", "this", "format")
void				ft_print_list(t_node *begin);
// for that you'll need a recursive function that prints a list backwards
void				ft_print_reversed(t_node *node);

// return the value a a list like an array
// example: ("Hello", "World!") --- ft_list_get(list, 1) returns World wich is at index 1 (Hello at index 0)
// got it ?
void				*ft_list_get(t_node *node, int index);

// It's getting harder and harder. 
// This guy down here replaces the value of a node[i], if the node doesn't existe (yet), pushes some empty nodes to creates the one it wants
// example : ("Hello", "my") --- ft_list_set(list, 3, "friend"); ft_list_set(list, 1, "My"); -> ("Hello", "My", , "friend")
t_node				*ft_list_set(t_node *node, int index, char *value);

// returns the index of an element if the particular element is exists in the list.
// if not, simply returns -1
int					ft_indexOf(t_node *node, char *data);

// Finals kids !
// this guy asks the user for a string removes the extra spaces and tabs, and create a list with the words
//
// guillaume_prompt$ ./prompt
// guillaume_prompt$ Type your command: Hello my name is guillaume
// guillaume_prompt$ ("Hello", "my", "name", "is", "guillaume")
t_node				*ft_parse(char *str);
```
####Enjoy
