#include <stdlib.h>
#include <stdio.h>

typedef struct {
  char* key;
  char* value;
  struct node_t* next;
} node_t;

typedef struct {
  char** table;
  int size;
} hashtable_t;

hashtable_t* ht_create (int size) {
  // malloc hash table struct.
  hashtable_t* hashtable = NULL;
  if((hashtable = malloc(sizeof(hashtable_t)))== NULL) {
    return NULL;
  } 

  // malloc for table array.
  if((hashtable->table = malloc(sizeof(node_t*) * size)) == NULL) {
    return NULL;
  }

  // Initialize table slots with Null
  memset(hashtable->table, 0, sizeof(node_t*) * size);

  hashtable->size = size;
}

// Interpreting keys as natural numbers
unsigned long int pre_hash(char* key) {
  unsigned long int natural_num_key = 5381;

  int i = 0;
  while (natural_num_key < ULONG_MAX && i < strlen(key)) {
    natural_num_key = natural_num_key << 8;
    natural_num_key += key[i];
    i++;
  }
  return natural_num_key;
}

// Map giant universe of keys to the small set of slots in the table.
// 3 populare methods. 1) Division method 2) Mulitplication method 3) Universal Hashing
// Third one is theoretically good. For ease, we will follow division method i.e. 
// h(k) = k mod m.
int hash(hashtable_t* hashtable, unsigned long int natural_num_key) {
  return natural_num_key % hashtable->size;
}

char* duplicate_string (char* src) {
  char* dst = malloc(strlen(src) + 1);
  if (dst == NULL) return NULL;
  strcpy(dst, src);
  return dst;
}

node_t* ht_newnode(char* key, char* value) {
  node_t* node;
  if ((node = malloc(sizeof node_t)) == NULL) return NULL;

  if ((node->key = duplicate_string (key)) == NULL) return NULL;
  if ((node->value= duplicate_string (value)) == NULL) return NULL;
  node->next = NULL;
  return node;
}

ht_insert(hashtable_t* hashtable, char* key, char* value) {

  // Create a new node.
  node_t* node = ht_newnode (key, value);
  
  // Get slot of table where new items should be inserted.
  unsigned long int prehash = pre_hash(key);
  int slot = hash(hashtable, prehash);

  // Check whether "key" already exist?
  node_t* next = hashtable->table[slot];
  while (next != NULL && (strcmp(key, next->key) != 0)) {
    last = next;
    next = next->next;
  }
  
  // Key exists
  if (next != NULL && (strcmp(key, next->key) == 0)) {
    free(next->value);
    next->value = node->value;
  } else {
    if (next == hashtable->table[slot]) {
      hashtable->table[slot] = node;
    } else {
      last->next = node;
    }
  }
}
