#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <vector>
#include "Tarefa.h"

/**
 * @brief Utilitário estático para persistência de tarefas em arquivo de texto.
 *
 * Fornece métodos para salvar e carregar a lista de tarefas em um arquivo
 * texto local, utilizando um formato separado por linhas com delimitador "---".
 * O tipo concreto de cada tarefa (TarefaSimples ou TarefaComPrazo) é inferido
 * a partir do campo prazo durante a leitura.
 */
class Arquivo {
public:
    /**
     * @brief Salva todas as tarefas em um arquivo de texto.
     *
     * Cada tarefa é serializada com os campos id, título, descrição, prazo,
     * prioridade, categoria e status, separados por quebras de linha.
     * Um separador "---" é inserido após cada tarefa.
     *
     * @param caminho  Caminho do arquivo de destino.
     * @param tarefas  Vetor de ponteiros para as tarefas a serem salvas.
     * @throws std::runtime_error Se o arquivo não puder ser aberto para escrita.
     */
    static void salvar(const std::string& caminho, const std::vector<Tarefa*>& tarefas);

    /**
     * @brief Carrega as tarefas salvas a partir de um arquivo de texto.
     *
     * Lê o arquivo linha a linha e reconstrói os objetos de tarefas
     * (TarefaSimples ou TarefaComPrazo) conforme o campo prazo.
     * Se o arquivo não existir, retorna um vetor vazio sem lançar exceção.
     *
     * @param caminho Caminho do arquivo a ser lido.
     * @return Vetor de ponteiros para as tarefas carregadas.
     *         O chamador é responsável por liberar a memória.
     */
    static std::vector<Tarefa*> carregar(const std::string& caminho);
};

#endif
