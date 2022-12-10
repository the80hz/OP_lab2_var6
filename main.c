/*
 * Вычислить функцию е^x, представленную в виде ряда Маклорена,
 * e^x=∑_(n=0)^∞ x^n/n! заданной точностью e>0 или с заданным числом членов разложения N>10.
 * Вывести в виде столбиков значения x, n, e^x, точность, разность между точным значением и приближенным.
 */

#include <stdio.h>

int main()
{
    printf("Выберите действие:\n1. Число членов разложение N > 10\n2. Точность вычислений eps > 0.\n");
    int choice;
    scanf("%d", &choice);

    double e = 1;
    double sum = 1;
    double fact = 1;

    switch (choice) {
    case 1:
        printf("Введите число членов разложения N > 10: ");
        int N = 10;
        scanf("%d", &N);
        while (N <= 10) {
            printf("Число членов разложения должно быть больше 10.\n");
        }
        printf("Введите x: ");
        double x;
        scanf("%lf", &x);

        for (int i = 1; i <= N; i++) {
            fact *= i;
            e *= x;
            sum += e / fact;
            printf("x = %lf\tn = %d\tsum = %lf\te = %lf\n", x, i, sum, e);
        }

        break;

    case 2:
        printf("Введите точность вычислений eps > 0: ");
        double eps = 0;
        scanf("%lf", &eps);
        while (eps <= 0) {
            printf("Точность вычислений должна быть больше 0.\n");
        }
        printf("Введите x: ");
        scanf("%lf", &x);
        int i = 1;
        while (1) {
            fact *= i;
            e *= x;
            sum += e / fact;
            if (e / fact < eps) {
                break;
            }
            i++;
            printf("x = %lf\tn = %d\tsum = %lf\te = %lf\n", x, i, sum, e);
        }
        break;
    }
    return 0;
}
