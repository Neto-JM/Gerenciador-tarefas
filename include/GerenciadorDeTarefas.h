#ifndef GERENCIADORDETAREFAS_H
#define GERENCIADORDETAREFAS_H

#include <vector>
#include <string>

#include "Tarefa.h"
#include "Categoria.h"
#include "Historico.h"

class GerenciadorDeTarefas {
private:
    std::vector<Tarefa> tarefas;
    std::vector<Categoria> categorias;
    Historico historico;

    int proximoId;

public:

    // Construtor do gerenciador
    // Deve inicializar o contador de IDs
    GerenciadorDeTarefas();

    // Adiciona uma nova tarefa ao sistema
    // Deve criar a tarefa e armazená-la no vetor
    void adicionarTarefa(const std::string& titulo,
                         const std::string& descricao,
                         const std::string& prazo,
                         Prioridade prioridade,
                         const std::string& categoria);

    // Edita uma tarefa existente
    // Deve validar se o ID informado existe
    void editarTarefa(int id,
                      const std::string& titulo,
                      const std::string& descricao,
                      const std::string& prazo,
                      Prioridade prioridade,
                      const std::string& categoria);

    // Remove uma tarefa do sistema
    // Deve validar se o ID existe antes da remoção
    void removerTarefa(int id);

    // Marca uma tarefa como concluída
    // Deve alterar o status da tarefa correspondente
    void marcarConcluida(int id);

    // Retorna todas as tarefas cadastradas
    std::vector<Tarefa> listarTarefas() const;

    // Filtra tarefas por status
    std::vector<Tarefa> filtrarPorStatus(Status status) const;

    // Filtra tarefas por prioridade
    std::vector<Tarefa> filtrarPorPrioridade(Prioridade prioridade) const;

    // Filtra tarefas por categoria
    std::vector<Tarefa> filtrarPorCategoria(const std::string& categoria) const;

    // Retorna tarefas vencidas
    std::vector<Tarefa> listarVencidas() const;

    // Salva as tarefas em arquivo
    void salvar(const std::string& caminho) const;

    // Carrega tarefas salvas em arquivo
    void carregar(const std::string& caminho);
};

#endif
