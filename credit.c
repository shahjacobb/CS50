#include <stdio.h>
#include <math.h>
// #include <cs50.h> // might need to comment out to switch to Ubuntu local based env

// case 1: add every other integer starting from the last most (LSB) digit to a running sum
// case 2: adds every other integer * 2 starting from the second last most digit,
// but splits up the digits if the digit * 2 is >= 10 and then adds them
void LuhnsAlgorithm(long long); // return type should actually be changed to string when submitted
int main()
{

    long long num;
    do
    {
        printf("Enter a credit card number for testing. Enter 0 to stop.\n");
        scanf("%lli", &num);
        LuhnsAlgorithm(num);

    } while (num != 0);
}

boolean LuhnsCheckSumAlgorithm(long long cc)
{
    int sum = 0, ccNumberSize = 0;
    long long ccSizeWorkingNumber = cc;

    // case 1
    long long case1 = cc;
    while (case1 > 0)
    {
        sum += case1 % 10;
        case1 = case1 / 100;
    }

    // case 2
    long long case2 = cc / 10;
    while (case2 > 0)
    {
        // assuming the product of the last digit (calculated by x % 10 * 2) >= 10
        if ((case2 % 10) * 2 >= 10)
        {

            int digitBreakUp = case2 % 10 * 2;
            // breaks up digit into two accordingly
            sum += (digitBreakUp / 10) + (digitBreakUp % 10);
        }
        else
        {
            // just appends sum by given digit * 2 if product ! >= 10
            sum += (case2 % 10) * 2;
        }
        case2 = case2 / 100;
    }
    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        0;
    }

    

    // gets size of number in # of digits
    while (ccSizeWorkingNumber > 0)
    {

        ccNumberSize += 1;
        ccSizeWorkingNumber = ccSizeWorkingNumber / 10;
    }
    // calculates the number to divide CC by in order to get the first two digits. it uses the math library in C
    // remember to link the math library with -lm (ex: gcc credit.c -lm) to make it work since math.h only includes the declaration and not the def
    long base10Dividend = pow(10, ccNumberSize - 2);
    int FirstTwo = cc / base10Dividend;

    printf("First two digits of %lli are %i\n", cc, FirstTwo);

    /* switch case block below determines which credit card
    AMEX: 15 digits, starts with 34 or 37
    Mastercard: 16 digits, start with 51-55
    Visa: 13 or 16, always starts with 4
    */

    if (ccNumberSize == 15)
    {

        if (FirstTwo == 34 || FirstTwo == 37)
        {
            printf("AMEX\n");
        }
    }
    if (ccNumberSize == 16)
    {
        int FirstTwo = cc / base10Dividend;
        if (FirstTwo == 51 || FirstTwo == 52 || FirstTwo == 53 || FirstTwo == 54 ||
            FirstTwo == 55 || FirstTwo == 56)
        {
            printf("MASTERCARD\n");
        }
        else if (cc / pow(10, ccNumberSize - 1) == 4)
        {
            printf("VISA\n");
        }
    }
    if (ccNumberSize == 13)
    {
        if (cc / pow(10, ccNumberSize - 1) == 4)
        {
            printf("VISA\n");
        }
    }
}