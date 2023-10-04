#include <iostream>
using namespace std;
int main() {
    int year = 2001, n, d, countdaysinmounth, countdaynum = 0, countdays = 0; //countdaysinmounth - подсчитывает количество дней в месяце; countdaynum - подсчет номера дня
    string mouth;
    cin >> n >> d; //вводим колво месяцев и дней
    setlocale(LC_ALL, "Russian");

    if (d > 365) {
        while (d > 365) {
            d -= 365;
            year += 1;
        }
    }

    //проверка на дни и добавление месяцев(проверку на январь не делаю)
    if (d > 31) { d -= 31; n += 1; }
    else if (d > 31 + 28) { d -= 31 + 28; n += 2; }
    else if (d > 31 * 2 + 28) { d -= 31 * 2 + 28; n += 3; }
    else if (d > 31 * 2 + 28) { d -= 31 * 2 + 28; n += 3; }
    else if (d > 31 * 2 + 28 + 30) { d -= 31 * 2 + 28 + 30; n += 5; }



    if (n > 12) {       //проверяем если месяцев больше чем 12
        while (n > 12) {
            n -= 12;
            year += 1;
        }
    }















    //cout << d << " " << n << " " << year;
    switch (n) {        //это свич который выбирает месяц и колво дней в месяце
    case 1:
        mouth = "январь";
        countdaysinmounth = 31;

    case 2:
        mouth = "февраль";
        countdaysinmounth = 28;
        countdaynum += 31;

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


}