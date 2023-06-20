#include "funcoes.h"
#include <iostream>
#include <fstream>

using namespace std;

int menu(){
    int opcao;
    cout << "\n\nOpcao:\n" << endl;
    cout << "[1]- Inserir\n[2]- Remover\n[3]- Buscar\n[4]- Árvores\n[5]- Imprimir árvore\n[6]- Imprimir lista\n[7]- Sair\n\nOpcao: ";
    cin >> opcao;
    return opcao;
}

int menu2(){
    system("clear");
    int opcao;
    cout << "\nÁrvore:\n\n[1]- Árvore AVL\n[2]- Árvore Binária\n\nOpcao: ";
    cin >> opcao;
    return opcao;
}

int menu3(){
    system("clear");
    int opcao;
    cout << "\nFiltro:\n\n[1]- Direção\n[2]- Câmbio\n\nOpcao: ";
    cin >> opcao;
    return opcao;
}

int menu4(){
    system("clear");
    int opcao;
    cout << "\nOpção:\n\n[1]- Hidráulica\n[2]- Elétrica\n\nOpção: ";
    cin >> opcao;
    return opcao;
}

int menu5(){
    system("clear");
    int opcao;
    cout << "\n\nOpção:\n\n[1]- Manual\n[2]- Automático\n\nOpção: ";
    cin >> opcao;
    return opcao;
}

void enter(){
    cout << "\nDigite ENTER para continuar...";
    getchar();
    getchar();
    system("clear");
}

void le_arquivo(tLista * ptlista) {
  noL *ant = NULL;
  
  ifstream myfile;
  myfile.open("BD_veiculos_2.txt");
  carro * aux;
  
  if (myfile.is_open()) {
    while (!myfile.eof()) {
      noL *novo_no = new noL;
      aux = new carro;
      myfile >> aux->modelo;
      myfile >> aux->marca;
      myfile >> aux->tipo;
      myfile >> aux->ano;
      myfile >> aux->km;
      myfile >> aux->potencia;
      myfile >> aux->combustivel;
      myfile >> aux->cambio;
      myfile >> aux->direcao;
      myfile >> aux->cor;
      myfile >> aux->portas;
      myfile >> aux->placa;
      myfile >> aux->preco;
      ptlista->tam++;
      
      if (!ant) {
        novo_no->chave = aux;
        ptlista->list = novo_no;
        ant = novo_no;
      } else {
        ant->prox = novo_no;
        ant = novo_no;
        novo_no->chave = aux;
        novo_no->prox = NULL;
     }
    }
    myfile.close();
  } else {
    cout << "Arquivo não encontrado" << endl;
  }
}

tLista * inicia_lista(){
  tLista *novo_no = new tLista;
  novo_no->tam = 0;
  novo_no->list = NULL;
  return novo_no;
}

void encerra_lista(tLista * ptlista){
  noL *ant = ptlista->list;
  noL *pont = ptlista->list;

  while (ant != NULL) {
    pont = ant->prox;
    delete (ant);
    ant = pont;
  }
  delete (ptlista);
}

void escreve_arquivo(tLista * ptlista){
   noL * atual;
  
  ofstream myfile;
  atual = ptlista->list;
  myfile.open("BD_veiculos_2.txt");
  if (myfile.is_open()){
     for (int i = 0; i < ptlista->tam; i++, atual = atual->prox){
       myfile << atual->chave->modelo  << " "
              << atual->chave->marca << " "
              << atual->chave->tipo << " "
              << atual->chave->ano << " "
              << atual->chave->km << " "
              << atual->chave->potencia << " "
              << atual->chave->combustivel << " "
              << atual->chave->cambio << " "
              << atual->chave->direcao << " "
              << atual->chave->cor << " "
              << atual->chave->portas << " "
              << atual->chave->placa << " "
              << atual->chave->preco;
       
       if (atual->prox != NULL){
           myfile << "\n";
       }
    }
     myfile.close();
  } 
}

void imprime_lista(tLista * ptlista){
  noL *ant = ptlista->list;
  int i = 1;

  while (ant != NULL) {
    cout << "Veículo [" << i << "]: \n"
         << endl
         << ant->chave->modelo << endl
         << ant->chave->marca << endl
         << ant->chave->tipo << endl
         << ant->chave->ano << endl
         << ant->chave->km << endl
         << ant->chave->potencia << endl
         << ant->chave->combustivel << endl
         << ant->chave->cambio << endl
         << ant->chave->direcao << endl
         << ant->chave->cor << endl
         << ant->chave->portas << endl
         << ant->chave->placa << endl
         << ant->chave->preco << ".00" << endl
         << "-----------------\n\n"
         << endl;
    ant = ant->prox;
    i++;
  }
}

void insere_no(tLista * ptlista, carro * novo_carro){
  noL * ant = ptlista->list; 
  
  while (ant->prox) 
    ant = ant->prox;
  
  noL * novo_no = new noL;
  novo_no->chave = novo_carro;
  ant->prox = novo_no;
  novo_no->prox = NULL;
  ptlista->tam++;
}


void apaga_no(tLista * ptlista, string placa){
  noL *ant = ptlista->list;
  noL *ptr = ant->prox;

  if (ant->chave->placa == placa){
    ptlista->list = ptr;
    ant = NULL;
    delete(ant);
  }else {
    while (ptr->chave->placa != placa) {
      ant = ptr;
      ptr = ptr->prox;
    }
    ant->prox = ptr->prox;
    ptr = NULL;
    delete (ptr);
  }
  ptlista->tam--;
}

carro * busca_lista(tLista * ptlista, string placa){
  noL *ant = ptlista->list;

  while (ant) {
    if (ant->chave->placa == placa) return ant->chave;
    else 
       ant = ant->prox;
  }
  return 0;
}

void dados_carro(carro ** aux){
          cout << "modelo: ";
          cin >> (*aux)->modelo;
          cout << "marca: ";
          cin >> (*aux)->marca;
          cout << "tipo: ";
          cin >> (*aux)->tipo;
          cout << "ano: ";
          cin >> (*aux)->ano;
          cout << "km: ";
          cin >> (*aux)->km;
          cout << "potencia: ";
          cin >> (*aux)->potencia;
          cout << "combustivel: ";
          cin >> (*aux)->combustivel;
          cout << "cambio: ";
          cin >> (*aux)->cambio;
          cout << "direcao: ";
          cin >> (*aux)->direcao;
          cout << "cor: ";
          cin >> (*aux)->cor;
          cout << "portas: ";
          cin >> (*aux)->portas;
          cout << "preco: ";
          cin >> (*aux)->preco;
}

bNode * inicia_binaria(){
  bNode *novoB = new bNode;
  novoB = NULL;
  return novoB;
}

bNode * insere_binaria(bNode * raiz, carro *x){
  if(!raiz){
    bNode * novo_no = new bNode;
    novo_no->chave = x;
    novo_no->dir = NULL;
    novo_no->esq = NULL;
    return novo_no;
  }
  else if(x->placa > raiz->chave->placa) 
    raiz->dir = insere_binaria(raiz->dir, x);
  else 
    raiz->esq = insere_binaria(raiz->esq, x);
  return raiz;
}


bNode * remove_noB (bNode * raiz, string valor){
  if (!raiz) return NULL;
  
  if (raiz->chave->placa > valor)
    raiz->esq = remove_noB(raiz->esq, valor);
    
  else if (raiz->chave->placa < valor)
    raiz->dir = remove_noB(raiz->dir, valor);
    
  else {
    if (!raiz->esq && !raiz->dir) {
      delete(raiz);
      return NULL;
    }
    else if (!raiz->esq) {
      bNode *tmp = raiz->dir;
      delete(raiz);
      return tmp;
    }
    else if (!raiz->dir) {
      bNode *tmp = raiz->esq;
      delete(raiz);
      return tmp;
    }
    else {
      bNode *tmp = raiz->dir;
      while(tmp->esq) tmp = tmp->esq;
      raiz->chave = tmp->chave;
      raiz->dir = remove_noB(raiz->dir, tmp->chave->placa);
    }
  }
   return raiz;
}

int alturaB(bNode *raiz){
    if(!raiz){
        return -1;
    }
    else{
        int esq = alturaB(raiz->esq);
        int dir = alturaB(raiz->dir);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

void encerra_B(bNode * raiz){
    if (raiz != NULL) { 
      encerra_B(raiz->esq); 
      encerra_B(raiz->dir);
      delete raiz;
    }
}

void imprimeB2(bNode *bt){
    cout << "[    Veículo    ]\n"
         << endl
         << bt->chave->modelo << endl
         << bt->chave->marca << endl
         << bt->chave->tipo << endl
         << bt->chave->ano << endl
         << bt->chave->km << endl
         << bt->chave->potencia << endl
         << bt->chave->combustivel << endl
         << bt->chave->cambio << endl
         << bt->chave->direcao << endl
         << bt->chave->cor << endl
         << bt->chave->portas << endl
         << bt->chave->placa << endl
         << bt->chave->preco << ".00" << endl
         << "-----------------\n\n"
         << endl;
}

void imprimirB(bNode *raiz){
    if (!raiz) return;
  
    imprimeB2(raiz);
    imprimirB(raiz->esq);
    imprimirB(raiz->dir);
}

void insere_arvoreBinaria(tLista * ptlista, string filtro, bNode **bt){
  *bt = inicia_binaria();
  noL *atual = ptlista->list;
  
  if(filtro == "Hidráulica" || filtro == "Elétrica"){
    for (int i = 0; i < ptlista->tam; i++, atual = atual->prox){
     if(atual->chave->direcao == filtro){
       *bt = insere_binaria(*bt, atual->chave);
     }
    }
  }else {
    for (int i = 0; i < ptlista->tam; i++, atual = atual->prox){
     if(atual->chave->cambio == filtro){
       *bt = insere_binaria(*bt, atual->chave);
     }
    }
  }
}

avlNode * inicia_AVL(){
    avlNode *novoB = new avlNode;
    novoB = NULL;
    return novoB;
  }

avlNode* novoNo(carro *x){
    avlNode *novo = new avlNode;

    if(novo){
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    else
        printf("\nERRO ao alocar nó em novoNo!\n");
    return novo;
}

short maior(short a, short b){
    return (a > b)? a: b;
}

short alturaDoNo(avlNode *no){
    if(!no)
        return -1;
    else
        return no->maxlevel;
}

short fatorDeBalanceamento(avlNode *no){
    if(no)
        return (alturaDoNo(no->esq) - alturaDoNo(no->dir));
    else
        return 0;
}

avlNode* rotacaoEsquerda(avlNode *r){
    avlNode *y, *f;

    y = r->dir;
    f = y->esq;

    y->esq = r;
    r->dir = f;

    r->maxlevel = maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;
    y->maxlevel = maior(alturaDoNo(y->esq), alturaDoNo(y->dir)) + 1;

    return y;
}

avlNode* rotacaoDireita(avlNode *r){
    avlNode *y, *f;

    y = r->esq;
    f = y->dir;

    y->dir = r;
    r->esq = f;

    r->maxlevel = maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;
    y->maxlevel = maior(alturaDoNo(y->esq), alturaDoNo(y->dir)) + 1;

    return y;
}

avlNode* rotacaoEsquerdaDireita(avlNode *r){
    r->esq = rotacaoEsquerda(r->esq);
    return rotacaoDireita(r);
}

avlNode* rotacaoDireitaEsquerda(avlNode *r){
    r->dir = rotacaoDireita(r->dir);
    return rotacaoEsquerda(r);
}

avlNode* balancear(avlNode *raiz){
    short fb = fatorDeBalanceamento(raiz);

    if(fb < -1 && fatorDeBalanceamento(raiz->dir) <= 0)
        raiz = rotacaoEsquerda(raiz);

    else if(fb > 1 && fatorDeBalanceamento(raiz->esq) >= 0)
        raiz = rotacaoDireita(raiz);

    else if(fb > 1 && fatorDeBalanceamento(raiz->esq) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    else if(fb < -1 && fatorDeBalanceamento(raiz->dir) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;
}

avlNode* inserir(avlNode *raiz, carro *x){
    if(!raiz)  
        return novoNo(x);
    else{
        if(x->placa < raiz->chave->placa)
            raiz->esq = inserir(raiz->esq, x);
        else if(x->placa > raiz->chave->placa)
            raiz->dir = inserir(raiz->dir, x);
    raiz->maxlevel = maior(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;
    raiz = balancear(raiz);
    }
    return raiz;
}

avlNode* remover(avlNode *raiz, carro *x) {
    if(!raiz){
        return NULL;
    } else {
        if(raiz->chave->placa == x->placa) {
            if(!raiz->esq && !raiz->dir) {
                delete(raiz);
                return NULL;
            }
            else{
                if(raiz->esq != NULL && raiz->dir != NULL){
                    avlNode *aux = raiz->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    raiz->chave = aux->chave;
                    aux->chave = x;
                    raiz->esq = remover(raiz->esq, x);
                    return raiz;
                }
                else{
                    avlNode *aux;
                    if(raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    delete(raiz);
                    return aux;
                }
            }
        } else {
            if(x->placa < raiz->chave->placa)
                raiz->esq = remover(raiz->esq, x);
            else
                raiz->dir = remover(raiz->dir, x);
        }
        raiz->maxlevel = maior(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;

        raiz = balancear(raiz);

        return raiz;
    }
}

void encerra_AVL(avlNode * avl){
    if (avl != NULL) { 
      encerra_AVL(avl->esq); 
      encerra_AVL(avl->dir);
      delete avl;
    }
}

void imprimeAVL2(avlNode *avl){
    cout << "[    Veículo    ]\n"
         << endl
         << avl->chave->modelo << endl
         << avl->chave->marca << endl
         << avl->chave->tipo << endl
         << avl->chave->ano << endl
         << avl->chave->km << endl
         << avl->chave->potencia << endl
         << avl->chave->combustivel << endl
         << avl->chave->cambio << endl
         << avl->chave->direcao << endl
         << avl->chave->cor << endl
         << avl->chave->portas << endl
         << avl->chave->placa << endl
         << avl->chave->preco << ".00" << endl
         << "-----------------\n\n"
         << endl;
}

void imprimirAVL(avlNode *raiz){
    if (!raiz)
        return;
    imprimeAVL2(raiz);
    imprimirAVL(raiz->esq);
    imprimirAVL(raiz->dir);
}

void insere_arvoreAVL(tLista * ptlista, string filtro, avlNode **avl){
  *avl = inicia_AVL();
  noL *atual = ptlista->list;
  
 if(filtro == "Hidráulica" || filtro == "Elétrica"){
    for (int i = 0; i < ptlista->tam; i++, atual = atual->prox){
     if(atual->chave->direcao == filtro){
       *avl = inserir(*avl, atual->chave);
     }
    }
  }else {
     for (int i = 0; i < ptlista->tam; i++, atual = atual->prox){
     if(atual->chave->cambio == filtro){
       *avl = inserir(*avl, atual->chave);
     }
    }
  }
}
