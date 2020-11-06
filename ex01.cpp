/* В строке необходимо заменить подстроку, находящуюся между первой открывающей
квадратной скобкой и соответствующей ей закрывающей. Исходная строка и новая
подстрока, которую необходимо вставить вместо выражения в квадратных скобках,
вводятся с клавиатуры.


Пример:
Входные данные:
Cтрока: "[Programming [langu[age]]] is the most popular programming language [today]",
подстрока: "Javascript". Выходные данные: "Javascript is the most popular programming language [today]".

g++ -std=c++1z ex01.cpp
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	string newString;
	getline(cin, s);
	getline(cin, newString);
	size_t firstBracket = s.find('[');
	size_t lastBracket = firstBracket;
	size_t includedBrackets = 0;
	if (s.size() == 0) {
		cout << "Error: The string to change is empty" << endl;
		return 0;
	}
	while (lastBracket < s.size()) {
		if (s[lastBracket] == '[') {
			includedBrackets += 1;
		} else if (s[lastBracket] == ']' && includedBrackets == 1) {
			break;
		} else if (s[lastBracket] == ']') {
			includedBrackets -= 1;
		}
		lastBracket++;
	}
	if (lastBracket >= s.size()) {
		cout << "Error: There is no valid pair of brackets" << endl;
		return 0;
	}

	s.erase(firstBracket, lastBracket - firstBracket + 1);
	s.insert(firstBracket, newString);
	cout << s << endl;
	return 0;
}