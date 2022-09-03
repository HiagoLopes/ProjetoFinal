#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
using namespace std;

// funções de interface 
void opcoes (){ // mostra as opções que o programa executa
	cout<<"_____________________"<<endl;
	cout<<"			CONTROLE DE ESTOQUE					"<<endl;
	cout<<"	 Escolha uma opcao a seguir para realizar uma acao	"<<endl;
	cout<<"1: Cadastrar um medicamento                        "<<endl;
	cout<<"2: Consultar um medicamento						"<<endl;
	cout<<"3: Listar medicamentos cadastrados					"<<endl;
	cout<<"4: Excluir um medicamento							"<<endl;
	cout<<"5: Efetuar uma venda 								"<<endl;
	cout<<"6: Listar dados de medicamentos em estoque			"<<endl;
	cout<<"7: Exportar dados									"<<endl;
	cout<<"8: Sair											"<<endl;
	cout<<"_____________________"<<endl;
} 

// registro que armazena os dados
struct registroMedicamento
{
    string NomeMedicamento;
    string DescricaoDoMedicamento;
    string NomeDoLaboratorio;
    int id_Medicamento;
    int QuantidadeDisponivel;
    int Preco;
};

// função redimensiona 
registroMedicamento* redimensiona (registroMedicamento *v, int &capacidade) // redimensiona o vetor de registro em 20% sempre que o vetor estiver totalmente preenchido
{
    int aumento = capacidade * 0.2;

    //cout << "Endereco antigo: " << v << endl;

	registroMedicamento *novo = new registroMedicamento[capacidade + aumento];
	
	memcpy(novo,v,(sizeof(registroMedicamento)*capacidade));

    capacidade = capacidade + aumento;

    //cout << "Endereco novo: " << novo << endl;
    cout << "Capacidade do vetor: " << capacidade << endl;

    delete [] v;

    return novo; 
}


// função para incluir 

registroMedicamento* incluir (registroMedicamento *v, int &tamanho, int &inserir)
{
    if (inserir < tamanho)
    {
        cout << "Numero de medicamentos inseridos: " << inserir << endl;
        cout << "Codigo do Medicamento: ";
        cin.ignore();
        cin>> v[inserir].id_Medicamento;
        cout << "Nome do medicamento: ";
        cin.ignore();
        getline(cin,v[inserir].NomeMedicamento);
        cout << "Descricao do medicamento: ";
        cin.ignore();
        getline(cin,v[inserir].DescricaoDoMedicamento);
        cout << "Nome do laboratorio: ";
        cin.ignore();
        getline(cin,v[inserir].NomeDoLaboratorio);
        cout << "Quantidade disponivel: ";
        cin>> v[inserir].QuantidadeDisponivel;
        cout<<"Preco: ";
        cin>> v[inserir].Preco;
	}
	
	else{
		
		int posicao = 0;
	
		while ((posicao < tamanho) and (v[posicao].NomeMedicamento != "-1")){
			posicao++;
		}
		
		if (posicao < tamanho){
			cout << "posicao:" << posicao << endl;
			cout << "Codigo do Medicamento: ";
			cin >> v[posicao].id_Medicamento;
			cout << "Informe o nome do medicamento: ";
			cin.ignore();
			getline(cin, v[posicao].NomeMedicamento);
			cout << "Informe a descrição do medicamento ";
			cin >> v[posicao].DescricaoDoMedicamento;
			cout << "Informe o nome do Laboratorio: ";
			cin.ignore();
			getline(cin, v[posicao].NomeDoLaboratorio);
            cout << "Informe a quantidade disponivel: ";
            cin >> v[posicao].QuantidadeDisponivel;
            cout << "Informe o Preco: ";
            cin >> v[posicao].Preco;
			inserir--;
		}
		
		else
        {
		
			v = redimensiona(v, tamanho);

			cout << "posicao:" << posicao << endl;
			cout << "Codigo do Medicamento: ";
			cin >> v[posicao].id_Medicamento;
            
			cout << "Informe o nome do medicamento: ";
			cin.ignore();
			getline(cin, v[posicao].NomeMedicamento);
            
			cout << "Informe a descrição do medicamento ";
			cin >> v[posicao].DescricaoDoMedicamento;
            
			cout << "Informe o nome do Laboratorio: ";
			cin.ignore();
			getline(cin, v[posicao].NomeDoLaboratorio);
            
            cout << "Informe a quantidade disponivel: ";
            cin >> v[posicao].QuantidadeDisponivel;
            
            cout << "Informe o Preco: ";
            cin >> v[posicao].Preco;
            
        }
    }
    
    return v;
}


// função para listar todas as series incluidas
void listar (registroMedicamento *v, int inserir)
{

    for (int i = 0; i <= inserir; i++)
        if (v[i].NomeMedicamento != "-1")
        {
            cout << "Nome do medicamento: " << i << endl;
            cout << "Descricao do medicamento: " << v[i].DescricaoDoMedicamento << endl;
            cout << "Nome do laboratorio: " << v[i].NomeDoLaboratorio << endl;
	        cout << "Codigo de identificacao: " << v[i].id_Medicamento << endl ;
	        cout << "Quantidade disponivel: "<< v[i].QuantidadeDisponivel << endl;
	        cout << "Preco: " << v[i].Preco << endl;
            cout << "----------------------------" << endl;
        }
    
} 

// função para ordenar os medicamentos
// (3) listar

void quick(registroMedicamento *vetor, int inicio, int fim)    // utiliza o método quick sort para fazer a ordençao
{ 
    int i, j, meio;
    int aux, pivo;
   
    i = inicio;
    j = fim;
   
    meio = (int) ((i + j) / 2);
    pivo = vetor[meio].id_Medicamento;
   
    do{
        while (vetor[i].id_Medicamento < pivo) 
            i = i + 1;
        while (vetor[j].id_Medicamento > pivo) 
            j = j - 1;
      
        if (i <= j){
            aux = vetor[i].id_Medicamento;
            vetor[i].id_Medicamento = vetor[j].id_Medicamento;
            vetor[j].id_Medicamento = aux;
            i = i + 1;
            j = j - 1;
        }
    }
    while(j > i);
   
    if(inicio < j) 
        quick(vetor, inicio, j);

    if(i < fim) 
        quick(vetor, i, fim);   
}

// função para buscar algum campo
int buscar(registroMedicamento remedio[], int tamanho, int opcao)// utiliza busca sequencial para varrer o vetor
{
    int preco,Disponivel ;
    string nome, Laboratorio, medicamento ;
    
    quick(remedio, 0, opcao);
    
    switch(opcao)
    {
        case 1: 
        cout << "Identificador: " ;// função usada para busca sequencial pelo identificador.
        cin >> medicamento;
        for(int i = 0; i < tamanho; i++)
            if(medicamento == remedio[i].id_Medicamento)
                return i;
        break;

        case 2: 
        cout << "Nome: "; // função usada para busca sequencial pelo nome.
        cin >> nome;
        for(int i = 0; i < tamanho; i++)
            if(nome == remedio[i].nome)
                return i;
        break;

        case 3: cout << "Laboratorio: ";	// função usada para busca sequencial pelo pais de origem.
        cin >> Laboratorio;
        for(int i = 0; i < tamanho; i++)
            if(laboratorio == remedio[i].Laboratorio)
                return i;
        break;

        case 4: cout << "Descriçao deo medicamento: ";	// função usada para busca sequencial pelo elenco principal.
        cin >> Descricao;
        for(int i = 0; i < tamanho; i++)
            if(elenco == remedio[i].Descricao)
                return i;
        break;
        
        case 5: cout << "Quantidade disponivel: ";	// função usada para busca sequencial pelo elenco principal.
        cin >> Disponivel;
        for(int i = 0; i < tamanho; i++)
            if(elenco == remedio[i].Disponivel)
                return i;
        break;
        
        case 6: 
        cout << "Preço: "; // função usada para busca sequencial pelo preço.
        cin >> preco;
        for(int i = 0; i < tamanho; i++)
            if(preco == remedio[i].preco)
                return i;
        break;
                
        default: 
        cout << "Valor Invalido. Voltando ao menu principal..." << endl;
        return -1;	// para retornar ao menu, com um valor invalido
    }
}


// funcao para excluir
void excluir(registroSerie serie[], int tamanho)
{	
    int posicao, opcao;
        cout << "Por qual campo voce deseja excluir?" << endl << endl;
        cout << "1 -  Codigo do Medicamento " << endl;
        cout << "2 -  Nome do medicamento" << endl;
        cout << "3 -  Descricao do medicamento " << endl;
        cout << "4 -  Nome do laboratorio " << endl;
        cout << "5 -  Quantidade disponivell " << endl << endl;
        cout << "6 -  Precol " << endl << endl;
        cout << "Digite o campo escolhido: ";
        cin >> opcao; 
        posicao = buscar(remedio, tamanho, opcao);				
        remedio[posicao].nome = "-1";
        cout << "Medicamento excluido com sucesso!" << endl << endl;     
}

// função principal
int main ()
{
    int numeroE = 0, inserir = -1, tamanho = 7 ;
    char escolha;


	registroSerie *serie = new registroSerie[tamanho]; // aloca dinamicamente o vetor de registros

    while (numeroE != 8)
    {
        opcoes(); // chama a função interface opcoes
        cin >> numeroE; // le a opcao digitada pelo usuario

        switch (numeroE) 
        {
            case (1):
            //bloco de comandos (função incluir)
            do {
				inserir++;
                cout << "Digite as informacoes a seguir:" << endl;
		        if (inserir == tamanho)
                    remedio = redimensiona(remedio, tamanho); // vetor de registros redimensiona o tamanho
                incluir (remedio, tamanho, inserir); // chama a função incluir e inclui uma nova serie
                cout << endl << endl << "Sucesso ao cadastrar o medicamento." << endl;
                system("cls");
                cout << "Gostaria de cadastrar uma serie novamente? [S/N]" << endl;
                cin >> simnao;
                system("cls");
            }
            while ((simnao == 's') or (simnao == 'S'));
            break;

            case (2):
            //bloco de comandos (função excluir)            
            excluir(remedio,tamanho); // chama a função excluir
                tamanho--;
                inserir--;
            break;

            case (3):
            //bloco de comandos (função listar)
            cout << "Lista de Medicamentos:" << endl;
            listar (remedio, inserir); // chama a função listar
            break;
            
            case (4):
            //bloco de comandos (função alterar)
            alterar (remedio, tamanho); // chama a função alterar
            break;
            
            case (5):
            //bloco de comandos (função ordenar)
            quick(remedio, 0, inserir + 1); // chama a função ordenar 
            system("cls");
            cout << endl <<"Lista ordenada com sucesso! Gostaria de listar? [S/N]";
            cin >> simnao;
            if ((simnao == 'S') or (simnao == 's'))
                listar (remedio, inserir);
            break;
            
            case (6):
            // sair
            system("cls");
            cout << "Obrigado por acessar o nosso sistema, " << nome << "!" << endl;
            break;
        }
    }
    
    return 0;
}
