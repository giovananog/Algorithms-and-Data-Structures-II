#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

typedef struct  {
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
}Tveiculo;

Tveiculo *carro[50];
Tveiculo *aux;
Tveiculo *ordenacao[50];
Tveiculo *aux2;


void ordena_placa(int *tam, Tveiculo *carro[]){
  int i, j, k;
  for (j = *tam; j > 0; j--) {
    for (i = 0, k = i+1;  k < *tam; i++, k++){
      if (carro[i]->placa > carro[k]->placa) {
        aux2 = carro[i]; 
        carro[i] = carro[k];
        carro[k] = aux2; 
      }
    }
  }
  ofstream myfile;
  myfile.open("BD_veiculos_2-ord.txt");
  if (myfile.is_open()){
    for (int i = 0; i < *tam; i++){
      myfile << carro[i]->modelo  << " ";
      myfile << carro[i]->marca << " ";
      myfile << carro[i]->tipo << " ";
      myfile << carro[i]->ano << " ";
      myfile << carro[i]->km << " ";
      myfile << carro[i]->potencia << " ";
      myfile << carro[i]->combustivel << " ";
      myfile << carro[i]->cambio << " ";
      myfile << carro[i]->direcao << " ";
      myfile << carro[i]->cor << " ";
      myfile << carro[i]->portas << " ";
      myfile << carro[i]->placa << " ";
      myfile << carro[i]->valor << ".00 ";
      myfile << "\n";
    }
    myfile.close();
  } 
}
     
void imprime(int *tam, Tveiculo *carro[]) {
  for (int j = 0; j < *tam; j++) {
    cout << setw(39) << "---------------------------\n";
    cout << setw(28) << "|     | veiculo  " << j+1 << " |     | " << endl;
    cout << setw(39) << "---------------------------\n";
    cout << setw(25) << "|  modelo   : " << carro[j]->modelo << endl;
    cout << setw(25) << "|  marca    : " << carro[j]->marca << endl;
    cout << setw(25) << "|  tipo     : " << carro[j]->tipo << endl;
    cout << setw(25) << "|  ano      : " << carro[j]->ano << endl;
    cout << setw(25) << "|  km       : " << carro[j]->km << endl;
    cout << setw(25) << "|  potencia : " << carro[j]->potencia << endl;
    cout << setw(25) << "|  comb     : " << carro[j]->combustivel << endl;
    cout << setw(25) << "|  cambio   : " << carro[j]->cambio << endl;
    cout << setw(25) << "|  direcao  : " << carro[j]->direcao << endl;
    cout << setw(25) << "|  cor      : " << carro[j]->cor << endl;
    cout << setw(25) << "|  portas   : " << carro[j]->portas << endl;
    cout << setw(25) << "|  placa    : " << carro[j]->placa << endl;
    cout << setw(25) << "|  valor    : " << carro[j]->valor << endl;
    cout << setw(38) << "---------------------------"<< endl;
  } }

int busca_placa(Tveiculo *p[], int *tamanho, string placa2){
  for(int i = 0; i < *tamanho; i++){
    if(placa2 == p[i]->placa){
      return i;
    }
  }
  return -1;
}

void remocao_placa(Tveiculo *p[], int *tamanho, string placa2){
  int result = busca_placa(p, tamanho, placa2);
  int i;
  delete (p[result]);
  for (i = result; i < *tamanho; i ++){
    p[i] = p[i + 1];
  }
  p[i+1] = NULL ;
  (*tamanho)--;
  cout << "Placa removida com sucesso!\n";
}

void insercao(Tveiculo *p[], Tveiculo *aux,int *tamanho){
  if ( (*tamanho) == 50)
    cout << "Impossível adicionar veículo! Banco de dados cheio!\n";
  else if (p[*tamanho]==NULL){
    p[*tamanho] = new Tveiculo(*aux);
    (*tamanho)++;
    cout <<"\nVeículo inserido com sucesso!!";
  }
}

void menu(){
  cout << "\n\nOpções:\n" << endl;
  cout << "[1]- Busca por placa\n[2]- Busca por valor\n[3]- Inserir veículo\n[4]- Imprimir\n[5]- Sair\n\nOpção: ";
}

void ordena(int *v, int tam) {
  int aux;
  for (int *tamanho = v + tam - 1; tamanho > v; tamanho--) {
    for (int *atual = v; atual < tamanho; atual++) {
      if (*atual > *(atual + 1)) {
        aux = *atual;
        *atual = *(atual + 1);
        *(atual + 1) = aux;
      }
    }
  }
} 


void busca_valor(int *tam, Tveiculo *carro[], int valor){
  int men = 0, ma = 0, valores[10], ant, val = 0, num, guarda_valor[*tam], cont;
  
  for (int j = 0; j < *tam; j++) {
    guarda_valor[j] = carro[j]->valor;
    if (guarda_valor[j] < valor) {
      men++; 
    }
  }
  cont = men;
  ma = *tam - men;
  ordena(guarda_valor, *tam);
  
  while (val < 10) {
    if (men > 0) {
      men--;
      valores[val++] = guarda_valor[men];
    }
    if (ma > 0) {
      ma--;
      valores[val++] = guarda_valor[cont++];
    } 
  }
  
  ordena(valores, val);

   for (int i = 0; i < 10; i++) {
     for(int j = 0; j < *tam; j++) {
       if (carro[j]->valor == valores[i]) {
         if (j != ant) {
           num = j; 
        }
      }
    }
    ant = num;
    cout << "\n" << i << ": | Veiculo " << num+1 << " |  valor: "<< valores[i] << endl;
  }
}

int main() {
  int opcao = 0, caso, tam = 0, result, w, valor;
  string placa;
  char sn;

  
  ifstream myfile;
  myfile.open("BD_veiculos_2.txt");
  if (myfile.is_open()){
    for (int i = 0; !myfile.eof(); i++){
      carro[i] = new Tveiculo;
      myfile >> carro[i]->modelo;
      myfile >> carro[i]->marca;
      myfile >> carro[i]->tipo;
      myfile >> carro[i]->ano;
      myfile >> carro[i]->km;
      myfile >> carro[i]->potencia;
      myfile >> carro[i]->combustivel;
      myfile >> carro[i]->cambio;
      myfile >> carro[i]->direcao;
      myfile >> carro[i]->cor;
      myfile >> carro[i]->portas;
      myfile >> carro[i]->placa;
      myfile >> carro[i]->valor;
      tam++;
    }
    myfile.close();

  }
  else{
    cout << "Impossível abrir o arquivo." << endl;
    return 0;
  }
  
  do{
      system ("clear");
      menu();
      cin >> opcao;
      switch (opcao){
        
      case 1: 
          cout << "Placa: ";
          cin >> placa;
          cout << endl;
          result = busca_placa(carro, &tam, placa);
          if (result == -1){
            cout << "\nPlaca não encontrada!\n" << endl;
            getchar();
            getchar();
          }else {
            cout << "\nPlaca encontrada\n" << endl;
            cout << "Deseja remover o veículo?(S/N): ";
            do {
              cin >> sn;
              if (sn == 'S'){
                remocao_placa(carro, &tam, placa);
              }
              else if (sn == 'N'){
                cout << "\nVeículo não removido";
              }
              else {
                cout << "Isso não é uma opção!" << endl;
            } }while(sn != 'S' && sn != 'N'); }
         break;

      case 2:
        cout << "Digite o valor de compra desejado: \n\n";
        cin >> valor;
        busca_valor(&tam, carro, valor);
        getchar();
        getchar();
        break;

      case 3:  
         cout << "Placa: ";
         cin >> placa;
         w = busca_placa(carro, &tam, placa);
         if (w == -1) {
          cout << "\nPlaca não encontrada, veículo apto para ser inserido!\n\n" << endl;
          aux = new Tveiculo;
          aux->placa = placa;
          cout << "modelo: " ;
          cin >> aux->modelo;
          cout << "marca: " ;
          cin >> aux->marca;
          cout << "tipo: ";
          cin >> aux->tipo;
          cout << "ano: ";
          cin >> aux->ano;
          cout << "km: " ;
          cin >> aux->km;
          cout << "potencia: " ;
          cin >> aux->potencia;
          cout << "comb: " ;
          cin >> aux->combustivel;
          cout << "cambio: " ;
          cin >> aux->cambio;
          cout << "direcao:" ;
          cin >> aux->direcao;
          cout << "cor: " ;
          cin >> aux->cor;
          cout << "portas: " ;
          cin >> aux->portas;
          cout << "valor: " ;
          cin >> aux->valor;
          insercao(carro,aux,&tam);
          delete (aux);
        }
         else 
           cout << "\nVeículo já existe";
         break;
        case 4:
          imprime(&tam, carro);
          cout << "\n\n Deseja fazer mais alguma alteração? (S/N): ";
          cin >> sn;
          if (sn == 'S')
            opcao = 1;
          else if (sn == 'N')
            opcao = 5;
          else
            cout << "\nOpção inválida! ";
        break;
        default:
          if (opcao != 5)
            cout << "Opção inválida!!\n";
    }
  }while(opcao!=5);

  system("clear");
  ordena_placa(&tam, carro);
  
  cout << "\n\n    O arquivo 'BD_veiculos_2-ord.txt' está ordenado de acordo com as placas dos veículos.\n\n" << endl;
  return 0;
}
