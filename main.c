#include <stdio.h>

void printpoly(float* output, float* outputcoefficient, int* outputpower, int g, int denomPower, float* denomCoefficienteno, int num_degree)
{
    int i, j = 0;
    printf("(");

    for (i = 0; i < g; i++)
    {
        if (outputcoefficient[i] != 0) {
            if (outputpower[i] != 0)
                printf("%f x^%d", outputcoefficient[i], outputpower[i]);
            else
                printf("%f", outputcoefficient[i]);

            if (i < g - 1)
                if (outputcoefficient[i + 1] >= 0)
                    printf("+");
        }
    }
    printf(")");


    for (i = num_degree; i >= 0; i--)
    {
        if (output[i] == 0) {
            i--;
            j++;
        }

        else
            if (num_degree - i == 0) {
                printf("+(");
                if (output[i] == 0) {

                }
                else if (output[i - 1] > 0)
                    printf("%f+", output[i]);
                else
                    printf("%f", output[i]);
            }
            else if (output[i - 1] > 0)
                printf("%f x^%d +", output[i], num_degree - i);
            else
                printf("%f x^%d", output[i], num_degree - i);


    }
    printf(")");
    if (j != num_degree) {
        printf("/(");
        for (i = denomPower; i >= 0; i--)
        {
            if (*denomCoefficienteno == 0)
            {
                denomCoefficienteno++;
                i--;
            }
            if (i == 0)
                printf("%f\n", *denomCoefficienteno);
            if (i >= 1)
            {
                printf("%fx^%d", *denomCoefficienteno, i);
                denomCoefficienteno++;
                if (i >= 1) {
                    if (*denomCoefficienteno + 1 >= 0)
                        printf("+");
                }
            }
        } printf(")\n");
    }
}

void takePoly(float* numCoefficient, float* denomCoefficient, int* numPower, int* denomPower)
{
    int i;

    printf("please entre the degree of numerator\n");
    scanf("%d", numPower);

    for (i = *numPower; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("please entre the value of the constant term\n");
            scanf("%f", numCoefficient);
        }
        else
        {
            printf("please entre the coefficient of x^%d of numerator\n", i);
            scanf("%f", numCoefficient++);
        }
    }

    printf("please entre the degree of denominator\n");
    scanf("%d", denomPower);


    for (i = *denomPower; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("please entre the value of the constant term\n");
            scanf("%f", denomCoefficient);
        }
        if (i >= 1)
        {
            printf("please entre the coefficient of x^%d of denominator\n", i);
            scanf("%f", denomCoefficient++);
        }
    }
}


int isDivisible(float* x, float* y, int nume, int deno)
{
    int i;
    if (nume < deno)
    {
        printf("can not solve with long devision\n");

        for (i = nume; i >= 0; i--)
        {
            if (*x == 0)
            {
                x++;
                i--;
            }
            if (i == 0)
                printf("%f", *x);
            else
            {
                printf("%fx^%d", *x, i);
                x++;
                if (*x > 0)
                    printf("+");
            }
        }
        printf("/ ");

        for (i = deno; i >= 0; i--)
        {
            if (*y == 0)
            {
                y++;
                i--;
            }
            if (i == 0)
                printf("%f\n", *y);
            if (i >= 1)
            {
                printf("%fx^%d", *y, i);
                y++;
                if (*y > 0)
                    printf("+");
            }
        }

        return 0;
    }

    else
        return 1;
}

void longDevision(float* numCoefficient, float* denomCoefficient, float* outcoefficient, int numPower, int denomPower, int* outPower)
{
    int i, j, z = 0, g = 0;

    float subtract[100];
    outcoefficient[g] = numCoefficient[g] / denomCoefficient[0];
    outPower[g] = numPower - denomPower;

A:

    for (i = 0; i <= denomPower; i++)
        subtract[i] = outcoefficient[g] * denomCoefficient[i];

    for (j = 0; j <= denomPower; j++)
        numCoefficient[j + g] = numCoefficient[j + g] - subtract[j];

    g++;
    for (z = 0; numCoefficient[z] == 0; z++) {
    }

    if (numPower - z >= denomPower)
    {
        outcoefficient[g] = numCoefficient[g] / denomCoefficient[0];
        outPower[g] = numPower - denomPower - z;
        goto A;
    }
    printpoly(numCoefficient, outcoefficient, outPower, g, denomPower, denomCoefficient, numPower);
}


int main()
{
    int numDegree, denomDegree, z, outPower[100];
    float numCoefficient[100], denomCoefficient[100], outCoefficient[100];
    takePoly(numCoefficient, denomCoefficient, &numDegree, &denomDegree);
    z = isDivisible(numCoefficient, denomCoefficient, numDegree, denomDegree);
    if (z == 1)
    {
        longDevision(numCoefficient, denomCoefficient, outCoefficient, numDegree, denomDegree, outPower);
    }
}
