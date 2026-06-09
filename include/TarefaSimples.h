#ifndef TAREFASIMPLES_H
#define TAREFASIMPLES_H

#include "Tarefa.h"

/**
 * @brief Tarefa sem prazo definido.
 *
 * Subclasse de Tarefa que representa atividades sem data limite.
 * Por não possuir prazo, nunca é considerada vencida.
 */
class TarefaSimples : public Tarefa {
public:
    /**
     * @brief Constrói uma tarefa simples (sem prazo).
     * @param id         Identificador único.
     * @param titulo     Título descritivo da tarefa.
     * @param descricao  Descrição detalhada.
     * @param prioridade Nível de prioridade.
     * @param categoria  Nome da categoria associada.
     */
    TarefaSimples(int id,
                  const std::string& titulo,
                  const std::string& descricao,
                  Prioridade prioridade,
                  const std::string& categoria);

    /**
     * @brief Indica se a tarefa está vencida.
     *
     * Tarefas simples não possuem prazo, portanto sempre retorna false.
     *
     * @return false sempre.
     */
    bool estaVencida() const override;
};

#endif
