#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char* duplicate_string (char* src) {
  char* dst = malloc(strlen(src) + 1);
  if (dst == NULL) return NULL;
  strcpy(dst, src);
  return dst;
}

char* compress_string (char* str) {
  int i = 0;
  int j = 0;
  int str_len = strlen(str);
  char* comp_str = malloc(str_len + 1);
  int count = 1;
  // TODO: return if null

  for (i = 0; i < str_len && j < str_len; i++) {
    if (str[i] == str[i+1]) {
      count++;
    } else {
      comp_str[j] = str[i];
      comp_str[j+1] = '0' + count;
      count = 1;
      j += 2;
    }
  }
  printf("compressed string = %s\n", comp_str);
  comp_str[j] = '\0';

  if (strlen(comp_str) < str_len)
    return comp_str;
  else
    return str;
}

int main(int argc, char* argv[]) {
  int opt = 0;
  char* str = NULL;
  char* comp_str = NULL;

  while((opt = getopt(argc, argv, "s:h")) != -1) {
    switch(opt) {
      case 's':
        str = duplicate_string(optarg);
        break;
      case 'h':
        printf("helpt");
        break;
    }
  }

  comp_str = compress_string(str);
  printf("compressed string = %s\n", comp_str);
}
