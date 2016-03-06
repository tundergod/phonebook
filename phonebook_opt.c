#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "phonebook_opt.h"

#define SIZE 9999

unsigned int hash(hash_table *hashtable, char *str)
{
	unsigned int hashval = 0;//start hash's value at 0
	unsigned int seed = 31;
	while(*str)
		hashval = hashval * seed + (*str++);
	return hashval % SIZE;//record as remainder
}

hash_table *create_hash_table()
{
	hash_table *new_table;
	if(SIZE<1) return NULL;//invalid size of table

	//allocate memory for hash table
	new_table = malloc(sizeof(hash_table));
	new_table->table = malloc(sizeof(entry *) *SIZE);

	if(new_table == NULL) return NULL;
	if(new_table->table == NULL) return NULL;

	//initialize the elements of the table
	for(int i; i<SIZE; i++)
		new_table->table[i] = NULL;
	return new_table;
}

entry *findName(char *lastName, hash_table *hashtable)
{
	entry *namelist;
	unsigned int hashval = hash(hashtable, lastName); //count hash value

	//check string is in the correct list based or not
	for(namelist = hashtable->table[hashval]; namelist!=NULL; namelist = namelist->pNext)
		if(strcmp(lastName, namelist->lastName) == 0) return namelist;
	return NULL;//if cant find
}

void append(char *lastName, hash_table *hashtable)//add string
{
	entry *hashed_entry;
	unsigned int hashval = hash(hashtable, lastName);
	hashed_entry = NULL;
	hashed_entry = (entry*) malloc(sizeof(entry)); //allocate memory for hashed's entry
	memcpy(hashed_entry->lastName, lastName, strlen(lastName)); //copy string
	hashed_entry->pNext = hashtable->table[hashval];
	hashtable->table[hashval] = hashed_entry;
}
