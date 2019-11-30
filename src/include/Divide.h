#pragma once
#include "basic.h"
#include "Sort.h"
/*分治法*/

//棋盘覆盖问题
void chessBoard(int tr, int tc, int dr, int dc, int size) { //tr,tc,size表示子棋盘, dr dc表示特殊方格
	int s, t1=0;	//t1表示骨牌的编号
	int board[MAX][MAX];
	if (size == 1) {  //边界条件，棋盘只有一个方格，而且是特殊方格。
		return;
	}
	t1++;
	s = size / 2;	//划分棋盘
	if (dr < tr + s && dc < tc + s) {	//特殊方格在左上角子棋盘中
		chessBoard(tr, tc, dr, dc, s);	//递归处理子棋盘
	}
	else {
		board[tr + s - 1][tc + s - 1] = t1; //t1号骨牌覆盖右下角，在递归处理子棋盘
		chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
	}
	if (dr < tr + s && dc >= tc + s) {	//特殊方格在右上角子棋盘中
		chessBoard(tr, tc + s, dr, dc, s);
	}
	else {
		board[tr + s - 1][tc + s] = t1; 
		chessBoard(tr, tc, tr + s-1, tc + s, s);
	}
	if (dr >= tr + s && dc < tc + s) {	//特殊方格在左下角子棋盘中
		chessBoard(tr + s, tc, dr, dc, s);
	}
	else {
		board[tr + s][tc + s - 1] = t1; 
		chessBoard(tr + s, tc, tr + s , tc + s - 1, s);
	}
	if (dr >= tr + s && dc >= tc + s) {	//特殊方格在右下角子棋盘中
		chessBoard(tr + s, tc + s, dr, dc, s);
	}
	else {
		board[tr + s - 1][tc + s - 1] = t1; 
		chessBoard(tr + s, tc + s, tr + s, tc + s, s);
	}
}


//最近对问题
struct point {
	int x, y;
};

double Distence(point a, point b) {  //返回两个点间的距离
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double Closest(point S[], int low, int high) {  //low和high表示x轴坐标的区间
	double d1, d2, d3, d;
	int mid, i, j, index;
	point P[MAX];
	if (high - low == 1) {  //只有两个点，返回两点间的距离
		return Distence(S[low], S[high]);
	}
	if (high - low == 2) {	//有三个点，求最近对距离
		d1 = Distence(S[low], S[low + 1]);
		d2 = Distence(S[low], S[high]);
		d3 = Distence(S[low + 1], S[high]);
		if ((d1 < d2) && (d1 < d3)) {
			return d1;
		}
		else if (d2 < d3) {
			return d2;
		}
		else {
			return d3;
		}
	}
	//大于三个点
	mid = (low + high) / 2;	//计算中间点 x=m
	d1 = Closest(S, low, mid);		//递归子问题1
	d2 = Closest(S, mid + 1, high);	//递归子问题2
	if (d1 < d2) {
		d = d1;		//获得最小距离
	}
	else {
		d = d2;
	}
	index = 0;	//建立集合P1 P2
	for (i = mid; (i >= low) && (S[mid].x - S[i].x < d); i--) {  //在s1中找与m的距离小于d的点
		P[index++] = S[i];
	}
	for (i = mid+1; (i <=high) && (S[i].x - S[mid].x < d); i++) {  //在s2中找与m的距离小于d的点
		P[index++] = S[i];
	}
	quickSort(P, 0, index - 1);  //对集合P1 P2按y坐标升序惊醒排序
	for (i = 0; i < index; i++) {
		for (j = i + 1; j < index; j++) {
			if (P[j].y - P[i].y >= d) {  //超出y坐标的范围，跳过
				break;
			}
			else {
				d3 = Distence(P[i], P[j]);  //依次检查两地间的距离
				if (d3 < d) {
					d = d3;
				}
			}
		}
	}
	return d;
}