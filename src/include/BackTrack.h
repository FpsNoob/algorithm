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
			k = k - 1;	//���ݵ���һ�����
		}
	}
}