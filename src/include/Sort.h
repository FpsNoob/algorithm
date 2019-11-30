#pragma once

#include "basic.h"

void selectionSort(int r[], int len) {
	int index;
	for (int i = 0; i < len-1; i++) {
		index = i;
		for (int j = i + 1; j < len; j++) {
			if (r[j] < r[index]) {
				index = j;
			}
		}
		if (index != i) {
			swap(r[i], r[index]);
		}
	}
}

void bubbleSort(int a[], int len) {
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < len - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void Merge(int r[], int r1[], int s, int m, int t) {  //合并两个子序列
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t) {
		if (r[i] <= r[j]) {
			r1[k++] = r[i++];
		}
		else {
			r1[k++] = r[j++];
		}
	}
	while (i <= m) {
		r1[k++] = r[i++];
	}
	while (j <= t) {
		r1[k++] = r[j++];
	}
}

void mergeSort(int r[], int s, int t) { //对序列r[s]-r[t]进行排序
	int m, r1[MAX];
	if (s == t) {   //边界条件，长度为1，已经有序
		return;
	}
	else {
		m = (s + t) / 2;
		mergeSort(r, s, m);
		mergeSort(r, m + 1, t);
		Merge(r, r1, s, m, t);  //将序列排序到r1数组中
		for (int i = s; i <= t; i++) {
			r[i] = r1[i];
		}
	}
}


int Partition(int r[], int first, int end) {
	int i = first, j = end;	//待划分区域
	while (i < j) {
		while (i < j && r[i] <= r[j]) {  //右侧扫描，是否有小于r[i]的数
			j--;
		}
		if (i < j) {
			swap(r[i], r[j]); //将最小的记录换到前面
			i++;
		}
		while (i < j && r[i] <= r[j]) {  //左侧扫描，是否有大于r[j]的数
			i++;
		}
		if (i < j) {
			swap(r[i], r[j]);
			j--;
		}
	}
	return i;	//返回轴值记录位置
}

template<typename T> void quickSort(T r[], int first, int end) {
	int pivot;
	if (first < end) {
		pivot = Partition(r, first, end);  //换份，pivot是轴值在序列中的位置
		quickSort(r, first, pivot - 1);		//求解子问题1，对左侧子序列进行快速排序
		quickSort(r, pivot + 1, end);			//求解子问题2，对右侧子序列进行快速排序
	}
}
