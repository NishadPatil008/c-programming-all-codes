#include <stdio.h>
#include <string.h> // ✅ Needed for strlen()

int max = 100;
int top = -1;
char stack[50];

int main()
{
    char arr[] = "(a+(b*c)/(d-e))"; // ✅ Only one declaration
    char opp[50];
    int n = strlen(arr), count = 0;
    char perfix_arr[50];

    // Reverse and swap brackets
    for (int i = 0; i < n; i++)
        perfix_arr[i] = arr[i];

    for (int i = n - 1; i >= 0; i--)
    {
        if (perfix_arr[i] == '(')
            arr[n - i - 1] = ')'; // ✅ Corrected index
        else if (perfix_arr[i] == ')')
            arr[n - i - 1] = '(';
        else
            arr[n - i - 1] = perfix_arr[i];
    }

    // Infix to Postfix (on reversed expression)
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z'))
        {
            opp[count++] = arr[i]; // adding
        }
        else
        {
            if (arr[i] == '+' || arr[i] == '-')
            {
                while (top != -1 && stack[top] != '(')
                {
                    opp[count++] = stack[top--]; // pop and adding
                }
                stack[++top] = arr[i]; // push
            }
            else if (arr[i] == '*' || arr[i] == '/')
            {
                while (top != -1 && (stack[top] == '*' || stack[top] == '/' || stack[top] == '^'))
                {
                    opp[count++] = stack[top--]; // pop and adding
                }
                stack[++top] = arr[i]; // push
            }
            else if (arr[i] == '^')
            {
                while (top != -1 && stack[top] == '^') // ✅ Added top check
                {
                    opp[count++] = stack[top--]; // pop and adding
                }
                stack[++top] = arr[i]; // push
            }
            else if (arr[i] == '(')
            {
                stack[++top] = arr[i]; // push
            }
            else if (arr[i] == ')')
            {
                while (top != -1 && stack[top] != '(') // ✅ Added top check
                {
                    opp[count++] = stack[top--]; // pop and adding
                }
                if (top != -1) top--; // pop '('
            }
        }
    }

    while (top != -1)
    {
        opp[count++] = stack[top--]; // pop remaining elements
    }

    // ✅ Postfix output (from reversed infix)
    printf("Postfix: ");
    for (int i = 0; i < count; i++)
        printf("%c", opp[i]);
    printf("\n");

    // ✅ Prefix output (reverse of postfix)
    printf("Prefix: ");
    for (int i = count - 1; i >= 0; i--)
        printf("%c", opp[i]);
    printf("\n");

    return 0;
}