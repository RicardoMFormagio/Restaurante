
#include<stdio.h>
#include<stdlib.h>
#include <stdlib.h>
#include <string.h>

	
//////////// Projeto fila


//DEFEINE A STRUCT FILA
struct Fila {
	int capacidade;
	int *dados;
	int primeiro;
	int ultimo;
	int nItens; 
};

//FUNÃ‡ÃƒO QUE CRIA FILAS
void criarFila( struct Fila *f, int c ) { 
	f->capacidade = c;
	f->dados = (int*) malloc (f->capacidade * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 
}

//FUNÃ‡ÃƒO QUE INSERE SENHAS NAS FILAS
void inserir(struct Fila *f, int v) {
	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido
}

//FUNÃ‡ÃƒO QUE REMOVE SENHAS DA FILA
int remover( struct Fila *f ) { // pega o item do comeÃƒÂ§o da fila
	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro
	if(f->primeiro == f->capacidade)
		f->primeiro = 0;
	f->nItens--;  // um item retirado
	return temp;
}

//FUNÃ‡ÃƒO QUE RETORNA SE FILA ESTA VAZIA
int estaVazia( struct Fila *f ) { // retorna verdadeiro se a fila estÃƒÂ¡ vazia
	return (f->nItens==0);
}

//FUNÃ‡ÃƒO QUE RETORNA SE FILA ESTA CHEIA
int estaCheia( struct Fila *f ) { // retorna verdadeiro se a fila estÃƒÂ¡ cheia
	return (f->nItens == f->capacidade);
}

//FUNÃ‡ÃƒO QUE MOSTRA AS FILAS
void mostrarFila(struct Fila *f){
	int cont, i;
	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){
		printf("%i\t",f->dados[i++]);
		if (i == f->capacidade)
			i=0;
	}
	printf("\n\n");
}

//FUNÃ‡ÃƒO MAIN
int senha () {

	//DEFINE CAPACIDADE DAS FILAS NORMAL E PREFERENCIAL
	int capa=10;
	int capapreferencial=5;
	
	int opcao, auxnormal, auxpreferencial;
	int valor=0;
	struct Fila umaFila;
	struct Fila preferencialFila;
	char op;
	
	//CRIA FILA NORMAL
	//printf("\nCapacidade da fila normal? ");
	//scanf("%d",&capa);
	criarFila(&umaFila, capa);
	
	//CRIA FILA PREFERENCIAL
	//printf("\nCapacidade da fila preferencial? ");
	//scanf("%d",&capapreferencial);
	criarFila(&preferencialFila, capapreferencial);
	
	//APRESENTA MENU
	do{
		system("clear");
		// 0 for background Color(Black) 
   		// A for text color(Green) 
    	system("Color 0A"); 
    	//https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/
    	
    	        //verifica se a fila normal esta vazia
    			if (estaVazia(&umaFila)){
						printf("\nFila normal vazia!!!\n\n");
					}
					else {
						printf("\nConteudo da fila normal => ");
						mostrarFila(&umaFila);

					}
					
				//verifica se a fila preferencial esta vazia
				if (estaVazia(&preferencialFila)){
						printf("\nFila preferencial vazia!!!\n\n");
					}
					else {
						printf("\nConteudo da fila preferencial => ");
						mostrarFila(&preferencialFila);
						printf("\n\n");
					}
		printf("1- Gerar senha normal \n"); 
		printf("2- Gerar senha preferencial \n"); 
		printf("3- Chamar \n"); 
		printf("9- FIM \n");
		scanf("%i", &opcao); 
		switch(opcao){ 

		case 1: //INSERE SENHA NORMAL
		printf("1- Gerar senha normal \n"); 
				if (estaCheia(&umaFila)){
					printf("\nFila Cheia!!!\n\n");
					printf("Tecle Enter");
					scanf ("%c%c",&op, &op);
				}
				else {
					valor++;
					inserir(&umaFila,valor);
				}
				break;
			case 2: //INSERE SENHA PREFERENCIAL
			printf("2- Gerar senha preferencial \n"); 
				if (estaCheia(&preferencialFila)){
					printf("\nFila Cheia!!!\n\n");
					printf("Tecle Enter");
					scanf ("%c%c",&op, &op);
				}
				else {
					valor++;
					inserir(&preferencialFila,valor);
				}
				break;
				break;
			case 3: //REMOVE SENHAS DA FILA (preferenciais antes das normais)
					printf("3- Chamar \n"); 
					
					//verifica se a fila preferencial esta vazia, caso sim, remove a senha da fila normal
					if (estaVazia(&preferencialFila)){
    					if (estaVazia(&umaFila)){
    					    printf("\nFila vazia!!!\n\n");
    				    }
    				    else {
    					    auxnormal=remover(&umaFila);
    					    printf("\n%i removido com sucesso\n\n",auxnormal) ; 
    					}
    				}
    				//caso a fila preferencial tenha alguem, remove a senha da fila preferencial
    				else{
    				    auxpreferencial=remover(&preferencialFila);
    					    printf("\n%i removido com sucesso\n\n",auxpreferencial) ; 
    				    
    				}
					break;
		}
}
while (opcao!= 9);
return 0; 
} 


//*********************************CÃ“DIGO RESTAURANTE***************************
int opPrincipal, opPedido, opPrato, opBebida, opSobremesa;
int ip,ib,is,i,k;
char confPedido;
char enter;

//STRUCT LANCHES
struct Lanches {
    char nome[20];
    int quantidade;
    int preco;
};

struct Lanches lanche[5];

//BANCO DE DADOS DOS LANCHES
void bancodadoslanches(){
    strcpy(lanche[0].nome, "X-burger");
    lanche[0].quantidade = 1;
    lanche[0].preco = 20;
    
    strcpy(lanche[1].nome, "X-salada");
    lanche[1].quantidade = 1;
    lanche[1].preco = 23;
    
    strcpy(lanche[2].nome, "X-bacon");
    lanche[2].quantidade = 1;
    lanche[2].preco = 25;
    
    strcpy(lanche[3].nome, "X-egg");
    lanche[3].quantidade = 1;
    lanche[3].preco = 27;
    
    strcpy(lanche[4].nome, "X-tudo");
    lanche[4].quantidade = 1;
    lanche[4].preco = 30;
    
}

//STRUCT BEBIDAS
struct Bebidas {
    char nome[20];
    int quantidade;
    int preco;
};

struct Bebidas bebida[5];

//BANCO DE DADOS DAS BEBIDAS
void bancodadosbebidas(){
    strcpy(bebida[0].nome, "Coca-cola");
    bebida[0].quantidade = 1;
    bebida[0].preco = 5;
    
    strcpy(bebida[1].nome, "Guarana");
    bebida[1].quantidade = 1;
    bebida[1].preco = 5;
    
    strcpy(bebida[2].nome, "Suco de laranja");
    bebida[2].quantidade = 1;
    bebida[2].preco = 8;
    
    strcpy(bebida[3].nome, "Suco de caju");
    bebida[3].quantidade = 1;
    bebida[3].preco = 8;
    
    strcpy(bebida[4].nome, "Suco de maracuja");
    bebida[4].quantidade = 1;
    bebida[4].preco = 8;
    
}

//STRUCT SOBREMESAS
struct Sobremesas {
    char nome[20];
    int quantidade;
    int preco;
};

struct Sobremesas sobremesa[5];

//BANCO DE DADOS DAS SOBREMESAS
void bancodadossobremesas(){
    strcpy(sobremesa[0].nome, "Pudim");
    sobremesa[0].quantidade = 1;
    sobremesa[0].preco = 7;
    
    strcpy(sobremesa[1].nome, "Bolo de chocolate");
    sobremesa[1].quantidade = 1;
    sobremesa[1].preco = 7;
    
    strcpy(sobremesa[2].nome, "Bolo de morango");
    sobremesa[2].quantidade = 1;
    sobremesa[2].preco = 7;
    
    strcpy(sobremesa[3].nome, "Milk shake");
    sobremesa[3].quantidade = 1;
    sobremesa[3].preco = 10;
    
    strcpy(sobremesa[4].nome, "Sundae");
    sobremesa[4].quantidade = 1;
    sobremesa[4].preco = 8;
    
}

//STRUCT PEDIDO
struct Pedido {
	int prato[10];
	int bebida[10];
	int sobremesa[10];
	int precofinal;
	int dia;
	int mes;
	int hora;
	int minutos;
};

struct Pedido pedido[10];

//FUNÃ‡AO QUE GERA OS PEDIDOS
gerarPedido(){
	//Pratos escolhidos
	printf ("\n");
	printf ("Lanche(s) escolhido(s): \n");
	for (i=0; i<ip; i++){
		printf("%i\n", pedido[k].prato[i]);
	}
	printf ("\n");
	printf ("Bebida(s) escolhida(s): \n");
	for (i=0; i<ib; i++){
		printf("%i\n", pedido[k].bebida[i]);
	}
	printf ("\n");
	printf ("Sobremesa(s) escolhida(s): \n");
	for (i=0; i<is; i++){
		printf("%i\n", pedido[k].sobremesa[i]);
	}
	printf ("\n");
	printf("VALOR FINAL DO PEDIDO:       R$%d,00",pedido[k].precofinal);
	printf ("\n\n");
	printf("Digite o dia de hoje: ");
	scanf("%d",&pedido[k].dia);
	printf("digite o mes de hoje: ");
	scanf("%d",&pedido[k].mes);
	printf("Digite a hora atual (foramato 24h): ");
	scanf("%d",&pedido[k].hora);
	printf("Digite os minutos atuais: ");
	scanf("%d",&pedido[k].minutos);
	senha();
	printf ("Confirma pedido? s/n");
	scanf("%c%c",&confPedido,&enter);
}


//FUNÃ‡ÃƒO ESCOLHER LANCHE
void menuPrato(){
    printf ("********** Menu de lanches **********\n");
    bancodadoslanches ();
    int j;
    
    for (j=0;j<5;j++) printf("%d - %-20s    R$%d,00\n",j+1,lanche[j].nome,lanche[j].preco);
    
    printf ("Escolha: ");
    scanf ("%i",&opPrato);
    switch (opPrato){
    	case 1:
    		pedido[k].prato[ip]=1;
    		pedido[k].precofinal+=lanche[opPrato-1].preco;
    		printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    		break;
    	case 2:
    		pedido[k].prato[ip]=2;
    		pedido[k].precofinal+=lanche[opPrato-1].preco;
    		printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    		break;
    	case 3: 
    		pedido[k].prato[ip]=3;
    		pedido[k].precofinal+=lanche[opPrato-1].preco;
    		printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    		break;
    	case 4: 
    		pedido[k].prato[ip]=4;
    		pedido[k].precofinal+=lanche[opPrato-1].preco;
    		printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    		break;
    	case 5: 
    		pedido[k].prato[ip]=5;
    		pedido[k].precofinal+=lanche[opPrato-1].preco;
    		printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    		break;
    }
    	ip++;
    	printf ("\n");
    	}

//FUNÃ‡ÃƒO ESCOLHE BEBIDA
void menuBebida(){
    printf ("********** Menu de Bebidas **********\n")	;
    bancodadosbebidas ();
    int j;
    
    for (j=0;j<5;j++) printf("%d - %-20s    R$%d,00\n",j+1,bebida[j].nome,bebida[j].preco);
    
    printf ("Escolha: ");
    	scanf ("%i",&opBebida);
    	switch (opBebida){
    		case 1:
    			pedido[k].bebida[ib]=1;
    			pedido[k].precofinal+=bebida[opBebida-1].preco;
    			printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    			break;
    		case 2:
    			pedido[k].bebida[ib]=2;
    			pedido[k].precofinal+=bebida[opBebida-1].preco;
    			printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    			break;
    		case 3: 
    			pedido[k].bebida[ib]=3;
    			pedido[k].precofinal+=bebida[opBebida-1].preco;
    			printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    			break;
    		case 4: 
    			pedido[k].bebida[ib]=4;
    			pedido[k].precofinal+=bebida[opBebida-1].preco;
    			printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    			break;
    		case 5: 
    			pedido[k].bebida[ib]=5;
    			pedido[k].precofinal+=bebida[opBebida-1].preco;
    			printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    			break;
    			}
    	ib++;
    	printf ("\n");
    	}
	
//FUNÃ‡ÃƒO ESCOLHE SOBREMESA
void menuSobremesa(){
    printf ("********** Menu de Sobremesas **********\n");
    bancodadossobremesas ();
    int j;
    
    for (j=0;j<5;j++) printf("%d - %-20s    R$%d,00\n",j+1,sobremesa[j].nome,sobremesa[j].preco);
    
    printf ("Escolha: ");
    scanf ("%i",&opSobremesa);
    switch (opSobremesa){
    	case 1:
    		pedido[k].sobremesa[is]=1;
    		pedido[k].precofinal+=sobremesa[opSobremesa-1].preco;
    		printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    		break;
        case 2:
    		pedido[k].sobremesa[is]=2;
    		pedido[k].precofinal+=sobremesa[opSobremesa-1].preco;
    		printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    		break;
    	case 3: 
    		pedido[k].sobremesa[is]=3;
    		pedido[k].precofinal+=sobremesa[opSobremesa-1].preco;
    		printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    		break;
    	case 4: 
    		pedido[k].sobremesa[is]=4;
    		pedido[k].precofinal+=sobremesa[opSobremesa-1].preco;
    		printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    		break;
    	case 5: 
    		pedido[k].sobremesa[is]=5;
    		pedido[k].precofinal+=sobremesa[opSobremesa-1].preco;
    		printf("VALOR DO PEDIDO:            R$%d,00",pedido[k].precofinal);
    		break;
    }
    	is++;
    	printf ("\n");
}

//FUNÃ‡ÃƒO MENU DO PEDIDO
void menuPedido(){
	system("clear");
	opPedido=1;
	ip=0;
	ib=0;
	is=0;

	
	while (opPedido!=0){
	printf ("1-Lanche\n2-Bebida\n3-Sobremesa\n0-Fechar Pedido\nEscolha: ");
	scanf ("%i",&opPedido);
	switch (opPedido){
		case 1:
		    printf("\n");
			menuPrato();
			printf("====================================");
			printf("\n\n");
			break;
		case 2:
		    printf("\n");
			menuBebida();
			printf("====================================");
			printf("\n\n");
			break;
		case 3: 
		    printf("\n");
			menuSobremesa();
			printf("====================================");
			printf("\n\n");
			break;
		case 0: 
			//gerarSenha();
			gerarPedido();
			break;
		}
	}
    k++;
}

void visualizar_pedidos() {
    int a,b;
    system("clear");
    printf("==================================================================\n");
    printf("Data | Hora | Senha | Valor\n");
    printf("==================================================================\n");

    for (a = 0; a < 10; a++) {
        
            printf("%i/%i   | %i:%i |   %i    \n", pedido[a].dia, pedido[a].mes, pedido[a].hora, pedido[a].minutos, pedido[a].precofinal);
    
    }

    printf("============================================\n");
    printf("Pressione Enter para continuar...");
    getchar();

}

//FUNÃ‡ÃƒO EDITAR LANCHES
void editarlanches(){
    int a, numlanche;

    system("clear");
    printf("================================================\n");
    printf(" Numero |    Nome    | Quantidade | Valor\n");
    printf("================================================\n");

    for (a = 0; a < 5; a++) {

            printf(" %-6i | %-10s | %-10i | R$%4i,00\n", a+1, lanche[a].nome, lanche[a].quantidade, lanche[a].preco);
        
    }

    printf("====================================================\n\n");
    
    printf("Digite o numero do lanche que deseja alterar: ");
    scanf("%d",&numlanche);
    printf("Digite o novo nome do lanche: ");
    scanf("%s",&lanche[numlanche-1].nome);
    printf("Digite o nova quantidade do lanche: ");
    scanf("%i",&lanche[numlanche-1].quantidade);
    printf("Digite o novo valor do lanche: ");
    scanf("%i",&lanche[numlanche-1].preco);
    printf("\n\nPressione Enter para continuar...");
    getchar();

}

//FUNÃ‡ÃƒO EDITAR BEBIDAS
void editarbebidas(){
    int a, numbebida;

    system("clear");
    printf("=========================================================\n");
    printf(" Numero |         Nome         | Quantidade | Valor\n");
    printf("=========================================================\n");

    for (a = 0; a < 5; a++) {
    
            printf(" %-6i | %-20s | %-10i | R$%4i,00\n", a+1, bebida[a].nome, bebida[a].quantidade, bebida[a].preco);
    }

    printf("=========================================================\n\n");
    
    printf("Digite o numero do bebida que deseja alterar: ");
    scanf("%d",&numbebida);
    printf("Digite o novo nome do bebida: ");
    scanf("%s",&bebida[numbebida-1].nome);
    printf("Digite o nova quantidade do bebida: ");
    scanf("%i",&bebida[numbebida-1].quantidade);
    printf("Digite o novo valor do bebida: ");
    scanf("%i",&bebida[numbebida-1].preco);
    printf("\n\nPressione Enter para continuar...");
    getchar();

}

//FUNÃ‡ÃƒO EDITAR SOBREMESAS
void editarsobremesa(){
    int a, numsobremesa;

    system("clear");
    printf("=========================================================\n");
    printf(" Numero |         Nome         | Quantidade | Valor\n");
    printf("=========================================================\n");

    for (a = 0; a < 5; a++) {
    
            printf(" %-6i | %-20s | %-10i | R$%4i,00\n", a+1, sobremesa[a].nome, sobremesa[a].quantidade, sobremesa[a].preco);
    }

    printf("=========================================================\n\n");
    
    printf("Digite o numero do sobremesa que deseja alterar: ");
    scanf("%d",&numsobremesa);
    printf("Digite o novo nome do sobremesa: ");
    scanf("%s",&sobremesa[numsobremesa-1].nome);
    printf("Digite o nova quantidade do sobremesa: ");
    scanf("%i",&sobremesa[numsobremesa-1].quantidade);
    printf("Digite o novo valor do sobremesa: ");
    scanf("%i",&sobremesa[numsobremesa-1].preco);
    printf("\n\nPressione Enter para continuar...");
    getchar();

}


//FUNÃ‡ÃƒO DO MENU PRINCIPAL
void menuPrincipal(){
	system("clear");
	printf ("1-Fazer Pedido\n2-Visualizar pedidos\n3-Chamar senha\n4-Editar lanches \n5-Editar bebidas\n6-Editar sobremesas\n7-Gerar senha normal \n8-Gerar senha preferencial\n0-FIM\nEscolha: ");
	scanf ("%i",&opPrincipal);
	
	getchar();
	switch (opPrincipal){
		case 1:
		    //pedido do cliente
			menuPedido();
			break;
		case 2:
		    //fila de senhas
		    visualizar_pedidos();
			break;
		case 3: 
		    //chamar Senha
		    senha();
			break;
		case 4: 
		    //Editar lanches
		    editarlanches();
			break;
		case 5: 
		    //Editar bebidas
		    editarbebidas();
			break;
		case 6: 
		    //Editar sobremesas
		    editarsobremesa();
			break;
		case 7: 
        	//INSERE SENHA NORMAL
        	break;
    	case 8: 
    		//INSERE SENHA PREFERENCIAL
    		break;
		}
	}


//FUNÃ‡ÃƒO MAIN
int main(void)
{
    bancodadoslanches();
    bancodadosbebidas();
    bancodadossobremesas();
	opPrincipal=1;
while (opPrincipal!=0){
	menuPrincipal();
}

return 0;
}
