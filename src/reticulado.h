/*1:*/
#line 89 "reticulado.tex"

#ifndef __RETICULADO_H_
#define __RETICULADO_H_
#ifdef __cplusplus
extern"C"{
#endif
/*18:*/
#line 464 "reticulado.tex"

#include <stdbool.h> 
/*:18*//*65:*/
#line 1423 "reticulado.tex"

#include <string.h> 
/*:65*/
#line 95 "reticulado.tex"

/*3:*/
#line 148 "reticulado.tex"

#if defined(NUMERO_EH_INT)
typedef int numero;
typedef double numero_real;
#endif
/*:3*//*4:*/
#line 178 "reticulado.tex"

#if defined(NUMERO_EH_DOUBLE)
typedef double numero;
typedef double numero_real;
#endif
/*:4*//*5:*/
#line 198 "reticulado.tex"

#if defined(NUMERO_EH_MPZ)
#include <gmp.h>  
typedef mpz_t numero;
typedef mpq_t numero_real;
#endif
/*:5*//*6:*/
#line 215 "reticulado.tex"

#if defined(NUMERO_EH_MPQ)
#include <gmp.h>  
typedef mpq_t numero;
typedef mpq_t numero_real;
#endif
/*:6*//*7:*/
#line 241 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#include <openssl/bn.h>  
typedef BIGNUM*numero;
typedef BIGNUM*numero_real;
#endif
/*:7*//*8:*/
#line 264 "reticulado.tex"

#if defined(NUMERO_EH_INT) || defined(NUMERO_EH_DOUBLE)
#define inicializa_numero(n)
#define finaliza_numero(n)
#define inicializa_numero_real(n)
#define finaliza_numero_real(n)
#endif
/*:8*//*9:*/
#line 279 "reticulado.tex"

#if defined(NUMERO_EH_MPZ) || defined(NUMERO_EH_MPQ)
#if defined(NUMERO_EH_MPZ)
#define inicializa_numero(n) mpz_init(n)
#define finaliza_numero(n) mpz_clear(n)
#endif
#if defined(NUMERO_EH_MPQ)
#define inicializa_numero(n) mpq_init(n)
#define finaliza_numero(n) mpq_clear(n)
#endif
#define inicializa_numero_real(n) mpq_init(n)
#define finaliza_numero_real(n) mpq_clear(n)
#endif
/*:9*//*10:*/
#line 302 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#define inicializa_numero(n) (n =  BN_new())
#define finaliza_numero(n) BN_clear_free(n)
#define inicializa_numero_real(n) (n =  BN_new())
#define finaliza_numero_real(n) BN_clear_free(n)
#endif
/*:10*//*11:*/
#line 325 "reticulado.tex"

#if defined(NUMERO_EH_INT) || defined(NUMERO_EH_DOUBLE)
#define soma_numero(r, a, b) (r =  a + b)
#define subtrai_numero(r, a, b) (r =  a - b)
#define soma_numero_real(r, a, b) (r =  a + b)
#define subtrai_numero_real(r, a, b) (r =  a - b)
#define neg_numero(r, a) (r =  -a)
#define neg_numero_real(r, a) (r =  -a)
#endif
/*:11*//*12:*/
#line 343 "reticulado.tex"

#if defined(NUMERO_EH_MPZ) || defined(NUMERO_EH_MPQ)
#if defined(NUMERO_EH_MPZ)
#define soma_numero(r, a, b) mpz_add(r, a, b)
#define subtrai_numero(r, a, b) mpz_sub(r, a, b)
#define neg_numero(r, a) mpz_neg(r, a)
#endif
#if defined(NUMERO_EH_MPQ)
#define soma_numero(r, a, b) mpq_add(r, a, b)
#define subtrai_numero(r, a, b) mpq_sub(r, a, b)
#define neg_numero(r, a) mpq_neg(r, a)
#endif
#define soma_numero_real(r, a, b) mpq_add(r, a, b)
#define subtrai_numero_real(r, a, b) mpq_sub(r, a, b)
#define neg_numero_real(r, a) mpq_neg(r, a)
#endif
/*:12*//*13:*/
#line 375 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#define soma_numero(r, a, b) BN_add(r, a, b)
#define subtrai_numero(r, a, b) BN_sub(r, a, b)
#define soma_numero_real(r, a, b) BN_add(r, a, b)
#define subtrai_numero_real(r, a, b) BN_sub(r, a, b)
#define neg_numero(r, a) (BN_copy(r, a),                    \
                          BN_set_negative(r, !BN_is_negative(r)))
#define neg_numero_real(r, a) (BN_copy(r, a),                    \
                               BN_set_negative(r, !BN_is_negative(r)))
#endif
/*:13*//*14:*/
#line 404 "reticulado.tex"

#if defined(NUMERO_EH_INT) || defined(NUMERO_EH_DOUBLE)
#define multiplica_numero(r, a, b) (r =  a * b)
#define divide_numero(r, a, b) (r =  a / b)
#define multiplica_numero_real(r, a, b) (r =  a * b)
#define divide_numero_real(r, a, b) (r =  a / b)
#define inverso_numero_real(r, a) (r =  (1.0/a))
#endif
/*:14*//*15:*/
#line 418 "reticulado.tex"

#if defined(NUMERO_EH_MPZ) || defined(NUMERO_EH_MPQ)
#if defined(NUMERO_EH_MPZ)
#define multiplica_numero(r, a, b) mpz_mul(r, a, b)
#define divide_numero(r, a, b) mpz_tdiv_q(r, a, b)
#endif
#if defined(NUMERO_EH_MPQ)
#define multiplica_numero(r, a, b) mpq_mul(r, a, b)
#define divide_numero(r, a, b) mpq_div(r, a, b)
#endif
#define multiplica_numero_real(r, a, b) mpq_mul(r, a, b)
#define divide_numero_real(r, a, b) mpq_div(r, a, b)
#define inverso_numero_real(r, a) mpq_inv(r, a)
#endif
/*:15*//*22:*/
#line 523 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#define multiplica_numero_real(r, a, b)  \
        (multiplica_numero(r, a, b),    \
         BN_div_word(r, 1000000000000000000lu))
#define divide_numero_real(r, a, b)     \
        (BN_div_word(b, 1000000000000000000lu), \
         divide_numero(r, a, b),                \
         BN_mul_word(b, 1000000000000000000lu))
#endif
/*:22*//*25:*/
#line 573 "reticulado.tex"

#if defined(NUMERO_EH_INT) || defined(NUMERO_EH_DOUBLE)
#if defined(NUMERO_EH_INT)
#define numero_de_numero_real(r, a) (r =  (int) a)
#endif
#if defined(NUMERO_EH_DOUBLE)
#define numero_de_numero_real(r, a) (r =  a)
#endif
#define numero_real_de_numero(r, a) (r =  (double) a)
#define copia_numero(r, a) (r =  a)
#define copia_numero_real(r, a) (r =  a)
#endif
/*:25*//*26:*/
#line 592 "reticulado.tex"

#if defined(NUMERO_EH_MPZ) || defined(NUMERO_EH_MPQ)
#if defined(NUMERO_EH_MPZ)
#define numero_real_de_numero(r, a) mpq_set_z(r, a)
#define copia_numero(r, a) mpz_set(r, a)
#endif
#if defined(NUMERO_EH_MPQ)
#define numero_real_de_numero(r, a) mpq_set(r, a)
#define copia_numero(r, a) mpq_set(r, a)
#define numero_de_numero_real(r, a) mpq_set(r, a)
#endif
#define copia_numero_real(r, a) mpq_set(r, a)
#endif
/*:26*//*29:*/
#line 651 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#define copia_numero(r, a) BN_copy(r, a)
#define copia_numero_real(r, a) BN_copy(r, a)
#define numero_real_de_numero(r, a) \
          (BN_copy(r, a) &&         \
          BN_mul_word(r, (unsigned long) 1000000000000000000lu))
#define numero_de_numero_real(r, a) \
          (BN_copy(r, a) &&         \
           BN_div_word(r, 1000000000000000000lu))
#endif
/*:29*//*30:*/
#line 680 "reticulado.tex"

#if defined(NUMERO_EH_INT) || defined(NUMERO_EH_DOUBLE)
#define numero_de_int(r, a) (r =  (numero) a)
#define numero_real_de_int(r, a) (r =  (double) a)
#define numero_pra_int(r) ((int) r)
#define numero_real_pra_int(r) ((int) r)
#endif
/*:30*//*31:*/
#line 694 "reticulado.tex"

#if defined(NUMERO_EH_MPZ)
#define numero_de_int(r, a) mpz_set_si(r, a)
#define numero_pra_int(r) ((int) mpz_get_si(r))
#define numero_real_de_int(r, a) (mpq_set_si(r, a, 1))
#define numero_real_pra_int(r) ((int) mpq_get_d(r))
#endif
#if defined(NUMERO_EH_MPQ)
#define numero_de_int(r, a) (mpq_set_d(r, (double) a))
#define numero_real_de_int(r, a) (mpq_set_si(r, a, 1))
#define numero_pra_int(r) ((int) mpq_get_d(r))
#define numero_real_pra_int(r) ((int) mpq_get_d(r))
#endif
/*:31*//*32:*/
#line 722 "reticulado.tex"

#if defined(NUMERO_EH_MPZ) || defined(NUMERO_EH_MPQ)
#if __SIZEOF_INT__ <= 4
#define numero_real_pra_int(r) ((int) mpq_get_d(r))
#else
#define numero_real_pra_int(r) __numero_real_pra_int(r)
#endif
#endif
/*:32*//*35:*/
#line 774 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#define numero_de_int(r, a)                                     \
          {BN_set_word(r, (unsigned long) ((a<0)?(-a):(a)));    \
           BN_set_negative(r, (a < 0));}
#define numero_real_de_int(r, a)   \
          {numero_de_int(r, a);  \
           BN_mul_word(r, (unsigned long) 1000000000000000000);}
#define numero_pra_int(r) ((BN_is_negative(r))?(-((int) BN_get_word(r))):\
                                              ((int) BN_get_word(r)))
#endif
/*:35*//*38:*/
#line 823 "reticulado.tex"

#if defined(NUMERO_EH_INT) || defined(NUMERO_EH_DOUBLE)
#if defined(NUMERO_EH_INT)
#define numero_de_double(r, a) (r =  (int) a)
#endif
#if defined(NUMERO_EH_DOUBLE)
#define numero_de_double(r, a) (r =  a)
#endif
#define numero_real_de_double(r, a) (r =  a)
#define numero_pra_double(r) ((double) r)
#define numero_real_pra_double(r) ((double) r)
#endif
/*:38*//*39:*/
#line 842 "reticulado.tex"

#if defined(NUMERO_EH_MPZ)
#define numero_de_double(r, a) (mpz_set_d(r, a))
#define numero_real_de_double(r, a) (mpq_set_d(r, a))
#define numero_pra_double(r) (mpz_get_d(r))
#define numero_real_pra_double(r) (mpq_get_d(r))
#endif
#if defined(NUMERO_EH_MPQ)
#define numero_de_double(r, a) (mpq_set_d(r, a))
#define numero_real_de_double(r, a) (mpq_set_d(r, a))
#define numero_pra_double(r) (mpq_get_d(r))
#define numero_real_pra_double(r) (mpq_get_d(r))
#endif
/*:39*//*40:*/
#line 864 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#define numero_de_double(r, a)                                      \
              (BN_set_word(r, (unsigned long) ((a<0)?(-a):(a))) &&  \
               BN_set_negative(r, (a < 0.0)))
#define numero_real_de_double(r, a)                                 \
              numero_de_double(r, a * 1000000000000000000.0)
#define numero_pra_double(r)                                        \
              ((BN_is_negative(r))?(-((double) BN_get_word(r))):    \
                                   ((double) BN_get_word(r)))
#endif
/*:40*//*44:*/
#line 939 "reticulado.tex"

#if defined(NUMERO_EH_INT) || defined(NUMERO_EH_DOUBLE)
#define compara_numero(a, b) ((a==b)?(0):((a> b)?(1):(-1)))
#define compara_numero_real(a, b) ((a==b)?(0):((a> b)?(1):(-1)))
#define compara_numero_numero_real(a, b) ((a==b)?(0):((a> b)?(1):(-1)))
#define compara_numero_real_numero(a, b) (-compara_numero_numero_real(b, a)
#endif
/*:44*//*45:*/
#line 952 "reticulado.tex"

#if defined(NUMERO_EH_MPZ)
#define compara_numero(a, b) mpz_cmp(a, b)
#define compara_numero_real(a, b) mpq_cmp(a, b)
#define compara_numero_numero_real(a, b) (- mpq_cmp_z(b, a))
#define compara_numero_real_numero(a, b) mpq_cmp_z(a, b)
#endif
#if defined(NUMERO_EH_MPQ)
#define compara_numero(a, b) mpq_cmp(a, b)
#define compara_numero_real(a, b) mpq_cmp(a, b)
#define compara_numero_numero_real(a, b) mpq_cmp(a, b)
#define compara_numero_real_numero(a, b) mpq_cmp(a, b)
#endif
/*:45*//*46:*/
#line 971 "reticulado.tex"

#if defined(NUMERO_EH_BN)
#define compara_numero(a, b) BN_cmp(a, b)
#define compara_numero_real(a, b) BN_cmp(a, b)

#define compara_numero_real_numero(a, b) (-compara_numero_numero_real(a,b))
#endif
/*:46*//*51:*/
#line 1116 "reticulado.tex"


#define le_matriz(A, i, j) A -> valores[i * A -> colunas + j]
/*:51*/
#line 96 "reticulado.tex"

/*49:*/
#line 1086 "reticulado.tex"

struct matriz{
int linhas,colunas;
numero*valores;
};
/*:49*//*50:*/
#line 1100 "reticulado.tex"

struct matriz_real{
int linhas,colunas;
numero_real*valores;
};
/*:50*/
#line 97 "reticulado.tex"

/*17:*/
#line 453 "reticulado.tex"

bool inicializa_api_reticulado(void);
void finaliza_api_reticulado(void);
/*:17*//*20:*/
#line 495 "reticulado.tex"

#if defined(NUMERO_EH_BN)
void multiplica_numero(numero r,numero a,numero b);
void divide_numero(numero r,numero a,numero b);
#endif
/*:20*//*23:*/
#line 543 "reticulado.tex"

#if defined(NUMERO_EH_BN)
void inverso_numero_real(numero_real r,numero_real a);
#endif
/*:23*//*27:*/
#line 623 "reticulado.tex"

#if defined(NUMERO_EH_MPZ)
void numero_de_numero_real(numero z,numero_real r);
#endif
/*:27*//*33:*/
#line 737 "reticulado.tex"

#if defined(NUMERO_EH_MPZ) || defined(NUMERO_EH_MPQ)
#if __SIZEOF_INT__ >  4
int __numero_real_pra_int(numero_real r);
#endif
#endif
/*:33*//*36:*/
#line 794 "reticulado.tex"

#if defined(NUMERO_EH_BN)
int numero_real_pra_int(numero_real r);
#endif
/*:36*//*41:*/
#line 883 "reticulado.tex"

#if defined(NUMERO_EH_BN)
double numero_real_pra_double(numero_real r);
#endif
/*:41*//*47:*/
#line 987 "reticulado.tex"

#if defined(NUMERO_EH_BN)
int compara_numero_numero_real(numero a,numero_real b);
#endif
/*:47*//*54:*/
#line 1192 "reticulado.tex"

struct matriz*nova_matriz(int linha,int coluna,numero*valores);
struct matriz*nova_matriz_nula(int linha,int coluna);
struct matriz*nova_matriz_identidade(int dim);
/*:54*//*56:*/
#line 1220 "reticulado.tex"

void destroi_matriz(struct matriz*A);
/*:56*//*58:*/
#line 1247 "reticulado.tex"

struct matriz_real*nova_matriz_real(struct matriz*A);
void destroi_matriz_real(struct matriz_real*A);
/*:58*//*61:*/
#line 1302 "reticulado.tex"

bool soma_matriz(struct matriz*A,struct matriz*B,struct matriz*C);
/*:61*//*68:*/
#line 1472 "reticulado.tex"

bool multiplica_matriz(struct matriz*A,struct matriz*B,
struct matriz*C);
/*:68*//*70:*/
#line 1576 "reticulado.tex"

bool troca_linha_matriz_real(struct matriz_real*A,int pos1,int pos2);
/*:70*//*72:*/
#line 1638 "reticulado.tex"

bool multiplica_linha_matriz_real(struct matriz_real*A,int pos1,
numero_real escalar);
/*:72*//*74:*/
#line 1670 "reticulado.tex"

bool soma_linha_e_multiplo_matriz_real(struct matriz_real*A,int pos1,
int pos2,numero_real escalar);
/*:74*//*76:*/
#line 1727 "reticulado.tex"

bool resolve_equacao_linear(struct matriz_real*resposta,
struct matriz*A,struct matriz*b);
/*:76*/
#line 98 "reticulado.tex"

#ifdef __cplusplus
}
#endif
#endif
/*:1*/
