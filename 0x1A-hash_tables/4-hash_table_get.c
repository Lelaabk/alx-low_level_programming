#include "hash_tables.h"

/**
 * hash_table_get - retrieve value associated with key
 * in hash table
 * @ht: pointer to hash table.
 * @key: key to get value of
 *
 * Return: if key cannot be matched - NULL
 * otherwise - value associated with key in ht
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->array[index];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;
	return ((node == NULL) ? NULL : node->value);
}
