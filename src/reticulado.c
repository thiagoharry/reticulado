/*2:*/
#line 111 "reticulado.tex"

#include "reticulado.h"
/*43:*/
#line 923 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#include <math.h> 
#endif
/*:43*//*53:*/
#line 1183 "reticulado.tex"

#include <stdlib.h> 
/*:53*/
#line 113 "reticulado.tex"



/*16:*/
#line 442 "reticulado.tex"

#if defined(NUMERO_EH_BN)
static BN_CTX*bn_context;
#endif
/*:16*//*66:*/
#line 1435 "reticulado.tex"

static bool(*funcoes_multiplicacao_matricial[])(struct matriz*,
struct matriz*,
struct matriz*)= 
{

NULL
};
/*:66*//*67:*/
#line 1454 "reticulado.tex"

static bool(*predicado_multiplicacao_matricial[])(struct matriz*,
struct matriz*,
struct matriz*)= 
{

NULL
};
/*:67*/
#line 116 "reticulado.tex"

/*52:*/
#line 1135 "reticulado.tex"

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
if(i==j){
numero_de_int(le_matriz(nova,i,j),1);
}
else{
numero_de_int(le_matriz(nova,i,j),0);
}
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
/*:52*//*63:*/
#line 1371 "reticulado.tex"

bool multiplica_simples_matriz(struct matriz*A,struct matriz*B,
struct matriz*C);
/*:63*/
#line 117 "reticulado.tex"

/*19:*/
#line 473 "reticulado.tex"

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
/*:19*//*21:*/
#line 508 "reticulado.tex"

#if defined(NUMERO_EH_BN)
void multiplica_numero(numero r,numero a,numero b){
BN_mul(r,a,b,bn_context);
}
void divide_numero(numero r,numero a,numero b){
BN_div(r,NULL,a,b,bn_context);
}
#endif
/*:21*//*24:*/
#line 554 "reticulado.tex"

#if defined(NUMERO_EH_BN)
void inverso_numero_real(numero_real r,numero_real a){
numero_real um;
inicializa_numero_real(um);
numero_real_de_int(um,1);
divide_numero_real(r,um,a);
finaliza_numero_real(um);
}
#endif
/*:24*//*28:*/
#line 633 "reticulado.tex"

#if defined(NUMERO_EH_MPZ)
void numero_de_numero_real(numero n,numero_real r){
mpz_t aux;
mpz_init(aux);
mpq_get_num(n,r);
mpq_get_den(aux,r);
mpz_tdiv_q(n,n,aux);
mpz_clear(aux);
}
#endif
/*:28*//*34:*/
#line 749 "reticulado.tex"

#if defined(NUMERO_EH_MPZ) || defined(NUMERO_EH_MPQ)
#if __SIZEOF_INT__ >  4
int __numero_real_pra_int(numero_real r){
mpz_t aux,a;
int ret;
mpz_init(aux);
mpz_init(a);
mpq_get_num(a,r);
mpq_get_den(aux,r);
mpz_tdiv_q(a,a,aux);
ret= (int)mpz_get_ui(a);
mpz_clear(aux);
mpz_clear(a);
return ret;
}
#endif
#endif
/*:34*//*37:*/
#line 802 "reticulado.tex"

#if defined(NUMERO_EH_BN)
int numero_real_pra_int(numero_real r){
int ret;
numero aux;
inicializa_numero(aux);
numero_de_numero_real(aux,r);
ret= numero_pra_int(aux);
finaliza_numero(aux);
return ret;
}
#endif
/*:37*//*42:*/
#line 891 "reticulado.tex"

#if defined(NUMERO_EH_BN)
double numero_real_pra_double(numero_real r){
BIGNUM*divisao,*resto,*dividendo;
int mod;
double frac;
bool negative= BN_is_negative(r);
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
return(negative)?(-frac):(frac);
}
#endif
/*:42*//*48:*/
#line 995 "reticulado.tex"

#if defined(NUMERO_EH_BN)
int compara_numero_numero_real(numero a,numero_real b){
numero_real aux;
int ret;
inicializa_numero_real(aux);
numero_real_de_numero(aux,a);
ret= compara_numero_real(aux,b);
finaliza_numero_real(aux);
return ret;
}
#endif
/*:48*//*55:*/
#line 1203 "reticulado.tex"

struct matriz*nova_matriz(int linha,int coluna,numero*valores){
return nova_matriz_aux(linha,coluna,valores,0);
}
struct matriz*nova_matriz_nula(int linha,int coluna){
return nova_matriz_aux(linha,coluna,NULL,0);
}
struct matriz*nova_matriz_identidade(int dim){
return nova_matriz_aux(dim,dim,NULL,1);
}
/*:55*//*57:*/
#line 1226 "reticulado.tex"

void destroi_matriz(struct matriz*A){
int i,total= A->linhas*A->colunas;
for(i= 0;i<total;i++){
finaliza_numero(A->valores[i]);
}
free(A->valores);
free(A);
}
/*:57*//*59:*/
#line 1254 "reticulado.tex"

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
numero_real_de_numero(nova->valores[i],A->valores[i]);
}
return nova;
}
/*:59*//*60:*/
#line 1280 "reticulado.tex"

void destroi_matriz_real(struct matriz_real*A){
int i,total= A->linhas*A->colunas;
for(i= 0;i<total;i++){
finaliza_numero_real(A->valores[i]);
}
free(A->valores);
free(A);
}
/*:60*//*62:*/
#line 1314 "reticulado.tex"

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
/*:62*//*64:*/
#line 1383 "reticulado.tex"

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
/*:64*//*69:*/
#line 1479 "reticulado.tex"

bool multiplica_matriz(struct matriz*A,struct matriz*B,
struct matriz*C){
int i;
for(i= 0;funcoes_multiplicacao_matricial[i]!=NULL;i++)
if(predicado_multiplicacao_matricial[i](A,B,C))
return funcoes_multiplicacao_matricial[i](A,B,C);
return multiplica_simples_matriz(A,B,C);
}
/*:69*//*71:*/
#line 1586 "reticulado.tex"

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
/*:71*//*73:*/
#line 1648 "reticulado.tex"

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
/*:73*//*75:*/
#line 1678 "reticulado.tex"

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
/*:75*//*77:*/
#line 1743 "reticulado.tex"

bool resolve_equacao_linear(struct matriz_real*resposta,
struct matriz*A,struct matriz*b){
struct matriz_real*U,*b_r;
numero_real n;
int i,j;

if(resposta->colunas!=1||b-> colunas!=1||
resposta->linhas!=A->linhas||b->linhas!=A->linhas||
A->linhas!=A->colunas)
return false;
U= nova_matriz_real(A);
b_r= nova_matriz_real(b);
inicializa_numero_real(n);
if(U==NULL||b_r==NULL)
return false;

for(j= 0;j<U->colunas;j++){

if(numero_real_pra_double(le_matriz(U,j,j))==0.0){
int k;
for(k= j+1;k<U->linhas;k++){
if(numero_real_pra_double(le_matriz(U,k,j))!=0.0){
if(!troca_linha_matriz_real(U,k,j)||
!troca_linha_matriz_real(b_r,k,j)){
destroi_matriz_real(U);
destroi_matriz_real(b_r);
finaliza_numero_real(n);
return false;
}
break;
}

if(numero_real_pra_double(le_matriz(U,j,j))==0.0){
destroi_matriz_real(U);
destroi_matriz_real(b_r);
finaliza_numero_real(n);
return false;
}
}
}
for(i= j+1;i<U->linhas;i++){

if(numero_real_pra_double(le_matriz(U,i,j))!=0.0){
neg_numero_real(n,le_matriz(U,i,j));
divide_numero_real(n,n,le_matriz(U,j,j));
soma_linha_e_multiplo_matriz_real(U,i,j,n);
soma_linha_e_multiplo_matriz_real(b_r,i,j,n);
}
}
}


for(i= resposta->linhas-1;i>=0;i--){
for(j= resposta->linhas-1;j> i;j--){
multiplica_numero_real(n,le_matriz(U,i,j),
le_matriz(resposta,j,0));
subtrai_numero_real(le_matriz(b_r,i,0),le_matriz(b_r,i,0),n);
}
inverso_numero_real(n,le_matriz(U,i,i));
multiplica_numero_real(le_matriz(resposta,i,0),n,
le_matriz(b_r,i,0));
}

destroi_matriz_real(U);
destroi_matriz_real(b_r);
finaliza_numero_real(n);
return true;
}
/*:77*/
#line 118 "reticulado.tex"

/*:2*/
