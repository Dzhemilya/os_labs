#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    char *USER_INPUT;

    int SIZE = 4096;

    USER_INPUT = (char *)malloc(SIZE * sizeof(char));

    printf("Enter string to reverse: ");
    getline(&USER_INPUT,&SIZE,stdin);
    printf("Reversed string: ");
    for (int i = strlen(USER_INPUT); i>=0; i--) {
	if (USER_INPUT[i] != '\n') {
		printf("%c", USER_INPUT[i]);
	}
    }
    printf("\n");
    return 0;
}
