//5.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char op[2], arg1[5], arg2[5], result[5];
void main()

{
    FILE *fp1, *fp2;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    while (!feof(fp1))
    {

        fscanf(fp1, "%s%s%s%s", result, arg1, op, arg2);
        printf("res =%s arg1=%s op=%s arg2=%s\n", result, arg1, op, arg2);
        fprintf(fp2, "\nMOV R0,%s", arg1);
        switch (op[0])
        {
        case '+':
            fprintf(fp2, "\nADD R0,%s\nMOV %s,R0\n", arg2, result);
            break;
        case '-':
            fprintf(fp2, "\nSUB R0,%s\nMOV %s,R0\n", arg2, result);
            break;
        case '*':
            fprintf(fp2, "\nMUL R0,%s\nMOV %s,R0\n", arg2, result);
            break;
        case '/':
            fprintf(fp2, "\nDIV R0,%s\nMOV %s,R0\n", arg2, result);
            break;
        case '=':
            fprintf(fp2, "\nMOV %s,R0\n", result);
            break;
        }
    }
    fclose(fp1);
    fclose(fp2);
}
