#include "hash_tables.h"

/**
 * shash_table_create - To creates sorted hash table
 * @size:Size of the new sorted hash table
 *
 * Return: NULL if error occurs
 * Otherwise - Pointer to the new sorted hash table
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;
	unsigned long int i;

	new_table = malloc(sizeof(shash_table_t));
	if (new_table == NULL)
		return (NULL);

	new_table->size = size;

	new_table->array = malloc(sizeof(shash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		new_table->array[i] = NULL;

	new_table->shead = NULL;
	new_table->stail = NULL;

	return (new_table);
}

/**
 * create_node - Creates a node
 * @size: The size of new sorted hash table.
 *
 * Return: new_node
 */

shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *new_node;

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;

	return (new_node);
}

/**
 * shash_table_set - it adds an element to a sorted hash table
 * @ht: a Pointer to the sorted hash table
 * @value: A value associated with key
 * @key: The key to Add - cannot be an empty string
 *
 * Return: 0 on failure Otherwise - 1.
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *temp;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = hash_djb2((const unsigned char *)key) % ht->size;

	temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			if (temp->value == NULL)
				return (0);
			return (1);
		}
		temp = temp->next;
	}

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		temp = ht->shead;
		while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
			temp = temp->snext;
		new_node->snext = temp->snext;
		new_node->sprev = temp;
		if (temp->snext != NULL)
			temp->snext->sprev = new_node;
		else
			ht->stail = new_node;
		temp->snext = new_node;
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

/**
 * shash_table_get - It retrieves the value associated
 * with a key in a sorted hash table.
 * @key: A Key to get the value of
 * @ht: pointer to the sorted hash table
 *
 * Return: NULL If key cannot be matched
 * Otherwise - The value associated with key in ht
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *temp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = hash_djb2((const unsigned char *)key) % ht->size;
	temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - it prints a sorted hash table in order
 * @ht: A Pointer to the sorted hash table
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	int flag = 0;

	if (ht == NULL)
		return;

	temp = ht->shead;

	printf("{");
	while (temp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		flag = 1;
		temp = temp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - it prints sorted hash table in reverse order
 * @ht: A Pointer to sorted hash table to print
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	int flag = 0;

	if (ht == NULL)
		return;

	temp = ht->stail;

	printf("{");
	while (temp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		flag = 1;
		temp = temp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - it deletes the sorted hash table
 * @ht: a pointer to a sorted hash table
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *temp, *next_node;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp != NULL)
		{
			next_node = temp->next;
			free(temp->key);
			free(temp->value);
			free(temp);
			temp = next_node;
		}
	}

	free(ht->array);
	free(ht);
}
