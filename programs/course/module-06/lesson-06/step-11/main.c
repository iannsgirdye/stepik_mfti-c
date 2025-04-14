#include <stdio.h>


typedef struct{
    int yy;   // год
    char mm;  // месяц
    char dd;  // день
} Data;

typedef struct {
    int yy;       // год
    char season;  // время года (зима - 0, весна - 1, лето - 2, осень - 3)
    int day;      // день от начала текущего времени года
} Season;


// Получает параметры даты с консоли (три целых числа через тире: YYYY-MM-DD). Например, 2020-12-13
Data getData() {
    Data data;
    scanf("%d-%hhd-%hhd", &data.yy, &data.mm, &data.dd);
    return data;
}


// Печатает дату в формате: YYYY-MM-DD завершая переносом строки (\n)
void printData(Data data) {
    printf("%04d-%02hhd-%02hhd\n", data.yy, data.mm, data.dd);
}


/* конвертирует дату в формат Season и возвращает это значение
зима  | с 1 декабря  по 28 или 29 февраля, 
весна | с 1 марта    по 31        мая, 
лето  | с 1 июня     по 31        августа,
осень | с 1 сентября по 30        ноября */
Season convToSeas(Data data) {
    Season season;
    season.yy = data.yy;
    switch (data.mm) {
        case 12:
            season.day = data.dd;
            season.season = 0;
            break;
        case 1:
            season.day = 31 + data.dd;
            season.season = 0;
            break;
        case 2:
            season.day = 31 + 31 + data.dd;
            season.season = 0;
            break;
        case 3:
            season.day = data.dd;
            season.season = 1;
            break;
        case 4:
            season.day = 31 + data.dd;
            season.season = 1;
            break;
        case 5:
            season.day = 31 + 30 + data.dd;
            season.season = 1;
            break;
        case 6:
            season.day = data.dd;
            season.season = 2;
            break;
        case 7:
            season.day = 30 + data.dd;
            season.season = 2;
            break;
        case 8:
            season.day = 30 + 31 + data.dd;
            season.season = 2;
            break;
        case 9:
            season.day = data.dd;
            season.season = 3;
            break;
        case 10:
            season.day = 30 + data.dd;
            season.season = 3;
            break;
        case 11:
            season.day = 30 + 31 + data.dd;
            season.season = 3;
            break;
    }
    return season;
}


// Печать времени года в формате: YYYY-SS-DD 
// (SS - номер времени года, DD - день от начала времени года, завершая переносом строки)
void printSeas(Season season) {
    printf("%04d-%02hhd-%02d\n", season.yy, season.season, season.day);
}


int main()
{
    Data dat;
    Season seas;
    dat = getData();
    printData(dat);
    seas = convToSeas(dat);
    printSeas(seas);

    return 0;
}
