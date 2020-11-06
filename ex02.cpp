/* На вход подается число. Необходимо проверить, является ли это число
палиндромом (то есть одинаково читается как слева направо, так и справа налево).
Нельзя использовать строки и встроенные функции языка программирования.

g++ -std=c++1z ex02.cpp
*/

#include <iostream>

using namespace std;

bool isPalindrom(int num) {
	int i = num / 10;
	int mirrorNum = num % 10;
	while (i != 0) {
		mirrorNum = mirrorNum * 10 + i % 10;
		i /= 10;
	}
	return mirrorNum == num;
}

int main() {
	int num;
	cin >> num;
	cout << isPalindrom(num) << endl;
	return 0;
}