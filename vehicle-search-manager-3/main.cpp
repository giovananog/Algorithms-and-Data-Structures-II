#include <iostream>
#include "funcoes.h"

using namespace std;

int main() {
  int i;
  string placa;
  carro * aux;

  bNode *bt = NULL;
  avlNode *avl = NULL;
  tLista *ptLista = inicia_lista();
  le_arquivo(ptLista);

  
  do{
    i = menu();
    switch(i){
      case 1:
        cout << "Placa: ";
        cin >> placa;
        aux = busca_lista(ptLista, placa);
        if (aux == NULL) {
          aux = new carro;
          aux->placa = placa;
          dados_carro(&aux);
          insere_no(ptLista, aux);
        } else
          cout << "\no veículo já existe\n";
        break;
      
      case 2:
        cout << "placa: ";
        cin >> placa;
        cout << endl;
        aux = busca_lista(ptLista, placa);
        if (aux){
          apaga_no(ptLista, placa);
          avl = remover(avl, aux);
          bt = remove_noB(bt, placa);
        }else{
          cout << "\nveículo não encontrado\n";
        }
        break;
      
      case 3:
        cout << "placa: ";
        cin >> placa;
        cout << endl;
        aux = busca_lista(ptLista, placa);
        if (aux == 0) {
          cout << "\nveículo não encontrado\n" << endl;
        } else {
          cout << "\nveículo encontrado\n" << endl; }
        break;
          
      case 4:
        i = menu2();
        switch(i){
          case 1:
            i = menu3();
            switch (i){
              case 1:
                i = menu4();
                switch (i){
                  case 1:
                    insere_arvoreAVL(ptLista, "Hidráulica", &avl);
                    cout << "\n\nNível máximo da árvore inserida: " << avl->maxlevel+1 << endl;
                    break;
                  case 2:
                    insere_arvoreAVL(ptLista, "Elétrica", &avl);
                    cout << "\n\nNível máximo da árvore inserida: " << avl->maxlevel+1 << endl;
                    break;
                  default:
                    break;
                }
                break;
              
              case 2:
                i = menu5();
                switch (i){
                  case 1:
                    insere_arvoreAVL(ptLista, "Manual", &avl);
                    cout << "\n\nNível máximo da árvore inserida: " << avl->maxlevel+1 << endl;
                    break;
                  case 2:
                    insere_arvoreAVL(ptLista, "Automático", &avl);
                    cout << "\n\nNível máximo da árvore inserida: " << avl->maxlevel+1 << endl;
                    break;
                  default:
                    break;
                }
                break;
              
              default:
                break;
            }
           break;
          
          case 2:
           i = menu3();
            switch (i){
              case 1:
                i = menu4();
                switch (i){
                  case 1:
                    insere_arvoreBinaria(ptLista, "Hidráulica", &bt);
                    i = alturaB(bt);
                    cout << "\n\nNível máximo da árvore inserida: " << i+1 << endl;
                    break;
                  case 2:
                    insere_arvoreBinaria(ptLista, "Elétrica", &bt);
                    i = alturaB(bt);
                    cout << "\n\nNível máximo da árvore inserida: " << i+1 << endl;
                    break;
                  default:
                    break;
                }
                break;
              
              case 2:
                 i = menu5();
                switch (i){
                  case 1:
                    insere_arvoreBinaria(ptLista, "Manual", &bt);
                    cout << "\n\nNível máximo da árvore inserida: " << alturaB(bt)+1 << endl;
                    break;
                  case 2:
                    insere_arvoreBinaria(ptLista, "Automático", &bt);
                    cout << "\n\nNível máximo da árvore inserida: " << alturaB(bt)+1 << endl;
                    break;
                  default:
                    break;
                }
                break;
              
              default:
                break;
            }
           break;
          
          default:
           break;
        }
        break;
          
      case 5:
        i = menu2();
        cout << "\n\n\n";
        switch(i){
          case 1:
            imprimirAVL(avl);
            break;
          case 2:
            imprimirB(bt);
            break;
          default:
            break;
        }
        break;
          
      case 6:
        imprime_lista(ptLista);
        break;

      default:
          break;
     }
    enter();
  }while (i != 7);

  escreve_arquivo(ptLista);
  encerra_lista(ptLista);
  if(bt) encerra_B(bt); 
  if(avl) encerra_AVL(avl);  
}
