#include <stdio.h>
#include <string.h>

void copyName(FILE* fpQuiz, FILE* fpAvg, char initialTest, int isEmpty);
void getAverage(FILE* fpQuiz, FILE* fpAvg);

int main(int argc, char * argv[])
{
    FILE *fpQuiz = fopen("quiz.txt", "r");
    FILE *fpAvg = fopen("average.txt", "w");
    int numOfConversions, isEmpty = 1;
    char initialTest;
    
    numOfConversions = fscanf(fpQuiz, "%c", &initialTest);
    
    if (numOfConversions == 1)
    {
        isEmpty = 0;
    }
    
    while(!feof(fpQuiz))
    {
        copyName(fpQuiz, fpAvg, initialTest, isEmpty);
        getAverage(fpQuiz, fpAvg);
        fprintf(fpAvg, "\n");
        isEmpty = 1;
    }
    
    fclose(fpAvg);
    fclose(fpQuiz);
    
    return 0;
}

void copyName(FILE* fpQuiz, FILE* fpAvg, char initialTest, int isEmpty)
{
    char firstName[30];
    char lastName[30];
    int numOfConversions = 0;
    
    firstName[30] = '\0';
    lastName[30] = '\0';
    
    if (isEmpty == 0)
    {
        firstName[0] = initialTest;
        
        for (int i = 1; i < 20; i++)
        {
            fscanf(fpQuiz, "%c", &firstName[i] );
            if (firstName[i] == ' ')
            {
                firstName[i] = '\0';
                break;
            }
            if (firstName[i] == '\n')
            {
                i--;
            }
        }
    }
    else
    {
        for (int i = 0; i < 20; i++)
        {
            fscanf(fpQuiz, "%c", &firstName[i] );
            if (firstName[i] == ' ')
            {
                firstName[i] = '\0';
                break;
            }
            if (firstName[i] == '\n')
            {
                i--;
            }
        }
    }
    
    for (int i = 0; i < 20; i++)
    {
        numOfConversions = fscanf(fpQuiz, "%c", &lastName[i] );
        if (lastName[i] == ' ')
        {
            lastName[i] = '\0';
            break;
        }
        if (numOfConversions == 0)
        {
            lastName[i] = '\0';
            break;
        }
        if (lastName[i] == '\n')
        {
            lastName[i] = '\0';
            break;
        }
    }
    
    strcat(lastName, ", ");
    strcat(lastName, firstName);
    
    fprintf(fpAvg, "%-20s", lastName);
}

void getAverage(FILE* fpQuiz, FILE* fpAvg)
{
    double sum = 0.0, numTests = 10.0, average;
    int score;
    
    for (int i = 0; i < 10; i++)
    {
        score = 0;
        fscanf(fpQuiz, "%d", &score);
        sum += score;
        fprintf(fpAvg, "%4d", score);
    }

    fprintf(fpAvg, "%10.2f", sum / numTests);
    
}



