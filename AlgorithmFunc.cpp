#include "AlgorithmFunc.h"

// �㷨�Ǿ���, �㷨�ڲ������߼��������Ը���, �����д
// �з���ֵ�ĵݹ麯�� �ڲ��ݹ�Ҫдreturn Function(...)
// ���еĺܶ��ж�, ��һ�����if elseif else, ��ͬ��ķֲ�ͬ��if


int BinarySearchLinearArray(int* array, int left, int right, int target) {

	if (left > right) {
		return -1;

	}
	int middle = (left + right) / 2;
	
	if (array[middle] == target) {
		return middle;

	}
	else if (array[middle] > target) {
		return BinarySearchLinearArray(array, left, middle, target);

	}
	else if (array[middle] < target) {
		return BinarySearchLinearArray(array, middle, right, target);

	}
}

int* SortLinearArray(int* array, int length) {

	int min = 0;
	int minIndex = 0;
	int temp = 0;

	for (int index = 0; index < length; index++)
	{
		min = array[index];
		minIndex = index;

		for (int i = index; i < length; i++)
		{
			if (array[i] < min) {
				min = array[i];
				minIndex = i;

			}
		}
		temp = array[index];
		array[index] = array[minIndex];
		array[minIndex] = temp;

	}
	return array;

}

void PrintLinearArray(int* array, int length) {

	cout << endl;
	int LineAmount = 10;

	for (int index = 0; index < length; index++)
	{
		cout << array[index] << " ";
		if (index % (LineAmount) == 9) {
			cout << endl;

		}
	}
}