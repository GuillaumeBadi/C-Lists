C-Lists
=======

### How to
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
