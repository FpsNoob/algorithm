#pragma once
#include "basic.h"

//ͼ��ɫ����
const int n = 10;
int color[n];
int arc[n][n];
int oK(int k) {
	for (int i = 0; i < k; i++) {
		if (arc[k][i] == 1 && color[i] == color[k]) { //�������ɫ���Ϸ�
			return 0;
		}
	}
	return 1;//�����ڶ���û����ɫ�ϵ���ͬ��������ɫ�Ϸ�
}

void graphColor(int m) {
	int i, k;
	for (i = 0; i < n; i++) {
		color[i] = 0;	//��ʼ��
	}
	k = 0;
	while (k >= 0) {
		color[k] = color[k] + 1;	//ȡ��һ����ɫ
		while (color[k] <= m) {	//���ÿ����ɫ�ĺϷ���
			if (oK(k)) {
				break;
			}
			else {
				color[k] = color[k] + 1;	//ȡ��һ����ɫ
			}
		}
		if (color[k] <= m && k == n - 1) {	//�����Ѿ�ȫ����ɫ
			for (i = 0; i < n; i++) {
				cout << color[i] << " ";
			}
			return;
		}
		if (color[k] <= m && k < n - 1) {//������һ������
			k = k + 1;
		}
		else {
			color[k] = 0;
			k = k - 1;	//���ݵ���һ�����
		}
	}
}

//��������ҵ����wenti
int batchJob(int a[], int b[], int n) {
	int i, k;
	int x[10], sum1[10], sum2[10];
	int best_time = 1000;
	for (i = 1; i <= n; i++) {	//��ʼ�����ȷ���
		x[i] = -1;
		sum1[i] = 0;
		sum2[i] = 0;
	}
	sum1[0] = 0, sum2[0] = 0, k = 1;//���ȵ�һ����ҵ
	while (k >= 1) {
		x[k] = x[k] + 1;	//���ŵ�k����ҵ��x[k]Ϊ��ҵ���
		while (x[k] < n) {	//����ÿһ����ҵ
			for (i = 1; i < k; i++) {	//�����ҵx[k]�Ƿ��ظ�
				if (x[i] == x[k]) {
					break;
				}
			}
			if (i == k) {	//��ҵx[k]��δ����
				sum1[k] = sum1[k - 1] + a[x[k]];
				if (sum1[k] > sum2[k - 1]) {
					sum2[k] = sum1[k] + b[x[k]];
				}
				else {
					sum2[k] = sum2[k - 1] + b[x[k]];
				}
				if (sum2[k] > best_time) {	//ʱ�����Ŀǰ���ʱ�䣬��֦
					x[k] = x[k] + 1;	//������һ����ҵ
				}
				else {
					break;
				}
			}
			else {
				x[k] = x[k] + 1;	//x[k]�Ѿ������ȹ���������һ����ҵ
			}
		}
		if (x[k] < n && k < n) {
			k = k + 1;//������һ����ҵ
		}
		else {
			if (x[k] < n && k == n) {	//�õ�һ����ҵ����
				if (best_time > sum2[k]) {
					best_time = sum2[k];	//������ǰ������ʱ��
					cout << "Ŀǰ�������ҵ�����ǣ�";
					for (int j = 1; i <= n; j++) {
						cout << x[j] + 1 << " ";	//��ҵ��Ŵ�1��ʼ
					}
					cout << "���ʱ���ǣ�" << best_time << endl;
				}
				x[k] = -1;
				k = k - 1;	//����
			}
		}
	}
	return best_time;
}

//n�ʺ�����
int x[n] = {-1};	//�ʺ�����Ľ�
int Place(int k) {	//��k���ʺ��λ�ã��Ƿ��г�ͻ
	for (int i = 0; i < k; i++) {
		if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k])) {	//�Խ��ߣ�ͬ��
			return 1;
		}
		return 0;
	}
}

void Queen(int n) {
	int k = 1;
	while (k >= 1) {	//�ڷŻʺ�k
		x[k]++;
		while (x[k] < n && Place(k) == 1) {	//�г�ͻ
			x[k]++;	//�ŵ���һ��
		}
		if (x[k] <= n && k == n) {	//�õ�һ���ʺ�İڷ�
			for (int i = 0; i < n; i++) {
				cout << x[i] + 1 << " ";
			}
			cout << endl;
			return;
		}
		if (x[k] < n && k < n) {//���лʺ�δ�ڷ�
			k = k + 1;//׼���ڷ���һ���ʺ�
		}
		else {
			x[k--] = -1;	//����
		}
	}
	cout << "�޽�" << endl;
}