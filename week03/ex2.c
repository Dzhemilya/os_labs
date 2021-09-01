#include <stdio.h>

void bubble_sort(int n, int args_of_integers[]){
	int temp;
	int flag = 1;
	//for(int i=0; i<n; i++)
	//	printf("%d + ", args_of_integers[i]);
	while (flag == 1) {
	flag = 0;
	for (int i=0; i<(n-1); i++){
		for (int j=1; j<n; j++){
			if (args_of_integers[i] > args_of_integers[j]){
				flag = 1;
				temp = args_of_integers[i];
				args_of_integers[i] = args_of_integers[j];
				args_of_integers[j] = temp;
				}
				
		}
	}
	}
	for(int i=0; i<n; i++)
		printf("%d\n", args_of_integers[i]);
}

int main(){
	int n, i, j, temp, args_of_integers[4096];
	printf("Enter number of elements in the array, please\n");
	scanf("%d", &n);
	printf("Enter elements of the array, please\n");
	for(int i=0; i < n; i++)
		scanf("%d", &args_of_integers[i]);
	bubble_sort(n, args_of_integers);
	}

