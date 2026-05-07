#ifndef GERENCIADORDETAREFAS_H
#define GERENCIADORDETAREFAS_H

#include <vector>
#include <string>
#include "Tarefa.h"
#include "Categoria.h"
#include "Historico.h"
#include "Arquivo.h"

class GerenciadorDeTarefas {
private:
    std::vector<Tarefa> tarefas;
    std::vector<Categoria> categorias;
    Historico historico;
    int proximoId;

public:
    GerenciadorDeTarefas();

    void adicionarTarefa(const std::string& titulo, const std::string& descricao,
                         const std::string& prazo, Prioridade prioridade,
                         const std::string& categoria);
    void editarTarefa(int id, const std::string& titulo, const std::string& descricao,
                      const std::string& prazo, Prioridade prioridade,
                      const std::string& categoria);
    void removerTarefa(int id);
    void marcarConcluida(int id);

    std::vector<Tarefa> listarTarefas() const;
    std::vector<Tarefa> filtrarPorStatus(Status status) const;
    std::vector<Tarefa> filtrarPorPrioridade(Prioridade prioridade) const;
    std::vector<Tarefa> filtrarPorCategoria(const std::string& categoria) const;
    std::vector<Tarefa> listarVencidas() const;

    void salvar(const std::string& caminho) const;
    void carregar(const std::string& caminho);
};

#endif
