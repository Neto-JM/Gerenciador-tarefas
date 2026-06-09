#ifndef HISTORICO_H
#define HISTORICO_H

#include <string>
#include <vector>

/**
 * @brief Registra e exibe o histórico de ações realizadas no sistema.
 *
 * Mantém uma lista cronológica de descrições de ações (adição, edição,
 * remoção, conclusão de tarefas, etc.) para fins de auditoria e rastreamento
 * do uso do gerenciador.
 */
class Historico {
private:
    std::vector<std::string> registros; ///< Lista de ações registradas em ordem cronológica

public:
    /**
     * @brief Registra uma ação realizada no sistema.
     *
     * Adiciona a descrição da ação ao final da lista de registros.
     *
     * @param acao Descrição textual da ação executada.
     */
    void registrarAcao(const std::string& acao);

    /**
     * @brief Exibe o histórico completo de ações no console.
     *
     * Imprime todas as ações registradas numeradas sequencialmente.
     * Caso nenhuma ação tenha sido registrada, exibe mensagem informativa.
     */
    void exibirHistorico() const;

    /**
     * @brief Retorna todos os registros armazenados.
     * @return Vetor de strings com todas as ações registradas.
     */
    std::vector<std::string> getRegistros() const;
};

#endif
