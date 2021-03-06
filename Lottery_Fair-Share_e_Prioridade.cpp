// Algoritmo de Prioridade, Fair-Share e Prioridade


#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class cpuschedule
{
    int n,Bu[20];
    float Twt,Awt,A[10],Wt[10],w;
public:
    //Obtendo o número de processos e tempo de burst
    void Getdata();
    //Algoritmo Fair Share
    void FS();
    //Algoritmo Prioridade
    void Prioridade();
};
// Arquivo de implementação para agendamento de Cpu

//Obtendo o número de processos e tempo de burst
void cpuschedule::Getdata()
{
    int i;
    cout<<"\nEntre com o processo:";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"\nInsira o horário de pico do processo"<<i<<"=	";
        cin>>Bu[i];
    }
}

//Fair Share Algoritimo
void cpuschedule::FS()
{
    int i,B[10];
    Twt=0.0;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst tempo de processo"<<i<<"=	";
        cout<<B[i];
    }
    Wt[1]=0;
    for(i=2; i<=n; i++)
    {
        Wt[i]=B[i-1]+Wt[i-1];
    }

    //calculando o tempo de espera
    for(i=1; i<=n; i++)
    {
        Twt=Twt+Wt[i];
    }
    Awt=Twt/n;
    cout<<"\n\nBurst tempo de processo="<<Twt;
    cout<<"\n\nEnter a prioridade do processo P="<<Awt<<""<<endl;
}
//Algoritmo de Prioridade

void cpuschedule::Prioridade()
{
    int i,B[10],P[10],j;
    w=0.0;
    int max;
    Twt=0.0;
    max=1;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst tempo de processo"<<i<<"=	";
        cout<<B[i];
        cout<<"\nEnter a prioridade do processo P"<<i<<"=	";
        cin>>P[i];
        if(max<P[i]){
            max=P[i];
        }
    }
    j=1;
    while(j<=max)
    {
        i=1;
        while(i<=n)
        {
            if(P[i]==j)
            {
                Wt[i]=w;
                w=w+B[i];
            }
            i++;
        }
        j++;
    }

    //calculando o tempo de espera
    for(i=1; i<=n; i++){
        Twt=Twt+Wt[i];
    }
    Awt=Twt/n;
    cout<<"\nTempo total de espera="<<Twt<<""<<endl;
    cout<<"\ntempo médio esperado="<<Awt<<""<<endl;
}



//opção de escalonamentos
int main()
{
    int ch,cho;
    cpuschedule c;
    do
    {
        cout<<"1.Obtendo Burst de tempo"<<endl;
        cout<<"2.Fair-Share"<<endl;
        cout<<"5.Prioridade"<<endl;
        cout<<"6.EXIT"<<endl;
        cout<<"Digite sua escolha: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            c.Getdata();
            break;
        case 2:
            cout<<"\n Algoritmo Fair-Share"<<endl;
            c.FS();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            cout<<"\n Algoritmo de Prioridade"<<endl;
            c.Prioridade();
            break;
        case 6:
            break;
        }
    }
    while(ch<=5);
}
