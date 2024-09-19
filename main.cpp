#include <iostream>
#include "menus.cpp"
#include <cstdlib>
using namespace std;

struct DadosPessoais // Estrutura dos dados dos funcionarios
{
    string nome;
    string cpf;
    string telefone;
    string email;
};
struct Familiar // Estrutura dos dados dos familiares
{
    string nome1;
    string cpfusuario, cpffamiliar, nascimento;
};

const int MAX_FUNCIONARIOS = 100;
const int MAX_FAMILIARES = 500;

void Limpar() // Void para limpar todo os dados solicitados anteriormente
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
int main()
{
    string op;
    int qtdfamiliar = 0, qtdfuncionario = 0;
    DadosPessoais pessoas[MAX_FUNCIONARIOS];
    Familiar familiares[MAX_FAMILIARES];
    string cpfAlterar;

    do
    {
        if (qtdfuncionario == 0) // Analise para ver se esta correto oque foi digitado pelo usuario
        {
            Limpar();
            op = menu1();
            if (op == "0") // Opcao para sair do programa
            {
                cout << "Saindo...." << endl;
                return 0;
            }
            else if (op == "1") // Solicitacao dos dados dos funcionarios
            {
                cout << "Digite o nome: ";
                getline(cin, pessoas[qtdfuncionario].nome);
                cout << "Digite o CPF (Somente numeros): ";
                cin >> pessoas[qtdfuncionario].cpf;
                cout << "Digite o telefone (Somente numeros): ";
                cin >> pessoas[qtdfuncionario].telefone;
                cout << "Digite o email: ";
                cin >> pessoas[qtdfuncionario].email;
                qtdfuncionario++;
            }
            else if (op == "exit")
            {
                cout << "Saindo...." << endl;
                system("pause");
                return 0;
            }
            else // Mensagem mostrada, caso oque seja digitado nao condizer com oque se e pedido
            {
                cout << "*Opcao invalida*" << endl;
                system("pause");
                continue;
            }
        }
        else
        {
            Limpar();
            op = menu2();
            if (op == "0") // Opcao para retornar ao menu inicial
            {
                cout << "Saindo...." << endl;
                return 0;
            }
            else if (op == "1") // Opcao caso queira cadastrar outro funcionario
            {
                cout << "Digite o nome: ";
                getline(cin, pessoas[qtdfuncionario].nome);
                cout << "Digite o CPF (Somente numeros): ";
                cin >> pessoas[qtdfuncionario].cpf;
                cout << "Digite o telefone (Somente numeros): ";
                cin >> pessoas[qtdfuncionario].telefone;
                cout << "Digite o email: ";
                cin >> pessoas[qtdfuncionario].email;
                qtdfuncionario++;
            }
            else if (op == "2") // Opcao caso queira cadastrar um familiar
            {

                cout << "Nome do familiar: ";
                getline(cin, familiares[qtdfamiliar].nome1);

                cout << "Cpf do familiar (Somente numeros): ";
                cin >> familiares[qtdfamiliar].cpffamiliar;

                cout << "Cpf do Funcionario (Somente numeros): ";
                cin >> familiares[qtdfamiliar].cpfusuario;

                cout << "Data de nascimento do familiar (Somente numeros): ";
                cin >> familiares[qtdfamiliar].nascimento;
                qtdfamiliar++;
            }
            else if (op == "3") // Opcao caso queira Listar dados
            {
                if (qtdfamiliar == 0) // Analise para ver se possui familiar
                {
                    op = menu3_1();
                    if (op == "0") // Opcao para retornar ao menu inicial
                    {
                        continue;
                    }
                    else if (op == "1") // Listar dados dos funcionarios
                    {
                        cout << endl;
                        cout << "---- DADOS PESSOAIS FUNCIONARIOS ----" << endl;
                        cout << endl;
                        for (int i = 0; i < qtdfuncionario; i++) // Repeticao para mostrar todos os funcionarios
                        {
                            cout << "Nome: " << pessoas[i].nome << endl;
                            cout << "CPF: " << pessoas[i].cpf << endl;
                            cout << "Telefone: " << pessoas[i].telefone << endl;
                            cout << "Email: " << pessoas[i].email << endl;
                            cout << endl;
                        }
                        cout << "-------------------------------------" << endl;
                        system("pause");
                    }
                    else // Analise caso oque seja solicitado nao seja oque foi pedido
                    {
                        cout << "*Opcao invalida*" << endl;
                        system("pause");
                        continue;
                    }
                }
                else // Condicao caso aja Familiar
                {
                    op = menu3_2();
                    if (op == "0")
                    {
                        continue;
                    }
                    if (op == "1") // Opcao para mostrar todos os Funcionarios
                    {
                        cout << endl;
                        cout << "---- DADOS PESSOAIS FUNCIONARIOS ----" << endl;
                        cout << endl;
                        for (int i = 0; i < qtdfuncionario; i++) // Estrutura para aparecer cada funcionario
                        {
                            cout << "Nome: " << pessoas[i].nome << endl;
                            cout << "CPF: " << pessoas[i].cpf << endl;
                            cout << "Telefone: " << pessoas[i].telefone << endl;
                            cout << "Email: " << pessoas[i].email << endl;
                            cout << endl;
                        }
                        cout << "-------------------------------------" << endl;
                        system("pause");
                    }

                    if (op == "2") // Opcao para ver o menu sobre os Familiares
                    {
                        op = menu3_2_1();
                        if (op == "0") // Analise para se solicitado, voltar ao primeiro menu
                        {
                            continue;
                        }
                        if (op == "1") // Opcao para mostrar todos os Familiares
                        {
                            cout << endl;
                            cout << "---- DADOS PESSOAIS FAMILIARES ----" << endl;
                            cout << endl;
                            for (int i = 0; i < qtdfamiliar; i++) // Estrutura para mostrar todos os familiares
                            {
                                cout << "Nome do familiar: " << familiares[i].nome1 << endl;
                                cout << "CPF do familiar: " << familiares[i].cpffamiliar << endl;
                                cout << "CPF do funcionario: " << familiares[i].cpfusuario << endl;
                                cout << "Data de nascimento: " << familiares[i].nascimento << endl;
                                cout << endl;
                            }
                            cout << "-----------------------------------" << endl;
                            system("pause");
                        }
                        else if (op == "2") // Opcao para buscar dados dos Familiares pelo funcionario
                        {
                            cout << endl;
                            cout << "Digite o CPF do funcionario (Somente numeros): ";
                            cin >> cpfAlterar;
                            cout << "---- DADOS PESSOAIS FAMILIARES ----" << endl;
                            cout << endl;
                            for (int i = 0; i < qtdfamiliar; i++) // Analise de cada Familiar
                            {
                                if (cpfAlterar == familiares[i].cpfusuario) // Comparacao de qual Familiar mostrar os dados
                                {
                                    cout << "Nome do familiar: " << familiares[i].nome1 << endl;
                                    cout << "CPF do familiar: " << familiares[i].cpffamiliar << endl;
                                    cout << "CPF do funcionario: " << familiares[i].cpfusuario << endl;
                                    cout << "Data de nascimento: " << familiares[i].nascimento << endl;
                                    cout << endl;
                                }
                            }
                            cout << "-----------------------------------" << endl;
                            system("pause");
                        }
                        else // Analise caso oque seja solicitado nao seja oque foi pedido
                        {
                            cout << "*Opcao invalida*" << endl;
                            system("pause");
                            continue;
                        }
                    }
                }
            }

            else if (op == "4") // Caso o funcionario tenha familiar
            {
                if (qtdfamiliar == 0)
                {
                    op = menu4_1();
                    if (op == "0") // Opcao para retornar ao menu inicial
                    {
                        continue;
                    }
                    if (op == "1") // Opcao caso queira alterar algo do funcionario
                    {
                        cout << endl;
                        cout << "Digite o CPF do funcionario que deseja alterar (Somente numeros): ";
                        cin >> cpfAlterar;

                        op = menu4_2_3();
                        if (op == "1") // Opcao para ver qual Nome alterar
                        {
                            for (int i = 0; i < qtdfuncionario; i++) // Verificacao de cada funcionario
                            {
                                if (cpfAlterar == pessoas[i].cpf) // Comparacao para encontrar o Nome da pessoa para alterar
                                {
                                    cout << "Digite o novo nome: ";
                                    getline(cin, pessoas[i].nome);
                                    break;
                                }
                            }
                        }
                        else if (op == "2")
                        {
                            for (int i = 0; i < qtdfuncionario; i++) // Verificacao de cada funcionario
                            {
                                if (cpfAlterar == pessoas[i].cpf) // Comparacao para encontrar o CPF da pessoa para alterar
                                {
                                    cout << "Digite o novo CPF (Somente numeros): ";
                                    cin >> pessoas[i].cpf;
                                    break;
                                }
                            }
                        }
                        else if (op == "3")
                        {
                            for (int i = 0; i < qtdfuncionario; i++) // Verificacao de cada funcionario
                            {
                                if (cpfAlterar == pessoas[i].cpf) // Comparacao para encontrar o Telefone da pessoa para alterar
                                {
                                    cout << "Digite o novo telefone (Somente numeros): ";
                                    cin >> pessoas[i].telefone;
                                    break;
                                }
                            }
                        }
                        else if (op == "4") // Opcao para ver qual Email alterar
                        {
                            for (int i = 0; i < qtdfuncionario; i++) // Verificacao de cada funcionario
                            {
                                if (cpfAlterar == pessoas[i].cpf) // Comparacao para encontrar o Email da pessoa para alterar
                                {
                                    cout << "Digite o novo email: ";
                                    cin >> pessoas[i].email;
                                    break;
                                }
                            }
                        }
                        else // Opcao caso, oque foi digitado pelo usuario, nao tenha sido oque foi solicitado pelo sistema
                        {
                            cout << "*Opcao invalida*" << endl;
                            system("pause");
                            continue;
                        }
                    }

                    else if (op == "2") // Opcao caso queira excluir
                    {
                        cout << "Digite o CPF do funcionario que deseja excluir (Somente numeros): ";
                        cin >> cpfAlterar;

                        for (int i = 0; i < qtdfuncionario; i++) // Verificacao de cada funcionario
                        {
                            if (cpfAlterar == pessoas[i].cpf) // Comparacao para encontrar qual CPF excluir
                            {

                                for (; i < qtdfuncionario; i++) // Fazer o ajuste no vetor
                                {
                                    pessoas[i].nome = pessoas[i + 1].nome;
                                    pessoas[i].cpf = pessoas[i + 1].cpf;
                                    pessoas[i].telefone = pessoas[i + 1].telefone;
                                    pessoas[i].email = pessoas[i + 1].email;
                                }
                                qtdfuncionario--;
                            }
                        }
                        for (int i = 0; i <= qtdfamiliar; i++) // Verificar se tem algum familiar linkado ao CPF do funcionario que sera excluido
                        {
                            if (cpfAlterar == familiares[i].cpfusuario) // Comparacao do CPF do funcionario nos dados do familiar e o CPF do funcionario
                            {
                                for (int a = i; a < qtdfamiliar; a++) // Verificar qual familiar excluir e fazer as devidas alteracoes
                                {
                                    familiares[a].nome1 = familiares[a + 1].nome1;
                                    familiares[a].cpffamiliar = familiares[a + 1].cpffamiliar;
                                    familiares[a].cpfusuario = familiares[a + 1].cpfusuario;
                                    familiares[a].nascimento = familiares[a + 1].nascimento;
                                }
                                i--;
                                qtdfamiliar--;
                            }
                        }
                    }
                    else // Se oque for digitado nao condizer com oque se pede
                    {
                        cout << "*Opcao invalida*" << endl;
                        system("pause");
                        continue;
                    }
                }
                else // Caso o funcionario tenha familiar
                {
                    op = menu4_2();
                    if (op == "0") // Opcao para retornar ao menu inicial
                    {
                        continue;
                    }
                    else if (op == "1") // Opcao caso queira alterar algo do funcionario
                    {
                        cout << endl;
                        cout << "Digite o CPF do funcionario que deseja alterar (Somente numeros): ";
                        cin >> cpfAlterar;

                        op = menu4_2_3();
                        if (op == "1") // Opcao para ver qual Nome alterar
                        {
                            for (int i = 0; i < qtdfuncionario; i++) // Estrutura para poder comparar cada funcionario
                            {
                                if (cpfAlterar == pessoas[i].cpf) // Analise de qual funcionario alterar
                                {
                                    cout << "Digite o novo nome: ";
                                    getline(cin, pessoas[i].nome);
                                    break;
                                }
                            }
                        }
                        else if (op == "2") // Opcao para ver qual Cpf alterar
                        {
                            for (int i = 0; i < qtdfuncionario; i++) // Estrutura para poder comparar cada funcionario
                            {
                                if (cpfAlterar == pessoas[i].cpf) // Analise de qual funcionario alterar
                                {
                                    cout << "Digite o novo CPF (Somente numeros): ";
                                    cin >> pessoas[i].cpf;
                                    break;
                                }
                            }
                        }
                        else if (op == "3") // Opcao para ver qual Telefone alterar
                        {
                            for (int i = 0; i < qtdfuncionario; i++) // Estrutura para poder comparar cada funcionario
                            {
                                if (cpfAlterar == pessoas[i].cpf) // Analise de qual funcionario alterara
                                {
                                    cout << "Digite o novo telefone (Somente numeros): ";
                                    cin >> pessoas[i].telefone;
                                    break;
                                }
                            }
                        }
                        else if (op == "4") // Opcao para ver qual Email alterar
                        {
                            for (int i = 0; i < qtdfuncionario; i++) // Estrutura para poder comparar cada funcionario
                            {
                                if (cpfAlterar == pessoas[i].cpf) // Analise de qual funcionario alterar
                                {
                                    cout << "Digite o novo email: ";
                                    cin >> pessoas[i].email;
                                    break;
                                }
                            }
                        }
                        else // Opcao caso, oque foi digitado pelo usuario, nao tenha sido oque foi solicitado pelo sistema
                        {
                            cout << "*Opcao invalida*" << endl;
                            system("pause");
                            continue;
                        }
                    }

                    else if (op == "2") // Opcao caso queira excluir
                    {
                        cout << "Digite o CPF do funcionario que deseja excluir (Somente numeros): ";
                        cin >> cpfAlterar;

                        for (int i = 0; i < qtdfuncionario; i++) // Estrutura para poder comparar cada funcionario
                        {
                            if (cpfAlterar == pessoas[i].cpf) // Analise de qual funcionario excluir
                            {
                                for (; i < qtdfuncionario; i++) // Verificar qual funcionario excluir e fazer as devidas alteracoes
                                {
                                    pessoas[i].nome = pessoas[i + 1].nome;
                                    pessoas[i].cpf = pessoas[i + 1].cpf;
                                    pessoas[i].telefone = pessoas[i + 1].telefone;
                                    pessoas[i].email = pessoas[i + 1].email;
                                }
                                qtdfuncionario--;
                            }
                        }
                        for (int i = 0; i <= qtdfamiliar; i++) // Estrutura para poder comparar cada familiar
                        {
                            if (cpfAlterar == familiares[i].cpfusuario) // Analise de qual familiar excluir
                            {
                                for (int a = i; a < qtdfamiliar; a++) // Verificar qual familiar excluir e fazer as devidas alteracoes
                                {
                                    familiares[a].nome1 = familiares[a + 1].nome1;
                                    familiares[a].cpffamiliar = familiares[a + 1].cpffamiliar;
                                    familiares[a].cpfusuario = familiares[a + 1].cpfusuario;
                                    familiares[a].nascimento = familiares[a + 1].nascimento;
                                }
                                i--;
                                qtdfamiliar--;
                            }
                        }
                    }
                    else if (op == "3") // Opcao caso o usuario deseje alterar o dado de algum familiar
                    {
                        cout << "Digite o CPF do familiar que deseja alterar (Somente numeros): ";
                        cin >> cpfAlterar;
                        op = menu4_2_4();
                        if (op == "1") // Opcao para alterar o Nome do familiar
                        {
                            for (int i = 0; i < qtdfamiliar; i++) // Estrutura para poder comparar cada familiar
                            {
                                if (cpfAlterar == familiares[i].cpffamiliar) // Analise de qual familiar alterar
                                {
                                    cout << "Digite o novo nome: ";
                                    getline(cin, familiares[i].nome1);
                                }
                            }
                        }
                        else if (op == "2") // Opcao para alterar o Cpf do familiar
                        {
                            for (int i = 0; i < qtdfamiliar; i++) // Estrutura para poder comparar cada familiar
                            {
                                if (cpfAlterar == familiares[i].cpffamiliar) // Analise de qual familiar alterar
                                {
                                    cout << "Digite o novo CPF (Somente numeros): ";
                                    cin >> familiares[i].cpffamiliar;
                                    break;
                                }
                            }
                        }
                        else if (op == "3") // Opcao para alterar o Cpf do funcionario cadastrado no familiar
                        {
                            for (int i = 0; i < qtdfamiliar; i++) // Estrutura para poder comparar o dado inserido no familiar
                            {
                                if (cpfAlterar == familiares[i].cpffamiliar) // Analise de qual funcionario alterar
                                {
                                    cout << "Digite o novo CPF do funcionario (Somente numeros): ";
                                    cin >> familiares[i].cpfusuario;
                                    break;
                                }
                            }
                        }
                        else if (op == "4") // Opcao para alterar a data de nascimento do Familiar
                        {
                            for (int i = 0; i < qtdfamiliar; i++) // Estrutura para poder comparar cada familiar
                            {
                                if (cpfAlterar == familiares[i].cpffamiliar) // Analise de qual familiar alterar
                                {
                                    cout << "Digite a nova data de nascimento (Somente numeros): ";
                                    cin >> familiares[i].nascimento;
                                    break;
                                }
                            }
                        }
                    }
                    else if (op == "4") // Opcao para excluir apenas o Familiar
                    {
                        cout << "Digite o CPF do familiar que deseja excluir (Somente numeros): ";
                        cin >> cpfAlterar;

                        for (int i = 0; i < qtdfamiliar; i++) // Verificar qual Familiar excluir
                        {
                            if (cpfAlterar == familiares[i].cpffamiliar)
                            {
                                for (; i < qtdfuncionario; i++) // Comando que exlui e fazer as devidas alteracoes no vetor
                                {
                                    familiares[i].nome1 = familiares[i + 1].nome1;
                                    familiares[i].cpffamiliar = familiares[i + 1].cpffamiliar;
                                    familiares[i].cpfusuario = familiares[i + 1].cpfusuario;
                                    familiares[i].nascimento = familiares[i + 1].nascimento;
                                }
                                qtdfamiliar--;
                            }
                        }
                    }
                    else // Opcao caso, oque foi digitado pelo usuario, nao tenha sido oque foi solicitado pelo sistema
                    {
                        cout << "*Opcao invalida*" << endl;
                        system("pause");
                        continue;
                    }
                }
            }
            else if (op == "exit")
            {
                cout << "Saindo...." << endl;
                system("pause");
                return 0;
            }
            else // Mensagem mostrada, caso oque seja digitado nao condizer com oque se e pedido
            {
                cout << "*Opcao invalida*" << endl;
                system("pause");
                continue;
            }
        }
    } while (op != "exit"); // Para rodar o programa, ate que o usuario digite "exit"
    {
        cout << "Saindo...." << endl;
    }
    return 0;
}
