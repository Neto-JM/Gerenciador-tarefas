#ifndef TAREFASIMPLES_H
#define TAREFASIMPLES_H

#include "Tarefa.h"

class TarefaSimples : public Tarefa {
public:
    TarefaSimples(int id,
                  const std::string& titulo,
                  const std::string& descricao,
                  Prioridade prioridade,
                  const std::string& categoria);

    // Tarefas simples nao possuem prazo, portanto nunca vencem
    bool estaVencida() const override;
};

#endif
