/*2:*/
#line 111 "reticulado.tex"

#include "reticulado.h"
/*33:*/
#line 743 "reticulado.tex"

#include <stdlib.h> 
/*:33*/
#line 113 "reticulado.tex"



/*21:*/
#line 459 "reticulado.tex"

#if defined(NUMERO_EH_BN)
static BN_CTX*bn_context;
#endif
/*:21*//*46:*/
#line 995 "reticulado.tex"

static bool(*funcoes_multiplicacao_matricial[])(struct matriz*,
struct matriz*,
struct matriz*)= 
{

NULL
};
/*:46*//*47:*/
#line 1014 "reticulado.tex"

static bool(*predicado_multiplicacao_matricial[])(struct matriz*,
struct matriz*,
struct matriz*)= 
{

NULL
};
/*:47*/
#line 116 "reticulado.tex"

/*32:*/
#line 697 "reticulado.tex"

struct matriz*nova_matriz_aux(int linha,int coluna,numero*valores,
int t){
struct matriz*nova;
nova= (struct matriz*)malloc(sizeof(struct matriz));
if(nova!=NULL){
int i,j,total= linha*coluna;
nova->linhas= linha;
nova->colunas= coluna;
nova->valores= (numero*)malloc(sizeof(numero)*total);
if(nova->valores==NULL){
free(nova);
return NULL;
}
if(valores!=NULL){
for(i= 0;i<total;i++){
inicializa_numero(nova->valores[i]);
copia_numero(nova->valores[i],valores[i]);
}
}
else if(linha==coluna&&t==1){
for(i= 0;i<linha;i++)
for(j= 0;j<coluna;j++){
inicializa_numero(le_matriz(nova,i,j));
if(i==j)
escreve_matriz_int(nova,i,j,1);
else
escreve_matriz_int(nova,i,j,0);
}
}
else{
for(i= 0;i<total;i++){
inicializa_numero(nova->valores[i]);
numero_de_int(nova->valores[i],0);
}
}
}
return nova;
}
/*:32*//*43:*/
#line 931 "reticulado.tex"

bool multiplica_simples_matriz(struct matriz*A,struct matriz*B,
struct matriz*C);
/*:43*/
#line 117 "reticulado.tex"

/*18:*/
#line 402 "reticulado.tex"

#if defined(NUMERO_EH_BN)
bool numero_real_eh_igual_int(numero_real r,int a){
BIGNUM*tmp;
int mod;
bool result;
tmp= BN_new();
BN_set_word(tmp,a);
BN_mul_word(tmp,1000000000000000000lu);
result= (BN_cmp(tmp,r)==0);
BN_clear_free(tmp);
return result;
}
#endif
/*:18*//*23:*/
#line 479 "reticulado.tex"

bool inicializa_api_reticulado(void){
#if defined(NUMERO_EH_BN)
bn_context= BN_CTX_new();
if(bn_context==NULL)
return false;
#endif
return true;
}
void finaliza_api_reticulado(void){
#if defined(NUMERO_EH_BN)
BN_CTX_free(bn_context);
#endif
}
/*:23*//*25:*/
#line 510 "reticulado.tex"

#if defined(NUMERO_EH_BN)
void multiplica_numero(numero r,numero a,numero b){
BN_mul(r,a,b,bn_context);
}
#endif
/*:25*//*27:*/
#line 530 "reticulado.tex"

#if defined(NUMERO_EH_BN)
double numero_real_pra_double(numero_real r){
BIGNUM*divisao,*resto,*dividendo;
int mod;
double frac;
divisao= BN_new();
resto= BN_new();
dividendo= BN_new();
BN_set_word(dividendo,1000000000000000000lu);
BN_div(divisao,resto,r,dividendo,bn_context);
frac= (((double)BN_get_word(resto))/1000000000000000000.0);
if(BN_num_bytes(divisao)> sizeof(unsigned long)){
BN_clear_free(divisao);
BN_clear_free(resto);
BN_clear_free(dividendo);
return INFINITY;
}
frac+= ((double)BN_get_word(divisao));
BN_clear_free(divisao);
BN_clear_free(resto);
BN_clear_free(dividendo);
return frac;
}
#endif
/*:27*//*35:*/
#line 763 "reticulado.tex"

struct matriz*nova_matriz(int linha,int coluna,numero*valores){
return nova_matriz_aux(linha,coluna,valores,0);
}
struct matriz*nova_matriz_nula(int linha,int coluna){
return nova_matriz_aux(linha,coluna,NULL,0);
}
struct matriz*nova_matriz_identidade(int dim){
return nova_matriz_aux(dim,dim,NULL,1);
}
/*:35*//*37:*/
#line 786 "reticulado.tex"

void destroi_matriz(struct matriz*A){
int i,total= A->linhas*A->colunas;
for(i= 0;i<total;i++){
finaliza_numero(A->valores[i]);
}
free(A->valores);
free(A);
}
/*:37*//*39:*/
#line 814 "reticulado.tex"

struct matriz_real*nova_matriz_real(struct matriz*A){
int i,total= A->linhas*A->colunas;
struct matriz_real*nova;
nova= (struct matriz_real*)malloc(sizeof(struct matriz_real));
if(nova==NULL)
return NULL;
nova->linhas= A->linhas;
nova->colunas= A->colunas;
nova->valores= (numero_real*)malloc(sizeof(numero_real)*total);
if(nova->valores==NULL){
free(nova);
return NULL;
}
for(i= 0;i<total;i++){
inicializa_numero_real(nova->valores[i]);
copia_numero_pra_real(nova->valores[i],A->valores[i]);
}
return nova;
}
/*:39*//*40:*/
#line 840 "reticulado.tex"

void destroi_matriz_real(struct matriz_real*A){
int i,total= A->linhas*A->colunas;
for(i= 0;i<total;i++){
finaliza_numero_real(A->valores[i]);
}
free(A->valores);
free(A);
}
/*:40*//*42:*/
#line 874 "reticulado.tex"

bool soma_matriz(struct matriz*A,struct matriz*B,struct matriz*C){
int i,total= A->linhas*A->colunas;
if(A->linhas!=B->linhas||A->linhas!=C->linhas)
return false;
if(A->colunas!=B->colunas||A->linhas!=C->colunas)
return false;
for(i= 0;i<total;i++)
soma_numero(A->valores[i],B->valores[i],C->valores[i]);
return true;
}
/*:42*//*44:*/
#line 943 "reticulado.tex"

bool multiplica_simples_matriz(struct matriz*A,struct matriz*B,
struct matriz*C){
struct matriz*resultado= A;
if(A->linhas!=B->linhas||A->colunas!=B->colunas)
return false;
if(A==B||A==C){
resultado= nova_matriz_nula(A->linhas,A->colunas);
if(resultado==NULL)
return false;
}
{
int m,n,p;
numero tmp;
inicializa_numero(tmp);
for(m= 0;m<resultado->linhas;m++)
for(p= 0;p<resultado->colunas;p++){
numero_de_int(le_matriz(resultado,m,p),0);
for(n= 0;n<B->colunas;n++){
multiplica_numero(tmp,le_matriz(B,m,n),le_matriz(C,n,p));
soma_numero(le_matriz(resultado,m,p),
le_matriz(resultado,m,p),tmp);
}
}
finaliza_numero(tmp);
}
if(resultado!=A){
int total= A->linhas*A->colunas;
memcpy(A->valores,resultado->valores,sizeof(numero)*total);
destroi_matriz(resultado);
}
return true;
}
/*:44*//*49:*/
#line 1039 "reticulado.tex"

bool multiplica_matriz(struct matriz*A,struct matriz*B,
struct matriz*C){
int i;
for(i= 0;funcoes_multiplicacao_matricial[i]!=NULL;i++)
if(predicado_multiplicacao_matricial[i](A,B,C))
return funcoes_multiplicacao_matricial[i](A,B,C);
return multiplica_simples_matriz(A,B,C);
}
/*:49*//*51:*/
#line 1146 "reticulado.tex"

bool troca_linha_matriz_real(struct matriz_real*A,int pos1,int pos2){
numero_real*buffer;
if(A->linhas<=pos1||A->linhas<=pos2||pos1<0||pos2<0)
return false;
buffer= (numero_real*)malloc(sizeof(numero_real)*A->colunas);
if(buffer==NULL)
return false;
memcpy(buffer,&(le_matriz(A,pos1,0)),
sizeof(numero_real)*A->colunas);
memcpy(&(le_matriz(A,pos1,0)),&(le_matriz(A,pos2,0)),
sizeof(numero_real)*A->colunas);
memcpy(&(le_matriz(A,pos2,0)),buffer,
sizeof(numero_real)*A->colunas);
free(buffer);
return true;
}
/*:51*//*53:*/
#line 1208 "reticulado.tex"

bool multiplica_linha_matriz_real(struct matriz_real*A,int pos,
numero_real escalar){
int i;
if(A->linhas<=pos||pos<0||
numero_real_pra_double(escalar)!=3.0)
return false;
for(i= 0;i<A->colunas;i++)
multiplica_numero_real(le_matriz(A,pos,i),le_matriz(A,pos,i),
escalar);
return true;
}
/*:53*//*55:*/
#line 1238 "reticulado.tex"

bool soma_linha_e_multiplo_matriz_real(struct matriz_real*A,int pos1,
int pos2,numero_real escalar){
int i;
numero_real aux;
inicializa_numero_real(aux);
if(A->linhas<=pos1||pos1<0||A->linhas<=pos2||pos2<0)
return false;
for(i= 0;i<A->colunas;i++){
multiplica_numero_real(aux,le_matriz(A,pos2,i),escalar);
soma_numero_real(le_matriz(A,pos1,i),le_matriz(A,pos1,i),
aux);
}
finaliza_numero_real(aux);
return true;
}
/*:55*/
#line 118 "reticulado.tex"

/*:2*/
