// Copyright 2024 <dimrimoff>

#include <stdio.h>

char* find_substring (char *str, char *substr) {
  int str_len = 0;
  int substr_len = 0;
    
  while (str[str_len] != '\0') {
    str_len++;
  }
  
  while (substr[substr_len] != '\0') {
    substr_len++;
  }

  for (int i = 0; i <= str_len - substr_len; i++) {
    int k;
        
    for (k = 0; k < substr_len; k++) {
      if (str[i + k] != substr[k]) {
        break;
      }
    }

    if (k == substr_len) {
      return str + i;
    }
  }

  return NULL;
}

int main() {
  char str[100];
  char substr[100];
    
  printf("Input string: ");
  scanf("%99[^\n]", str);
  getchar();
    
  printf("Input substring: ");
  scanf("%99[^\n]", substr);

  printf("Substring pointer is: %p\n", find_substring(str, substr));
  
  return 0;
}
