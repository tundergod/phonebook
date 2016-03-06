#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define OPT 1//judge is OPT or ORIG(in main.c)
typedef struct __PHONE_BOOK_ENTRY {
	char lastName[MAX_LAST_NAME_SIZE];
	char firstName[16];
	char email[16];
	char phone[10];
	char cell[10];
	char addr1[16];
	char addr2[16];
	char city[16];
	char state[2];
	char zip[5];
	struct __PHONE_BOOK_ENTRY *Next;
} entry_all;

typedef struct __LAST_NAME_ENTRY {
	char lastName[MAX_LAST_NAME_SIZE];
	entry_all *detail;
	struct __LAST_NAME_ENTRY *pNext;
} entry;

typedef struct _BKDRHASH_TABLE {
	int size;//size of table
	entry **table;
} hash_table;

entry *findName(char *lastName, hash_table *hashtable);
void append(char *lastName, hash_table *hashtable);
unsigned int hash(hash_table *hashtable, char *str);
hash_table *create_hash_table();
#endif
