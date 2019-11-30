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

void Merge(int r[], int r1[], int s, int m, int t) {  //�ϲ�����������
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

void mergeSort(int r[], int s, int t) { //������r[s]-r[t]��������
	int m, r1[MAX];
	if (s == t) {   //�߽�����������Ϊ1���Ѿ�����
		return;
	}
	else {
		m = (s + t) / 2;
		mergeSort(r, s, m);
		mergeSort(r, m + 1, t);
		Merge(r, r1, s, m, t);  //����������r1������
		for (int i = s; i <= t; i++) {
			r[i] = r1[i];
		}
	}
}


int Partition(int r[], int first, int end) {
	int i = first, j = end;	//����������
	while (i < j) {
		while (i < j && r[i] <= r[j]) {  //�Ҳ�ɨ�裬�Ƿ���С��r[i]����
			j--;
		}
		if (i < j) {
			swap(r[i], r[j]); //����С�ļ�¼����ǰ��
			i++;
		}
		while (i < j && r[i] <= r[j]) {  //���ɨ�裬�Ƿ��д���r[j]����
			i++;
		}
		if (i < j) {
			swap(r[i], r[j]);
			j--;
		}
	}
	return i;	//������ֵ��¼λ��
}

template<typename T> void quickSort(T r[], int first, int end) {
	int pivot;
	if (first < end) {
		pivot = Partition(r, first, end);  //���ݣ�pivot����ֵ�������е�λ��
		quickSort(r, first, pivot - 1);		//���������1������������н��п�������
		quickSort(r, pivot + 1, end);			//���������2�����Ҳ������н��п�������
	}
}
