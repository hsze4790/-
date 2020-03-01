// Floyd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
const int maxsize = 4;
char point[maxsize] = {'a','b','c','d'};
int LinkChart[4][4];
int p[4][4];
int InitPic() {
	for (int i = 0; i < maxsize; i++)
	{
		for (int j = 0; j < maxsize; j++) {
			if (i == j) {
				LinkChart[i][j] = 0;
			}
			
			p[i][j] = -1;
		}
		LinkChart[0][1] = 5;
		LinkChart[0][2] = 100;
		LinkChart[0][3] = 7;

		LinkChart[1][0] = 100;
		LinkChart[1][2] = 4;
		LinkChart[1][3] = 2;

		LinkChart[2][0] = 3;
		LinkChart[2][1] = 3;
		LinkChart[2][3] = 2;

		LinkChart[3][0] = 100;
		LinkChart[3][1] = 100;
		LinkChart[3][2] = 1;
	}
	return 1;
}

void Floyd(int mid) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (LinkChart[i][j] > LinkChart[i][mid] + LinkChart[mid][j]) {
				LinkChart[i][j] = LinkChart[i][mid] + LinkChart[mid][j];
				p[i][j] = mid;
			}
		}
	}

}

void print(int Start_p,int End_p) {
	if (p[Start_p][End_p]==-1) {
		cout <<"("<< point[Start_p] << "->" << point[End_p]<<")";
	}else{
		int mid = p[Start_p][End_p];
		print(Start_p, mid);
		print(mid, End_p);
	}
}

int main()
{
	//cout << "1" << endl;
	InitPic();
	for (int  i = 0; i < 4; i++)
	{
		Floyd(i);
	}
	print(0, 2);
	
  
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
