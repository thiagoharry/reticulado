#include "src/reticulado.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int numero_de_testes = 0, acertos = 0, falhas = 0;
void imprime_resultado(void){
  printf("\n%d tests: %d sucess, %d fails\n\n",
	 numero_de_testes, acertos, falhas);
}

void assert(char *descricao, bool valor){
  char pontos[72], *s = descricao;
  size_t tamanho_string = 0;
  int i;
  while(*s)
    tamanho_string += (*s++ & 0xC0) != 0x80;
  pontos[0] = ' ';
  for(i = 1; i < 71 - (int) tamanho_string; i ++)
    pontos[i] = '.';
  pontos[i] = '\0';
  numero_de_testes ++;
  printf("%s%s", descricao, pontos);
  if(valor){
#if defined(__unix__) && !defined(__EMSCRIPTEN__)
    printf("\e[32m[OK]\033[0m\n");
#else
    printf("[OK]\n");
#endif
    acertos ++;
  }
  else{
#if defined(__unix__) && !defined(__EMSCRIPTEN__)
    printf("\033[0;31m[FAIL]\033[0m\n");
#else
    printf("[FAIL]\n");
#endif
    falhas ++;
  }
}

void test_matrix_basic(void){
  struct matriz *A, *B, *C;
  numero valores[25];
  int i, j;
  bool ok = true;
  A = nova_matriz_identidade(5);
  B = nova_matriz_nula(5, 5);
  for(i = 0; i < 25; i ++){
    inicializa_numero(valores[i]);
    numero_de_int(valores[i], 5);
  }
  C = nova_matriz(5, 5, valores);
  for(i = 0; i < 25; i ++){
    finaliza_numero(valores[i]);
  }
  assert("Alocação de Matrizes", A != NULL && B != NULL && C != NULL);
  for(i = 0; i < 5; i ++)
    for(j = 0; j < 5; j ++){
      if(i == j){
	if(numero_pra_int(le_matriz(A, i, j)) != 1)
	  ok = false;
      }
      else
	if(numero_pra_int(le_matriz(A, i, j)) != 0){
	  printf("Erro: [%d, %d], %d\n", i, j, numero_pra_int(le_matriz(A, i, j)));
	  ok = false;
	}
      if(numero_pra_int(le_matriz(B, i, j)) != 0)
	ok = false;
      if(numero_pra_int(le_matriz(C, i, j)) !=  5)
	ok = false;
    }
  assert("Inicialização de Matrizes", ok);
  ok = soma_matriz(B, A, C);
  for(i = 0; i < 5; i ++)
    for(j = 0; j < 5; j ++){
      if(i == j){
	if(numero_pra_int(le_matriz(B, i, j)) != 6)
	  ok = false;
      }
      else
	if(numero_pra_int(le_matriz(B, i, j)) != 5)
	  ok = false;
    }
  assert("Soma de Matrizes", ok);
  destroi_matriz(A);
  destroi_matriz(B);
  destroi_matriz(C);
  {
    A = nova_matriz_nula(4, 3);
    B = nova_matriz_identidade(3);
    C = nova_matriz_nula(4, 3);
    
    escreve_matriz_int(A, 0, 0, 1); escreve_matriz_int(A, 0, 1, 0);
    escreve_matriz_int(A, 0, 2, 1); escreve_matriz_int(A, 1, 0, 2);
    escreve_matriz_int(A, 1, 1, 1); escreve_matriz_int(A, 1, 2, 1);
    escreve_matriz_int(A, 2, 0, 0); escreve_matriz_int(A, 2, 1, 1);
    escreve_matriz_int(A, 2, 2, 1); escreve_matriz_int(A, 3, 0, 1);
    escreve_matriz_int(A, 3, 1, 1); escreve_matriz_int(A, 3, 2, 2);
    
    escreve_matriz_int(B, 0, 0, 1); escreve_matriz_int(B, 0, 1, 2);
    escreve_matriz_int(B, 0, 2, 1); escreve_matriz_int(B, 1, 0, 2);
    escreve_matriz_int(B, 1, 1, 3); escreve_matriz_int(B, 1, 2, 1);
    escreve_matriz_int(B, 2, 0, 4); escreve_matriz_int(B, 2, 1, 2);
    escreve_matriz_int(B, 2, 2, 2);

    ok = multiplica_matriz(C, A, B);
    assert("Multiplicação de Matrizes", ok &&
	   numero_pra_int(le_matriz(C, 0, 0)) == 5 &&
	   numero_pra_int(le_matriz(C, 0, 1)) == 4 &&
	   numero_pra_int(le_matriz(C, 0, 2)) == 3 &&
	   numero_pra_int(le_matriz(C, 1, 0)) == 8 &&
	   numero_pra_int(le_matriz(C, 1, 1)) == 9 &&
	   numero_pra_int(le_matriz(C, 1, 2)) == 5 &&
	   numero_pra_int(le_matriz(C, 2, 0)) == 6 &&
	   numero_pra_int(le_matriz(C, 2, 1)) == 5 &&
	   numero_pra_int(le_matriz(C, 2, 2)) == 3 &&
	   numero_pra_int(le_matriz(C, 3, 0)) == 11 &&
	   numero_pra_int(le_matriz(C, 3, 1)) == 9 &&
	   numero_pra_int(le_matriz(C, 3, 2)) == 6);
    destroi_matriz(A);
    destroi_matriz(B);
    destroi_matriz(C);
    }
}

void test_matrix_solve_equation(void){
  struct matriz *A;
  struct matriz_real *R;
  numero_real n;
  bool ok;
  int i, j;
  inicializa_numero_real(n);
  A = nova_matriz_identidade(5);
  R = nova_matriz_real(A);
  ok = troca_linha_matriz_real(R, 2, 3);
  for(i = 0; i < 5; i ++)
    for(j = 0; j < 5; j ++){
      if(i == 2){
	if(j == 3 && numero_real_pra_double(le_matriz(R, i, j)) != 1.0)
	   ok = false;
	else if(j != 3 &&
		numero_real_pra_double(le_matriz(R, i, j)) != 0.0)
	  ok = false;
      }
      else if(i == 3){
	if(j == 2 && numero_real_pra_double(le_matriz(R, i, j)) != 1.0)
	   ok = false;
	else if(j != 2 &&
		numero_real_pra_double(le_matriz(R, i, j)) != 0.0)
	  ok = false;
      }
      else{
	if(i == j && numero_real_pra_double(le_matriz(R, i, j)) != 1.0)
	  ok = false;
	else if(i != j &&
		numero_real_pra_double(le_matriz(R, i, j)) != 0.0)
	  ok = false;
      }
    }
  assert("Troca de ordem de linhas em matriz", ok);
  destroi_matriz_real(R);
  R = nova_matriz_real(A);
  numero_real_de_int(n, 3);
  ok = multiplica_linha_matriz_real(R, 2, n);
  for(i = 0; i < 5; i ++)
    for(j = 0; j < 5; j ++){
      if(i == j){
	if(i == 2 && numero_real_pra_double(le_matriz(R, i, j)) != 3.0)
	  ok = false;
	else if(i != 2 &&
		numero_real_pra_double(le_matriz(R, i, j)) != 1.0)
	  ok = false;
      }
      else if(numero_real_pra_double(le_matriz(R, i, j)) != 0.0)
	ok = false;
    }
  assert("Multiplica linha de matriz por escalar", ok);
  destroi_matriz_real(R);
  R = nova_matriz_real(A);
  ok = soma_linha_e_multiplo_matriz_real(R, 2, 3, n);
  for(i = 0; i < 5; i ++)
    for(j = 0; j < 5; j ++){
      if(i == 2){
	if(j == 2 && numero_real_pra_double(le_matriz(R, i, j)) != 1.0){
	  ok = false;
	}
	else if(j == 3 &&
		numero_real_pra_double(le_matriz(R, i, j)) != 3.0)
	  ok = false;
	else if(j != 2 && j != 3 &&
		numero_real_pra_double(le_matriz(R, i, j)) != 0.0)
	  ok = false;
      }
      else{
	if(i == j && numero_real_pra_double(le_matriz(R, i, j)) != 1.0)
	  ok = false;
	else if(i != j &&
		numero_real_pra_double(le_matriz(R, i, j)) != 0.0)
	  ok = false;
      }
    }
  assert("Soma linha de matriz por múltiplo de outra linha", ok);
  destroi_matriz_real(R);
  destroi_matriz(A);
  finaliza_numero_real(n);
}


int main(int argc, char **argv){
  if(!inicializa_api_reticulado()){
    printf("ERRO: Falha na inicialização.\n");
    exit(1);
  }
  test_matrix_basic();
  test_matrix_solve_equation();
  imprime_resultado();
  finaliza_api_reticulado();
  return 0;
}
