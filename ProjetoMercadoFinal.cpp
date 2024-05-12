#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

int *codigoProduto, *x, *quant;
float *total, *subtotal;

typedef struct {
	int codigo, quantidade;
	char produto[20];
	float preco;
}Produto;

typedef struct Node{
	Produto data;
	struct Node* next;
} Node;

typedef struct stack{
	Node* top;
}Stack;

Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

Stack* stack = createStack();

Node* createNode(Produto data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertAtBeginning(Node** head, Produto data){
	Node* newNode = createNode(data);
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void displayList(Node* head) {
   
    Node* current = head;

    if (current == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("Lista de Produtos: ");
   
    while (current != NULL) {
        printf("\nCodigo do produto: %d ", current->data.codigo);
        printf("\nNome do produto: %s ", current->data.produto);
        printf("\nValor do produto: %.2f R$", current->data.preco);
        printf("\nQuantidade em estoque: %d  \n\n", current->data.quantidade);
        current = current->next;
    }
    printf("\n");
}

Node* comprandoItem(Node* head, int data){
	Node* current = head;
	if(current == NULL){
		printf("\nItem nao encontrado.");
		return NULL;
	} 
	while (current != NULL){
		if(current->data.codigo == *codigoProduto && current->data.quantidade >= *quant){
			current->data.quantidade = current->data.quantidade - *quant;
			return current;
		} else if (current->data.codigo == *codigoProduto && current->data.quantidade < *quant){
			printf("\nNao temos esse saldo no estoque \nSaldo disponivel no estoque: %d", current->data.quantidade);
			return NULL;
		}
		current = current->next;
	}
}


void renovandoItem(Node* head, int data){
		Node* current = head;
	if(current == NULL){
		printf("\nItem nao encontrado.");
		return;
	} 
	while (current != NULL){
		if(current->data.codigo == *codigoProduto){
			current->data.quantidade = current->data.quantidade + *quant;
			printf("\nValor acrescentado %d \nValor total do item apos atualizacao: %d \n", *quant, current->data.quantidade);
			return;
		}
		current = current->next;
	}
}


void push(Stack* stack, Node* current){
	Node* newNode = (Node*) malloc (sizeof(Node));
	newNode->data = current->data;
	newNode->data.preco = current->data.preco * *quant;
	newNode->next = stack->top;
	stack->top = newNode;
	*subtotal = current->data.preco * *quant;
	return;
}


void imprimirListaVendas(Stack* stack){
	Node* temp;
	temp = stack->top;
	while(temp != NULL){
		printf("\n=====================\nProduto inserido na lista de vendas: \n %s", temp->data.produto);
		printf("\nTotal desse produto: %.2f R$ \n=====================", temp->data.preco);
		temp = temp->next;
	}
}

Produto prod;
Node* head = NULL;

void cadastro(); 
void vender(); 

int main(){
	
	codigoProduto = (int*) malloc (sizeof(int));
	quant = (int*) malloc (sizeof(int));	
	total = (float*) malloc (sizeof(float));
	subtotal = (float*) malloc (sizeof(float));
	
	int op=1;
	while(op!=0){	
		
	printf("CONTROLE DE PRODUTOS\n\n\n\n");
	printf("ESCOLHA UMA DAS OPCOES A SEGUIR: \n1 - Cadastrar item\n2 - Lista de produtos\n3 - Vender\n4 - Renovar estoque\n0 - Sair\n\n\nOPCAO: ");
	scanf("%d", &op);
	system("cls");
	switch(op){
		case 1 : 
			cadastro();
			
		break;
		
		case 2 : 
			displayList(head);
			system("pause");
			system("cls");
		break;
		
		case 3 : 
			
			vender();
			printf("\nO seu total foi de : %.2f R$ \n", *total);
			system("pause");
			system("cls");
			free(total);
		break;
		
		case 4 :
			int on = 1, data;
			while(on==1){
			printf("\nDigite o codigo do item que deseja renovar: ");
			scanf("%d", codigoProduto);
			printf("\nDigite a quantidade que deseja acrescentar ao estoque: ");
			scanf("%d", quant);
			renovandoItem(head, data);
			system("pause");
			printf("\nGostaria de renovar estoque de alguem outro item? \n1 - Sim \n0 - Nao \n");
			scanf("%d", &on); 
			system("cls");
			}
		break;		
		}
	
	
	
	}
	system("cls");
	printf("\nAte a proxima!! =D");
	
	printf("\n	         /.     */               ");
printf("\n                *@@@ @@@                ");
printf("\n                *@@@@@@@                ");
printf("\n               @@/     &@@              ");
printf("\n              #@@       @@              ");
printf("\n              .@@@@@@@@@@@              ");
printf("\n          #@@@@   @@@@@   @@@@,         ");
printf("\n       .@@@      @@& @@@     .@@@       ");
printf("\n      @@@       @@@@@@@@@       @@@     ");
printf("\n     @@        @@@%%%%%@@@        @@    ");
printf("\n    @@@       @@&       @@@       @@,   ");
printf("\n     &@@@  .@@@@@@@@@@@@@@@@@   @@@(    ");
printf("\n        .@@@ @@@         @@@ @@@        ");
printf("\n              %@@@     @@@.             ");
printf("\n                 #@@@@@*                ");
printf("\n                   @@&  ");
printf("\n      GABRIEL SILVA LEMOS DOS SANTOS");

	
}


void cadastro(){
	printf("\nQuandos produtos ira cadastrar: ");
	scanf("%d", quant);
	for(int c=0; c<*quant; c++){
	printf("Digite o codigo do produto: ");
	scanf("%d", &prod.codigo);
	printf("Digite o nome do produto: ");
	scanf(" %s", &prod.produto);
	printf("Digite o valor do produto: ");
	scanf("%f", &prod.preco);
	printf("Digite a quantidade do produto: ");
	scanf("%d", &prod.quantidade);
	insertAtBeginning(&head, prod);
	system("cls");
	}
}


void vender(){
	int on=1;
	int data;
	
	while(on!=0){

	printf("\nDigite o codigo do produto: ");
	scanf("%d", codigoProduto);
	printf("\nDigite a quantidade do produto: ");
	scanf("%d", quant);
	
	Node* current = comprandoItem(head, data);

	if(current != NULL){
	push(stack, current);

	imprimirListaVendas(stack);
	
	
	*total = *total + *subtotal;
	printf("\nTotal ate o momento: %.2f R$ \n", *total);
	}
	printf("\nDeseja comprar algo mais? \n1-Sim \n0-Nao\n");
	scanf("%d", &on);
	system("cls");
	}
}


