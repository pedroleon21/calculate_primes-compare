#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ANSI_COLOR_GREEN   "\x1b[32m"

#define ANSI_COLOR_RESET   "\x1b[0m"

int is_prime(long long num)
{
    if(num < 1) return  0;

    for(long long i = 2; i*i <= num ;i++){
        if(!(num % i))
            return 0;
    }
    return 1;
}

FILE * open_file(char* arquivo, char * modo){
    return fopen(arquivo,modo);
}

int main()
{
    char input[10000];

    long long num = 0;

    FILE *f = open_file("size.txt","r");
    fscanf(f,"%lli",&num);

    fclose(open_file("testc.txt","w"));

    long double total=0;
    for(long long i=0; i<num ;i++)
    {
        clock_t inicio = clock();
        if(is_prime(i)){
            printf(ANSI_COLOR_GREEN "\n%lli" ANSI_COLOR_RESET,i);
            FILE * file = open_file("testc.txt","a");
            fprintf(file, "%lli\n",i);
            fclose(file);
        }else
            printf("\n%lli",i);
        clock_t fim = clock();
        total += (long double)(fim - inicio)/CLOCKS_PER_SEC;
    }
    printf("\n Total: %Lf", total);
    return 0;
}