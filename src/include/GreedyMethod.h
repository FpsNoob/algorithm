#pragma once
#include "basic.h"

//TSP问题
const int n = 10;	//结点的个数
int TSP1(int arc[n][n], int w) {	//假定从顶点w开始
	int edge_cnt = 0, tsp_length = 0;
	int min, u, v;
	int flag[n] = { 0 };
	u = w, flag[w] = 1;	//点被经历过
	while (edge_cnt <n-1) {//循环，知道边数=n-1
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
		u = v;	//下一次从顶点v出发
	}
	cout << v << "-->" << w << endl;
	return (tsp_length + arc[u][w]);
}

//背包问题，假设物品已按照单位重量降序排序  O(nlogn)
int kNapsack(int w[], int v[], int n, int c) {
	double x[10] = { 0 };
	int max_value = 0;
	int i;
	for (i = 0; w[i] < c; i++) {
		x[i] = 1;	//将物品i装入背包
		max_value += v[i];
		c = c-w[i];
	}
	x[i] = 1.0 * c / w[i];	//加入部分物品
	max_value += x[i] * v[i];
	return max_value;
}


//活动安排问题
int activeManage(int s[], int f[], int B[], int n) {
	int i, j, cnt;
	B[0] = 1;	//安排活动1
	j = 0, cnt;
	for (i = 1; i < n; i++) {
		if (s[i] >= f[j]) {	//活动i与上一个活动相容
			B[i] = 1;
			j = i;
			cnt++;
		}
		else {
			B[i] = 0;
		}
	}
	return cnt;	//返回已安排的活动数
}


//Prim算法
typedef struct {
	int lowcost;
	int adjvex;
}Element;

void Prim(int arc[n][n], int w) {	//从顶点w开始构造最小生成树
	int i, j, k;
	int min;
	Element short_edge[10];//存储候选最短边集，假设最多10个顶点
	for (i = 0; i < n; i++) {	//初始化short_egde
		short_edge[i].lowcost = arc[w][i];
		short_edge[i].adjvex = w;
	}
	short_edge[w].lowcost = 0;
	for (i = 0; i < n - 1; i++) {
		min = 100;
		for (j = 0; i < n; j++) {	//寻找最短边的邻接点
			if ((short_edge[j].lowcost != 0) && (short_edge[j].lowcost < min)) {
				min = short_edge[j].lowcost;
				k = j;
			}
		}
	}
	cout << short_edge[k].adjvex << "--" << k << endl;
	short_edge[k].lowcost = 0;
	for (j = 0; j < n; j++) {
		if (arc[k][j] < short_edge[j].lowcost) {	//更新short_edge数组
			short_edge[j].lowcost = arc[k][j];
			short_edge[j].adjvex = k;
		}
	}
}