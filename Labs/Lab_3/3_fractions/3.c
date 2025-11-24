#include <stdio.h>
#include <stdlib.h>

typedef struct fraction
{
    int numerator;
    int denominator;
} fraction, *p_fraction;

int NOD(int a, int b)
{
    if (a < 0) {a *= -1;}
    if (b < 0) {b *= -1;}
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a == 0 ? 1 : a;

}

int sum_frac(fraction * ab, fraction * cd, fraction *sum)
{
    int nod;
    fraction temp;
    if(sum == NULL && ab == NULL && cd == NULL){ return -1; }

    if(ab->denominator == cd->denominator)
    {
        sum->numerator = ab->numerator + cd->numerator;
        sum->denominator = ab->denominator;

        nod = NOD(sum->numerator, sum->denominator);

        sum->numerator /= nod;
        sum->denominator /= nod;
    }
    else
    {
        temp.numerator = ab->numerator;
        temp.denominator = ab->denominator;
        
        ab->numerator *= cd->denominator;
        ab->denominator *= cd->denominator;


        cd->numerator *= temp.denominator;
        cd->denominator *= temp.denominator;

        sum->numerator = ab->numerator + cd->numerator;
        sum->denominator = ab->denominator;

        nod = NOD(sum->numerator, sum->denominator);

        sum->numerator /= nod;
        sum->denominator /= nod;
    }
    return 0;
}


int sub_frac(fraction * ab, fraction * cd, fraction *sub)
{
    int nod;
    fraction temp;
    if(sub == NULL && ab == NULL && cd == NULL){ return -1; }

    if(ab->denominator == cd->denominator)
    {
        sub->numerator = ab->numerator - cd->numerator;
        sub->denominator = ab->denominator;
    }
    else
    {
        temp.numerator = ab->numerator;
        temp.denominator = ab->denominator;
        
        ab->numerator *= cd->denominator;
        ab->denominator *= cd->denominator;

        cd->numerator *= temp.denominator;
        cd->denominator *= temp.denominator;

        sub->numerator = ab->numerator - cd->numerator;
        sub->denominator = ab->denominator;

        nod = NOD(sub->numerator, sub->denominator);

        sub->numerator /= nod;
        sub->denominator /= nod;
    }
    return 0;
}


int mul_frac(fraction * ab, fraction * cd, fraction *mul)
{
    int nod;
    if(mul == NULL && ab == NULL && cd == NULL){ return -1; }

    mul->numerator = ab->numerator * cd->numerator;
    mul->denominator = ab->denominator * cd->denominator;

    nod = NOD(mul->numerator, mul->denominator);

    mul->numerator /= nod;
    mul->denominator /= nod;
    return 0;
}

int div_frac(fraction * ab, fraction * cd, fraction *div)
{
    int nod;
    if(div == NULL && ab == NULL && cd == NULL){ return -1; }

    if(cd->numerator == 0){ return -2;}

    div->numerator = ab->numerator * cd->denominator;
    div->denominator = ab->denominator * cd->numerator;

    nod = NOD(div->numerator, div->denominator);

    div->numerator /= nod;
    div->denominator /= nod;
    return 0;
}


int main()
{
    int a, b, c, d;
    fraction ab;
    // *p_fraction = &ab
    fraction cd;
    fraction sum;
    fraction sub;
    fraction mul;
    fraction div; 
    printf("A and C need to be whole and positive.\n");
    printf("B and D need to be whole and can be not positive, but not equal 0\n");
    printf("Enter a, b, c, d:\n");
    // if(scanf("%d %d %d %d", &a, &b, &c, &d) != 4)
    // {
    //     printf("Wrong arguments!\n");
    //     return -1;
    // }
    // Alternative version of validation
    
    while(scanf("%d %d %d %d", &a, &b, &c, &d) != 4)
    {
        printf("Error! :[  Please type your numbers again:\n");
        while(getchar() != '\n');
    }
        if((a >= 0 && c >= 0) && (b != 0 && d != 0))
        {
            ab.numerator = a;
            ab.denominator = b;
            cd.numerator = c;
            cd.denominator = d;
        }
        else
        {
            printf("You entered invalid values!\n");
            return -2;
        }

        // sum
        if(sum_frac(&ab, &cd, &sum) == 0)
        {
            printf("Sum a/b and c/d:\n %d/%d\n", sum.numerator, sum.denominator);
        }
        else if(sum_frac(&ab, &cd, &sum) == -1)
        {
            printf("Can not read pointer to a fraction.\n");
        }


        // subtraction
        if(sub_frac(&ab, &cd, &sub) == 0)
        {
            printf("Subtraction a/b and c/d:\n %d/%d\n", sub.numerator, sub.denominator);
        }
        else if(sub_frac(&ab, &cd, &sub) == -1)
        {
            printf("Can not read pointer to a fraction.\n");
        }

        //multiplication
        if(mul_frac(&ab, &cd, &mul) == 0)
        {
            printf("Multiplication a/b and c/d:\n %d/%d\n", mul.numerator, mul.denominator);
        }
        else if(mul_frac(&ab, &cd, &mul) == -1)
        {
            printf("Can not read pointer to a fraction.\n");
        }

        //division
        if(div_frac(&ab, &cd, &div) == 0)
        {
            printf("Division a/b and c/d:\n %d/%d\n", div.numerator, div.denominator);
        }
        else if(div_frac(&ab, &cd, &mul) == -1)
        {
            printf("Can not read pointer to a fraction.\n");
        }
        else if(div_frac(&ab, &cd, &mul) == -2)
        {
            printf("A or C are 0!\n");
    }

    return 0;
}