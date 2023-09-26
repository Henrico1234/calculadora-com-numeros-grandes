#include <stdio.h>
#include <string.h>

//função que removera os zeros a esquerda
void removezeros(char c[])
{

    int i = 0, j = 0, x0 = 0;
    int tam = strlen(c);
    for (i = 0; i < tam; i++)
    {
    // ao achar um numero diferente de 0 a variavel x0 fica igual a 1
        if (c[i] != '0')
        {
            x0 = 1;
            break;
        }
    }

    if (x0)
    {
    /* caso tenha 0 ele entrara nesse if e passara os caracteres da antiga string pra essa
     porém sem os zeros a esquerda*/
        for (; i < tam; i++)
        {
            c[j++] = c[i];
        }
        c[j] = '\0'; 
    }
    else
    {
        c[0] = '\0';
    }
}
//função de somas
void soma(char a[], char b[], char c[])

{
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0;
    int carry = 0;
    int x, y, z;
    char aux;
    /*aqui é um laço que começa no final da string e transoforma o caractere em um int usando
    tabela ASCII, e faz a soma juntamante com o carry que é um emprestimo caso seja necessario*/
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
    //inverte a string resutado porque começamos no final da string porém armazenamos no inicio 
    int p = k - 1;
    int q = 0;
    for (; q < p; p--, q++)
    {
        aux = c[q];
        c[q] = c[p];
        c[p] = aux;
    }
    c[k] = '\0'; // para sinalizar o final da string
}
//função de subtração 
void sub(char a[], char b[], char c[])
{
    int tamanhoa = strlen(a);
    int tamanhob = strlen(b);

    int max = (tamanhoa > tamanhob) ? tamanhoa : tamanhob;

    int k = max;
    int borrow = 0;
    int x, y, z;

     // compara para testar se os numeros são iguais e ja retornar o resultado 0
        if (strcmp(a,b) == 0){
        c[0]= '0';
        c[1]= '\0';
        return;
    }  
     //teste se é negativo para no final colocarmos o sinal caso negativo vire igual a 1
    int neg = 0;
    if (tamanhoa < tamanhob || (tamanhoa == tamanhob && strcmp(a, b) < 0))
    {
        neg = 1;
    }
    for (int i = 0; i < max; i++)
    {
        //subtraindo tbm usando a tebela ASCII, para tranformar um caractere em int 
        x = (i < tamanhoa) ? a[tamanhoa - i - 1] - '0' : 0;
        y = (i < tamanhob) ? b[tamanhob - i - 1] - '0' : 0;
        /*operaçoes para ambos os casos, sendo negativo ou não, e não se faz necessario
        inverter a string pois ja armazenei o resultado no lugar correto
        borrow é um emprestimo feito quando necessario*/
        if (neg)
        {
            z = y - x - borrow;

            if (y - borrow < x)
            {
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            if (z < 0)
            {
                z += 10;
                borrow = 1;
            }
            c[k - i - 1] = z + '0';//armazenado no lugar correto
        }
        else
        {
            z = x - y - borrow;
            if (x - borrow < y)
            {
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            if (z < 0)
            {
                z += 10;
                borrow = 1;
            }
            c[k - i - 1] = z + '0';//armazenado no lugar correto
        }

    }
    c[max] = '\0';// finalaziando a string resultado
    removezeros(c); //removendo zeros quando necessario
   
    // colocando o sinal '-'no primiero digito da string, quando negativo for igual 1,
    if (neg)
    {
        int res = strlen(c);
        for (int j = res; j >= 0; j--)
        {
            c[j + 1] = c[j];
        }
        c[0] = '-';
    }
}
//função de multiplicação
void mult(char a[], char b[], char c[])
{
    int tamanhoa = strlen(a);
    int tamanhob = strlen(b);
    int tamanhoc = tamanhob + tamanhoa;
    int resultado[tamanhoc];
    int carry = 0;
    int soma;
    // caso as string 'a' ou 'b' seja 0 ja retorna 0
     if(a[0] == '0'|| b[0] == '0'){
        c[0]= '0';
        c[1]= '\0';
        return;
         }
    // defini todas as posições de "resultado" para 0
    memset(resultado, 0, sizeof(resultado));

    /* laço que realiza as operaçoes de multplicação também usando tabela 
     ASCII, armazena em um vetor resultado dps soma '0' para novamente transformar
    em string, porem armazena de forma inversa, assim como na soma */
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
    // invertendo a string para que esteja na ordem correta 
    int p = tamanhoc - 1;
    int q = 0;
    for (; q < p; p--, q++)
    {
        int aux = c[q];
        c[q] = c[p];
        c[p] = aux;
    }
    // caso tenha zeros a esquerda, chama a função remove zeros
    if (c[0] == '0')
    {
        removezeros(c);
    }
    c[tamanhoc + 1] = '\0'; // finalizar a string 
}

/* aqui é a main onde será declarado o numero de operações e quais operações, e os numeros
que serão usados nelas */
int main()
{
    int n, i;
    char a[502], b[502], c[10000];
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        // perguntando os numeros e a operação
        scanf("%s", a);
        scanf("%s", b);
        int o;
        scanf("%d", &o);
        if (o == 1)
        {
            soma(a, b, c);//chamando a função
            printf("%s\n", c);
        }

        if (o == 2)
        {
            sub(a, b, c);//chamando a função
            printf("%s\n", c);
        }
        
        if (o == 3)
        { 
            mult(a, b, c);//chamando a função
            printf("%s\n", c);
            }
    }
    return 0;    
 }
 