#include "include/basic.h"
#include "include/Chicken.h"
#include "include/Search.h"
#include "include/stringMatching.h"
#include "include/Sort.h"

int main()
{
	/*��Ԫ������*/
	//Chicken();

	/*˳�����*/
	//int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
	//int index = seqSearch(a, 10, 13);
	//if (index == 0) {
	//	cout << "�Ҳ����������" << endl;
	//}
	//else {
	//	cout << "��������±�Ϊ��" << index << endl;
	//}
	//return 0;

	/*��ƥ��-BF�㷨*/
	/*string s = "mofucker";
	string t = "fuck";
	int index = KMP(s, t);
	if (index == 0) {
		cout << "�Ҳ����������" << endl;
	}
	else {
		cout << "��������±꿪ʼΪ��" << index << endl;
	}*/

	/*�����㷨*/
	int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int len = 10;
	//selectionSort(a, len);
	//bubbleSort(a, len);
	//mergeSort(a,0, len-1);
	quickSort(a, 0, len - 1);
	for (int i = 0; i < len; i++) {
		cout << a[i] << " ";
	}
	return 0;
}