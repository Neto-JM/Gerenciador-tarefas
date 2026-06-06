#include "TarefaSimples.h"

TarefaSimples::TarefaSimples(int id, const std::string& titulo, const std::string& descricao,
                             Prioridade prioridade, const std::string& categoria)
    : Tarefa(id, titulo, descricao, "Sem Prazo", prioridade, categoria) {}

bool TarefaSimples::estaVencida() const {
    return false;
}
