/*1:*/
#line 89 "reticulado.tex"

#ifndef __RETICULADO_H_
#define __RETICULADO_H_
#ifdef __cplusplus
extern"C"{
#endif
/*19:*/
#line 422 "reticulado.tex"

#include <stdbool.h> 
/*:19*//*28:*/
#line 561 "reticulado.tex"

#include <math.h> 
/*:28*//*45:*/
#line 983 "reticulado.tex"

#include <string.h> 
/*:45*/
#line 95 "reticulado.tex"

/*3:*/
#line 146 "reticulado.tex"

#if defined(NUMERO_EH_INT)
typedef int numero;
typedef double numero_real;
#endif
#if defined(NUMERO_EH_DOUBLE)
typedef double numero;
typedef double numero_real;
#endif
/*:3*//*4:*/
#line 165 "reticulado.tex"

#if defined(NUMERO_EH_INT) || defined(NUMERO_EH_DOUBLE)
#define inicializa_numero(n)
#define finaliza_numero(n)
#define inicializa_numero_real(n)
#define finaliza_numero_real(n)
#endif
/*:4*//*5:*/
#line 179 "reticulado.tex"

#if defined(NUMERO_EH_INT) || defined(NUMERO_EH_DOUBLE)
#define soma_numero(r, a, b) (r =  a + b)
#define subtrai_numero(r, a, b) (r =  a - b)
#define multiplica_numero(r, a, b) (r =  a * b)
#define divide_numero(r, a, b) (r =  a / b)
#define soma_numero_real(r, a, b) (r =  a + b)
#define subtrai_numero_real(r, a, b) (r =  a - b)
#define multiplica_numero_real(r, a, b) (r =  a * b)
#define divide_numero_real(r, a, b) (r =  a / b)
#endif
/*:5*//*6:*/
#line 196 "reticulado.tex"

#if defined(NUMERO_EH_INT) || defined(NUMERO_EH_DOUBLE)
#define numero_eh_igual_int(r, a) (r == a)
#define numero_eh_igual_int(r, a) (r == a)
#endif
/*:6*//*7:*/
#line 210 "reticulado.tex"

#if defined(NUMERO_EH_INT) || defined(NUMERO_EH_DOUBLE)
#define copia_numero(r, a) (r =  a)
#define numero_de_int(r, a) (r =  a)
#define numero_real_de_int(r, a) (r =  a)
#define numero_pra_int(r) ((int) r)
#define numero_real_pra_double(r) ((double) r)
#define copia_numero_pra_real(r, a) (r =  (double) a)
#endif
/*:7*//*8:*/
#line 227 "reticulado.tex"

#if defined(NUMERO_EH_MPZ)
#include <gmp.h> 
typedef mpz_t numero;
typedef mpq_t numero_real;
#endif
#if defined(NUMERO_EH_MPQ)
#include <gmp.h> 
typedef mpq_t numero;
typedef mpq_t numero_real;
#endif
/*:8*//*9:*/
#line 244 "reticulado.tex"

#if defined(NUMERO_EH_MPZ)
#define inicializa_numero(n) mpz_init(n)
#define finaliza_numero(n) mpz_clear(n)
#define inicializa_numero_real(n) mpq_init(n)
#define finaliza_numero_real(n) mpq_clear(n)
#endif
#if defined(NUMERO_EH_MPQ)
#define inicializa_numero(n) mpq_init(n)
#define finaliza_numero(n) mpq_clear(n)
#define inicializa_numero_real(n) mpq_init(n)
#define finaliza_numero_real(n) mpq_clear(n)
#endif
/*:9*//*10:*/
#line 264 "reticulado.tex"

#if defined(NUMERO_EH_MPZ) || defined(NUMERO_EH_MPQ)
#define soma_numero_real(r, a, b) mpq_add(r, a, b)
#define subtrai_numero_real(r, a, b) mpq_sub(r, a, b)
#define multiplica_numero_real(r, a, b) mpq_mul(r, a, b)
#define divide_numero_real(r, a, b) mpq_div(r, a, b)
#if defined(NUMERO_EH_MPZ)
#define soma_numero(r, a, b) mpz_add(r, a, b)
#define subtrai_numero(r, a, b) mpz_sub(r, a, b)
#define multiplica_numero(r, a, b) mpz_mul(r, a, b)
#define divide_numero(r, a, b) mpz_tdiv_q(r, a, b)
#endif
#if defined(NUMERO_EH_MPQ)
#define soma_numero(r, a, b) mpq_add(r, a, b)
#define subtrai_numero(r, a, b) mpq_sub(r, a, b)
#define multiplica_numero(r, a, b) mpq_mul(r, a, b)
#define divide_numero(r, a, b) mpq_div(r, a, b)
#endif
#endif
/*:10*//*11:*/
#line 289 "reticulado.tex"

#if defined(NUMERO_EH_MPZ) || defined(NUMERO_EH_MPQ)
#define numero_real_eh_igual_int(r, a) (mpq_cmp_si(r, a, 1) == 0)
#define numero_real_pra_double(r) (mpq_get_d(r))
#endif
#if defined(NUMERO_EH_MPZ)
#define numero_eh_igual_int(r, a) (mpz_cmp_si(r, a) == 0)
#endif
#if defined(NUMERO_EH_MPQ)
#define numero_eh_igual_int(r, a) (mpq_cmp_si(r, a, 1) == 0)
#endif
/*:11*//*12:*/
#line 307 "reticulado.tex"

#if defined(NUMERO_EH_MPZ)
#define copia_numero(r, a) mpz_set(r, a)
#define numero_de_int(r, a) mpz_set_si(r, a)
#define numero_pra_int(r) ((int) mpz_get_si(r))
#define numero_real_de_int(r, a) (mpq_set_si(r, a, 1))
#define copia_numero_pra_real(r, a) mpq_set_z(r, a)
#endif
#if defined(NUMERO_EH_MPQ)
#define copia_numero(r, a) mpq_set(r, a)
#define numero_de_int(r, a) (mpq_set_d(r, (double) a))
#define numero_real_de_int(r, a) (mpq_set_si(r, a, 1))
#define numero_pra_int(r) ((int) mpq_get_d(r))
#define copia_numero_pra_real(r, a) mpq_set(r, a)
#endif
/*:12*//*13:*/
#line 334 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#include <openssl/bn.h> 
typedef BIGNUM*numero;
typedef BIGNUM*numero_real;
#endif
/*:13*//*14:*/
#line 346 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#define inicializa_numero(n) (n =  BN_new())
#define finaliza_numero(n) BN_clear_free(n)
#define inicializa_numero_real(n) (n =  BN_new())
#define finaliza_numero_real(n) BN_clear_free(n)
#endif
/*:14*//*15:*/
#line 359 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#define soma_numero(r, a, b) BN_add(r, a, b)
#define subtrai_numero(r, a, b) BN_sub(r, a, b)
#define divide_numero(r, a, b) BN_div(r, NULL, a, b)
#define soma_numero_real(r, a, b) BN_add(r, a, b)
#define subtrai_numero_real(r, a, b) BN_sub(r, a, b)
#define multiplica_numero_real(r, a, b)  \
        (multiplica_numero(r, a, b),    \
         BN_div_word(r, 1000000000000000000lu))
#define divide_numero_real(r, a, b) BN_div(r, NULL, a, b)
#endif
/*:15*//*16:*/
#line 379 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#define numero_eh_igual_int(r, a) BN_is_word(r, a)
#endif
/*:16*//*20:*/
#line 433 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#define copia_numero(r, a) BN_copy(r, a)
#define numero_de_int(r, a) BN_set_word(r, a)
#define numero_real_de_int(r, a) \
          (BN_set_word(r, a) &&  \
           BN_mul_word(r, (unsigned long) 1000000000000000000))
#define numero_pra_int(r) ((int) BN_get_word(r))
#define copia_numero_pra_real(r, a) \
          (BN_copy(r, a) &&         \
          BN_mul_word(r, (unsigned long) 1000000000000000000))
#endif
/*:20*//*31:*/
#line 674 "reticulado.tex"


#define le_matriz(A, i, j) A -> valores[i * A -> colunas + j]
#define escreve_matriz(A, i, j, v)                    \
        copia_numero(A -> valores[i * A -> colunas + j], v)
#define escreve_matriz_int(A, i, j, v)                \
        numero_de_int(A -> valores[i * A -> colunas + j], v)
/*:31*/
#line 96 "reticulado.tex"

/*29:*/
#line 644 "reticulado.tex"

struct matriz{
int linhas,colunas;
numero*valores;
};
/*:29*//*30:*/
#line 658 "reticulado.tex"

struct matriz_real{
int linhas,colunas;
numero_real*valores;
};
/*:30*/
#line 97 "reticulado.tex"

/*17:*/
#line 391 "reticulado.tex"

#if defined(NUMERO_EH_BN)
bool numero_real_eh_igual_int(numero_real r,int a);
#endif
/*:17*//*22:*/
#line 469 "reticulado.tex"

bool inicializa_api_reticulado(void);
void finaliza_api_reticulado(void);
/*:22*//*24:*/
#line 500 "reticulado.tex"

#if defined(NUMERO_EH_BN)
void multiplica_numero(numero r,numero a,numero b);
#endif
/*:24*//*26:*/
#line 522 "reticulado.tex"

#if defined(NUMERO_EH_BN)
double numero_real_pra_double(numero_real r);
#endif
/*:26*//*34:*/
#line 752 "reticulado.tex"

struct matriz*nova_matriz(int linha,int coluna,numero*valores);
struct matriz*nova_matriz_nula(int linha,int coluna);
struct matriz*nova_matriz_identidade(int dim);
/*:34*//*36:*/
#line 780 "reticulado.tex"

void destroi_matriz(struct matriz*A);
/*:36*//*38:*/
#line 807 "reticulado.tex"

struct matriz_real*nova_matriz_real(struct matriz*A);
void destroi_matriz_real(struct matriz_real*A);
/*:38*//*41:*/
#line 862 "reticulado.tex"

bool soma_matriz(struct matriz*A,struct matriz*B,struct matriz*C);
/*:41*//*48:*/
#line 1032 "reticulado.tex"

bool multiplica_matriz(struct matriz*A,struct matriz*B,
struct matriz*C);
/*:48*//*50:*/
#line 1136 "reticulado.tex"

bool troca_linha_matriz_real(struct matriz_real*A,int pos1,int pos2);
/*:50*//*52:*/
#line 1198 "reticulado.tex"

bool multiplica_linha_matriz_real(struct matriz_real*A,int pos1,
numero_real escalar);
/*:52*//*54:*/
#line 1230 "reticulado.tex"

bool soma_linha_e_multiplo_matriz_real(struct matriz_real*A,int pos1,
int pos2,numero_real escalar);
/*:54*/
#line 98 "reticulado.tex"

#ifdef __cplusplus
}
#endif
#endif
/*:1*/
