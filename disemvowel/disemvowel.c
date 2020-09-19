#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char *disemvowel(char *str) {
	int size, i, j;
	int num_vowels;
	char* result;
	size = strlen(str);
	

	//Creates function to check string for vowels and change the value of num_vowels
	int vowelCheck(char str) {
		int num_vowels;
		for (i = 0; str[i] != '\0'; ++i){
			if (str[1] == 'a' || str[i] == 'e' || str[i] == 'i'|| str[i] == 'o' || str[i] == 'U' || str [i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
			       	++num_vowels
			}
		}
	}

	//Runs the function
	vowelCheck(str);
	
	//If there are no vowels, return the input string
	if (num_vowels = 0){
		return str;
	}
	
	//Otherwise, remove the vowels from the string
	else{
		for(i=0; i<size; i++){
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
				for(j=i; j<size; j++)
				{
					str[j]=str[j+1];
				}
				size--;
			}
		}

		//Allocates memory for the resulting string including an extra bit for the null terminator
		//Freees the memory
		//return
		result = (char*)calloc(size-num_vowels+1, sizeof(char));
		result[0] = '\0';
		free(result);
		return result;
	}
}
