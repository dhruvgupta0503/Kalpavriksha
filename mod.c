#include <stdio.h>

int exponentMod(int A, int B, int C)
{
    // Base cases
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;

    // If B is even
    long y;
    if (B % 2 == 0) {
        y = exponentMod(A, B / 2, C);
        y = (y * y) % C;
    }
    // If B is odd
    else {
        y = A % C;
        y = (y * exponentMod(A, B - 1, C) % C) % C;
    }

    return (int)((y + C) % C);
}

int main()
{
    int A, B, C;

   
    printf("Enter the base (A): ");
    scanf("%d", &A);

    printf("Enter the exponent (B): ");
    scanf("%d", &B);

    printf("Enter the modulus (C): ");
    scanf("%d", &C);

   
    printf("Power is %d\n", exponentMod(A, B, C));

    return 0;
}
