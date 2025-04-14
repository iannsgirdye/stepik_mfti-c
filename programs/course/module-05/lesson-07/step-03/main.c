typedef struct
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

// считать RGB-формат с консоли
Color getColor();

// перевод из RGB-формата в число
unsigned long long convertToHTML(Color);

// преобразование числа цвета в RGB-формат
Color convertToRGB(unsigned long long);

// печать цвета в RGB-формате (печать значений в десятичном виде через пробел)
// red green blue:
// 255 128 222
// Печатать только числа через пробел и \n в конце!!!
void printRGB(Color);

// печать цвета в HTML-формате и \n в конце.
// Примеры: FFA902 0AA3FF
void printHTML(Color);


Color getColor() 
{
    Color RGB;
    scanf("%d%d%d", &RGB.red, &RGB.green, &RGB.blue);
    return RGB;
}

unsigned long long convertToHTML(Color RGB)
{
    return RGB.red * 256 * 256 + RGB.green * 256 + RGB.blue;  // БайтБайтБайт --- новое число => 256-ричная система счисления
}

Color convertToRGB(unsigned long long number)
{
    Color RGB;
    RGB.red = (number / 256) / 256;
    RGB.green = (number / 256) % 256;
    RGB.blue = number % 256;
    return RGB;
}

void printRGB(Color RGB)
{
    printf("%d %d %d\n", RGB.red, RGB.green, RGB.blue);
}

void printHTML(Color RGB)
{
    printf("%02X%02X%02X\n", RGB.red, RGB.green, RGB.blue);
}
