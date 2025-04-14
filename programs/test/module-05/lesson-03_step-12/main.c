// module5 -> lesson3 -> step12

#include <stdio.h>

struct Student
{
    int age;
    int id; 
};

void plus_one(struct Student * pName)
{
    (*pName).age += 1;
    pName->id += 1;
}

int main()
{
    struct Student Ivan;
    
    printf("Введите возраст: ");
    scanf("%d", &Ivan.age);
    printf("Введите айди: ");
    scanf("%d", &Ivan.id);

    plus_one(&Ivan);
    printf("Изменены данные | возраст: %d, айди: %d\n", Ivan.age, Ivan.id);
    
    return 0;
}
