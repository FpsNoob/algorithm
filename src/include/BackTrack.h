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
			k = k - 1;	//回溯到上一个结点
		}
	}
}