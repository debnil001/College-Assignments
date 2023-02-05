#include <stdio.h>

int gcdEuclid(int a, int b)
{
    printf("GCD(%d %d)\n", a, b);
    if (a == 0)
        return b;
    return gcdEuclid(b%a, a);
}

int gcdFactorization(int a, int b)
{
    if(a == 0 && b != 0)
        return b;
    if(a != 0 && b == 0)
        return a;
    int gcd = 1, i;
    for (i = 2; i <= a; i++)
    {
        while (a % i == 0 && b % i == 0)
        {
            printf("%d | %d , %d \n", i, a, b);
            gcd *= i;
            a /= i;
            b /= i;
        }
    }
    printf("  | %d , %d \n", a, b);
    return gcd;
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    if(a == 0 && b == 0) {
        printf("\nUndefined");
        return 0;
    }
    printf("\nGCD using Euclid's method: \n");
    printf("GCD of %d and %d using Euclid's Algorithm is %d\n", a, b, gcdEuclid(a, b));
    printf("\nGCD using Factorization method: \n");
    printf("GCD of %d and %d using Factorization method: %d", a, b, gcdFactorization(a, b));
    return 0;
}