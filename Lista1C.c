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
    printf("\n\n******PILHA*******\n\n");
    while(var!=NULL){
        printf("\t %d \n",var->r.chave);
        var=var->prox;
    }
}
void ImprimirPilha2(Pilha *p2){
    PONT var=p2->topo;
    printf("\n\n******PILHA2*******\n\n");
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

bool POP(Pilha *p, Registro *r){
    if(p->topo==NULL)
        return false;
    *r=p->topo->r;
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

void transferirPilha(Pilha* p, Pilha* p2, Registro* r) {
    Registro s;
    if (p->topo == NULL)
        return false;
    while (p->topo != NULL) {
        *r = p->topo->r;
        s = p->topo->r;
        PUSH(p2, s);
        PONT limpar = p->topo;
        p->topo = p->topo->prox;
        free(limpar);
    }
}
void inverterPilha(Pilha* p) {
    Pilha aux;
    Registro r;
    InicializarPilha(&aux);
    while (!PilhaVazia(p)) {
        POP(p, &r);
        PUSH(&aux, r);
    }
    p->topo = aux.topo;
}

bool TamanhoElementosPilhas(Pilha* p1, Pilha* p2) {
    int tamanhoP1 = Tamanho(p1);
    int tamanhoP2 = Tamanho(p2);
    return tamanhoP1 > tamanhoP2;
}

int main()
{
    setlocale(LC_ALL,"");
    Pilha p,p2,p3;

    char sair,op;
    int opcao=0;
    TipoChave ch;
    Registro r;

    do{

        printf("1- Criar PILHA de alunos: \n");
        printf("2- Inserir um elemento na PILHA: \n");
        printf("3- Imprimir a PILHA: \n");
        printf("4- Excluir um elemento da PILHA: \n");
        printf("5- Transferir pilhas: \n");
        printf("6- Inverter Pilha: \n");
        printf("7- Ver qual pilha tem mais elementos: \n");
        printf("Digite a op??o: \n");
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
            case 5:
                InicializarPilha(&p2);
                transferirPilha(&p, &p2, &r);
                printf("\nPilha transferida com sucesso!\n");
                ImprimirPilha(&p);
                ImprimirPilha2(&p2);
                break;
            case 6:
                inverterPilha(&p);
                printf("\nPilha invertida com sucesso!\n");
                ImprimirPilha(&p);
                break;
            case 7:
                if (TamanhoElementosPilhas(&p, &p2)) {
                    printf("A primeira pilha tem mais elementos que a segunda pilha.\n");
                } else {
                    printf("A primeira pilha n?o tem mais elementos que a segunda pilha.\n");
                }
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
