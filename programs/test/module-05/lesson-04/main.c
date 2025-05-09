// module5 -> lesson4
// Проверка работы структур


struct One                    // Объявление и определение структуры One
{                             //
    int a;                    //
    int b;                    //
    int c;                    //
};                            //

typedef struct One One_real;  // Создание псевдонима One_real структуры One


//-----------------------------------------------------------------------------------------------------------------//


typedef struct Two            // Объявление, определение и создание псевдонима Two_real структуры Two
{                             //
    int a;                    //
    int b;                    //
    int c;                    //
}                             //
Two_real;                     //


//-----------------------------------------------------------------------------------------------------------------//


struct                        // Объявление и определение анонимной структуры с именами Three, Four, Five
{                             //
    int a;                    //
    int b;                    //
    int c;                    //
}                             //
Three, Four, Five;            //


//-----------------------------------------------------------------------------------------------------------------//


typedef struct                // Объявление, определение и создание псевдонимов Six, Seven, Eight анонимной структуры
{                             //
    int a;                    //
    int b;                    //
    int c;                    //
}                             //
Six, Seven, Eight;            //

