#include "stdafx.h"
#include <iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string s1;//Вспомогательная строка для ввода
	string Proverka;
	ifstream fin("FNAME4.txt"); // файл из которого читаем
	if (!fin) //входной контроль на корректность/существование файла
	{
		cout << "Файл некорректен или не существует!";
		fin.close();
		return 1;
	}
	getline(fin, s1);//считываем строку 1
	if (!fin.eof()) //проверка файла на отсутствие данных
	{
		cout << "Файл пуст!";
		fin.close();
		return 2;
	}//if





	char s[100];//Массив,который включает 1-ю строку
	char sp[100];//Вспомогательный массив для отделения слов
	char smax[100];//Массив,который содержит предложение,в котором наибольшее кол-во чисел
	int i;//Счетчик
	int j;//Счетчик
	int p = 0;//Счетсчик кол-ва символов в предложении
	int pmax = 0;//Максимальное кол-во символов в предложении
	int len;//Длина строки
	int k = 0;//Количество чисел в предложении
	int kmax = -1;//Максимальное количество чисел в предложении
	char mas[] = { '0','1','2','3','4','5','6','7','8','9' };//Вспомогательный массив для поиска чисел
	len = s1.size();//Длина строки
	for (i = 0;i < len; i++)//
	{
		s[i] = s1[i];
		cout << s[i];
	}

	cout << endl;
	//Цикл поиска предложения в котором макс кол-вл чисел
	for (i = 0;i < len; i++)
	{
		//Пока мы не встретим точку мы идем по предложению
		if ((s[i] != '.') && (s[i] != '?') && (s[i] != '!')) {
			sp[p] = s[i];//Присваиваем значения sp[p]=sp[i]
						 //Сравниваем значения spp с массивом чисел
			for (j = 0;j < 10; j++) {//Сравниваем значения spp с массивом чисел
				if (sp[p] == mas[j]) {
					k++;
				}
			}
			p++;
		}
		//Если кол-во цифр в предложении большее максимального присваиваем массив smax значения
		else {
			if (k > kmax)
			{

				kmax = k;
				pmax = p;
				for (j = 0;j < p;j++) {
					smax[j] = sp[j];
				}

			}
			k = 0;
			p = 0;
		}

	}//for
	if (kmax == -1) {
		cout << "В данной строке нет чисел";
	}
	else {

		for (i = 0;i < pmax;i++) {
			cout << smax[i];
		}
	}
	for (int i = 0;i < len;i++) {
		switch (s[i]) {
		case '0':
			cout << "ноль" << " ";
			break;
		case '1':
			cout << "один" << " ";
			break;
		case '2':
			cout << "два" << " ";
			break;
		case '3':
			cout << "три" << " ";
			break;
		case '4':
			cout << "четыре" << " ";
			break;
		case '5':
			cout << "пять" << " ";
			break;
		case '6':
			cout << "шесть" << " ";
			break;
		case '7':
			cout << "семь" << " ";
			break;
		case '8':
			cout << "восемь" << " ";
		case '9':
			cout << "девять" << " ";
			break;
		default:
			cout << s[i];
			break;

		}
	}
	return 0;
}