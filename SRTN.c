#include <stdio.h>
// nome: Orion Jorjuan 


/*

Exemplo de execução
Entrar com o número de processos:
4
enter timpo de chegada
0
1
2
3
enter tempo de estouro
8
4
9
5

Tempo médio de espera = 6.500.000
Tempo médio de retorno = 13,000000


*/





int main() 
{
 int a[10],b[10],x[10],i,j,smallest,count=0,time,n;
 double avg=0,tt=0,end;
  printf("digite o número total de processos:\n");
  scanf("%d",&n); 
 printf("digite tempo de chegada\n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("digite o tempo de estouro\n");
 for(i=0;i<n;i++)
 scanf("%d",&b[i]); 
 for(i=0;i<n;i++)
 x[i]=b[i];

  b[9]=9999;
  
 for(time=0;count!=n;time++)
 {
   smallest=9;
  for(i=0;i<n;i++)
  {
   if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
   smallest=i;
  }
  b[smallest]--;
  if(b[smallest]==0)
  {
   count++;
   end=time+1;
   avg=avg+end-a[smallest]-x[smallest];
   tt= tt+end-a[smallest];
  }
 }
 printf("\n\nTempo médio de espera = %lf\n",avg/n);
    printf("Tempo médio de retorno = %lf",tt/n);
    return 0;
}
