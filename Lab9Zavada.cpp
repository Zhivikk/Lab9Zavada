// LaboratoryProject9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
// Прототипи Змінних



// Прототипи Функцій

int menu; // меню
void task1(void);
void task2(void);
void ReverseWords(string& in_str, string& out_str);
string& my_assign(string& str, const char* s);

string& my_assign(string& str, const char* s)
{
	str = (s != nullptr) ? s : ""; // Присвоюєму передню строку, або пусту строку, якщо передан nullptr
	return str;
}

void task1() 
{
	const char basis_string[] = " 1 ";
	string str1;//цільова строка
	string str2;//цільова строка    
	//перший спосіб
	str1.assign(basis_string);
	cout << str1 << '\n';
	//другий спосіб
	my_assign(str2, basis_string);
	cout << str2 << '\n';

	if (str1.compare(str2) == 0) // Порівняння строк
	{
		cout << "equal" << '\n';
	}

}

void ReverseWords(string& in_str, string& out_str)
{

    bool end_word_Flag = false;
    bool start_word_Flag = false;
    bool first_word_Flag = false;
    size_t end_word_index = 0;
    size_t start_word_index = 0;

    size_t counter = in_str.length();//довжина строки
    do
    {
        counter--;
        // Кінець Слова
        if ((end_word_Flag == false) && (in_str[counter] != ' '))
        {
            end_word_Flag = true;
            end_word_index = counter;
        }
        //Початок Слова
        if ((end_word_Flag == true) && ((in_str[counter] == ' ') || counter == 0))
        {
            start_word_Flag = true;
            start_word_index = counter;
            if (counter != 0)
            {
                start_word_index += 1;
            }
        }
        //добавлення слова
        if ((end_word_Flag == true) && (start_word_Flag == true))
        {
            start_word_Flag = false;
            end_word_Flag = false;
            if (first_word_Flag == false)
            {
                first_word_Flag = true;
            }
            else
            {
                out_str += " "; // Якщо не в початку лінії то добавляється пробел
            }
            string partToAdd = in_str.substr(start_word_index, (end_word_index - start_word_index + 1));
            out_str += partToAdd;
        }

    } while (counter > 0);


}

void task2()
{
	string str = "  Тест Цього У Завданні  ";
	string out;
	// Переставляння слова
	ReverseWords(str, out);

	// Виведення результату

	string outFileName = "task2output.txt";
	ofstream fout(outFileName);
	fout << out;
	fout.close();
}

int main()
{
	{
		setlocale(LC_ALL, "Ukrainian");
		cout << "Choose task:1,2: ";
		cin >> menu;
		switch (menu)
		{ // перемикання між завданнями
		case 1:
		{
			task1(); break; // Завдання 1
		}
		case 2:
		{
			task2(); break; // Завдання 2
		}
		default: cout << "Wrong task! (Only 1,2)" << endl; //повідомлення про помилку
		}
		system("pause");

	}
	return 0;
}

