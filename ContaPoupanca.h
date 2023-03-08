#pragma once
#include "Conta.h"

class ContaPoupanca final : public Conta
{
public:
    ContaPoupanca(std::string numero, Titular titular);
    float taxaDeSaque() const override;
};
