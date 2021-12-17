/////базовый класс/////
class Computer
{
    int Number = 0; //пордковый номер
    int Name = 0; //серийный номер
    int Cost = 0; //стоимость
public:
    Computer(int Number1, int Name1, int Cost1) { Number = Number1; Name = Name1; Cost = Cost1; }
    void get_Name_Cost() { cout << Number << ". Серийный но-мер: " << Name << "\nВведите новую стоимость (руб.): "; cin >> Cost; cout << endl; } //изменение стоимости
    void show_Name_Cost() { cout << Number << ". Серийный номер: " << Name << "\nСтоимость (руб.): " << Cost << endl; } //вывод значений
    int get_Number() { return Number; }
    int get_Name() { return Name; }
    int get_Cost() { return Cost; }
};
/////1 производный класс/////
class Desktop : public Computer
{
    string Inf; //доп. информация
public:
    Desktop(int Number1, int Name1, int Cost1, string Inf1) : Computer(Number1, Name1, Cost1) { Inf = Inf1; }
    void show_Inf() { cout << "Тип: " << Inf << endl; }
};
/////2 производный класс/////
class Laptop : public Computer
{
    string Inf; //доп. информация
public:
    Laptop(int Number1, int Name1, int Cost1, string Inf1) : Computer(Number1, Name1, Cost1) { Inf = Inf1; }
    void show_Inf() { cout << "Тип: " << Inf << endl; }
};

