#define N 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char pilha[N];
static int t;

void iniciapilha (void) {
   t = 0; 
}

void empilha (char y) {
   pilha[t] = y;
   t++;
}

char desempilha (void) {
   t=t-1;
   return pilha[t];
} 

int pilhavazia (void) {
   return t <= 0;
}

int pilhacheia (void) {
   return t > N;
}


/*
Escreva uma função que receba uma string contendo uma expressão aritmética 
e retorne se ela está com a parentização correta. A função deverá verificar 
se cada “abre parênteses’” tem um “fecha parênteses” correspondente. 
Se correto, retorna 1. Exemplos:
•Correto: 
(()) 
(()())
()()
•Incorreto: 
)( 
(()( 
))((
*/
int checa_parenteses(char* string_parenteses){
   char *pilha;
   int t=0,n,i;

   iniciapilha();

      if(pilhavazia){
         return NULL;
      }

   n=strlen(string_parenteses);
   pilha = malloc(n*sizeof(char));
      
         for(i=0;string_parenteses != '\0';++i){
            
            switch (string_parenteses[i])
            {
                  case ')':
                     if(t!=0 && pilha[t-1]=='('){
                        --t;
                     }else{
                        return 0;
                     }
                  break;
            
            default:
               pilha[t++] = string_parenteses[i];
            }
         }
   free(pilha);
      
      if(t==0){
            return 1;
         }else{
            return 0;
         }
   desempilha();
}

/*
crie uma função que verifique se uma palavra é um palíndromo. retorna 1 se palíndromo
*/
int checa_palindromo(char* string_palindromo){
   iniciapilha();
   
   int i,tamanho = strlen(string_palindromo);

      if(pilhavazia){
         return NULL;
      }
         for(i=0;i<tamanho/2;i++){
            if(string_palindromo[i] != string_palindromo[tamanho -i -1]){
               return 0;
            }else{
               return 1;
            }
         }
   desempilha();
}

int main(){
char testeparenteses[]="(())";

if (checa_parenteses(testeparenteses)==1)   
  printf("parenteses estão balanceados\n");
else 
  printf("parenteses não balanceados\n");


char testepalindromo[]="osso";

if (checa_palindromo(testepalindromo)==1)   
  printf("palindromo\n");
else 
  printf("não palindromo\n");

}
