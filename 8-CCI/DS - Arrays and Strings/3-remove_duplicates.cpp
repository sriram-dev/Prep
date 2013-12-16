#include<stdio.h>
#include<conio.h>

char* RemoveDuplicates(char* str) {
	int tail = 1,j,i;
	int len = 0;
	
	if(str == NULL)
		return str;
		
	while(str[len])
		len++;
		
	if(len < 2)
		return str;
	for(i=1;i<len;i++) {
		printf("%d\n", i);
		for(j=0;j<tail;j++) {
			printf("j : %d\n", j);
			printf("%c %c ", str[i], str[j]);
			if(str[i] == str[j])
				break;
		}
		if(j == tail) {
			// means character at i is not seen before
			// place it in position tail
			str[tail] = str[i];
			tail++;
			printf("new tail %d\n", tail);
		}
	}
	str[tail] = '\0';
	return str;
}

