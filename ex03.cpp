/* Отсортировать массив чисел таким образом, чтобы сначала шли
все четные числа по возрастанию, затем все нечетные по убыванию.

Пример:
Входные данные: [3, 4, 1, 2, 16, 27, 13].
Выходные данные: [2, 4, 16, 27, 13, 3, 1].

Команда для компиляции:
g++ -std=c++1z ex01.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> NapoleonSort(vector<int>& v) {
	vector<int> evenNums;
	vector<int> oddNums;
	for (int i : v) {
		if (i % 2 == 0) {
			evenNums.push_back(i);
		} else {
			oddNums.push_back(i);
		}
	}
	sort(evenNums.begin(), evenNums.end());
	sort(oddNums.begin(), oddNums.end(), greater<int>());
	evenNums.insert(evenNums.end(), oddNums.begin(), oddNums.end());
	return evenNums;
}

int main()
{
	vector<int> v = { 3, 4, 1, 2, 16, 27, 13 };
	v = NapoleonSort(v);
	cout << "["; 
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ", ";
	}
	cout << v[v.size() - 1] << "]" << endl;
	return 0;
}