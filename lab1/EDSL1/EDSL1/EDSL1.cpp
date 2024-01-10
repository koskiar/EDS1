#include <iostream>
#include <cmath>

void InputFraction(int& Num, int& Denom, int& Num2, int& Denom2, int& Num3, int& Denom3, int& Num4, int& Denom4) {
    std::cout << "Enter a positive or zero numerator for the first fraction: ";
    std::cin >> Num;
    while (Num < 0) {
        std::cout << std::endl << "Numerator must be positive or zero, please enter a new value: ";
        std::cin >> Num;
    }
    std::cout << "Enter a positive (non-zero) denominator for the first fraction: ";
    std::cin >> Denom;
    while (Denom <= 0) {
        std::cout << std::endl << "Denominator must be positive, please enter a new value: ";
        std::cin >> Denom;
    }
    std::cout << "Enter a positive or zero numerator for the second fraction: ";;
    std::cin >> Num2;
    while (Num2 < 0) {
        std::cout << std::endl << "Numerator must be positive or zero, please enter a new value: ";
        std::cin >> Num2;
    }
    std::cout << "Enter a positive (non-zero) denominator for the second fraction: ";
    std::cin >> Denom2;
    while (Denom2 <= 0) {
        std::cout << std::endl << "Denominator must be positive, please enter a new value: ";
        std::cin >> Denom2;
    }
    std::cout << "Enter a positive or zero numerator for the third fraction: ";
    std::cin >> Num3;
    while (Num3 < 0) {
        std::cout << std::endl << "Numerator must be positive or zero, please enter a new value: ";
        std::cin >> Num3;
    }
    ;
    std::cout << "Enter a positive (non-zero) denominator for the third fraction: ";
    std::cin >> Denom3;
    while (Denom3 <= 0) {
        std::cout << std::endl << "Denominator must be positive, please enter a new value: ";
        std::cin >> Denom3;
    }
    std::cout << "Enter a positive or zero numerator for the fourth fraction: ";
    std::cin >> Num4;
    while (Num4 < 0) {
        std::cout << std::endl << "Numerator must be positive or zero, please enter a new value: ";
        std::cin >> Num;
    }
    std::cout << "Enter a positive (non-zero) denominator for the fourth fraction: ";
    std::cin >> Denom4;
    while (Denom4 <= 0) {
        std::cout << std::endl << "Denominator must be positive, please enter a new value: ";
        std::cin >> Denom4;
    }
    std::cout << std::endl;
}
//-------------------------------------------------------------------
void Reduce1(int& Num, int& Denom, int& Num2, int& Denom2, int& Num3, int& Denom3, int& Num4, int& Denom4) {
    int a, b, c, d, i, j, k, l, m, n, A, B, C, D, I, J, K, L, M, N = 0;
    a = Denom; A = Denom;
    b = Num; B = Num;
    c = Denom2; C = Denom2;
    d = Num2; D = Num2;
    l = Denom3; L = Denom3;
    k = Num3; K = Num3;
    n = Denom4; N = Denom4;
    m = Num4; M = Num4;
    for (i = a * b; i > 1; i--)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            a /= i;
            b /= i;
        }
    }
    for (j = c * d; j > 1; j--)
    {
        if ((c % j == 0) && (d % j == 0))
        {
            c /= j;
            d /= j;
        }
    }
    for (I = k * l; I > 1; I--)
    {
        if ((k % I == 0) && (l % I == 0))
        {
            k /= I;
            l /= I;
        }
    }
    for (J = m * n; J > 1; J--)
    {
        if ((m % J == 0) && (n % J == 0))
        {
            m /= J;
            n /= J;
        }
    }

    std::cout << B << "/" << A << " is reduced to " << b << "/" << a << std::endl;
    std::cout << D << "/" << C << " is reduced to " << d << "/" << c << std::endl;
    std::cout << K << "/" << L << " is reduced to " << k << "/" << l << std::endl;
    std::cout << M << "/" << N << " is reduced to " << m << "/" << n << std::endl;
    std::cout << std::endl;
}
//-------------------------------------------------------------------
void Reduce2(int& Num, int& Denom, int& Num2, int& Denom2, int& Num3, int& Denom3, int& Num4, int& Denom4) {
    int a, b, c, d, i, j, k, l, m, n, A, B, C, D, I, J, K, L, M, N = 0;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    a = Denom; A = Denom;
    b = Num; B = Num;
    c = Denom2; C = Denom2;
    d = Num2; D = Num2;
    l = Denom3; L = Denom3;
    k = Num3; K = Num3;
    n = Denom4; N = Denom4;
    m = Num4; M = Num4;
    for (i = a * b; i > 1; i--)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            a /= i;
            b /= i;
        }
    }
    for (j = c * d; j > 1; j--)
    {
        if ((c % j == 0) && (d % j == 0))
        {
            c /= j;
            d /= j;
        }
    }
    for (I = k * l; I > 1; I--)
    {
        if ((k % I == 0) && (l % I == 0))
        {
            k /= I;
            l /= I;
        }
    }
    for (J = m * n; J > 1; J--)
    {
        if ((m % J == 0) && (n % J == 0))
        {
            m /= J;
            n /= J;
        }
    }

    while (a <= b) {
        count1 = count1 + 1;
        b = b - a;
    }
    while (c <= d) {
        count2 = count2 + 1;
        d = d - c;
    }
    while (l <= k) {
        count3 = count3 + 1;
        k = k - l;
    }
    while (n <= m) {
        count4 = count4 + 1;
        m = m - n;
    }

    std::cout << B << "/" << A << " is reduced to " << count1 << " and " << b << "/" << a << std::endl;
    std::cout << D << "/" << C << " is reduced to " << count2 << " and " << d << "/" << c << std::endl;
    std::cout << K << "/" << L << " is reduced to " << count3 << " and " << k << "/" << l << std::endl;
    std::cout << M << "/" << N << " is reduced to " << count4 << " and " << m << "/" << n << std::endl;
    std::cout << std::endl;
}
//-------------------------------------------------------------------
void Reduce3(int& Num, int& Denom, int& c1) {
    int a = 0; int A = 0;
    int b = 0; int B = 0;
    int i = 0;
    a = Denom; A = Denom;
    b = Num; B = Num;
    for (i = a * b; i > 1; i--) {
        if ((a % i == 0) && (b % i == 0)) {
            a /= i;
            b /= i;
        }
    }
    Denom = a;
    Num = b;
    std::cout << B << "/" << A << " is reduced to " << b << "/" << a << std::endl;
    while (a <= b) {
        c1 = c1 + 1;
        b = b - a;
    }
    std::cout << B << "/" << A << " is reduced to " << c1 << " and " << b << "/" << a << std::endl;
}
//-------------------------------------------------------------------
void Reduce4(int& Num, int& Denom, int& p1) {
    int a = 0; int A = 0;
    int b = 0; int B = 0;
    int i = 0; int P = 0;
    a = Denom; A = Denom;
    b = Num; B = Num;
    P = p1;
    a = std::pow(a, P);
    b = std::pow(b, P);
    for (i = a * b; i > 1; i--) {
        if ((a % i == 0) && (b % i == 0)) {
            a /= i;
            b /= i;
        }
    }
    Denom = a;
    Num = b;
}
//-------------------------------------------------------------------
void AddFraction(int& Num, int& Denom, int& Num2, int& Denom2, int& Num3, int& Denom3, int& Num4, int& Denom4, int& c1) {
    int A, B, C, D, K, L, M, N = 0;
    A = Denom; B = Num; C = Denom2; D = Num2; L = Denom3; K = Num3; N = Denom4; M = Num4;
    if (Denom != Denom2) {
        Num = Num * Denom2;
        Num2 = Num2 * Denom;
        Denom = Denom * Denom2;
        Denom2 = Denom2 * Denom;
        Num = Num + Num2;
    }
    else {
        Num = Num + Num2;
    }
    std::cout << std::endl << "The Sum of " << B << "/" << A << " and " << D << "/" << C << " is " << Num << "/" << Denom << std::endl;
    Reduce3(Num, Denom, c1);

    Num = B; Denom = A; c1 = 0;
    if (Denom != Denom3) {
        Num = Num * Denom3;
        Num3 = Num3 * Denom;
        Denom = Denom * Denom3;
        Denom3 = Denom3 * Denom;
        Num = Num + Num3;
    }
    else {
        Num = Num + Num3;
    }
    std::cout << std::endl << "The Sum of " << B << "/" << A << " and " << K << "/" << L << " is " << Num << "/" << Denom << std::endl;
    Reduce3(Num, Denom, c1);
    Num2 = D; Denom2 = C; Num3 = K; Denom3 = L; c1 = 0;
    if (Denom2 != Denom3) {
        Num2 = Num2 * Denom3;
        Num3 = Num3 * Denom2;
        Denom2 = Denom2 * Denom3;
        Denom3 = Denom3 * Denom2;
        Num2 = Num2 + Num3;
    }
    else {
        Num2 = Num2 + Num3;
    }
    Num = Num2; Denom = Denom2;
    std::cout << std::endl << "The Sum of " << D << "/" << C << " and " << K << "/" << L << " is " << Num << "/" << Denom << std::endl;
    Reduce3(Num, Denom, c1);

    Num2 = D; Denom2 = C; c1 = 0;
    if (Denom2 != Denom4) {
        Num2 = Num2 * Denom4;
        Num4 = Num4 * Denom2;
        Denom2 = Denom2 * Denom4;
        Denom4 = Denom4 * Denom2;
        Num2 = Num2 + Num4;
    }
    else {
        Num2 = Num2 + Num4;
    }
    Num = Num2; Denom = Denom2;
    std::cout << std::endl << "The Sum of " << D << "/" << C << " and " << M << "/" << N << " is " << Num << "/" << Denom << std::endl;
    Reduce3(Num, Denom, c1);
    std::cout << std::endl;
    Denom = A; Num = B; Denom2 = C; Num2 = D; Denom3 = L; Num3 = K; Denom4 = N; Num4 = M;
}
//-------------------------------------------------------------------
void IsGreater(int& Num, int& Denom, int& Num2, int& Denom2, int& Num3, int& Denom3, int& Num4, int& Denom4)
{
    if ((Num / Denom) > (Num2 / Denom2)) { std::cout << Num << "/" << Denom << " is greater than " << Num2 << "/" << Denom2 << std::endl; }
    else { std::cout << Num << "/" << Denom << " is not greater than " << Num2 << "/" << Denom2 << std::endl; }
    if ((Num2 / Denom2) > (Num3 / Denom3)) { std::cout << Num2 << "/" << Denom2 << " is greater than " << Num3 << "/" << Denom3 << std::endl; }
    else { std::cout << Num2 << "/" << Denom2 << " is not greater than " << Num3 << "/" << Denom3 << std::endl; }
    if ((Num2 / Denom2) > (Num4 / Denom4)) { std::cout << Num2 << "/" << Denom2 << " is greater than " << Num4 << "/" << Denom4 << std::endl; }
    else { std::cout << Num2 << "/" << Denom2 << " is not greater than " << Num4 << "/" << Denom4 << std::endl; }
    if ((Num3 / Denom3) > (Num4 / Denom4)) { std::cout << Num3 << "/" << Denom3 << " is greater than " << Num4 << "/" << Denom4 << std::endl; }
    else { std::cout << Num3 << "/" << Denom3 << " is not greater than " << Num4 << "/" << Denom4 << std::endl; }
}
//-------------------------------------------------------------------
void FracPower(int& Num, int& Denom, int& Num2, int& Denom2, int& Num3, int& Denom3, int& Num4, int& Denom4, int& p1, int& p2, int& p3, int& p4)
{
    int A, B, C, D, K, L, M, N, P, S, T = 0;
    A = Denom; B = Num; C = Denom2; D = Num2; L = Denom3; K = Num3; N = Denom4; M = Num4;

    std::cout << std::endl << "Enter a positive power for the first fraction: ";
    std::cin >> p1;
    while (p1 < 0) {
        std::cout << std::endl << "the power for the first fraction must be positive, please enter a new value: ";
        std::cin >> p1;
    }
    P = p1;
    Reduce4(Num, Denom, p1);
    S = Num; T = Denom;
    std::cout << "Enter a positive power for the second fraction: ";
    std::cin >> p2;
    while (p2 < 0) {
        std::cout << std::endl << "the power for the second fraction must be positive, please enter a new value: ";
        std::cin >> p2;
    }
    Num = Num2; Denom = Denom2; p1 = p2;
    Reduce4(Num, Denom, p1);
    Num2 = Num; Denom2 = Denom;
    std::cout << "Enter a positive power for the third fraction: ";
    std::cin >> p3;
    while (p3 < 0) {
        std::cout << std::endl << "the power for the third fraction must be positive, please enter a new value: ";
        std::cin >> p3;
    }
    Num = Num3; Denom = Denom3; p1 = p3;
    Reduce4(Num, Denom, p1);
    Num3 = Num; Denom3 = Denom;
    std::cout << "Enter a positive power for the fourth fraction: ";
    std::cin >> p4;
    while (p4 < 0) {
        std::cout << std::endl << "the power for the fourth fraction must be positive, please enter a new value: ";
        std::cin >> p4;
    }
    Num = Num4; Denom = Denom4; p1 = p4;
    Reduce4(Num, Denom, p1);
    Num4 = Num; Denom4 = Denom;
    std::cout << std::endl;
    std::cout << B << "/" << A << " raised to power " << P << " is " << S << "/" << T << std::endl;
    std::cout << D << "/" << C << " raised to power " << p2 << " is " << Num2 << "/" << Denom2 << std::endl;
    std::cout << K << "/" << L << " raised to power " << p3 << " is " << Num3 << "/" << Denom3 << std::endl;
    std::cout << M << "/" << N << " raised to power " << p4 << " is " << Num4 << "/" << Denom4 << std::endl;
    Denom = A; Num = B; Denom2 = C; Num2 = D; Denom3 = L; Num3 = K; Denom4 = N; Num4 = M;
}
//-------------------------------------------------------------------
int main() {
    char an;
    do {
        int Num, Denom, Num2, Denom2, Num3, Denom3, Num4, Denom4, p1, p2, p3, p4, c1 = 0;
        InputFraction(Num, Denom, Num2, Denom2, Num3, Denom3, Num4, Denom4);
        Reduce1(Num, Denom, Num2, Denom2, Num3, Denom3, Num4, Denom4);
        Reduce2(Num, Denom, Num2, Denom2, Num3, Denom3, Num4, Denom4);
        AddFraction(Num, Denom, Num2, Denom2, Num3, Denom3, Num4, Denom4, c1);
        IsGreater(Num, Denom, Num2, Denom2, Num3, Denom3, Num4, Denom4);
        FracPower(Num, Denom, Num2, Denom2, Num3, Denom3, Num4, Denom4, p1, p2, p3, p4);
        std::cout << std::endl;
        std::cout << "Would you like to do another fraction? (y/n): ";
        std::cin >> an;
        std::cout << std::endl;
    } while ((an == 'y') || (an == 'Y'));
    return(0);
}
// Code Written By Andrew Koski :)