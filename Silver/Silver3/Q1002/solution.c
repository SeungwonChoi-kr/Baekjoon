#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculateDistance(int x1, int y1, int x2, int y2);
void printMeetTime(double distance, int r1, int r2);

int main()
{
    const int inputValueNum = 6;
    int caseNum = 0;
    int* caseArr = (int*)malloc(sizeof(int) * caseNum * inputValueNum);
    double distance = 0.0;
    
    scanf("%d", &caseNum);
    
    for (int caseIdx = 0; caseIdx < caseNum; caseIdx++)
    {
        int tempArr[6] = { 0, };
        
        for (int valueIdx = 0; valueIdx < inputValueNum; valueIdx++)
        {
            int* tmp_ptr = (caseArr + valueIdx + caseIdx * caseNum);
            scanf("%d", tmp_ptr);
            
            tempArr[valueIdx] = *tmp_ptr;
        }
        distance = calculateDistance(tempArr[0], tempArr[1], tempArr[3], tempArr[4]);
        
        printMeetTime(distance, tempArr[2], tempArr[5]);
    }
    
    free(caseArr);
    
    return 0;
}

double calculateDistance(int x1, int y1, int x2, int y2)
{
    double distance = 0.0;
    double distance_X = 0.0;
    double distance_Y = 0.0;
    
    if (x1 == x2)
        distance_X = 0.0;
    else if (x1 > x2)
        distance_X = (x1 - x2);
    else
        distance_X = (x2 - x1);
    
    if (y1 == y2)
        distance_Y = 0.0;
    else if (y1 > y2)
        distance_Y = (y1 - y2);
    else
        distance_Y = (y2 - y1);
    
    if (distance_X == 0 && distance_Y == 0)
        distance = 0.0;
    else if (distance_X == 0)
        distance = distance_Y;
    else if (distance_Y == 0)
        distance = distance_X;
    else
    {
        distance = pow(distance_X, 2) + pow(distance_Y, 2);
        distance = pow(distance, 0.5);
    }

    return distance;
}

void printMeetTime(double distance, int r1, int r2)
{
    if (distance == 0.0)
    {
        if (r1 == r2)
            printf("-1\n");
        else
            printf("0\n");
    }
    else if (distance + r1 > r2)
    {
        if (distance - r1 >= 0)
        {
            if (distance - r1 < r2)
                printf("2\n");
            else if (distance - r1 == r2)
                printf("1\n");
            else
                printf("0\n");
        }
        else
        ;
    }
    else if (distance + r1 < r2)
    {
        printf("0\n");
    }
}