//Заменить в строке все повторяющиеся символы на комбинацию цифры указывающей колличество повторяющихся символов и самого символа.


#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

inline void Animate(string);//отвечает за анимацию

int main()
{
	setlocale(LC_ALL, "Russian");
	string inputStr; //строка пользователя
	string outputStr; //преобразованная строка
	string subStr; //строка под цифру
	int countStr; // колличество символов в строке
	int counter; //количество повторяющихся символов 
	int ind;//индекс первого повторяющегося элемента
	

	cout << "Заменить в строке все повторяющиеся символы" << endl;
	cout << "на комбинацию цифры, указывающей колличество повторяющихся символов," << endl;
	cout << "и самого символа." << endl;
	cout << endl << "----------------------------------------------------------------------" << endl << "Ведите строку: ";
	cin >> inputStr;

	 
	outputStr = inputStr;
	countStr = inputStr.length();
	for (int i = 0; i < countStr; )
	{

		if (outputStr[i] == ' ') //проверка на пробел
		{
			i++;
			continue;
		}
		else
		{

			if (outputStr[i] == outputStr[i + 1]) //если текущий символ такой же как следующий
			{
				ind = i;                           
				counter = 2;
				for (int j = ind + 1; j < countStr; j++)
				{
					if (outputStr[j] == outputStr[j + 1])
					{
						counter++;
					}
					else
					{
						break;
					}
				}
				subStr = to_string(counter); // преобразуем из int в string

				outputStr.erase(ind + 1, counter - 1); //удаляем все повторяющиеся символы кроме первого
				Animate(outputStr);
				outputStr.insert(ind, subStr); //вставляем цифру перед первым повторяющимся символом
				Animate(outputStr);
				i = ind + 2; //следущая итерация основного цикла будет начинаться с сивола следующего за символом который повторялся
				countStr = outputStr.length(); //размер строки изменился поэтому находим новое значение длинны строки
			}
			else
			{
				i++;
			}
		}
	}
	cout << endl << "----------------------------------------------------------------------" << endl <<endl;
	cout << "исходная строка: " << inputStr <<endl << endl;
	cout << "получившаяся строка: " << outputStr << endl;



}

void Animate(string Str) {

	system("cls");
	cout << Str << endl;
	Sleep(800);
}
