#include <iostream>
#include <string>
#include "Conta.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Titular.h"
#include "Cpf.h"
#include "Funcionario.h"

using namespace std;

void ExibeSaldo(const Conta& conta)
{
    cout << "O saldo da conta é: " << conta.recuperaSaldo() << endl;
}

void RealizaSaque(Conta& conta)
{
    conta.sacar(200);
}

void FazLogin(Autenticavel& alguem, string senha)
{
    if (alguem.autentica(senha)) {
        cout << "Login realizado com sucesso" << endl;
    } else {
        cout << "Senha inválida" << endl;
    }
}

int main()
{
    Titular titular(Cpf("123.456.789-10"), "Leonardo", "umasenha");

    ContaPoupanca umaConta("123456", titular);
    umaConta.depositar(500);
    RealizaSaque(umaConta);

    ExibeSaldo(umaConta);

    Titular outro(Cpf("098.765.432-10"), "Leonardo Possan", "outrasenha");
    ContaCorrente umaOutraConta("654321", titular);
    umaOutraConta.depositar(300);
    
    ContaCorrente outraContaCorrente("546312", titular);
    
    umaOutraConta.transferePara(umaConta, 250);

    ExibeSaldo(umaOutraConta);
    ExibeSaldo(outraContaCorrente);

    cout << "Número de contas: " << Conta::recuperaNumeroDeContas() << endl;

    return 0;
}