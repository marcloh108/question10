#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_valid_Parantheses(char *s)
{
    int n = 0, cap = 100;
    char *tstack = malloc(cap);

    while (*s != '\0')
    {
        switch(*s)
        {
        case '(':
        case '[':
        case '{':
            if(n + 1 >= cap)
            {
                cap *= 2;
                tstack = realloc(tstack, cap);
            }
            tstack[n++] = *s;
            break;
        case ')':
            if (tstack[--n]!='(') return false;
            break;
        default:
            return false;
        }
        s++;
    }
    return n == 0;
}
int main()
    {
    char **vbracket = "([)]";
    printf("%s\n", is_valid_Parantheses(vbracket) ? "true" : "false");
    return 0;
    }


