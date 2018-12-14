#include<stdio.h>
 // nome: Orion Jorjuan 


/*

Exemplo de execução
Entrar com o número de processos:
3
enter timpo de chegada
P[1]:0
P[2]:1
P[3]:2

Tempo médio de espera = 2
Tempo médio de retorno = 5


*/




int main()
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    printf("Digite o número total de processos (máximo 20)");
    scanf("%d",&n);
 
    printf("\nInsira o tempo de interrupção do processo\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
 
    wt[0]=0;    //o tempo de espera para o primeiro processo é 0
 
    //calculando o tempo de espera
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("\nProcessos\t\tTempo de interupcao\tTempo de espera\tTempo de resposta");
 
    //cálculo do tempo de resposta
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nTempo Médio de Espera:%d",avwt);
    printf("\nTempo Médio de Retorno:%d",avtat);
 
    return 0;
}
