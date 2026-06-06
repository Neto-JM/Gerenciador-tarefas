#ifndef TAREFACOMPRAZO_H
#define TAREFACOMPRAZO_H

#include "Tarefa.h"

class TarefaComPrazo : public Tarefa {
public:
    TarefaComPrazo(int id,
                   const std::string& titulo,
                   const std::string& descricao,
                   const std::string& prazo,
                   Prioridade prioridade,
                   const std::string& categoria);

    // Verifica se a tarefa passou da data limite
    bool estaVencida() const override;
};

#endif
