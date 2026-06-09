/**
 * @file Historico.cpp
 * @brief Implementação da classe Historico.
 */

#include "Historico.h"
#include <iostream>

void Historico::registrarAcao(const std::string& acao) {
    registros.push_back(acao);
}

void Historico::exibirHistorico() const {
    if (registros.empty()) {
        std::cout << "Nenhuma acao registrada no historico.\n";
        return;
    }
    std::cout << "\n=== Historico de Acoes ===\n";
    for (size_t i = 0; i < registros.size(); ++i) {
        std::cout << "[" << (i + 1) << "] " << registros[i] << "\n";
    }
    std::cout << "==========================\n";
}

std::vector<std::string> Historico::getRegistros() const {
    return registros;
}
