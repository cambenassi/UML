#include <stdio.h>

typedef struct Date 
{
    int month;
    int day;
    int year;
} Date;

Date getYesterdayDate(Date userInput);

int main(int argc, char * arv[])
{
    Date userInput;
    Date yesterdayDate;
    
    printf("Please enter a month (1~12):\n");
    scanf("%d", &userInput.month);
    printf("Please enter a valid day in the month:\n");
    scanf("%d", &userInput.day);
    userInput.year = 2019;
    
    printf("Today is: %d/%d/%d\n", userInput.month, userInput.day, userInput.year);
    yesterdayDate = getYesterdayDate(userInput);
    printf("Yesterday is: %d/%d/%d\n", yesterdayDate.month, yesterdayDate.day, yesterdayDate.year);

    return 0;
}

Date getYesterdayDate(Date userInput)
{
    Date yesterdayDate;
    int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;
    
    if (userInput.day - 1 == 0)
    {
        if (userInput.month == 1)
        {
            yesterdayDate.month = 12;
            yesterdayDate.year = 2018;
            yesterdayDate.day = 31;
        }
        else
        {
            yesterdayDate.month = userInput.month - 1;
            i = yesterdayDate.month - 1;
            yesterdayDate.day = daysInMonths[i];
        }
    }
    else
    {
        yesterdayDate.day = userInput.day - 1;
        yesterdayDate.month = userInput.month;
        yesterdayDate.year = userInput.year;
    }
    
    return yesterdayDate;
}