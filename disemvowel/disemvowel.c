#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char* disemvowel(char* str) {
  int size, i, j;
  int num_vowels;
  char* result;

  size = strlen(str);
  
for (i = 0; str[i] != '\0'; ++i) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
            str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
            str[i] == 'U') {
            ++num_vowels;
    }
}


for(i=0; i<size; i++){
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
            str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
            str[i] == 'U'){
	    for(j=i; j<size; j++)
	    {
		    str[j]=str[j+1];
	    }
	    size--;
    }
}

result = calloc(size-num_vowels+1, sizeof(char*));
result[0] = '\0';
free(result);
return result;
}
