#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Binary2Decimal(char * BinaryArray)
{
    double num = 0;
    int N = strlen(BinaryArray);
    for (int i = 0; i < N; ++i)
    {
        num += pow(2, N-1-i) * (BinaryArray[i] - '0');
    }
    return num;
}

int main(int argc, char* argv[])
{
    if (argc >= 2)
    {
        double num = Binary2Decimal(argv[1]);
        printf("%.0f\n", num);
    }
    return 0;
}