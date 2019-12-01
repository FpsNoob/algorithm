#pragma once
#include "basic.h"

//������������
//����p�洢�������ά�ȣ�n�Ǿ��������**m�������ֵ��**s��ŶϿ�λ��
void MatrixChain(int* p, int n, int** m, int** s) {
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;	//�ݹ麯���ı߽�,����ĶԽ���
	}
	for (int r = 2; r <= n; r++) {	//r��ʾ���������ȣ�i��j������
		for (int i = 1; i <= n - r + 1; i++) {
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];  //�Խ�������������
			s[i][j] = i;
			for (int k = i + 1; k < j; k++) {
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];//����
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}	
	}
}

void traceBack(int i, int j, int** s) {  //�ݹ���ϵ�
	if (i == j) {
		return;
	}
	traceBack(i, s[i][j], s);
	traceBack(s[i][j] + 1, j, s);
	cout << "Multiply A" << i << ", " << s[i][j];
	cout << "and A" << (s[i][j] + 1) << ", " << j << endl;
}

//���������������
void commonOrder(int m, int n, char* x, char* y, int** L, int** S) {
	//����S[i][j]��¼L[i][j]��ֵ������һ��״̬�Ľ�õ���
	int i, j;
	for (i = 0; i <= m; i++) {
		L[i][0] = 0;
	}
	for (j = 0; j <= n; j++) {
		L[0][j] = 0;	//��ʼ��
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (x[i] == y[i]) {
				L[i][j] = L[i - 1][j - 1] + 1;
				S[i][j] = 1;
			}
			else if (L[i][j - 1] >= L[i - 1][j]) {
				L[i][j] = L[i][j - 1];
				S[i][j] = 3;
			}
			else {
				L[i][j] = L[i - 1][j];
				S[i][j] = 2;
			}
		}
	}
}
// �����������д洢��z��
void LCS(int i, int j, char* x, char** S) {
	if (i == 0 || j == 0) {
		return;
	}
	if (S[i][j] == 1) {
		LCS(i - 1, j - 1, x, S);
	}
	else if (S[i][j] == 2) {
		LCS(i - 1, j, x, S);
	}
	else {
		LCS(i, j - 1, x, S);  //O(m+n)
	}
}

//0/1��������
int kNapsack(int w[], int **v, int n, int c) {
	int i, j;
	for (i = 0; i < n; i++) {
		v[i][0] = 0;
	}
	for (j = 0; j <= c; j++) {
		v[0][j] = 0;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= c; j++) {
			if (j < w[i]) { //��������С��w[i]����װ�뱳��
				v[i][j] = v[i - 1][j];
			}
			else {
				//v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + v[i]);
			}
		}
		int *x;
		for (j = c, i = n; i > 0; i--) {	//����Ʒװ�뱳��
			if (v[i][j] > v[i - 1][j]) {
				x[i] = 1;
				j = j - w[i];
			}
			else {
				x[i] = 0;
			}
		}
	}
	return v[n][c];
}

//���Ų��Ҷ�����
const int n = 5;//������
int C[n + 1][n + 1], R[n + 1][n + 1]; //cƽ�����Ҵ�����r���ѡ��
double optimalBST(double p[], int n) {
	int i, j, k, d;
	int min, mink, sum;
	for (i = 1; i <= n; i++) {	//��ʼ��
		C[i][i - 1] = 0;
		C[i][i] = p[i - 1];
		R[i][i] = i;
	}
	C[n + 1][n] = 0;
	for (d = 1; d < n; d++) {  //���Խ�����������
		for (i = 1; i <= n - d; i++) {
			j = i + d;
			min = 1000, mink = i, sum = 0;
			for (k = i; k <= j; k++) {  //ɸѡ���
				sum = sum + p[k - 1];	//���������
				if (C[i][k - 1] + C[k + 1][j] < min) {
					min = C[i][k - 1] + C[k + 1][j];
					mink = k;	//�����
				}
			}
			C[i][j] = min + sum;
			R[i][j] = mink;
		}
		return C[1][n];
	}
}

//TSP����
 