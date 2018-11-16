#include "Array2D.h"
#include <stdio.h>

/* Array2D_tester library */

#define ROW 5
#define COL 10

void Array2D_tester()
{

    int A[ROW][COL];
    int key;

    printf("\n:Test PopulateArray2D\n");
    PopulateArray2D(A, ROW, COL, 0);
    DisplayArray2D(A, ROW, COL);

    printf("\n:Test PopulateArray2DRandom\n");
    PopulateArray2DRandom(A, ROW, COL, 1, 9);
    DisplayArray2D(A, ROW, COL);

    printf("\n:Test partial PopulateArray2D\n");
    PopulateArray2D(A, ROW/2, COL/2, 99);
    DisplayArray2D(A, ROW, COL);

    printf("\n:Test SumRow\n");
    PopulateArray2DRandom(A, ROW, COL, 1, 9);
    DisplayArray2D(A, ROW, COL);
    printf("The sum of row 0 is: %d\n", SumRow(A, ROW, COL, 0));
    printf("The sum of row 1 is: %d\n", SumRow(A, ROW, COL, 1));

    printf("\n:Test FindArray2D\n");
    PopulateArray2DRandom(A, ROW, COL, 1, 99);
    DisplayArray2D(A, ROW, COL);
    do
    {
        printf("Enter a value to search for, or 0 to quit:");
        scanf("%d", &key);
        if (key!=0)
        {
            printf("Looking for %d...\n", key);
            if(FindArray2D(A, ROW, COL, key) == 1)
                printf("found\n");
            else
                printf("not found\n");
        }
    } while(key!=0);

}
