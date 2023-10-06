#include <iostream>
using namespace std;
int main() {
    long long year = 2001, countdaysinmounth, countdaynum = 0, countdays = 0, deltadays = 0, delta; //countdaysinmounth - подсчитывает количество дней в месяце; countdaynum - подсчет номера дня; deltadays - разница между днями
    long long n, d;
    long long summouth = 0, numberweek = 0, daysinweek, numberinyear; //сумма месяцев для проверки на дни
    long long firstday = 1, firstmouth = 1, firstyear = 2001, firstweek = 1; // создание первоначальной даты
    int countleapyear = 0; // счетчик для високосных годов
    string mouth, weekinday, numberday, leapyear;       //название месяца и дня недели
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
                countleapyear++;

                
            }
            else {
                firstday -= 365;
                firstyear += 1;
                flag1 = false;
            }
        }
    } 
    numberinyear = firstday;
   
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


    //это свич который выбирает месяц и колво дней в месяце
    switch (firstmouth) {        
    case 1:
        mouth = "январь";
        countdaysinmounth = 31;
        countdaynum = 0;
        break;

    case 2:
        mouth = "февраль";
        countdaysinmounth = 28;
        countdaynum += 31;
        if (flag1) {
            countdaysinmounth = 29;
        }
        break;

    case 3:
        mouth = "март";
        countdaysinmounth = 31;
        countdaynum += 31 + 28;
        break;
    case 4:
        mouth = "апрель";
        countdaysinmounth = 30;
        countdaynum += 31 * 2 + 28;
        break;
    case 5:
        mouth = "май";
        countdaysinmounth = 31;
        countdaynum += 31 * 2 + 28 + 30;
        break;
    case 6:
        mouth = "июнь";
        countdaysinmounth = 30;
        countdaynum += 31 * 3 + 28 + 30;
        break;

    case 7:
        mouth = "июль";
        countdaysinmounth = 31;
        countdaynum += 31 * 3 + 28 + 30 * 2;
    case 8:
        mouth = "август";
        countdaysinmounth = 31;
        countdaynum += 31 * 4 + 28 + 30 * 2;
        break;
    case 9:
        mouth = "сентябрь";
        countdaysinmounth = 30;
        countdaynum += 31 * 5 + 28 + 30 * 2;
        break;
    case 10:
        mouth = "октябрь";
        countdaysinmounth = 31;
        countdaynum += 31 * 5 + 28 + 30 * 3;
        break;
    case 11:
        mouth = "ноябрь";
        countdaysinmounth = 30;
        countdaynum += 31 * 6 + 28 + 30 * 3;
        break;
    case 12:
        mouth = "декабрь";
        countdaysinmounth = 31;
        countdaynum += 31 * 6 + 28 + 30 * 4;
        break;
    }

    long long SummCountDayNumAndFirstDay = countdaynum + firstday;
    daysinweek = SummCountDayNumAndFirstDay;
    delta = 365 - SummCountDayNumAndFirstDay;
    
    
   
    numberweek = SummCountDayNumAndFirstDay;
    if (numberweek > 7) {
        while (numberweek > 7) {
            numberweek -= 7;
            firstweek++;
            
        }
    }
    
    if (flag1) daysinweek = (firstyear - 2001 + countleapyear + SummCountDayNumAndFirstDay + 1) % 7;
    else daysinweek = (firstyear - 2001 + countleapyear + SummCountDayNumAndFirstDay) % 7;

    //определяем день недели
    switch (daysinweek) {
    case 1: weekinday = "понедельник"; break;
    case 2: weekinday = "вторник"; break;
    case 3: weekinday = "среда"; break;
    case 4: weekinday = "четверг"; break;
    case 5: weekinday = "пятница"; break;
    case 6: weekinday = "суббота"; break;
    case 7: weekinday = "воскресенье";  break;
    }
    
    switch (firstday) {
    case 1: numberday = "первое"; break;
    case 2: numberday = "второе"; break;
    case 3: numberday = "третье"; break;
    case 4: numberday = "четвертое"; break;
    case 5: numberday = "пятое"; break;
    case 6: numberday = "шестое"; break;
    case 7: numberday = "седьмое"; break;
    case 8: numberday = "восьмое"; break;
    case 9: numberday = "девятое"; break;
    case 10: numberday = "десятое"; break;
    case 11: numberday = "одиннадцатое"; break;
    case 12: numberday = "двенадцатое"; break;
    case 13: numberday = "тринадцатое"; break;
    case 14: numberday = "четырнадцатое"; break;
    case 15: numberday = "пятнадцатое"; break;
    case 16: numberday = "шестнадцатое"; break;
    case 17: numberday = "семьнадцатое"; break;
    case 18: numberday = "восемьнадцатое"; break;
    case 19: numberday = "девятнадцатое"; break;
    case 20: numberday = "двадцатое"; break;
    case 21: numberday = "двадцать первое"; break;
    case 22: numberday = "двадцать второе"; break;
    case 23: numberday = "двадцать третье"; break;
    case 24: numberday = "двадцать четвертое"; break;
    case 25: numberday = "двадцать пятое"; break;
    case 26: numberday = "двадцать шестое"; break;
    case 27: numberday = "двадцать седьмое"; break;
    case 28: numberday = "двадцать восьмое"; break;
    case 29: numberday = "двадцать девятое"; break;
    case 30: numberday = "тридцатое"; break;
    case 31: numberday = "тридцать первое"; break;
    }

    if (flag1) leapyear = "високосный";
    else leapyear = "не високосный";

    

    //блок вывода в консоль
    cout << "День недели: " << weekinday << endl;
    cout << "Число: " <<numberday << endl; //+
    cout << SummCountDayNumAndFirstDay << "-й день года" << endl; //+
    cout << "Месяц: " << mouth << endl; //+
    cout << "Дней в месяце: " << countdaysinmounth << endl; //+
    cout << "Номер недели года: " << firstweek << endl; //+
    cout << "До конца года осталось: " << delta << endl;
    cout << firstyear << ", " << leapyear; //+ 
}
//04.10.2023 была сделано большую часть проекта, я почти определил правильно дату, но есть ошибка в месяцах(фиксить буду завтра!!)
//05.10.2023 пофиксил баг со временем
//05.10.2023 проект почти готов
//05.10.2023 2 часть  все готово, время тестировать
// тесты провалены...выдает не верную дату 