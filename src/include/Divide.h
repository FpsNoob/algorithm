#pragma once
#include "basic.h"
#include "Sort.h"
/*���η�*/

//���̸�������
void chessBoard(int tr, int tc, int dr, int dc, int size) { //tr,tc,size��ʾ������, dr dc��ʾ���ⷽ��
	int s, t1=0;	//t1��ʾ���Ƶı��
	int board[MAX][MAX];
	if (size == 1) {  //�߽�����������ֻ��һ�����񣬶��������ⷽ��
		return;
	}
	t1++;
	s = size / 2;	//��������
	if (dr < tr + s && dc < tc + s) {	//���ⷽ�������Ͻ���������
		chessBoard(tr, tc, dr, dc, s);	//�ݹ鴦��������
	}
	else {
		board[tr + s - 1][tc + s - 1] = t1; //t1�Ź��Ƹ������½ǣ��ڵݹ鴦��������
		chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
	}
	if (dr < tr + s && dc >= tc + s) {	//���ⷽ�������Ͻ���������
		chessBoard(tr, tc + s, dr, dc, s);
	}
	else {
		board[tr + s - 1][tc + s] = t1; 
		chessBoard(tr, tc, tr + s-1, tc + s, s);
	}
	if (dr >= tr + s && dc < tc + s) {	//���ⷽ�������½���������
		chessBoard(tr + s, tc, dr, dc, s);
	}
	else {
		board[tr + s][tc + s - 1] = t1; 
		chessBoard(tr + s, tc, tr + s , tc + s - 1, s);
	}
	if (dr >= tr + s && dc >= tc + s) {	//���ⷽ�������½���������
		chessBoard(tr + s, tc + s, dr, dc, s);
	}
	else {
		board[tr + s - 1][tc + s - 1] = t1; 
		chessBoard(tr + s, tc + s, tr + s, tc + s, s);
	}
}


//���������
struct point {
	int x, y;
};

double Distence(point a, point b) {  //�����������ľ���
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double Closest(point S[], int low, int high) {  //low��high��ʾx�����������
	double d1, d2, d3, d;
	int mid, i, j, index;
	point P[MAX];
	if (high - low == 1) {  //ֻ�������㣬���������ľ���
		return Distence(S[low], S[high]);
	}
	if (high - low == 2) {	//�������㣬������Ծ���
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
	//����������
	mid = (low + high) / 2;	//�����м�� x=m
	d1 = Closest(S, low, mid);		//�ݹ�������1
	d2 = Closest(S, mid + 1, high);	//�ݹ�������2
	if (d1 < d2) {
		d = d1;		//�����С����
	}
	else {
		d = d2;
	}
	index = 0;	//��������P1 P2
	for (i = mid; (i >= low) && (S[mid].x - S[i].x < d); i--) {  //��s1������m�ľ���С��d�ĵ�
		P[index++] = S[i];
	}
	for (i = mid+1; (i <=high) && (S[i].x - S[mid].x < d); i++) {  //��s2������m�ľ���С��d�ĵ�
		P[index++] = S[i];
	}
	quickSort(P, 0, index - 1);  //�Լ���P1 P2��y��������������
	for (i = 0; i < index; i++) {
		for (j = i + 1; j < index; j++) {
			if (P[j].y - P[i].y >= d) {  //����y����ķ�Χ������
				break;
			}
			else {
				d3 = Distence(P[i], P[j]);  //���μ�����ؼ�ľ���
				if (d3 < d) {
					d = d3;
				}
			}
		}
	}
	return d;
}