#pragma once

#include "basic.h"

//蛮力法
int BF(string s, string t) {
	int index = 0;
	int i = 0, j = 0;
	while (s[i]!='\0' && t[j]!='\0') {
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {//回溯
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


//求子串T的next数组
void getNext(string T, int next[]) { 
	int i, j, len;
	next[0] = -1;
	for (j = 1; T[j] != '\0'; j++) {
		for (len = j - 1; len >= 1; len--) {  //相等子串的长度不超过j-1,len尝试每种子串大小,从最长的开始
			for (i = 0; i < len; i++) {
				if (T[i] != T[j - len + i]) {
					break;
				}
			}
			if (i == len) { //长度匹配
				next[j] = len;
				break;
			}
		}
		if (len < 1) {
			next[j] = 0;//没有相同的子串
		}
	}

}

//KMP算法
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
			if (j == -1) {  //字符串开头就不匹配，主串的字符下移一位
				i++; 
				j++;
			}
		}
	}
	if (T[j] == '\0') {
		return (i - T.length() + 1); //返回匹配开始的位置
	}
	else {
		return 0;
	}
}