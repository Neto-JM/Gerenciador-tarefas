/**
 * @file TarefaComPrazo.cpp
 * @brief Implementação da classe TarefaComPrazo.
 */

#include "TarefaComPrazo.h"

TarefaComPrazo::TarefaComPrazo(int id, const std::string& titulo, const std::string& descricao,
                               const std::string& prazo, Prioridade prioridade, const std::string& categoria)
    : Tarefa(id, titulo, descricao, prazo, prioridade, categoria) {}
