#pragma once

#include "basic.h"

int seqSearch(int a[], int n, int k) {
	int i = n;
	while (i > 0 && a[i] != k) {
		i--;
	}
	return i;
}
