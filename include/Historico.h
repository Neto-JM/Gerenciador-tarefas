#ifndef HISTORICO_H
#define HISTORICO_H

#include <string>
#include <vector>

class Historico {
private:
    std::vector<std::string> registros;

public:
    void registrarAcao(const std::string& acao);
    void exibirHistorico() const;
    std::vector<std::string> getRegistros() const;
};

#endif
