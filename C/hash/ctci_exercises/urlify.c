#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int space_count(char* str, char* char_to_find) {
  int i = 0;
  int count = 0;
  printf("str=%s, char=%s", str, char_to_find);
  fflush(stdout);
  int str_length = strlen(str);

  for (i = 0; i < str_length; i++) {
    if (str[i] == char_to_find[0]) {
      count++;
    }
  }
  return count;
}

char* replace_str(char* str, char* find, char* replace) {
  int num_occurances = 0;
  int find_len = 0;
  int replace_len = 0;
  char* insert_point = NULL;
  char* new_str = NULL;
  char* result = NULL;
  int len_str_before_ins_point = 0;

  find_len = strlen(find);
  replace_len= strlen(replace);
  num_occurances = space_count(str, find);
  printf("number of matches=%d\n", num_occurances);

  new_str = result = malloc(strlen(str) + (replace_len - find_len) * num_occurances + 1);

  if (!new_str)
    return NULL;

  while (num_occurances--) {
    insert_point = strstr(str, find);
    len_str_before_ins_point = insert_point - str;
    new_str = strncpy(new_str, str, len_str_before_ins_point) + len_str_before_ins_point;
    new_str = strcpy(new_str, replace) + replace_len;
    str += len_str_before_ins_point + replace_len; // move to next "end of rep"
  }
  strcpy(new_str, str);
  return result;
}

char* duplicate_string (char* src) {
  char* dst = malloc(strlen(src) + 1);
  if (dst == NULL) return NULL;
  strcpy(dst, src);
  return dst;
}

int main (int argc, char *argv[]) {
  int opt = 0;
  char* str = NULL;
  char* find = NULL;
  char* replace = NULL;
  char* new_str = NULL;

  while ((opt = getopt(argc, argv, "s:f:r:")) != -1) {
    switch(opt) {
      case 's':
        str = duplicate_string(optarg);
        break;
      case 'f':
        find = duplicate_string(optarg);
        break;
      case 'r':
        replace = duplicate_string(optarg);
        break;
      case '?':
        printf("invalid charachter\n");
      break;
    }
  }

  new_str = replace_str(str, find, replace);
  printf("====== new_str=%s ======\n", new_str);
  // Free memory
  free(str);
  free(find);
  free(replace);
}
