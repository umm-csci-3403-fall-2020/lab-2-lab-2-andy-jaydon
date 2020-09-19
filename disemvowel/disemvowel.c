#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"
//Function for checking vowels
int vowelCheck(char c){
            if (c == 'a' || c == 'e' || c == 'i' ||
                   c == 'o' || c == 'u' || c == 'A' ||
                   c == 'E' || c == 'I' || c == 'O' ||
                   c == 'U')
               return 0;
	    else
	       return 1;
}
//Main functions
  char* disemvowel(char* str) {
  int size = 0;
  int i = 0;
  int spot = 0;
  int cons = 0;
  char *result;
//get size of string
  size = strlen(str);
//If string is empty return string
  if (size <= 0){
    return str;
  }
//Set number of constants in string
  for (i=0; i<size; i++){
	if (vowelCheck(str[i])==1){
		cons++;
	}
  }
//If number of constants equal size of string, then return string
  if (cons == size){
	return str;
  }
//Allocate mem  
  result = (char*)calloc(cons+1, sizeof(char*));
//Main part of method that removes vowels from the inputted string
  for(i=0; i<size; i++){
    if (vowelCheck(str[i])==1){
		    result[spot]=str[i];
		    spot++;
    }
  }
//Put null char on end of string
result[cons+1] = '\0';
//Output new string with no vowels
return result;
}
