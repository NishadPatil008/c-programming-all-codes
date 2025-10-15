#include <stdio.h>
int max = 100;
int top = -1;
char stack[50];
int main()
{
    char arr[] = "(a+(b*c)/(d-e))";
    char arr[] = "a+b*c/d-e";
    char opp[50];
    int n = 15, count = 0;
    int printCount = n;
        int perfix_arr[50];
        for(int i = 0; i < n; i++)
            perfix_arr[i] = arr[i];
        for(int i = n-1; i >= 0; i--)
        {
            if(perfix_arr[i] == '(')
                arr[(n-i)-1] = ')';
            else if(perfix_arr[i] == ')')
                arr[(n-i)-1] = '(';
            else
                arr[(n-i)-1] = perfix_arr[i];        
        }
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= 'A' && arr[i] <= 'Z') {
            opp[count++] = arr[i];// adding
        }
        else
        {
            if (arr[i] == '+' || arr[i] == '-')
            {
                while (top != -1 && stack[top] != '(' )
                {
                    opp[count++] = stack[top--];// pop and adding
                }
                stack[++top] = arr[i]; // push
            }
            else if (arr[i] == '*' || arr[i] == '/')
            {
                while (top != -1 && (stack[top] == '*' || stack[top] == '/' || stack[top] == '^'))
                {
                    opp[count++] = stack[top--];// pop and adding
                }
                stack[++top] = arr[i]; // push
            }
            else if (arr[i] == '^')
            {
                while (stack[top] == '^')
                {
                    opp[count++] = stack[top--];// pop and adding
                }
                stack[++top] = arr[i]; // push
            }
            else if (arr[i] == '(')
            {
                stack[++top] = arr[i]; // push
                printCount -= 2;
            }
            else if (arr[i] == ')')
            {
                while (stack[top] != '(')
                {
                    opp[count++] = stack[top--];// pop and adding
                }
                top--;// pop '('
            }
        }
    }
    while (top != -1)
    {
        opp[count++] = stack[top--]; // pop remaining elements
    }
    for (int i = 0; i < printCount; i++)
        printf("%c", opp[i]);
    for (int i = printCount; i > 0; i--)
        printf("%c", opp[i]);
    return 0;
}