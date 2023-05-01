# 0x13. C - More singly linked lists

0. print_listint.c: function that prints all the elements of a listint_t list.(Return: the number of nodes, You are allowed to use printf).
1. listint_len.c: function that returns the number of elements in a linked listint_t list.
2. add_nodeint.c: function that adds a new node at the beginning of a listint_t list.(Return: the address of the new element, or NULL if it failed).
3. add_nodeint_end.c: function that adds a new node at the end of a listint_t list.(Return: the address of the new element, or NULL if it failed).
4. free_listint.c: function that frees a listint_t list.
5. free_listint2.c: function that frees a listint_t list.(The function sets the head to NULL).
6. pop_listint.c:function that deletes the head node of a listint_t linked list, and returns the head node’s data (n).(if the linked list is empty return 0).
7. get_nodeint.c: function that returns the nth node of a listint_t linked list.(where index is the index of the node, starting at 0, if the node does not exist, return NULL).
8. sum_listint.c: function that returns the sum of all the data (n) of a listint_t linked list.(if the list is empty, return 0).
9. insert_nodeint.c: function that inserts a new node at a given position.(where idx is the index of the list where the new node should be added. Index starts at 0, Returns: the address of the new node, or NULL if it failed, if it is not possible to add the new node at index idx, do not add the new node and return NULL).
10. delete_nodeint.c: function that deletes the node at index index of a listint_t linked list.(where index is the index of the node that should be deleted. Index starts at 0, Returns: 1 if it succeeded, -1 if it failed).
100. reverse_listint.c: function that reverses a listint_t linked list.

Prototype: listint_t *reverse_listint(listint_t **head);
Returns: a pointer to the first node of the reversed list
You are not allowed to use more than 1 loop.
You are not allowed to use malloc, free or arrays
You can only declare a maximum of two variables in your function.
