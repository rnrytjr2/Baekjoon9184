// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int W(int a, int b, int c);
int answer;
int DP[21][21][21] = { 0 };
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	DP[0][0][0] = DP[1][0][0] = DP[0][1][0] = DP[0][0][1] = 1;
	while (!(a == -1 && b == -1 && c == -1))
	{
		answer = W(a, b, c);
		//cout << "w(" << a << ", " << b << ", " << c << ") = " << answer << "\n";
		printf("w(%d, %d, %d) = %d\n", a, b, c, answer);
		cin >> a >> b >> c;
	}
}
int W(int a, int b, int c)
{
	if (a <= 0 or b <= 0 or c <= 0)
	{
		return 1;
	}
	if (a > 20 or b > 20 or c > 20)
	{
		return W(20, 20, 20);
	}
	if (a < b and b < c)
	{
		DP[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c - 1);
		return DP[a][b][c];
	}
	if (DP[a][b][c] != 0)
	{
		return DP[a][b][c];
	}
	DP[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
	return DP[a][b][c];
}
