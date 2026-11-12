/*  stats.c - how it works.
 *
 *  Part of the provided material for Laboratory Exercise 01, Part A.
 *  It does not build as handed to you. Making it build is the exercise.
 *
 *  Every line of arithmetic in here is correct. 
 * 	You can rewrite this file but do not rewrite the arithmetic.
 *  One function that main.c needs is missing entirely; the rest is here.
 */

#include <stdio.h>
#include "stats.h"


int readValues(int arr[], int max)
{
	int n = 0;
	int v;

	while (n < max && scanf("%d", &v) == 1)
		arr[n++] = v;

	fprintf(stderr, "[stats] read %d values\n", n);

	return n;
}

int sumOf(const int arr[], int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

int minOf(const int arr[], int n)
{
	int lo = arr[0];

	for (int i = 1; i < n; i++)
		if (arr[i] < lo)
			lo = arr[i];

	return lo;
}

int maxOf(const int arr[], int n)
{
	int hi = arr[0];

	for (int i = 1; i < n; i++)
		if (arr[i] > hi)
			hi = arr[i];

	return hi;
}

double meanOf(const int arr[], int n)
{
	if (n == 0)
		return 0.0;

	return (double)sumOf(arr, n) / n;
}
int rangeOf(const int arr[], int n)
{
    return maxOf(arr, n) - minOf(arr, n);
}