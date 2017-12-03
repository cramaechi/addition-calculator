//Program that reads in two is of maximum length 20 and outputs the sum of the two.
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void input(char i1[], char i2[], int arraySize, int& numUsed1, int& numUsed2);
//Precondition: arraySize == 20 and numUsed >= 1 && <= arraySize.
//Postcondition: Fills in both arrays, i1 and i2 with values from the keyboard.
//The value of numUsed has been set.

void sum(char i1[], char i2 [], int i3[], int i4[], int sum[], int numUsed1, int numUsed2, int& numUsed3);
//Precondition: array i1 and i2 have both been filled. numUsed
//is >= 1.
//Postcondition: Adds the is of i1 and i2 and stores it in the array sum.

void convertAndReverseElements(char i1[], char i2 [], int i3[], int i4[], int len1, int len2);
//Precondition: the arrays, i1 and i2 have been filled. len1 and len2 >= 1.
//Postcondition: Converts the elements of i1 and i2 to i types and reverses their order. Assigns 
//all values of the elements of i1 and i2 to i3 and i4.

bool isOneDigit(int i1, int i2);
//Precondition: Both i1 and i2 are >= 0.
//Postcondition: Returns true if the addition of i1 and i is a one 
//digit number, and false if not.

bool isTwoDigit(int i1, int i2);
//Precondition: Both i1 and i2 are >= 0.
//Postcondition: Returns true if the addition of i1 and i is a two
//digit number, and false if not.

bool noAdditionNeeded(int len1, int len2);
//Precondition: len1 and len2 are >= 1.
//Postcondition: Returns true if i1 > i2, and false if not.

void output(int sum[], int numUsed);
//Precondition: array sum has been filled.
//Outputs the value of array sum.

const int INT_LENGTH = 20;

int main()
{
	char i1[INT_LENGTH], i2[INT_LENGTH];
	int i3[INT_LENGTH], i4[INT_LENGTH], s[INT_LENGTH], numUsed1, numUsed2, numUsed3;

	input(i1, i2, INT_LENGTH, numUsed1, numUsed2);
	sum(i1, i2, i3, i4, s, numUsed1,  numUsed2, numUsed3);
    output(s, numUsed3);

    return 0;
}

void input(char i1[], char i2[], int arraySize, int& numUsed1, int& numUsed2)
{
    int index1 = 0, index2 = 0;

    cout<<"Press + to add number.\n"<<"Press = to compute answer.\n\n";

    do
    {
        cin>>i1[index1++];
    }while(i1[index1 - 1] != '+' && index1 < arraySize);

    numUsed1 = index1 - 1;

    do
    {
        cin>>i2[index2++];
    }while(i2[index2 - 1] != '=' && index2 < arraySize);

    numUsed2 = index2 - 1;
}

void sum(char i1[], char i2 [], int i3[], int i4[], int sum[], int len1, int len2, int& sumLength)
{
    convertAndReverseElements(i1, i2, i3, i4, len1, len2);

    sumLength = max(len1, len2);
    int sumIndex = sumLength - 1;

    for (int i = 0; i < sumLength; i++)
    {
        if (isTwoDigit(i3[i], i4[i]) && i == sumLength - 1)
            sum[sumIndex] = (i3[i] + i4[i]);
        else if(isTwoDigit(i3[i], i4[i]))
        {
            sum[sumIndex] = (i3[i] + i4[i])%10;
            i3[i + 1]+=(i3[i] + i4[i])/10;
        }
        else if (isOneDigit(i3[i], i4[i]))
            sum[sumIndex] = (i3[i] + i4[i]);
        else if (noAdditionNeeded(i, len2 - 1))
            sum[sumIndex] = i3[i];
        else if (noAdditionNeeded(i, len1 - 1))
            sum[sumIndex] = i4[i];

        sumIndex--;
    }
}

bool isOneDigit(int i1, int i2)
{
    return ((i1 + i2 < 10) && i1 >=0 && i2 >= 0);
}

bool isTwoDigit(int i1, int i2)
{
    return (i1 + i2 >= 10);
}

bool noAdditionNeeded(int len1, int len2)
{
    return len1 > len2;
}

void output(int s[], int numUsed3)
{
    for (int i = 0; i < numUsed3; i++)
        cout<<s[i];

    cout<<"\n\n";
}

void convertAndReverseElements(char i1[], char i2 [], int i3[], int i4[], int len1, int len2)
{
    int index1 = len1 - 1, index2 = len2 - 1;

    for (int i = 0; i < len1; i++)
        i3[i] = i1[index1--] - 48;

    for (int i = 0; i < len2; i++)
        i4[i] = i2[index2--] - 48;
}
