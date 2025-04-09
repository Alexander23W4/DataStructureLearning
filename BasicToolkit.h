#ifndef BASIC_TOOLKIT_H

#include <iostream>    
#include <string>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <cctype>
#include <cerrno>
#include <cstdarg>
#include <cassert>
#include <cinttypes>
#include <cfloat>
#include <cstdbool> 
#include <cstdlib>     
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>  
#include <algorithm>
#include <cctype>
#include <windows.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <iomanip>
#include <string.h>
using namespace std;
// 递归三要素: 每个节点操作逻辑相同  嵌套  终止条件
// while循环代替递归的感觉: 一个while循环只能由一个逻辑, 所以一次只能顺着一个逻辑走到头; 用变量的更新替代嵌套

int* Renew(int* array, int PreLength, int length);

int GetRandomNumber(int range);
int GetRandomNumberR(int minNumber, int maxNumber);

void PrintCurrentTime(void);
const char* getCurrentTime();

int* FillIntLinearArray(int* array, int length, int numberRange);

int GetMax2(int num1, int num2);

int FindMaxIndex(int* array, int start, int end);


#endif // !BASIC_TOOLKIT_H

