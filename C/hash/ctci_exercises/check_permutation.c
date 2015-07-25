#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_permutation(char* str1, char* str2) {
  if(str1 == NULL || str2 == NULL) return false;
  int str1_len = strlen(str1);
  int str2_len = strlen(str2);
  if(str1_len != str2_len) return false;

  int occurances_table[256];
  memset(occurances_table, 0, sizeof(occurances_table));
  int i = 0;
  for(i = 0; i < str1_len; i++) {
    int slot = (int)str1[i];
    occurances_table[slot]++;
  }

  i = 0;
  for(i = 0; i < str2_len; i++) {
    int slot = (int)str2[i];
    occurances_table[slot]--;
    if(occurances_table[slot] < 0) return false;
  }
  return true;
}

int main(void) {
  char str[10] = "abcdefg";
  char str_perm[10] = "bacedgf";
  char str_not_perm[10] = "gffaecd";
  char str_wrong_length[10] = "ab";
  char *str_null = NULL;

  if(is_permutation(str, str))
    printf("str, str passed\n");
  else
    printf("str, str failed\n");

  if(is_permutation(str, str_perm))
    printf("str, str_perm passed\n");
  else
    printf("str, str_perm failed\n");

  if(is_permutation(str, str_not_perm))
    printf("str, str_not_perm failed\n");
  else
    printf("str, str_not_perm passed\n");

  if(is_permutation(str, str_wrong_length))
    printf("str, str_wrong_length failed\n");
  else
    printf("str, str_wrong_length passed\n");

  if(is_permutation(str, str_null))
    printf("str, str_null failed\n");
  else
    printf("str, str_null passed\n");

  return EXIT_SUCCESS;
}
