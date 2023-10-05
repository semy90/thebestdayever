#include <iostream>
using namespace std;
int main() {
    int year = 2001, n, d, countdaysinmounth, countdaynum = 0, countdays = 0, deltadays = 0; //countdaysinmounth - подсчитывает количество дней в месяце; countdaynum - подсчет номера дня; deltadays - разница между днями
    int summouth = 0; //сумма месяцев для проверки на дни
    int firstday = 1, firstmouth = 1, firstyear = 2001; // создание первоначальной даты
    string mouth;       //название месяца
    bool flag1 = false;     //флаг на вискоксный год 
    cin >> n >> d; //вводим колво месяцев и дней
    setlocale(LC_ALL, "Russian");

    firstday += d;
    firstmouth += n;

    if (firstday > 365) {
        while (firstday > 365) {
            if (firstday <= 365) {
                break;
            }
            else if ((firstyear % 4 == 0 and firstyear % 100 != 0) or (firstyear % 400 == 0)) {
                firstday -= 366;
                flag1 = true;
                firstyear += 1;
            }
            else {
                firstday -= 365;
                firstyear += 1;
                flag1 = true;
            }
        }
    }


    //проверка на дни и добавление месяцев
    if (firstday > 31) { deltadays = 31; summouth = 1; }        //1 проверка на февраль
    if (firstday > 31 + 28) { deltadays = 31 + 28; summouth = 2; }     //2 проверка на март
    if (firstday > 31 + 28 + 31) { deltadays = 31 * 2 + 28; summouth = 3; }     //3 проверка на апрель
    if (firstday > 31 * 2 + 28 + 30) { deltadays = 31 * 2 + 28 + 30; summouth = 4; }     //4 проверка на май
    if (firstday > 31 * 3 + 28 + 30) { deltadays = 31 * 3 + 28 + 30; summouth = 5; }       //5 проверка на июнь
    if (firstday > 31 * 3 + 28 + 30 * 2) { deltadays = 31 * 3 + 28 + 30 * 2; summouth = 6; }        //6 проверка на июль
    if (firstday > 31 * 4 + 28 + 30 * 2) { deltadays = 31 * 4 + 28 + 30 * 2; summouth = 7; }        //7 проверка на август
    if (firstday > 31 * 5 + 28 + 30 * 2) { deltadays = 31 * 5 + 28 + 30 * 2; summouth = 8; }        //8 проверка на сентябрь
    if (firstday > 31 * 5 + 28 + 30 * 3) { deltadays = 31 * 5 + 28 + 30 * 3; summouth = 9; }        //9 проверка на октябрь
    if (firstday > 31 * 6 + 28 + 30 * 3) { deltadays = 31 * 6 + 28 + 30 * 3; summouth = 10; }        //10 проверка на ноябрь
    if (firstday > 31 * 6 + 28 + 30 * 4) { deltadays = 31 * 6 + 28 + 30 * 4; summouth = 11; }        //11 проверка на декабрь

    //выполняем операцию сложения и вычитания месяцев и дней
    firstday -= deltadays;
    firstmouth += summouth;


    if (firstmouth > 12) {       //проверяем если месяцев больше чем 12
        while (firstmouth > 12) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                firstmouth -= 12;
                flag1 = true;
                firstyear += 1;
            }
            else {
                firstmouth -= 12;
                firstyear += 1;
                flag1 = false;

            }
        }
    }

    switch (firstmouth) {        //это свич который выбирает месяц и колво дней в месяце
    case 1:
        mouth = "январь";
        countdaysinmounth = 31;

    case 2:
        mouth = "февраль";
        countdaysinmounth = 28;
        countdaynum += 31;
        if (flag1) {
            countdaysinmounth = 29;
        }

    case 3:
        mouth = "март";
        countdaysinmounth = 31;
        countdaynum += 31 + 28;
    case 4:
        mouth = "апрель";
        countdaysinmounth = 30;
        countdaynum += 31 * 2 + 28;
    case 5:
        mouth = "май";
        countdaysinmounth = 31;
        countdaynum += 31 * 2 + 28 + 30;

    case 6:
        mouth = "июнь";
        countdaysinmounth = 30;
        countdaynum += 31 * 3 + 28 + 30;


    case 7:
        mouth = "июль";
        countdaysinmounth = 31;
        countdaynum += 31 * 3 + 28 + 30 * 2;
    case 8:
        mouth = "август";
        countdaysinmounth = 31;
        countdaynum += 31 * 4 + 28 + 30 * 2;
    case 9:
        mouth = "сентябрь";
        countdaysinmounth = 30;
        countdaynum += 31 * 5 + 28 + 30 * 2;

    case 10:
        mouth = "октябрь";
        countdaysinmounth = 31;
        countdaynum += 31 * 5 + 28 + 30 * 3;

    case 11:
        mouth = "ноябрь";
        countdaysinmounth = 30;
        countdaynum += 31 * 6 + 28 + 30 * 3;

    case 12:
        mouth = "декабрь";
        countdaysinmounth = 31;
        countdaynum += 31 * 6 + 28 + 30 * 4;

    }


    cout << firstday << " " << firstmouth << " " << firstyear;
}
//04.10.2023 была сделано большую часть проекта, я почти определил правильно дату, но есть ошибка в месяцах(фиксить буду завтра!!)
//05.10.2023 пофиксил баг со временем