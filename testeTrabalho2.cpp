#include <iostream>
#include <string.h>
using namespace std;

// funções de interface 
void opcoes (){ // mostra as opções que o programa executa
	cout<<"___"<<endl;
	cout<<"			CONTROLE DE ESTOQUE					"<<endl;
	cout<<"	 Escolha uma opcao a seguir para realizar uma acao	"<<endl;
	cout<<"(1): Cadastrar um medicamento                        "<<endl;
	cout<<"(2): Consultar um medicamento						"<<endl;
	cout<<"(3): Listar medicamentos cadastrados					"<<endl;
	cout<<"(4): Excluir um medicamento							"<<endl;
	cout<<"(5): Efetuar uma venda 								"<<endl;
	cout<<"(6): Listar dados de medicamentos em estoque			"<<endl;
	cout<<"(7): Exportar dados									"<<endl;
	cout<<"(8): Sair											"<<endl;
	cout<<"___"<<endl;
} 

// registro que armazena os dados
struct registroMedicamento{
    string NomeMedicamento;
    string DescricaoDoMedicamento;
    string NomeDoLaboratorio;
    string CodigoDeIdentificacao;
    int QuantidadeDisponivel;
    float Preco;
};



// função para incluir 
registroMedicamento* incluir (registroMedicamento *v, int &tamanho, int &inserir){
    if (inserir < tamanho){
        cout << "Nome do medicamento: ";
        cin.ignore();
		getline(cin,v[inserir].NomeMedicamento);
		cout << "Descricao do medicamento: ";
		getline(cin,v[inserir].DescricaoDoMedicamento);
		cout << "Nome do laboratorio: ";
		getline(cin,v[inserir].NomeDoLaboratorio);
		cout << "Codigo de identificacao: ";
		cin>> v[inserir].CodigoDeIdentificacao;
		cout << "Quantidade disponivel: ";
		cin>> v[inserir].QuantidadeDisponivel;
		cout<<"Preco: ";
		cin>> v[inserir].Preco;
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
            cout << "Codigo de identificacao: " << v[i].CodigoDeIdentificacao<< endl ;
            cout << "Quantidade disponivel: "<< v[i].QuantidadeDisponivel << endl;
            cout << "Preco: " << v[i].Preco << endl;
            cout << "----------------------------" << endl;
        }

} 

void excluir(registroMedicamento medicamento[], int tamanho)
{	
    //int posicao, opcoes;
        cout << "Por qual campo voce deseja excluir?" << endl << endl;
        cout << "1 -  Codigo do Medicamento " << endl;
        cout << "2 -  Nome do medicamento" << endl;
        cout << "3 -  Descricao do medicamento " << endl;
        cout << "4 -  Nome do laboratorio " << endl;
        cout << "5 -  Quantidade disponivell " << endl << endl;
        cout << "6 -  Precol " << endl << endl;
        cout << "Digite o campo escolhido: ";
        //cin >> opcoes; 
        //posicao = consulta(medicamento, tamanho, opcoes);				
        //medicamento[posicao].NomeMedicamento = "-1";
        cout << "Medicamento excluido com sucesso!" << endl << endl;     
}


int main ()
{

    int numeroE = 0, inserir = -1, tamanho = 7;
    char escolha;

	registroMedicamento *medicamento = new registroMedicamento[tamanho]; // aloca dinamicamente o vetor de registros

    while (numeroE != 8)
    {
        opcoes(); // chama a função interface opcoes
        cin >> numeroE; // le a opcao digitada pelo usuario
        switch (numeroE) 
        {
            case (1):
            //bloco de comandos (função incluir)
            {
                escolha='s';
            while(escolha == 's' or escolha == 'S'){
                inserir++;
                cout << "Digite as informacoes" << endl;
                incluir (medicamento, tamanho, inserir); // chama a função incluir e inclui uma nova serie
                cout << endl << endl << "Cadastrado com sucesso" << endl;
                cout << "Cadastrar mais um medicamento? s/n" << endl;
                cin >> escolha;

            }
        }

            break;
            case(2):
            {
            string medicamentoProcurado;
            int RemedioEncontrado = 0;
            cout<<"Digite o nome do medicamento procurado: ";
            cin.ignore();
            getline(cin, medicamentoProcurado);
            for(int i=0; i<=inserir; i++)
            {
                if(medicamentoProcurado == medicamento[i].NomeMedicamento)
                {
                    cout<<"Nome: "<<medicamento[i].NomeMedicamento<<endl<<  "Descricao do medicamento: "<<medicamento[i].DescricaoDoMedicamento<<endl;
                    cout<<"Nome do laboratorio: "<<medicamento[i].NomeDoLaboratorio<<endl<< "Codigo de identificacao: "<<medicamento[i].CodigoDeIdentificacao<<endl;
                    cout<< "Quantidade disponivel: "<<medicamento[i].QuantidadeDisponivel<<endl<<"Preco: "<<medicamento[i].Preco<<endl;
                    RemedioEncontrado=1;	

                }
            }
                if(RemedioEncontrado != 1)
                {
                    cout<<"Remedio nao encontrado";
                }
            } 
            break;
			case (3):
			//bloco de comandos (função listar)
			cout << "Lista de Medicamentos:" << endl;
			listar (medicamento, inserir); // chama a função listar
			break;
			
			case (4):
			//bloco de comandos (função excluir)            
			excluir(medicamento,tamanho); // chama a função excluir
				tamanho--;
				inserir--;
			break;
			
		}
	}
      
	system("cls");
	if(numeroE==8)
		cout<<"Encerrando Sistema...";
		
     return 0;
 }
