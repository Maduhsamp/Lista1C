#include <stdio.h>

#include <stdlib.h>

#include<malloc.h>

#include<stdbool.h>

#include<locale.h>



typedef int TipoChave;



typedef struct{

    TipoChave chave;

}Registro;



typedef struct aux{

    Registro r;

    struct aux* prox;

}Elemento;



typedef Elemento *PONT;



typedef struct{

    PONT topo;

}Pilha;



void InicializarPilha(Pilha *p){

    p->topo=NULL;

}



int Tamanho(Pilha *p){

    PONT var=p->topo;

    int tam=0;

    while(var!=NULL){

        tam++;

        var=var->prox;

    }

    return tam;

}



bool PilhaVazia(Pilha *p){

    if(p->topo==NULL)

        return true;

    return false;

}



void ImprimirPilha(Pilha *p){

    PONT var=p->topo;

    printf("\n\n*************PILHA******************\n\n");

    while(var!=NULL){

        printf("\t %d \n",var->r.chave);

        var=var->prox;

    }

}



bool PUSH(Pilha *p,Registro r){

    PONT NovaPilha=(PONT)malloc(sizeof(Elemento));

    NovaPilha->r=r;

    NovaPilha->prox=p->topo;

    p->topo=NovaPilha;

    return true;

}



bool POP(Pilha *p, Registro *r, Pilha *q){

    if(p->topo==NULL)

        return false;

    *r=p->topo->r;

    PONT limpar=p->topo;

    p->topo=p->topo->prox;

}

bool Transferir(Pilha *p, Registro *r, Pilha *q){
	
	if(p->topo==NULL)

        return false;

    *r=p->topo->r;
    
    PUSH(Pilha *q, Registro r);

    PONT limpar=p->topo;

    p->topo=p->topo->prox;
}



void ReinicializarPilha(Pilha *p){

    PONT limpar;

    PONT pos=p->topo;

    while(pos!=NULL){

        limpar=pos;

        pos=pos->prox;

        free(limpar);

    }

    p->topo=NULL;

}


int main()

{

    setlocale(LC_ALL,"Portuguese");

    Pilha p;

    char sair,op;

    int opcao=0;

    TipoChave ch;

    Registro r;







    do{

        printf("1- Criar PILHA de alunos: \n");

        printf("2- Inserir um elemento na PILHA: \n");

       printf("3- Imprimir a PILHA: \n");

       printf("4- Excluir um elemento da PILHA: \n");



        printf("Digite a opção: \n");

        scanf("%d",&opcao);

        printf("\n==================================\n");

        switch(opcao){

            case 1:

                   InicializarPilha(&p);

                   break;

            case 2:

                 do{

                    printf("\nDigite a chave: ");

                    scanf("%d",&r.chave);

                   PUSH(&p,r);

                    printf("\nDeseja digitar mais elementos (s/n)? ");

                    fflush(stdin);

                    scanf("%c",&op);

                 }while(op!='n');

                    break;





            case 3:

                    ImprimirPilha(&p);

                    break;

            case 4:

                   POP(&p,&r);

                    break;



        }

        printf("\n\n==================================\n\n");

        fflush(stdin);

        printf("Deseja sair do programa (s/n): \n");

        scanf("%c",&sair);

        printf("\n\n==================================\n\n");

    }while(sair!='s');

    return 0;

}
