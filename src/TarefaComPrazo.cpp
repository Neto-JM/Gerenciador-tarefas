/**
 * @file TarefaComPrazo.cpp
 * @brief Implementação da classe TarefaComPrazo.
 */

#include "TarefaComPrazo.h"
#include <ctime>
#include <sstream>

TarefaComPrazo::TarefaComPrazo(int id, const std::string& titulo, const std::string& descricao,
                               const std::string& prazo, Prioridade prioridade, const std::string& categoria)
    : Tarefa(id, titulo, descricao, prazo, prioridade, categoria) {}

bool TarefaComPrazo::estaVencida() const {
    if (status == Status::CONCLUIDA) return false;
    if (prazo.size() != 10) return false; 

    int dia, mes, ano;
    char sep1, sep2;
    std::istringstream ss(prazo);
    ss >> dia >> sep1 >> mes >> sep2 >> ano;

    if (ss.fail() || sep1 != '/' || sep2 != '/') return false;
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900) return false;

    std::time_t agora = std::time(nullptr);
    struct std::tm* hoje = std::localtime(&agora);

    int anoHoje = hoje->tm_year + 1900;
    int mesHoje = hoje->tm_mon + 1;
    int diaHoje = hoje->tm_mday;

    if (ano != anoHoje) return ano < anoHoje;
    if (mes != mesHoje) return mes < mesHoje;
    return dia < diaHoje;
}
