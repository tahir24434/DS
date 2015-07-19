#include <stblib.h>
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
  if(hashtable = malloc(sizeof(hashtable_t)) == NULL) {
    return NULL;
  } 

  // malloc for table array.
  if(hashtable->table = malloc(sizeof(node_t*) * size) == NULL) {
    return NULL;
  }

  // Initialize table slots with Null
  int i;
  for (i=0; i<size; i++) {
    hashtable->table[i] = NULL;
  }

  hashtable->size = size;
}


