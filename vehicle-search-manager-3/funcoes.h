#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>

using namespace std;

typedef struct carro{
  string modelo;
  string marca; 
  string tipo;
  int ano;
  int km;
  float potencia;
  string combustivel;
  string direcao;
  string cambio; 
  string cor;
  int portas;
  string placa; 
  float preco;
}carro;


typedef struct _noL{
  carro * chave;
  struct _noL * prox;
}noL;


typedef struct{
  int tam;
  noL * list;
}tLista;


typedef struct _binarytree{
   carro *chave;
  _binarytree * dir, * esq;
}bNode;  


typedef struct _avltree{
  carro *chave;
  int fb;  
  int maxlevel;
  _avltree * dir, * esq;
}avlNode;


int menu();

int menu2();

int menu3();

int menu4();

int menu5();

void enter();

void le_arquivo(tLista * ptlista);

tLista * inicia_lista();

void encerra_lista(tLista * ptlista);

void escreve_arquivo(tLista * ptlista);

void imprime_lista(tLista * ptlista);

void insere_no(tLista * ptlista, carro * novo_carro);

void apaga_no(tLista * ptlista, string Lplate);

carro *  busca_lista(tLista * ptlista, string Lplate);

void dados_carro(carro ** aux);

bNode * inicia_binaria();

bNode * insere_binaria(bNode * root, carro *x);

bNode * menor_noB(bNode * smallest);

bNode * remove_noB(bNode * root, string value);

int alturaB(bNode *raiz);

void encerra_B(bNode * root);

void imprimeB2(bNode *bt);

void imprimirB(bNode *raiz);

void insere_arvoreBinaria(tLista * ptlista, string filter, bNode **bt);

avlNode * inicia_AVL();

short maior(short a, short b);

short alturaDoNo(avlNode *noL);

short fatorDeBalanceamento(avlNode *noL);

avlNode* rotacaoEsquerda(avlNode *r);

avlNode* rotacaoDireita(avlNode *r);

avlNode* rotacaoEsquerdaDireita(avlNode *r);

avlNode* rotacaoDireitaEsquerda(avlNode *r);

avlNode* balancear(avlNode *raiz);

avlNode* inserir(avlNode *raiz, carro *x);

avlNode* remover(avlNode *raiz, carro *x); 

int alturaAVL(avlNode *raiz);

void encerra_AVL(avlNode * avl);

void imprimeAVL2(avlNode *avl);
  
void imprimirAVL(avlNode *raiz);

void insere_arvoreAVL(tLista * ptlista, string filter, avlNode **avl);

#endif
