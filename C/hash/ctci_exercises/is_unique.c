#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// TODO: One can implement following function using bitshifting as well.
bool is_unique(char* string) {

  int str_len = strlen(string);
  if (str_len > 256) {
    return false;
  }

  bool occurance_table[256];
  memset(occurance_table, 0, sizeof(occurance_table));

  int i = 0;
  for(i = 0; i < str_len; i++) {
    int slot = (int)string[i];
    if(occurance_table[slot]) return false;
    occurance_table[slot] = true;
  }
}

int main(void) {
  bool unique = is_unique("I am legind");
  if (unique) {
    printf("YES, I am unique \n");
  } else {
    printf("I am not unique. There is legend elsewhere as well. \n");
  }
}
