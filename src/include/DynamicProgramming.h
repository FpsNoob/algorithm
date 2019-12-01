#pragma once
#include "basic.h"

//矩阵连乘问题
//数据p存储各矩阵的维度，n是矩阵个数，**m存放最优值，**s存放断开位置
void MatrixChain(int* p, int n, int** m, int** s) {
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;	//递归函数的边界,矩阵的对角线
	}
	for (int r = 2; r <= n; r++) {	//r表示矩阵链长度，i与j相差的数
		for (int i = 1; i <= n - r + 1; i++) {
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];  //对角线向上填充矩阵
			s[i][j] = i;
			for (int k = i + 1; k < j; k++) {
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];//最优
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}	
	}
}

void traceBack(int i, int j, int** s) {  //递归求断点
	if (i == j) {
		return;
	}
	traceBack(i, s[i][j], s);
	traceBack(s[i][j] + 1, j, s);
	cout << "Multiply A" << i << ", " << s[i][j];
	cout << "and A" << (s[i][j] + 1) << ", " << j << endl;
}

//最长公共子序列问题
void commonOrder(int m, int n, char* x, char* y, int** L, int** S) {
	//数组S[i][j]记录L[i][j]的值是由哪一个状态的解得到的
	int i, j;
	for (i = 0; i <= m; i++) {
		L[i][0] = 0;
	}
	for (j = 0; j <= n; j++) {
		L[0][j] = 0;	//初始化
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
// 将公共子序列存储到z里
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

//0/1背包问题
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
			if (j < w[i]) { //背包容量小于w[i]，不装入背包
				v[i][j] = v[i - 1][j];
			}
			else {
				//v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + v[i]);
			}
		}
		int *x;
		for (j = c, i = n; i > 0; i--) {	//将物品装入背包
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

//最优查找二叉树
const int n = 5;//结点个数
int C[n + 1][n + 1], R[n + 1][n + 1]; //c平均查找次数，r结点选择
double optimalBST(double p[], int n) {
	int i, j, k, d;
	int min, mink, sum;
	for (i = 1; i <= n; i++) {	//初始化
		C[i][i - 1] = 0;
		C[i][i] = p[i - 1];
		R[i][i] = i;
	}
	C[n + 1][n] = 0;
	for (d = 1; d < n; d++) {  //按对角线逐条计算
		for (i = 1; i <= n - d; i++) {
			j = i + d;
			min = 1000, mink = i, sum = 0;
			for (k = i; k <= j; k++) {  //筛选结点
				sum = sum + p[k - 1];	//结点概率相加
				if (C[i][k - 1] + C[k + 1][j] < min) {
					min = C[i][k - 1] + C[k + 1][j];
					mink = k;	//根结点
				}
			}
			C[i][j] = min + sum;
			R[i][j] = mink;
		}
		return C[1][n];
	}
}

//TSP问题
 