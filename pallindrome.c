#include <stdio.h>
#include <conio.h>

int main()
{
    int num, result = 0;
    printf("Enter the number : ");
    scanf("%d", &num);
    int og = num;
    while (num > 0)
    {
        int rem = num % 10;
        result = result * 10 + rem;
        num = num / 10;
    }
    if (result == og)
    {
        printf("It is a Pallindrome..");
    }
    else
    {
        printf("It is not a Pallindrome..");
    }
}