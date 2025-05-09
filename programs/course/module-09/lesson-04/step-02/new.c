// Примечание: (-1)-я строка = строка из нулей (как будто сверху все белые), аналогично для столбцов
/*      .***.*   -->   012301
        .***.*   -->   024602
        .***.*   -->   036903
        .....*   -->   000004
        .**...   -->   012000
        .**...   -->   024000         */


#include <stdio.h>


#define max(a, b) ((a > b)? a : b)


int main() {
    int N;                        // размер квадрата, не более 100
    scanf("%d", &N);

    int last_line[101] = {0};     // предыдущая строка
    int current_line[101] = {0};  // текущая строка
    char line[101];
    int row = 0;                  // количество подряд идущих
    int result = 0;

    for (int i = 0; i < N; i++) {
        scanf("%101s", line);
        for (int j = 0; j < N; j++) {
            last_line[j] = current_line[j];
            if (line[j] == '\0') {                              // если достигнут конец строки
                break;
            }

            else if (line[j] == '*') {                          // если чёрная
                if (i == 0) {                                   //   если 0-я строка
                    if (j == 0 || current_line[j - 1] == 0) {   //     если 0-я строка ИЛИ сверху белая
                        row = 1;                                //       квадрат 1х1 (сейчас левый верхний угол) 
                        current_line[j] = row;
                    }
                    else {                                      //     если 1-й+ столбец И слева чёрная
                        row = current_line[j - 1] + 1;          //       +1 к площади (сейчас верхняя стенка) 
                        current_line[j] = row;
                    }
                }
                else {                                             //   если 1-я+ строка
                    if (last_line[j] == 0) {                       //     если сверху белая
                        if (j == 0 || current_line[j - 1] == 0) {  //       если 0-й столбец ИЛИ слева белая      
                            row = 1;                               //         квадрат 1х1 (сейчас левый верхний угол)
                            current_line[j] = row;                             
                        }
                        else {                                      //       если 1-й+ столбец И слева чёрная
                            row = current_line[j - 1] + 1;
                            current_line[j] = row;                  //         +1 к площади (сейчас верхняя стенка)      
                        }
                    }
                    else if (last_line[j] != 0) {                    //   если сверху чёрная
                        if (current_line[j - 1] == 0) {              //     если слева белая
                            row += last_line[j];
                            current_line[j] = row;
                        }
                        else {                                       //     если слева чёрная
                            if (last_line[j - 1] == 0) {              //       если по диагонали слева белый
                                
                            {                                      //   если 1-я+ строка И сверху чёрная
                                row++;                                  //     +1 ряд к площади (сейчас 2-я+ строка в фигуре)
                                last_line[j] += last_line[j - 1] + row;
                            }
                        }
                    }
                }
    
                
                result = max(last_line[j], result);          //   вычисление текущей максимальной площади
            }

            else {                                           // если белая
                last_line[j] = 0;
                row = 0;                                     //   обнуление подряд идущих
            }
        }
        
        row = 0;  // обнуление подряд идущий после окончания строки
    }
    
    printf("%d\n", result);

    return 0;
}
