#pragma once

#include "basic.h"

//������
int BF(string s, string t) {
	int index = 0;
	int i = 0, j = 0;
	while (s[i]!='\0' && t[j]!='\0') {
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {//����
			index++;
			i = index;
			j = 0;
		}
	}
	if (t[j] == '\0') {
		return (index + 1);
	}
	else {
		return 0;
	}
}


//���Ӵ�T��next����
void getNext(string T, int next[]) { 
	int i, j, len;
	next[0] = -1;
	for (j = 1; T[j] != '\0'; j++) {
		for (len = j - 1; len >= 1; len--) {  //����Ӵ��ĳ��Ȳ�����j-1,len����ÿ���Ӵ���С,����Ŀ�ʼ
			for (i = 0; i < len; i++) {
				if (T[i] != T[j - len + i]) {
					break;
				}
			}
			if (i == len) { //����ƥ��
				next[j] = len;
				break;
			}
		}
		if (len < 1) {
			next[j] = 0;//û����ͬ���Ӵ�
		}
	}

}

//KMP�㷨
int KMP(string S,string T) {
	int i = 0, j = 0;
	int next[MAX];
	getNext(T, next);
	while (S[i] != '\0' && T[j] != '\0') {
		if (S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
			if (j == -1) {  //�ַ�����ͷ�Ͳ�ƥ�䣬�������ַ�����һλ
				i++; 
				j++;
			}
		}
	}
	if (T[j] == '\0') {
		return (i - T.length() + 1); //����ƥ�俪ʼ��λ��
	}
	else {
		return 0;
	}
}