﻿#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
    system("chcp 1251>nul");                                                          // Изменение кодировки кансоли
    system("color 80");                                                               // Изменяем цвет консоли и текста
    double sum = 0;                                                                   // Переменная для записи суммы выплат
    double max = 0;                                                                   // Переменная для записи максимальной выплаты
    string maxN;                                                                      // Переменная для записи имени и фамилии макс

    ifstream payName;                                                                 // Объявляем поток
    payName.open("Test_file.txt");                                                    // Открываем файл в потоке

    if (!payName.is_open())                                                           // Проверяем открытие файла в потоке
    {
        cerr << " Файл не открыт!" << endl;                                           // Выводим сообщение об ошибке
        system("pause>nul");                                                          // Задержка консоли окна
        return 1;                                                                     // Возвращяем ошибку 1
    }

    while (!payName.eof())                                                            // Цикл продолжается до конца до конца файла
    {
        string name;                                                                  // Переменная для записи имени
        string surname;                                                               // Переменная для записи фамилии 
        double pay = 0;                                                               // Переменная для записи выплаты
        string date;                                                                  // Переменная для записи даты
        payName >> name >> surname >> pay >> date;                                    // Считываем значения в переменные
        sum += pay;                                                                   // Суммируем выплаты
        if (pay > max)                                                                // Если выплата больше максимальной выплаты
        {
            max = pay;                                                                // выплата присваивается максимальному значению
            maxN = name + " " + surname;                                              // и имени максимального присваивается текущее
        }
    }
    payName.close();                                                                  // Закрываем поток
    cout << endl;
    cout << " Сумма выплат: " << sum << " долларов." << endl;                         // Выводим сумму
    cout << " У " << maxN << " наибольшая выплата в " << max << " долларов!" << endl; // Выводим имя обладателя максимальной выплаты и выплату
    system("pause>nul");                                                              // Задержка консоли окна
    return 0;
}