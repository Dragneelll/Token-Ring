/*Feito por Bruno Miguel Caregnato */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

struct nodo{
  int rede;
  struct TokenRing *valor;
  struct nodo *prox;
}elemento;

struct TokenRing{
    char token[30];
    int rede;
};

struct monitor{
    int rede;
};

struct nodo *inicio;
struct nodo *fim;
struct TokenRing *token;
struct monitor *monitor;

// Procedimento para inserção
void insere(int dado)
{
  struct nodo *pnovo;

  pnovo=(struct nodo*)malloc(sizeof(elemento));
  pnovo->rede = dado;
  pnovo->prox=NULL;

  struct nodo *atual = inicio;
  if(inicio == NULL){

     inicio = pnovo;
     pnovo->prox=pnovo;
     fim = pnovo;
     inicio->valor = NULL;

  }
  else{
	  while(atual != fim){
		  atual = atual->prox;

	  }

      atual->prox = pnovo;
      pnovo->prox=inicio;
      fim=pnovo;

  }
}

//Insercao no token
void encherToken(char texto[], int rede){

    strcpy(token->token,texto);
    token->rede = rede;
    inicio->valor = token;
    monitor->rede = inicio->rede;

}

//Busca a rede cadastrada no token
int buscaRedeToken(){

    if(inicio->rede == token->rede) return 1;
    else return 0;

}

//Passa o token de rede em rede
void passaToken(){

    inicio->valor = token;

}

//Zera o token
void zerarToken(){

    inicio->valor = NULL;
    free(token);

}

//Percorre a lista
void percorreLista(){

    inicio = inicio->prox;
    passaToken();
    int encontrouRede = buscaRedeToken();
    if(encontrouRede){
        printf("\nRede encontrada.\n");
        printf("\nMensagem do Token: %s\n",inicio->valor->token);
        zerarToken();

    }
    if(inicio->rede == monitor->rede){
        printf("O Monitor percebeu que foi feita uma volta inteira\ne nao foi encontrado token. O mesmo foi excluido!\n");
        zerarToken();
    }


}

//Verifica os dados da rede
void dadosRede(){

    printf("Rede numero: %d\n",inicio->rede);

    if(inicio->valor->token != NULL){
        printf("Token atual: %s\n",inicio->valor->token);
    }
    else printf("Token vazio esta vazio nessa rede\n");
}

//Menu de opcoes
void menu(){
     printf("1 - Ir para proxima rede\n");
     printf("2 - Dados da rede atual\n");
     printf("3 - Inserir mensagem para o token\n");
     printf("0 - Sair\n");
}

int main(){

  inicio = NULL;
  token = (struct TokenRing *)malloc(sizeof(struct TokenRing));
  monitor = (struct monitor *)malloc(sizeof(struct monitor));
  int pos;
  int qtd=0;

  printf("Digite a quantidade de redes que deseja ter: ");
  scanf("%d",&qtd);

  printf("\n");

  int i;
  for(i=1;i<=qtd;i++){
    insere(i);
  }

  printf("Voce esta na rede: %d\n",inicio->rede);
  printf("-----------------\n");
  menu();
  fflush(stdin);
  printf("Digite sua opcao:\n");
  scanf("%d",&pos);
  system("cls");

  while(pos != 0){
    switch(pos){
                //Percorre lista
        case 1: percorreLista();
                break;

                //Percorre dados da rede
        case 2: dadosRede();
                break;

                //Insere token (mensagem)
        case 3: if(inicio->valor == NULL){
                    printf("Digite a mensagem do token: ");
                    fflush(stdin);
                    char texto[30];
                    fgets(texto, 100, stdin);
                    printf("\nDigite a rede a ser enviada o token: ");
                    int rede;
                    fflush(stdin);
                    scanf("%d",&rede);
                    encherToken(texto, rede);
                }
                else printf("\nToken ja esta preenchido.\n");
                break;

    }

    printf("Voce esta na rede: %d\n",inicio->rede);
    printf("-----------------\n");
    menu();
    fflush(stdin);
    printf("Digite sua opcao:\n");
    scanf("%d",&pos);
    system("cls");
  }
}
