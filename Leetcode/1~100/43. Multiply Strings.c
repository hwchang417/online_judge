#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


char* multiply(char* num1, char* num2){
    int i, i1, i2, s, stmp, carry;
	int s1 = strlen(num1);
	int s2 = strlen(num2);
	
	int* iarr;
	char* carr;
	
	s = s1 + s2;
	iarr = (int*)calloc((s), sizeof(int));
	
	//multiply and add
	for(i1 = 0;i1 < s1;i1++)
		for(i2 = 0;i2 < s2;i2++)
			iarr[i1 + i2] += (num1[s1 - 1 - i1] - '0') * (num2[s2 - 1 - i2] - '0');
	
	//carry out
	for(i = 0;i < s - 1;i++){
 	    carry = iarr[i] / 10;
		iarr[i + 1] += carry;
		iarr[i] = iarr[i] - ((carry << 3) + (carry << 1));
	}
	
	//check zero
	stmp = s;
	for(i = 0;i < s;i++){
		if(iarr[s - 1 - i] == 0 && s - 1 - i != 0) {
		    stmp--;
		}else{
		    break;
		}
	}
	
	carr = (char*)calloc((stmp + 1), sizeof(char));
	
	for(i = 0;i < stmp;i++){
  		carr[stmp - 1 - i] = iarr[i] + '0';
	}
	carr[stmp] = '\0';
	
	return carr;
}
