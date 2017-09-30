#include <cstdio>
#include <cmath>

int main()
{
    std::puts("please enter a, b and c for 'ax^2 + bx + c': ");

    float a = 0;
    float b = 0;
    float c = 0;
    std::scanf("%f %f %f", &a, &b, &c);

    float discr = (b * b) - (4 * a * c);

    float x1 = (-b + sqrt(discr)) / (2 * a);
    float x2 = (-b - sqrt(discr)) / (2 * a);

    std::printf("solution: %f and %f\n", x1, x2);
}