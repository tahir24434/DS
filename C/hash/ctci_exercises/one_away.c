#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

char* duplicate_string (char* src) {
  char* dst = malloc(strlen(src) + 1);
  if (dst == NULL) return NULL;
  strcpy(dst, src);
  return dst;
}

bool is_one_away(char* str1, char* str2) {
  int str1_len = 0;
  int str2_len = 0;
  int smaller_len = 0;
  char* smaller = NULL;
  char* bigger = NULL;
  int smaller_index, bigger_index = 0;
  bool diff_allow = true;

  // If difference of string length is greater than 1 characheter: return false.
  str1_len = strlen(str1);
  str2_len = strlen(str2);
  if ((str2_len - str1_len) > 1 || (str1_len - str2_len) > 1)
    return false;

  if (str1_len < str2_len) {
    smaller = str1;
    bigger = str2;
    smaller_len = str1_len;
  }
  else {
    smaller = str2;
    bigger = str1;
    smaller_len = str2_len;
  }

  // Here begins the real game.
  for (smaller_index = 0; smaller_index < smaller_len; smaller_index++) {
    if (smaller[smaller_index] != bigger[bigger_index]) {
      if (diff_allow) {
        diff_allow = false;
        smaller_index++;
      }
      else
        return false;
    } else {
      smaller_index++;
      bigger_index++;
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  char* str1 = NULL;
  char* str2 = NULL;
  int opt = 0;

  while ((opt=getopt(argc, argv, "a:b:h")) != -1) {
    switch(opt) {
      case 'a':
        str1 = duplicate_string(optarg);
        break;
      case 'b':
        str2 = duplicate_string(optarg);
        break;
      case 'h':
        printf("./one_away.out -a pale -b palr\n");
        return 0;
        break;
    }
  }

  bool one_away = is_one_away(str1, str2);
  if (one_away == 0)
    printf("NO. strings are not one operation away\n");
  else
    printf("YES. strings are one operation away\n");
}
