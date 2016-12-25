#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

void max_heapify(int A[], int i, int length);
void build_max_heap(int A[], int length);
void heap_sort(int A[], int length);

//int A[100000];
//int A[500000];
int A[1000000];

int main()
{
	srand(time(NULL));

	//int length = 100000;
	//int length = 500000;
	int length = 1000000;

	for (int i = 0; i < length; i++)
	{
		A[i] = rand() % 100;
	}

	heap_sort(A, length);
	getchar();
}

void max_heapify(int A[], int i, int length)
{
	int left, right, largest, tmp;
	left = 2 * i;
	right = 2 * i + 1;

	if ((left <= length) && A[left] > A[i])
		largest = left;
	else largest = i;
	if ((right <= length) && A[right] > A[largest])
		largest = right;

	if (largest != i)
	{
		tmp = A[i];
		A[i] = A[largest];
		A[largest] = tmp;
		max_heapify(A, largest, length);
	}
}

void build_max_heap(int A[], int length)
{
	for (int i = (length / 2); i >= 1; i--)
	{
		max_heapify(A, i, length);
	}
}

void heap_sort(int A[], int length)
{
	build_max_heap(A, length);
	int tmp;

	float start = GetTickCount();
	for (int i = length; i >= 2; i--)
	{
		tmp = A[i];
		A[i] = A[1];
		A[1] = tmp;
		length--;
		max_heapify(A, 1, i - 1);
	}
	float finish = GetTickCount();
	float result = (finish - start) / 1000;

	printf("the sorted array: ");

	//for (int i = 0; i<100000; i++)
	//for (int i = 0; i<500000; i++)
	for (int i = 0; i<1000000; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n time (seconds): %f", result);
}
