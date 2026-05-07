#ifndef HISTORICO_H
#define HISTORICO_H

#include <string>
#include <vector>

class Historico {
private:
    std::vector<std::string> registros;

public:

    // Registra uma ação realizada no sistema
    // Deve armazenar a descrição da ação no vetor
    void registrarAcao(const std::string& acao);

    // Exibe o histórico completo de ações
    void exibirHistorico() const;

    // Retorna todos os registros armazenados
    std::vector<std::string> getRegistros() const;
};

#endif
