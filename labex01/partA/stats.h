/*  stats.h - what exists.
 *
 *  Part of the provided material for Laboratory Exercise 01, Part A.
 *
 *  This header is NOT guaranteed to be correct. A header and its source
 *  file are two halves of a promise, and they have to agree. One of the
 *  defects in Part A lives in a place where they do not.
 */

#ifndef STATS_H
#define STATS_H

int readValues(int arr[], int max);
int sumOf(const int arr[], int n);
int minOf(const int arr[], int n);
int maxOf(const int arr[], int n);
int rangeOf(const int arr[], int n);
double meanOf(const int arr[], int n);

#endif
