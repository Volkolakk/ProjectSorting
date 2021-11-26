#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sort(int num, double* ptr);

int main(void) {

	int num = 1, counter = 1;
	double* ptr = (double*)calloc(1, sizeof(double));
	if (ptr == NULL)
		exit(-1);

	printf("Put numbers over space.Use any letter in the end:\n");
	while (1) {
		if (scanf("%lf", &ptr[num-1]) == 1) {
			void* tmp = ptr;
			ptr = (double*)realloc(tmp, (++num) * sizeof(double));
			if (ptr == NULL)
				exit(-1);

		}
		else {
			num = num - 1;
			break;
		}
	}

	/*for (int i = 0; i < num; i++)
		printf("%.1lf ", *(ptr+i));
	printf("\n");*/

	sort(num, ptr);

	free(ptr);
	return 0;

}

void sort(int num, double* ptr) {
	for(int i=num-1;i>=0;i--)
		for (int j = 0; j < i; j++) {
			if (ptr[j] > ptr[j + 1]) {
				double tmp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = tmp;
			}
		}

	for (int i = 0; i < num; i++)
		printf("%.1lf ", *(ptr + i));
	printf("\n");

}
