#include <stdio.h>

#define SIZE 30

void flip(int flipnum);

int totalNum;
int current;
int pancakes[SIZE];

int main()
{
    int maxIndex;

    printf("Type number of pancakes : ");
    scanf("%d", &totalNum);

    printf("Type diameter of pancakes in order\n");

    //get sequence
    for (int i = 0; i < totalNum; i++)
    {
        scanf("%d", &pancakes[i]);
    }

    for (int i = 0; i < totalNum; i++)
    {
        printf("%d", pancakes[i]);
    }

    current = totalNum;

    while (current != 1)
    {

        //max
        for (int i = 0; i < current; i++)
        {
            if (i == 0)
            {
                maxIndex = i;
            }
            if (pancakes[maxIndex] < pancakes[i])

            {
                maxIndex = i;
            }
        }

        if (maxIndex + 1 == current)
        {
            current--;
        }

        else
        {

            // array i +1  - (max index i) flip
            if (maxIndex != 0)
            {
                flip(maxIndex + 1);
                // printf(" [flip(%d)]", totalNum - maxIndex);
                flip(current);
                // printf(" [flip(%d)]", totalNum - current + 1);
                current--;
            }

            // current flip
            if (maxIndex == 0)
            {
                flip(current);
                // printf(" [flip(%d)]",totalNum - current + 1);
                current--;
            }
        }
    }

    return 0;
}

void flip(int flipnum)
{
    int temp[SIZE];

    for (int i = 0; i < flipnum; i++)
    {
        temp[i] = pancakes[i];
    }

    for (int i = flipnum - 1; i >= 0; i--)
    {
        pancakes[i] = temp[flipnum - 1 - i];
    }

    printf("  -------->  ");

    printf(" [flip(%d)] ", totalNum - flipnum + 1);

    for (int i = 0; i < totalNum; i++)
    {
        printf("%d", pancakes[i]);
    }
}
