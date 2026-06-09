#ifndef TAREFACOMPRAZO_H
#define TAREFACOMPRAZO_H

#include "Tarefa.h"

/**
 * @brief Tarefa com prazo de vencimento definido.
 *
 * Subclasse de Tarefa que representa atividades com data limite no
 * formato DD/MM/AAAA. Sobrescreve estaVencida() para comparar o prazo
 * com a data atual do sistema.
 */
class TarefaComPrazo : public Tarefa {
public:
    /**
     * @brief Constrói uma tarefa com prazo.
     * @param id         Identificador único.
     * @param titulo     Título descritivo da tarefa.
     * @param descricao  Descrição detalhada.
     * @param prazo      Data limite no formato DD/MM/AAAA.
     * @param prioridade Nível de prioridade.
     * @param categoria  Nome da categoria associada.
     */
    TarefaComPrazo(int id,
                   const std::string& titulo,
                   const std::string& descricao,
                   const std::string& prazo,
                   Prioridade prioridade,
                   const std::string& categoria);

    /**
     * @brief Verifica se a tarefa passou da data limite.
     *
     * Compara o prazo armazenado com a data atual obtida do sistema.
     * Tarefas já concluídas nunca são consideradas vencidas.
     *
     * @return true se o prazo já passou e a tarefa ainda está pendente,
     *         false caso contrário.
     */
    bool estaVencida() const override;
};

#endif
