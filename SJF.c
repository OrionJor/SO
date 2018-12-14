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

Tempo médio de espera = 0.33
Tempo médio de retorno = 1.33


*/


void main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Digite o número total de processos:");
    scanf("%d",&n);
 
    printf("\ndigite o tempo de estouro:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contém o número do processo
    }
 
    //ordenação do tempo na ordem crescente usando seleção
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //o tempo de espera pelo primeiro processo será zero
 
    //calcular o tempo de espera
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //tempo médio de espera
    total=0;
 
    printf("\nProcessos\t  Tempo de estrouro   \t Tempo de espera\tTempo de resposta");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nTempo Médio de Espera=%f",avg_wt);
    printf("\nTempo Médio de Retorno=%f\n",avg_tat);
}
