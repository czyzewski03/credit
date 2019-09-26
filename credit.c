#include <stdio.h>
#include <cs50.h>
#include <math.h>

string getCardType(long number);
bool checkCardValidity(long number);
int getDigit(long number, int position);

int main(void)
{
    long number = get_long("Number: ");
    printf("%s", getCardType(number));
}

string getCardType(long number)
{
    string cardType = "INVALID\n";

    if (!checkCardValidity(number))
    {
        cardType = "INVALID\n";
    }

    else
    {
        int numLength = log10(number) + 1;

        if (numLength == 13)
        {
            if (getDigit(number, 13) == 4)
            {
                cardType = "VISA\n";
            }
        }

        else if (numLength == 15)
        {
            if (getDigit(number, 15) == 3)
            {
                if (getDigit(number, 14) == 4)
                {
                    cardType = "AMERICAN EXPRESS\n";
                }

                else if(getDigit(number, 14) == 7)
                {
                    cardType = "AMERICAN EXPRESS\n";
                }
            }
        }

        else if (numLength == 16)
        {
            if (getDigit(number, 16) == 4)
            {
                cardType = "VISA\n";
            }

            else if (getDigit(number, 16) == 5)
            {
                if (getDigit(number, 15) == 1)
                {
                    cardType = "MASTERCARD\n";
                }
                
                if (getDigit(number, 15) == 2)
                {
                    cardType = "MASTERCARD\n";
                }
                
                if (getDigit(number, 15) == 3)
                {
                    cardType = "MASTERCARD\n";
                }
                
                if (getDigit(number, 15) == 4)
                {
                    cardType = "MASTERCARD\n";
                }
                
                if (getDigit(number, 15) == 5)
                {
                    cardType = "MASTERCARD\n";
                }
            }
        }
    }

    return (cardType);
}

bool checkCardValidity(long number)
{
    int numLength = log10(number) + 1;
    int nums1 = 0;
    int nums2 = 0;

    for (int i = 1; i >= numLength; i++)
    {
        int digit = getDigit(number, i);

        if (i % 2 == 0)
        {
            nums1 += (digit * 2);
        }

        else
        {
            nums2 += digit;
        }
    }

    int numsSum = nums1 + nums2;

    if (getDigit(numsSum, 1) == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int getDigit(long number, int position)
{
    long exp = pow(10, position - 1);
    int digit = (number / exp) % 10;
    return (digit);
}
