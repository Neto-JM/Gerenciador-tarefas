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

    // Adiciona uma categoria ao sistema (valida duplicatas)
    void adicionarCategoria(const std::string& nome);

    // Verifica se uma categoria existe
    bool categoriaExiste(const std::string& nome) const;

    // Retorna todos os nomes de categorias cadastradas
    std::vector<std::string> listarCategorias() const;

    // Exibe o historico de acoes
    void exibirHistorico() const;

    // Salva as tarefas em arquivo (nao-const para registrar no historico)
    void salvar(const std::string& caminho);

    // Carrega tarefas salvas em arquivo
    void carregar(const std::string& caminho);

    // busca por palavra chave
    std::vector<Tarefa> buscarPorTitulo(const std::string& termo) const;

    //caso seja uma tarefa que conclui parcialmente control oq ja fez
    void exibirEstatisticas() const;
};

#endif
