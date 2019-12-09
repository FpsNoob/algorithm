#pragma once
#include "basic.h"

//图着色问题
const int n = 10;
int color[n];
int arc[n][n];
int oK(int k) {
	for (int i = 0; i < k; i++) {
		if (arc[k][i] == 1 && color[i] == color[k]) { //所填的颜色不合法
			return 0;
		}
	}
	return 1;//与相邻顶点没有颜色上的相同，所填颜色合法
}

void graphColor(int m) {
	int i, k;
	for (i = 0; i < n; i++) {
		color[i] = 0;	//初始化
	}
	k = 0;
	while (k >= 0) {
		color[k] = color[k] + 1;	//取下一种颜色
		while (color[k] <= m) {	//检查每种着色的合法性
			if (oK(k)) {
				break;
			}
			else {
				color[k] = color[k] + 1;	//取下一种颜色
			}
		}
		if (color[k] <= m && k == n - 1) {	//顶点已经全部着色
			for (i = 0; i < n; i++) {
				cout << color[i] << " ";
			}
			return;
		}
		if (color[k] <= m && k < n - 1) {//处理下一个顶点
			k = k + 1;
		}
		else {
			color[k] = 0;
			k = k - 1;	//回溯到上一个结点
		}
	}
}

//批处理作业调度wenti
int batchJob(int a[], int b[], int n) {
	int i, k;
	int x[10], sum1[10], sum2[10];
	int best_time = 1000;
	for (i = 1; i <= n; i++) {	//初始化调度方案
		x[i] = -1;
		sum1[i] = 0;
		sum2[i] = 0;
	}
	sum1[0] = 0, sum2[0] = 0, k = 1;//调度第一个作业
	while (k >= 1) {
		x[k] = x[k] + 1;	//安排第k个作业，x[k]为作业编号
		while (x[k] < n) {	//考察每一种作业
			for (i = 1; i < k; i++) {	//检查作业x[k]是否重复
				if (x[i] == x[k]) {
					break;
				}
			}
			if (i == k) {	//作业x[k]尚未处理
				sum1[k] = sum1[k - 1] + a[x[k]];
				if (sum1[k] > sum2[k - 1]) {
					sum2[k] = sum1[k] + b[x[k]];
				}
				else {
					sum2[k] = sum2[k - 1] + b[x[k]];
				}
				if (sum2[k] > best_time) {	//时间大于目前最短时间，剪枝
					x[k] = x[k] + 1;	//调度下一个作业
				}
				else {
					break;
				}
			}
			else {
				x[k] = x[k] + 1;	//x[k]已经被调度过，调度下一个作业
			}
		}
		if (x[k] < n && k < n) {
			k = k + 1;//安排下一个作业
		}
		else {
			if (x[k] < n && k == n) {	//得到一个作业安排
				if (best_time > sum2[k]) {
					best_time = sum2[k];	//更换当前最短完成时间
					cout << "目前的最短作业安排是：";
					for (int j = 1; i <= n; j++) {
						cout << x[j] + 1 << " ";	//作业编号从1开始
					}
					cout << "最短时间是：" << best_time << endl;
				}
				x[k] = -1;
				k = k - 1;	//回溯
			}
		}
	}
	return best_time;
}

//n皇后问题
int x[n] = {-1};	//皇后问题的解
int Place(int k) {	//第k个皇后的位置，是否有冲突
	for (int i = 0; i < k; i++) {
		if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k])) {	//对角线，同列
			return 1;
		}
		return 0;
	}
}

void Queen(int n) {
	int k = 1;
	while (k >= 1) {	//摆放皇后k
		x[k]++;
		while (x[k] < n && Place(k) == 1) {	//有冲突
			x[k]++;	//放到下一列
		}
		if (x[k] <= n && k == n) {	//得到一个皇后的摆放
			for (int i = 0; i < n; i++) {
				cout << x[i] + 1 << " ";
			}
			cout << endl;
			return;
		}
		if (x[k] < n && k < n) {//尚有皇后未摆放
			k = k + 1;//准备摆放下一个皇后
		}
		else {
			x[k--] = -1;	//回溯
		}
	}
	cout << "无解" << endl;
}