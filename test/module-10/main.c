// module10
// Самостоятельная практика, так как на платформе отсутствуют задания в этом модуле

#include <stdio.h>
#define N 1000

int main()
{
    const char * file1_name = "10_input.txt";
    const char * file2_name = "10_output.txt";

    FILE * file1 = fopen(file1_name, "r");
    FILE * file2 = fopen(file2_name, "w");

    char word[N];
    while(1 == fscanf(file1, "%s", word))
    {
        fprintf(file2, "%s", word);
    }

    fclose(file1);
    fclose(file2);

    return 0;
}
