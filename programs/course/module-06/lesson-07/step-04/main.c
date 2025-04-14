/*
Примечание
    Автобусы ходят до 00:00

Ситуации
    1) Минимум 1 автобус на остановке:
        1.1) оба автобуса на останоке: победитель A
        1.2) только 1 автобус на остановке: тот и победитель
    2) 0 автобусов на остановке:
        2.1) оба автобуса не вышли на маршрут: победитель B
        2.2) только автобус B вышел на маршрут: кто раньше, того и тапки
        2.3) оба автобуса вышли на маршрут: кто раньше, того и тапки
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int h;
    int m;
} Clocks;


int in_minutes(Clocks time) {
    return time.h * 60 + time.m;
}


int main() {
    // 1. Параметры
    Clocks moment;
    scanf("%d%d", &moment.h, &moment.m);  // текущее время

    int t1, t2;
    scanf("%d", &t1);                     // периодичность автобуса A в минутах
    scanf("%d", &t2);                     // периодичность автобуса B в минутах

    Clocks A = {6, 0}, B = {5, 45};       // время выхода на маршрут обоих автобусов

    // 2. Вычисления
    int moment_minutes = in_minutes(moment);   // время с начала суток (минуты)
    int A_minutes = in_minutes(A);             // время выхода на маршрут автобуса А (минуты)
    int B_minutes = in_minutes(B);             // время выхода на маршрут автобуса B (минуты)

    int delta_A = moment_minutes - A_minutes;  // прошло с момента выхода на маршрут автобуса А (минуты)
    int delta_B = moment_minutes - B_minutes;  // прошло с момента выхода на маршрут автобуса B (минуты)

    int last_A = abs(delta_A) % t1;            // минут назад пришёл автобус A 
    int last_B = abs(delta_B) % t2;            // минут назад пришёл автобус B

    // 3. Ситуации
    int waiting_A, waiting_B;
    
    if (delta_B < 0) {                      // 2.1
        waiting_A = abs(delta_A);           // минут ждать автобус A
        waiting_B = abs(delta_B);           // минут ждать автобус B
    }
    else if (delta_B > 0 && delta_A < 0) {  // 2.2
        waiting_A = abs(delta_A);
        waiting_B = abs(last_B - t2);
    }
    else if (last_A == 0) {                 // 1.1, 1.2
        waiting_A = last_A;
        waiting_B = (last_B == 0)? last_B : abs(last_B - t2);
    }
    else if (last_B == 0) {
        waiting_A = abs(last_A - t1);
        waiting_B = 0;
    }
    else {                                  // 2.3
        waiting_A = abs(last_A - t1);
        waiting_B = abs(last_B - t2);
    }

    char winner = (waiting_A <= waiting_B)? 'A' : 'B';

    // 4. Вывод результата
    printf("%d\n%d\n%c\n", waiting_A, waiting_B, winner);

    return 0;
}
