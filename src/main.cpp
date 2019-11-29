#include "include/basic.h"
#include "include/Chicken.h"
#include "include/Search.h"
#include "include/stringMatching.h"
#include "include/Sort.h"

int main()
{
	/*百元买鸡问题*/
	//Chicken();

	/*顺序查找*/
	//int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
	//int index = seqSearch(a, 10, 13);
	//if (index == 0) {
	//	cout << "找不到这个数。" << endl;
	//}
	//else {
	//	cout << "这个数的下标为：" << index << endl;
	//}
	//return 0;

	/*串匹配-BF算法*/
	/*string s = "mofucker";
	string t = "fuck";
	int index = KMP(s, t);
	if (index == 0) {
		cout << "找不到这个串。" << endl;
	}
	else {
		cout << "这个串的下标开始为：" << index << endl;
	}*/

	/*排序算法*/
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