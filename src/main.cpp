//#include "include/basic.h"
//#include "include/Chicken.h"
//#include "include/Search.h"
//#include "include/stringMatching.h"
//#include "include/Sort.h"
//#include "include/Divide.h"
//
//int main()
//{
//	/*��Ԫ������*/
//	//Chicken();
//
//	/*˳�����*/
//	//int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	//int index = seqSearch(a, 10, 13);
//	//if (index == 0) {
//	//	cout << "�Ҳ����������" << endl;
//	//}
//	//else {
//	//	cout << "��������±�Ϊ��" << index << endl;
//	//}
//	//return 0;
//
//	/*��ƥ��-BF�㷨*/
//	/*string s = "mofucker";
//	string t = "fuck";
//	int index = KMP(s, t);
//	if (index == 0) {
//		cout << "�Ҳ����������" << endl;
//	}
//	else {
//		cout << "��������±꿪ʼΪ��" << index << endl;
//	}*/
//
//	/*�����㷨*/
//	int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int len = 10;
//	//selectionSort(a, len);
//	//bubbleSort(a, len);
//	//mergeSort(a,0, len-1);
//	//quickSort(a, 0, len - 1);
//	//for (int i = 0; i < len; i++) {
//	//	cout << a[i] << " ";
//	//}
//
//	//��������
//	chessBoard(0, 0, 0, 1, 4);
//	return 0;
//}

#include <stdio.h>
#include <string.h>

int main() {
	char a[1000] = "123";
	char b[1000];
	int n, i, k, t, x;
	n = strlen(a);
	k = 0; t = 0;
	for (i = n - 1; i >= 0; i--) {
		x = (a[i] - '0') * 2 + t;
		b[k] = x % 10;
		t = x / 10;
		k++;
	}
	for (int i = k-1; i >=0; i--) {
		printf("%d", b[i]);
	}
	
}
