#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls");
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause");
	}
}

void inicializar()
{
	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;

		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;

	cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	int digitado = novo->valor;

	if (posicaoElemento(novo->valor) != NULL) {
		cout << "Esse elemento ja existe\n";
		free(novo);
		return;
	}

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		ultimo->prox = novo;
		ultimo = novo;
	}
	cout << "Elemento inserido com sucesso!\n";
}

void excluirElemento()
{
	int excluir;
	NO* atual = primeiro;
	NO* anterior = NULL;

	if (primeiro == NULL) {
		cout << "a lista vazia, nada pra excluir\n";
		return;
	}

	cout << "por favor digite o valor que voce quer excluir: \n";
	cin >> excluir;

	while (atual->valor != excluir)
	{
		anterior = atual;
		atual = atual->prox;
	}

	if (atual == NULL) {
		cout << "numero nao existe na lista\n";
		return;
	}
	
	if (anterior == NULL) { 
		primeiro = atual->prox;

		if (primeiro == NULL) {
			ultimo = NULL;
		}
	}

	else {
		anterior->prox = atual->prox;

		if (atual->prox == NULL) {
			ultimo = anterior;
		}
	}

	free(atual);
	cout << "numero excluido com sucesso!\n";
}

void buscarElemento()
{
	int digitado;

	cout << "Digite o elemento: ";
	cin >> digitado;

	NO* pos = posicaoElemento(digitado);

	if (pos == NULL) {
		cout << "numero não encontrado\n";
	}
	else {
		cout << "Numero digitado existe na lista\n";
	}
}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}