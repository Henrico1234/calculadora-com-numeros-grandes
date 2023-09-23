#include <stdio.h>
#include <string.h>

void removezeros(char strc[], char dest[])
{
    int tamanhoc = strlen(strc);
    int i = 0;
    int j = 0;
    if (strc[i] == '-')
    {
        dest[j++] = strc[i++];
    }
    for (i = 1; i < tamanhoc && strc[i] == '0'; i++)
    {
    }
    for (; i < tamanhoc; i++)
    {
        dest[j++] = strc[i];
    }
    if (j == 1 && dest[0] == '-')
    {
        dest[j++] = '0';
    }
    dest[j] = '\0';
}
void soma(char a[], char b[], char c[])
{
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0;
    int carry = 0;
    int x, y, z;
    char aux;

    while (i >= 0 || j >= 0 || carry)
    {
        x = (i >= 0) ? (a[i] - '0') : 0;
        y = (j >= 0) ? (b[j] - '0') : 0;
        z = x + y + carry;
        carry = z / 10;
        c[k++] = (z % 10) + '0';
        if (i >= 0)
            i--;
        if (j >= 0)
            j--;
    }
    int p = k - 1;
    int q = 0;
    for (; q < p; p--, q++)
    {
        aux = c[q];
        c[q] = c[p];
        c[p] = aux;
    }
    c[k] = '\0';
}

void sub(char a[], char b[], char c[])
{
    int tamanhoa = strlen(a);
    int tamanhob = strlen(b);

    int max = (tamanhoa > tamanhob) ? tamanhoa : tamanhob;

    if (tamanhob < tamanhoa)
    {

        for (int i = tamanhoa, j = tamanhob; i >= 0; i--, j--)
        {
            if (j < 0)
            {
                b[i] = '0';
            }
            else
            {
                b[i] = b[j];
            }
        }
    }
    if (tamanhoa < tamanhob)
    {

        for (int i = tamanhob, j = tamanhoa; i >= 0; i--, j--)
        {
            if (j < 0)
            {
                a[i] = '0';
            }
            else
            {
                a[i] = a[j];
            }
        }
    }
    int i = max - 1;
    int j = max - 1;
    int k = 0;
    int borrow = 0;
    int x, y, z;

    int comparacao = strcmp(a, b);
    if (comparacao < 0)
    {
        c[k++] = '-';
        char aux[1000];
        strcpy(aux, a);
        strcpy(a, b);
        strcpy(b, aux);
    }
    else if (comparacao == 0)
    {

        c[k++] = '0';
    }

    while (i >= 0 || j >= 0 || borrow)
    {
        x = (i >= 0) ? (a[i] - '0' - i) : 0;
        y = (j >= 0) ? (b[j] - '0' - j) : 0;
        z = x - y - borrow;
        if (z < 0)
        {
            z += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        c[k++] = z + '0';
        if (i >= 0)
            i--;
        if (j >= 0)
            j--;
    }

    int p = k - 1;
    int q = 0;
    for (; q < p; p--, q++)
    {
        int aux = c[q];
        c[q] = c[p];
        c[p] = aux;
    }

    if (c[k - 1] == '-')
    {
        for (int p = k - 1; p >= 0; p--)
        {
            c[p + 1] = c[p];
        }
        c[0] = '-';
    }
    c[k] = '\0';
    removezeros(c, c);
    if (c[0] == '\0')
    {
        strcpy(c, "0");
    }
}
void mult(char a[], char b[], char c[])
{

    int tamanhoa = strlen(a);
    int tamanhob = strlen(b);
    int tamanhoc = tamanhob + tamanhoa;
    int resultado[tamanhoc];
    int carry = 0;
    int soma;

        if(a == '0'|| b == '0'){
        c[0] = "0";
        c[tamanhoc + 1] = '\0';
    }
    
    memset(resultado, 0, sizeof(resultado));

    for (int i = 0; i < tamanhoa; i++)
    {
        for (int j = 0; j < tamanhob; j++)
        {
            int x = a[tamanhoa - i - 1] - '0';
            int y = b[tamanhob - j - 1] - '0';
            resultado[i + j] += x * y;
        }
    }
    for (int i = 0; i < tamanhoc; i++)
    {
        soma = resultado[i] + carry;
        c[i] = (soma % 10) + '0';
        carry = soma / 10;
    }

    int p = tamanhoc - 1;
    int q = 0;
    for (; q < p; p--, q++)
    {
        int aux = c[q];
        c[q] = c[p];
        c[p] = aux;
    }
    if (c[0] == '0')
    {
        removezeros(c, c);
    }
    for (int i = 0; tamanhoc > 0 && c[i] == '0'; i++)
    {
        tamanhoc--;
    }
    c[tamanhoc + 1] = '\0';
}

int main()
{
    int n, i;
    char a[502], b[502], c[10000];
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        scanf("%s", a);
        scanf("%s", b);
        int o;
        scanf("%d", &o);
        if (o == 1)
        {
            soma(a, b, c);
            printf("%s\n", c);
        }

        if (o == 2)
        {
            sub(a, b, c);
            printf("%s\n", c);
        }
        if (o == 3)
        {
            mult(a, b, c);
            printf("%s\n", c);
        }
    }
    return 0;
}
