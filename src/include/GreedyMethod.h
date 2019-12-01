#pragma once
#include "basic.h"

//TSP����
const int n = 10;	//���ĸ���
int TSP1(int arc[n][n], int w) {	//�ٶ��Ӷ���w��ʼ
	int edge_cnt = 0, tsp_length = 0;
	int min, u, v;
	int flag[n] = { 0 };
	u = w, flag[w] = 1;	//�㱻������
	while (edge_cnt <n-1) {//ѭ����֪������=n-1
		min = MAX;
		for (int j = 0; j < n; j++) {
			if ((flag[j] == 0) && (arc[u][j] != 0) && (arc[u][j] < min)) {
				v = j;
				min = arc[u][j];
			}
		}
		tsp_length += arc[u][v];
		flag[v] = 1;
		edge_cnt++;
		cout << u << "-->" << w << endl;
		u = v;	//��һ�δӶ���v����
	}
	cout << v << "-->" << w << endl;
	return (tsp_length + arc[u][w]);
}

//�������⣬������Ʒ�Ѱ��յ�λ������������  O(nlogn)
int kNapsack(int w[], int v[], int n, int c) {
	double x[10] = { 0 };
	int max_value = 0;
	int i;
	for (i = 0; w[i] < c; i++) {
		x[i] = 1;	//����Ʒiװ�뱳��
		max_value += v[i];
		c = c-w[i];
	}
	x[i] = 1.0 * c / w[i];	//���벿����Ʒ
	max_value += x[i] * v[i];
	return max_value;
}


//���������
int activeManage(int s[], int f[], int B[], int n) {
	int i, j, cnt;
	B[0] = 1;	//���Ż1
	j = 0, cnt;
	for (i = 1; i < n; i++) {
		if (s[i] >= f[j]) {	//�i����һ�������
			B[i] = 1;
			j = i;
			cnt++;
		}
		else {
			B[i] = 0;
		}
	}
	return cnt;	//�����Ѱ��ŵĻ��
}


//Prim�㷨
typedef struct {
	int lowcost;
	int adjvex;
}Element;

void Prim(int arc[n][n], int w) {	//�Ӷ���w��ʼ������С������
	int i, j, k;
	int min;
	Element short_edge[10];//�洢��ѡ��̱߼����������10������
	for (i = 0; i < n; i++) {	//��ʼ��short_egde
		short_edge[i].lowcost = arc[w][i];
		short_edge[i].adjvex = w;
	}
	short_edge[w].lowcost = 0;
	for (i = 0; i < n - 1; i++) {
		min = 100;
		for (j = 0; i < n; j++) {	//Ѱ����̱ߵ��ڽӵ�
			if ((short_edge[j].lowcost != 0) && (short_edge[j].lowcost < min)) {
				min = short_edge[j].lowcost;
				k = j;
			}
		}
	}
	cout << short_edge[k].adjvex << "--" << k << endl;
	short_edge[k].lowcost = 0;
	for (j = 0; j < n; j++) {
		if (arc[k][j] < short_edge[j].lowcost) {	//����short_edge����
			short_edge[j].lowcost = arc[k][j];
			short_edge[j].adjvex = k;
		}
	}
}