// Подключаем заголовок cstdio из стандартной библиотеки
#include <cstdio>

// Определяем функцию main, возвращающую целочисленный код завершения.
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int sum = 0;

    std::scanf("%d %d %d", &a, &b, &c);

    sum = a + b + c;

    std::printf("%d\n", sum);
}