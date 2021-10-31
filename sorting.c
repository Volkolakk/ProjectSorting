#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sort(int maxSize, float* numbers);
void sortTreeMassive(int maxSize, float* numbers, int i);

int main(void)
{
    float *numbers;
    int maxSize = 0;
    float * tmparray;

    numbers =(float*) malloc(sizeof(float)*8);

    printf("write numbers over space. Any letter was been writed on end\n");
    while(true){
        if (scanf("%f", numbers+maxSize) == 1) { //цикл продолжается пока не будет введен любой некорректный симвл 
            maxSize++;
            tmparray = (float*)realloc(numbers, sizeof(float) * 8 * (maxSize + 1));
            numbers = tmparray;
        }
        else {
            break;
        }  
    }
    //printf("%d", maxSize);
    /*for (int i = maxSize - 1;i >= 0;i--)
        printf("%.1f ", *(numbers + i));
    printf("\n");*/
    sort(maxSize-1, numbers);
    for (int i = maxSize-1;i >= 0;i--)
        printf("%.1f ", *(numbers + i));
}

void sortTreeMassive(int maxSize, float * numbers,int i) { //алгоритм перемещения самого большого числа в корень
    int bigger = i; // индекс самого большого числа в узле дерева
    int left = 2 * i + 1; // левый лист
    int right = 2 * i + 2; // правый лист
    if (maxSize >= left && numbers[bigger] < numbers[left])
        bigger = left;
    if (maxSize >= right && numbers[bigger] < numbers[right])
        bigger = right;

    if (bigger != i) {
        float tmp = numbers[bigger];
        numbers[bigger] = numbers[i];
        numbers[i] = tmp;
        /*for (int g = 0;g <= maxSize;g++)
            printf("%.1f\n", *(numbers + g));
        printf("\n");*/
        sortTreeMassive(maxSize, numbers, bigger);
    }
}

void sort(int maxSize, float* numbers) {
    for (int i = (maxSize+1) / 2;i >= 0;i--) //предворительная сортировка всех элементов дерева кроме нижних листьев
        sortTreeMassive(maxSize, numbers, i);
    //printf("ok");
    for (int i = maxSize;i >= 1;i--) { // сортировка массива
        sortTreeMassive(i, numbers, 0);
        float tmp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = tmp;
    }
}
