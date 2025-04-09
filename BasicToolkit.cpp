#include "BasicToolkit.h"

int GetRandomNumber(int range)
{
	return rand() % (range)+1;

}

const char* getCurrentTime() {

	static char buffer[20];

	time_t now = time(NULL);
	struct tm time_info;
	localtime_s(&time_info, &now);
	strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", &time_info);    // 格式化(字符化)当下的时间戳..

	return buffer;

}


int GetRandomNumberR(int minNumber, int maxNumber) {

	if (minNumber < maxNumber) {

		int range = maxNumber - minNumber + 1;
		return minNumber + (rand() % range);

	}
	else {
		perror("Error input range numbers");
		return -1;

	}
}

void PrintCurrentTime(void) {
	static char buffer[20];
	time_t now = time(NULL);
	struct tm time_info;
	localtime_s(&time_info, &now);
	strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", &time_info);

	cout << buffer << " ";


}

int* FillIntLinearArray(int* array, int length, int numberRange) {

	for (int index = 0; index < length; index++)
	{
		*(array + index) = GetRandomNumber(numberRange);

	}
	return array;

}


int* Renew(int* array, int PreLength, int length) {

	if (length < PreLength) {
		perror("ERROR");
		return NULL;

	}
	int* newarray = new int[length];
	for (int index = 0; index < PreLength; index++)
	{
		newarray[index] = array[index];
	}
	delete[] array;

	return newarray;


}

int GetMax2(int num1, int num2) {
	return num1 > num2 ? num1 : num2;
}

int FindMaxIndex(int* array, int start, int end) {
	int max = array[start];
	int maxIndex = start;
	for (int i = start; i <= end; i++)
	{
		if (array[i] > max) {
			maxIndex = i;
			max = array[i];
		}
	}
	return maxIndex;
}