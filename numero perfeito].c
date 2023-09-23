#include <stdio.h>
#include <string.h>


void removezeros(char strc[], char dest[])

{
    int tamanhoc = strlen(strc);
    int i = 0;
    int j = 0;
     if (strc[i] == '-') {
        dest[j++] = strc[i++]; // Copie o sinal de negativo para o destino
    }
    for( i = 1; i < tamanhoc && strc[i] == '0'; i++){
    }
    for(; i < tamanhoc; i++){
     dest[j++] = strc[i];
    }
    if (j == 1 && dest[0] == '-'){
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
    removezeros(c, c);
     if (c[0] == '\0') {
    strcpy(c, "0");
     }

}


void sub(char a[], char b[], char c[])
{
    int tamanhoa = strlen(a);
    int tamanhob = strlen(b);

    int max = (tamanhoa > tamanhob) ? tamanhoa : tamanhob;

    if(tamanhob < tamanhoa){

        for(int i=tamanhoa,j=tamanhob;i>=0;i--,j--){
            if(j<0){
                b[i]='0'; 
            }
            else{   
                b[i] = b[j];
            }
        }
    }
    if(tamanhoa < tamanhob){

        for(int i=tamanhob,j=tamanhoa;i>=0;i--,j--){
            if(j<0){
                a[i]='0';
            }
            else{   
                a[i] = a[j];
            }
        }
    }
    int i = max - 1;
    int j = max - 1;
    int k = 0;
    int borrow = 0;
    int x, y, z;
     
    int numericComparison = strcmp(a, b);
    if (numericComparison < 0)
    {
        c[k++] = '-'; // Adicione o sinal de negativo
        // Inverta as strings a e b para garantir que a seja maior em valor absoluto
        char aux[1000];
        strcpy(aux, a);
        strcpy(a, b);
        strcpy(b, aux);
    }
    else if (numericComparison == 0)
    {
        // Caso especial: se as strings forem numericamente iguais, retorne '0'
        c[k++] = '0';
    }

    while (i >= 0 || j >= 0 || borrow)
    {
        x = (i >= 0) ? (a[i] - '0' - i)  : 0;
        y = (j >= 0) ? (b[j] - '0' - j)  : 0;
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
    if (c[0] == '\0') {
    strcpy(c, "0"); // Defina a string como "0"
}
}

int main()
{
    int n, i;
    char a[502], b[502], c[1002];
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        scanf("%s",a);
        scanf("%s",b);
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
}
return 0;
}