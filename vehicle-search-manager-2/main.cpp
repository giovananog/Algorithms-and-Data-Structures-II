#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

typedef struct {
  string modelo;
  string marca;
  string tipo;
  int ano;
  int km;
  float potencia;
  string combustivel;
  string cambio;
  string direcao;
  string cor;
  int portas;
  string placa;
  float valor;
} Tveiculo;

typedef struct no_ {
  Tveiculo *valor;
  struct no_ *prox;
} no;

typedef struct {
  int tam;
  no *lista;
} tLista;

Tveiculo *aux;

tLista *inicia_lista() {
  tLista *novo = new tLista;
  novo->tam = 0;
  novo->lista = NULL;
  return novo;
}

no *encerra_lista(tLista *ptlista) {
  no *ant = ptlista->lista;
  no *pont = ptlista->lista;

  while (ant != NULL) {
    pont = ant->prox;
    delete (ant);
    ant = pont;
  }
  delete (ptlista);
  return NULL;
}

void escreve_arquivo2(tLista *ptlista){
  no * atual;
  
  ofstream myfile;
  atual = ptlista->lista;
  myfile.open("BD_veiculos_2.txt");
  if (myfile.is_open()){
     for (int i = 0; i < ptlista->tam; i++, atual = atual->prox){
       myfile << atual->valor->modelo  << " ";
       myfile << atual->valor->marca << " ";
       myfile << atual->valor->tipo << " ";
       myfile << atual->valor->ano << " ";
       myfile << atual->valor->km << " ";
       myfile << atual->valor->potencia << " ";
       myfile << atual->valor->combustivel << " ";
       myfile << atual->valor->cambio << " ";
       myfile << atual->valor->direcao << " ";
       myfile << atual->valor->cor << " ";
       myfile << atual->valor->portas << " ";
       myfile << atual->valor->placa << " ";
       myfile << atual->valor->valor;
       
       if (atual->prox != NULL){
           myfile << "\n";
       }
    }
     myfile.close();
  } 
}

void imprime(tLista *ptlista) {
  no *ant = ptlista->lista;
  int i = 1;

  while (ant != NULL) {
    cout << "Veículo [" << i << "]: \n"
         << endl
         << ant->valor->modelo << endl
         << ant->valor->marca << endl
         << ant->valor->tipo << endl
         << ant->valor->ano << endl
         << ant->valor->km << endl
         << ant->valor->potencia << endl
         << ant->valor->combustivel << endl
         << ant->valor->cambio << endl
         << ant->valor->direcao << endl
         << ant->valor->cor << endl
         << ant->valor->portas << endl
         << ant->valor->placa << endl
         << ant->valor->valor << ".00" << endl
         << "-----------------\n\n"
         << endl;
    ant = ant->prox;
    i++;
  }
}

void ordena_placa(tLista *ptlista) {
  tLista *ptlista2 = inicia_lista();
  no *atual2 = ptlista2->lista;
  no *atual;
  string menor;
  string x = "1";

  while (ptlista2->tam != ptlista->tam) {
    menor = "ZZZZZZ";
    atual = ptlista->lista;
    while (atual != NULL) {
      if (atual->valor->placa < menor && atual->valor->placa > x) {
        menor = atual->valor->placa;
      }
      atual = atual->prox;
    }

    no *novo = new no;
    x = menor;

    atual = ptlista->lista;
    while (atual != NULL) {
      if (atual->valor->placa == menor) {
        novo->valor = atual->valor;
      }
      atual = atual->prox;
    }
    ptlista2->tam++;

    if (ptlista2->tam == 1) {
      ptlista2->lista = novo;
      atual2 = novo;
    } else {
      atual2->prox = novo;
      novo->prox = NULL;
      atual2 = atual2->prox;
    }
  }
  imprime(ptlista2);
}

void le_arquivo(tLista *ptlista) {
  no *ant = ptlista->lista;
  int i = 0;
  ifstream myfile;
  myfile.open("BD_veiculos_2.txt");

  if (myfile.is_open()) {
    while (!myfile.eof()) {
      no *novo = new no;
      aux = new Tveiculo;
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
      myfile >> aux->valor;
      ptlista->tam++;
      if (i == 0) {
        novo->valor = aux;
        ptlista->lista = novo;
        ant = novo;
        i++;
      } else {
        ant->prox = novo;
        ant = novo;
        novo->valor = aux;
        novo->prox = NULL;
      }
    }
    myfile.close();
  } else {
    cout << "Impossível abrir o arquivo." << endl;
  }
}

void menu() {
  cout << "\n\nOpções:\n" << endl;
  cout << "[1]- Busca por placa\n[2]- Inserir veículo\n[3]- Imprimir "
          "veiculos\n[4]- Obter Pilha\n[5]- Obter Fila\n[6]- Ordenar por placa\n[7]- Sair \n\nOpção: ";
}

void enter() {
  cout << "\nDigite ENTER para continuar...";
  getchar();
  getchar();
  system("clear");
}

void insere(Tveiculo *novo, tLista *ptlista) {
  no *ant = ptlista->lista; 
  while (ant->prox != NULL) {
    ant = ant->prox;
  }
  no *novo_no = new no;
  novo_no->valor = novo;
  ant->prox = novo_no;
  novo_no->prox = NULL;
  ptlista->tam++;
}

void insere_inicio(Tveiculo *veiculo, tLista *lista){
  no* novo = new no;
  novo->valor = veiculo;
  novo->prox = lista->lista;
  lista->lista = novo;
  lista->tam = lista->tam + 1;
}

no* remove_inicio(tLista *lista){
  no* retorno = lista->lista;
  lista->lista = retorno->prox;
  lista->tam = lista->tam - 1;
  return retorno;
}

no * remove_fim(tLista *ptlista){
  no * atual = ptlista->lista;
  no * anterior;
  int i = 0;
  if (atual == NULL)
      return NULL;
  while(atual->prox != NULL){
    anterior = atual;
    atual = atual->prox;
    i++;
  }
  if(i == 0){
    ptlista->lista = atual->prox;
    return atual;
  }
  anterior->prox = atual->prox;
  ptlista->tam--;
  return atual;
}

void remove_placa(string placa, tLista *ptlista) {
  no *ant = ptlista->lista;
  no *ptr = ant->prox;

  while (ptr->valor->placa != placa) {
    ant = ptr;
    ptr = ptr->prox;
  }
  ant->prox = ptr->prox;
  ptr = NULL;
  delete (ptr);
  ptlista->tam--;
}

Tveiculo *busca_placa(string placa, tLista *ptlista) {
  no *ant = ptlista->lista;
  if (ant->prox == NULL) {
    return 0;
  } else {
    while (ant != NULL) {
      if (ant->valor->placa != placa) {
        ant = ant->prox;
      } else {
        return ant->valor;
        ant = NULL;
      }
    }
    return 0;
  }
}

tLista *pilha(tLista *ptlista) {
  tLista *lista2 = inicia_lista();
  no * ant = ptlista->lista;
  lista2->tam = 0;
  while (ant != NULL) {
    if (ant->valor->direcao == "Hidráulica") {
      insere_inicio(ant->valor, lista2);
    }else if(ant->valor->direcao == "Elétrica" && lista2->lista != NULL){
      delete(remove_inicio(lista2));
    }
    ant = ant->prox;
  }
return lista2;
}

tLista *fila(tLista *ptlista) {
    tLista *lista2 = inicia_lista();
  no * ant = ptlista->lista;
  lista2->tam = 0;
  while (ant != NULL) {
    if (ant->valor->cambio == "Automático") {
      insere_inicio(ant->valor, lista2);
    }else if(ant->valor->cambio == "Manual" && lista2->lista != NULL){
      delete(remove_fim(lista2));
    }
    ant = ant->prox;
  }
return lista2;
}

int main() {
  tLista *ptlista = inicia_lista();
  tLista *fila1;
  tLista *pilha1;

  le_arquivo(ptlista);

  int i = 0;
  int opcao = 0;
  int valor;
  string placa;
  char sn;
  
  do {

    if (i != 0) {
      enter();
    }
    menu();
    i++;
    cin >> opcao;

    switch (opcao) {
    case 1:
      cout << "Placa: ";
      cin >> placa;
      cout << endl;
      aux = busca_placa(placa, ptlista);
      if (aux == 0) {
        cout << "\nPlaca não encontrada\n" << endl;
      } else {
        cout << "\nPlaca encontrada\n" << endl;
        cout << "Deseja remover o veículo?(S/N): ";
        do {
          cin >> sn;
          if (sn == 'S') {
            remove_placa(placa, ptlista);
          } else if (sn == 'N') {
            cout << "\nVeículo não removido";
          } else {
            cout << "Isso não é uma opção!" << endl;
          }
        } while (sn != 'S' && sn != 'N');
      }
      break;
    case 2:
      cout << "Placa: ";
      cin >> placa;
      aux = busca_placa(placa, ptlista);
      if (aux == 0) {
        cout << "\nPlaca não encontrada, veículo apto para ser inserido!\n\n"
             << endl;
        aux = new Tveiculo;
        aux->placa = placa;
        cout << "modelo: ";
        cin >> aux->modelo;
        cout << "marca: ";
        cin >> aux->marca;
        cout << "tipo: ";
        cin >> aux->tipo;
        cout << "ano: ";
        cin >> aux->ano;
        cout << "km: ";
        cin >> aux->km;
        cout << "potencia: ";
        cin >> aux->potencia;
        cout << "comb: ";
        cin >> aux->combustivel;
        cout << "cambio: ";
        cin >> aux->cambio;
        cout << "direcao:";
        cin >> aux->direcao;
        cout << "cor: ";
        cin >> aux->cor;
        cout << "portas: ";
        cin >> aux->portas;
        cout << "valor: ";
        cin >> aux->valor;
        insere(aux, ptlista);
      } else
        cout << "\nVeículo já existe";
      break;

    case 3:
      imprime(ptlista);
      break;

    case 4:
      pilha1 = pilha(ptlista);
      imprime(pilha1);
      encerra_lista(pilha1);
      break;
    case 5:
      fila1 = fila(ptlista);
      imprime(fila1);
      encerra_lista(fila1);
      break;
      
    case 6:
      ordena_placa(ptlista);
      break;
      
    case 7:
      break;
      
    default:
      cout << "Opção inválida!!\n";
      break;
    }
  } while (opcao != 7);

  escreve_arquivo2(ptlista);
  encerra_lista(ptlista);
  delete (aux);
}
