#pragma once
#include <string>
#include "Autenticavel.h"
#include "Pessoa.h"
#include "Cpf.h"

class Titular : public Pessoa, public Autenticavel
{
public:
    Titular(Cpf cpf, std::string nome, std::string senha);
};
