#include <iostream>
#include <string>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <cstdlib>
using namespace std;




void lab6()
{
    cout << "6.1 Двумерный массив со случайными числами" << endl;

    int list[3][3]{};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            list[i][j] = rand() % 110;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << list[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "6.2 Динамический двумерный массив со случайными числами" << endl;

    int x,y;
    cin >> x >> y;

    int** list2 = new int*[x];

    for (int i = 0; i < x; i++) {
        list2[i] = new int[y];
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            list2[i][j] = rand() % 101 ;
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {

            cout << list2[i][j] << "\t";
        }

        cout << endl;
    }
    cout << endl;
    cout << "6.3 Сумма элементов двумерного массива" << endl;
    int temp = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {

            temp += list2[i][j];
        }
    }
    cout << "Сумма элементов: " << temp << endl;
}

void lab7() {
    cout << "7.1 Переворачивание строки" << endl;
    string x = "", xout ="";
    getline(cin, x);
    for (int i = x.size() - 1; i >= 0; i--) {
        xout += x[i];
    }
    cout << xout << endl << endl;

    cout << "7.2 Нахождение количества вхождений символа в строке" << endl;
    char x1;
    int temp = 0;
    cin >> x1;
    for (int i = 0; i < x.size(); i++) {
        if (x1 == x[i]) {
            temp++;
        }
    }
    if (temp == 0) {
        cout << "Нет таких" << endl << endl;
    }
    else {
        cout << temp << endl << endl;
    }
    
    cout << "7.3 Изменение регистра строки" << endl;
    for (int i = 0; i < x.size(); i++) {
        putchar((toupper(x[i])));
    }
    cout << endl << endl;
    
    cout << "7.4 Вывод предложений текса в отдельные строки с удалением пробелов и знаков препинаний в конце и начале" << endl;
    string text = "";
    cin.ignore();
    getline(cin, text);
    int size = text.size();
    for (int i = 0; i < size; i++) {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.') {
            text[i] = '\0';
        }
        else {
            if (text[i] == ' ') {
                if (text[i - 1] == '\0')
                {
                    cout << '\n';
                }
                else{ cout << ' '; }
            }
            else putchar(text[i]);
        }   
    }
    cout << endl;
    cout << "7.5 Замена указанного символа в тексте на введенный" << endl;
    string text5;
    char symboltodel, symboltoinsert;
    getline(cin, text5);
    cout << "Символ для замены Заменитель (с учетом регистра): ";
    cin >> symboltodel >> symboltoinsert;
    for (int i = 0; i < text5.size(); i++) {
        if (symboltodel == text5[i]) { text5[i] = symboltoinsert; }
    }
    cout << text5 << endl;
}

void division(double a, double b) {
    if (b == 0) { cout << "0 div"; }
    else { cout << a / b << endl << endl; };
}

void area(double a, double b) {
    cout << "area(double a, double b) для площади треугольника:" << endl;
    cout << a * (b / 2) << endl;
}

void area(double a) {
    cout << "double area(double a) для площади квадрата: " << endl;
    cout << a * a << endl << endl;
}

void degree(int a, int x) {
    for (int i = 1; i < x; i++) {
        a *= a;
    }
    cout << a << endl<< endl;
}
void recdegree(double a, int x) {
    if (x != 0) {
        a *= a;
        recdegree(a, x +1);
    }
    else {
        cout << "1/" << a << " or " << 1 / a << endl << endl;
    }
    
}

void lab8() {
    cout << "8.1 Частное двух чисел см строка 130" << endl;
    double a, b;
    cout << "Делимое и делитель(a/b): ";
    cin >> a>> b;
    division(a, b);

    cout << "8.2 Перегрузка функции area() см строки 135 и 140" << endl;
    int c= 0;
    area(12.0, 6.0);
    area(12.0);

    cout << "8.3 Степень числа см 145 строка" << endl;
    degree(5, 3);

    cout << "8.4 Степень числа с отрицательным показателем степени через рекурсию функции см 152 строка" << endl;
    recdegree(5.0, -2);

}

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void Print(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void InputRand(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void lab9() {
    cout << "9.1 Свап элементов" << endl;
    int a = 10, b = 20;
    cout << "Исходные значения: a = " << a << ", b = " << b << endl;
    Swap(a, b);
    cout<< "Итоговые значения: a = " << a << ", b = " << b << endl << endl;

    cout << "9.2 Передача и вывод элементов масива" << endl;
    int arr[10]{ 1,2,3,4,5,6,7,8,9,0 };
    Print(arr, (int)(sizeof(arr) / sizeof(arr[0])));

    cout << "9.3 Заполнение массива случайными элементами" << endl;
    int arr1[10];
    InputRand(arr, (int)(sizeof(arr) / sizeof(arr[0])));


}


void lab10()
{
    cout << "10.1,2 Открытие файла и чтение его содержимого" << endl;
    fstream fs;
    string file1 = "1.txt", file2="2.txt";
    char text[256];
    fs.open(file1, ios::in);
    if (!fs) {
        cout << "Couldn't open file: " << file1<<endl;
    }
    else {
        fs.getline(text, 256);
        cout << text;
        fs.close();
    }
    cout << endl << endl;
    cout << "10.3 Перезапись файла 1 данными из файла 2" << endl;
    
    fs.open(file2, ios::in);
    if (!fs) {
        cout << "Couldn't open file: " << file2 << endl;
    }
    else {
        fs.getline(text, 256);
        fs.close();
    }
    fs.open(file1, ios::out);
    fs << text;
}
struct Student
{
    string fio;
    string prof;
    int course;

};
void lab12() {
    Student students[6];
    string names[4]{ "Артемий", "Анастасия", "Юрий", "Никита"};
    string profs[4]{ "Программист", "Веб-Прог", "Связист" };
    int courses[4]{ 1,2,3,4 };
    for (int i = 0; i < 5; i++) {
        students[i].course = courses[rand() % 4];
        students[i].fio = names[rand() % 4];
        students[i].prof = profs[rand() % 4];
    }
    
    cout << "12.2" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Имя: " << students[i].fio << "\t| Специальность: " << students[i].prof << "\t| Курс: " << students[i].course << endl;
    }
    string nameu, profu;
    int courseu;

    cout << "12.3 Ввод информации пользователем" << endl;
    cout << "Введите имя, специальность и курс: ";
    cin >> nameu >> profu >> courseu;
    students[5].fio = nameu;
    students[5].prof = profu;
    students[5].course = courseu;

    for (int i = 0; i < 6; i++) {
        cout << "Имя: " << students[i].fio << "\t| Специальность: " << students[i].prof << "\t| Курс: " << students[i].course << endl;
    }

    cout << "12.4 Фильтр по специальности и курсу или имени" << endl;
    cout << "Введите имя: ";
    cin >> nameu;
    int temp = 0;
    for (int i = 0; i < 6; i++) {
        if (students[i].fio == nameu) {
            temp++;
        }
    }
    cout << "Количество студентов с именем " << nameu << " - " << temp << endl;
    temp = 0;
    cout << "Введите специальность и курс: ";
    cin >> profu >> courseu;
    for (int i = 0; i < 6; i++) {
        if (students[i].course == courseu && students[i].prof == profu) {
            temp++;
        }
    }
    cout << "Количество студентов на " << courseu << " курсе со специальностью " << profu << " - " << temp << endl;
}
//void lab13();


int main()
{
    setlocale(LC_CTYPE, "ru");
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    
    int x = 0;
    lab12();
}
