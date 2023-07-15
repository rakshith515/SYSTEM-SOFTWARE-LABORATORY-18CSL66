#include <stdio.h>
#include <stdlib.h>
void FIFO(char[], char[], int, int);
void lru(char[], char[], int, int);
void opt(char[], char[], int, int);
int main()
{
    int ch, YN = 1, i, length_of_string, frame_length;
    char FRAMES[10], s[25];
    printf("\n\n\tEnter the no ofempty frames: ");
    scanf("%d", &frame_length);
    printf("\n\n\tEnter the length of the string: ");
    scanf("%d", &length_of_string);
    printf("\n\n\tEnter the string: ");
    scanf("%s", s);

    for (i = 0; i < frame_length; i++)
    {
        FRAMES[i] = "#";
    }
    for (;;)
    {
        printf("\n\n\t*********** MENU ***********");
        printf("\n\n\t1:FIFO\n\n\t2:LRU\n\n\t4:EXIT");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            FIFO(s, FRAMES, length_of_string, frame_length);
            break;
        case 2:

            lru(s, FRAMES, length_of_string, frame_length);
            break;
        case 4:
            exit(0);
        }
        printf("\n\n\tDo u want to continue IF YES PRESS 1\n\n\tIF NO PRESS 0 :");
        scanf("%d", &YN);
    }
    return (0);
}
// FIFO
// i is main var, j in second var,k is counter var
void FIFO(char input[], char FRAMES[], int length_of_string, int frame_length)
{
    int i, k = 0, j, flag = 0, cnt = 1;
    printf("\n\tPAGE\t FRAMES \t FAULTS");
    for (i = 0; i < length_of_string; i++)
    {
        for (j = 0; j < frame_length; j++)
        {
            // check if the page is in the frames
            if (FRAMES[j] == input[i])
            {
                flag = 1;
                break;
            }
        }
        printf("\n\t%c\t", input[i]);
        if (flag == 0)
        {
            // add the page to the frames
            FRAMES[k] = input[i];
            k++;
            for (j = 0; j < frame_length; j++)
            {
                printf(" %c", FRAMES[j]);
            }
            printf("\tPage-fault %d", cnt);
            cnt++;
        }
        else
        {
            flag = 0;

            for (j = 0; j < frame_length; j++)
            {
                printf(" %c", FRAMES[j]);
            }
            printf("\tNo page-fault");
        }
        // in case the frame is full, the first element is removed and the new element is added to the end of the frame,by reseting k to 0
        if (k == frame_length)
            k = 0;
    }
}
// LRU #unchanged
void lru(char s[], char F[], int l, int f)
{
    int i, j = 0, k, m, flag = 0, cnt = 0, top = 0;
    printf("\n\tPAGE\t FRAMES\t FAULTS");
    for (i = 0; i < l; i++)
    {
        for (k = 0; k < f; k++)
        {
            if (F[k] == s[i])
            {
                flag = 1;
                break;
            }
        }
        printf("\n\t%c\t", s[i]);
        if (j != f && flag != 1)
        {
            F[top] = s[i];
            j++;
            if (j != f)
                top++;
        }
        else
        {
            if (flag != 1)
            {
                for (k = 0; k < top; k++)
                {
                    F[k] = F[k + 1];
                }
                F[top] = s[i];
            }
            if (flag == 1)
            {
                for (m = k; m < top; m++)
                {
                    F[m] = F[m + 1];
                }
                F[top] = s[i];
            }
        }
        for (k = 0; k < f; k++)
        {
            printf(" %c", F[k]);
        }
        if (flag == 0)
        {
            printf("\tPage-fault%d", cnt);
            cnt++;
        }
        else
            printf("\tNo page fault");
        flag = 0;
    }
}
