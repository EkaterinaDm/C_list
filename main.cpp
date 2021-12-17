#include <iostream>
#include <cstring>
#include <list>
using namespace std;
#include "Classes.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    int i, k = 0;
    int a = 4000, b = 6000;
    int variant = 0, data = 0;
    list<Computer*> l; //создание списка
    
    ////Добавляем в список объекты////
    for (i = 0; i < a; i++)  
        l.push_back(new Desktop(i + 1, rand(), rand(), "на-стольный компьютер"));
    for (i = a; i < a+b; i++)
        l.push_back(new Laptop(i + 1, rand(), rand(), "ноут-бук"));

    list<Computer*>::iterator iter; //итератор
    iter = l.begin();
    
    while (variant != 4)
    {
        cout << "Введите: \n1 - если хотите изменить стоимость компьютера \n2 - если хотите вывести информацию о компьютере \n3 - если хотите вывести информацию о самом дешевом компьютере \n4 - если хотите выйти\n";
        cout << ">>> ";
        cin >> variant;
        switch (variant)
        {
        case 1: cout << "\nВведите номер компьютера для из-менения стоимости: "; //изменение стоимости
            cin >> data; cout << endl; //ввод номера компью-тера
            advance(iter, data - 1); //смещение итератора
            cout << "Введите стоимость: ";
            cin >> k; cout << endl; //ввод новой стоимости
            if ((data - 1) < a) //добавление нового значения
                l.insert(iter, new Desktop(data, rand(), k, "настольный компьютер"));
            else l.insert(iter, new Laptop(data, rand(), k, "ноутбук"));
            l.erase(iter); //удаление старого значения
            iter = l.begin(); //переход к началу списка
            break;

        case 2: cout << "\nВведите номер компьютера для вывода информации: "; //вывод информации компьютере
            cin >> data; cout << endl; //ввод номера компью-тера
            advance(iter, data-1); //смещение итератора
            (*iter)->show_Name_Cost(); //обращение к функции
            Desktop* D;
            D = (Desktop*)(*iter);
            D->show_Inf();
            iter = l.begin(); //переход к началу списка
            cout << endl;
            break;

        case 3: int min = (*iter)->get_Cost();
            int Number = (*iter)->get_Number();
            int Name = (*iter)->get_Name();
            for (iter = l.begin(); iter != l.end(); iter++) //поиск наименьшео значения
            {
                if ((*iter)->get_Cost() < min)
                {
                    min = (*iter)->get_Cost();
                    Number = (*iter)->get_Number();
                    Name = (*iter)->get_Name();
                }
            }
            iter = l.begin(); //переход к началу списка
            cout << "\nСамый дешевый компьютер\n" << endl;
            cout << Number << ". Серийный номер: " << Name << "\nСтоимость (руб.): " << min << endl;
            cout << endl;
            break;
        }
    }
   
    cout << endl;
    return 0;
}

