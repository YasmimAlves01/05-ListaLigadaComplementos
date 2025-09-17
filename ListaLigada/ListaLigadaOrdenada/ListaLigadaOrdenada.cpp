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
		system("cls"); // somente no windows
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

		system("pause"); // somente no windows
	}
}

void inicializar()
{
// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	NO* ajd = ultimo;
	while (aux != NULL && ajd != NULL) {
		NO* paraExcluir = aux;
		NO* paraResetar = ajd;
		aux = aux->prox;
		ajd = ajd->prox;
		free(paraExcluir);
		free(paraResetar);
	}

	ultimo = NULL;
	primeiro = NULL;
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
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	NO* atual = primeiro;
	NO* anterior = NULL;

	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	// passa por cada item da fila para achar oq seja maior ao numero digitado, enquanto for menor ao numero digitado ele continua andando
	while(atual != NULL && atual->valor < novo->valor)
{
		anterior = atual;
		atual = atual->prox;

}		

		// se o numero ja existe ele não insere
		if(atual != NULL && atual->valor == novo->valor){
			cout << "numero existe";
			free(novo);
			return;
		}
		// se o digitado for menor que todos os outros, ou seja, o anterior ao encaixe dele for null, ele vira o primeiro 
		if(anterior == NULL){
			novo->prox = primeiro;
			primeiro = novo;
		}
		// caso contrario, ele se encaixa entre o anterior e o atual
		/*
		* exemplo: Digitei o numero 5
		* Lista: [2][4][7]
		*o ponteiro vai rodar até chegar ao [7] pois ele é maior que 5
		* o numero digitado (5) vai se encaixar entre o anterior [4] que foi onde o ponteiro passou e o [7] que é onde o ponteiro se encontra atualmente e onde achou o espaço para o 5
		*/
		else{
			novo->prox = atual;
			anterior->prox = novo;
		}

}

void excluirElemento()
{
	int excluir;
	NO* atual = primeiro;
	NO* anterior = NULL;

	cout << "Por favor digite o valor que voc� quer excluir: \n";
	cin >> excluir;
	

	// se o atual (primeiro digitio) for diferente de Null ele entra no while
	while (atual != NULL)
	{


		// se o valor do atual for igual ao digitado pelo usuarioa entra dentro do if e começa o processo de excluir
		if (atual->valor == excluir)
		{
		
		// se o anterior for igual a null significa que o numero é o primeiro, então ele apaga o primeiro e tranforma o primeiro no valor do proximo
		if (anterior == NULL)
		{
			primeiro = atual->prox;
		}
		// se não for o primeiro da lista então o nó anterior pula o numero que foi digitado em excluir e faz o anterior apontar direto para o proximo
		/*
		*Exemplo: [1][2][5][8]
		*voce quer excluir o [5], então o ponteiro que esta no [2] vai pular o [5] e substituir esse apontamento para apontar para o [8], substituindo o lugar do [5] pelo do [8] e assim apagando o [5] sem deixar rastros. 
		* o free(atual) apaga o valor do [5] da memoria, ja que o ponteiro atual estava em cima do [5]
		*/
		else
		{
			
			anterior->prox = atual->prox;
		}
			free(atual);
			
			cout << "numero excluido com sucesso!\n";
			return;
		}		
		
		// se durante a busca ele achar um numero maior que o digitado, significa que o digitado não existe, pois como a lista esta em ordem não tem como o numero digitado estar depois de um numero maior que ele
		if(atual->valor > excluir)
		{
			cout << "NUMERO NÃO ENCONTRADO\n";
			return;
		}

		// Avança na lista: o 'anterior' passa a ser o 'atual',
		// e o 'atual' vai para o próximo nó da lista.
		anterior = atual;
		atual = atual->prox;
	}
}

void buscarElemento()
{
	NO* aux = primeiro;
	int digitado;

	cout << "Digite o elemento: ";
	cin >> digitado;

	// NO* pos = posicaoElemento(digitado);
	

	while(aux != NULL){

	if (aux->valor == digitado) {
		cout << "ENCONTRADO\n";
		return;
	}
	
	if(aux->valor > digitado) {
		cout << "ELEMENTO NÃO ENCONTRADO\n";
		break;
	}
	aux = aux->prox;
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







// resto do inserir
	// if (primeiro == NULL)
	// {
		

		
	// 	primeiro = novo;
	// }
	// else
	// {
	// 	// procura o final da lista
	// 	NO* aux = primeiro;
	// 	while (aux->prox != NULL) {
	// 		aux = aux->prox;
	// 	}
	// 	aux->prox = novo;
	// }