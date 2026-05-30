#include "GerenciadorDeTarefas.h"
#include "Arquivo.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

GerenciadorDeTarefas::GerenciadorDeTarefas() : proximoId(1) {}

void GerenciadorDeTarefas::adicionarTarefa(const std::string& titulo,
                                            const std::string& descricao,
                                            const std::string& prazo,
                                            Prioridade prioridade,
                                            const std::string& categoria) {
    Tarefa nova(proximoId++, titulo, descricao, prazo, prioridade, categoria);
    tarefas.push_back(nova);
    historico.registrarAcao("Tarefa adicionada: " + titulo);
}

void GerenciadorDeTarefas::editarTarefa(int id,
                                         const std::string& titulo,
                                         const std::string& descricao,
                                         const std::string& prazo,
                                         Prioridade prioridade,
                                         const std::string& categoria) {
    for (Tarefa& t : tarefas) {
        if (t.getId() == id) {
            t.setTitulo(titulo);
            t.setDescricao(descricao);
            t.setPrazo(prazo);
            t.setPrioridade(prioridade);
            t.setCategoria(categoria);
            historico.registrarAcao("Tarefa editada: ID " + std::to_string(id));
            return;
        }
    }
    throw std::runtime_error("Tarefa com ID " + std::to_string(id) + " nao encontrada.");
}

void GerenciadorDeTarefas::removerTarefa(int id) {
    auto it = std::find_if(tarefas.begin(), tarefas.end(),
        [id](const Tarefa& t) { return t.getId() == id; });

    if (it == tarefas.end()) {
        throw std::runtime_error("Tarefa com ID " + std::to_string(id) + " nao encontrada.");
    }

    historico.registrarAcao("Tarefa removida: " + it->getTitulo() + " (ID " + std::to_string(id) + ")");
    tarefas.erase(it);
}

void GerenciadorDeTarefas::marcarConcluida(int id) {
    for (Tarefa& t : tarefas) {
        if (t.getId() == id) {
            t.marcarConcluida();
            historico.registrarAcao("Tarefa concluida: " + t.getTitulo() + " (ID " + std::to_string(id) + ")");
            return;
        }
    }
    throw std::runtime_error("Tarefa com ID " + std::to_string(id) + " nao encontrada.");
}

std::vector<Tarefa> GerenciadorDeTarefas::listarTarefas() const {
    return tarefas;
}

std::vector<Tarefa> GerenciadorDeTarefas::filtrarPorStatus(Status status) const {
    std::vector<Tarefa> resultado;
    for (const Tarefa& t : tarefas) {
        if (t.getStatus() == status) {
            resultado.push_back(t);
        }
    }
    return resultado;
}

std::vector<Tarefa> GerenciadorDeTarefas::filtrarPorPrioridade(Prioridade prioridade) const {
    std::vector<Tarefa> resultado;
    for (const Tarefa& t : tarefas) {
        if (t.getPrioridade() == prioridade) {
            resultado.push_back(t);
        }
    }
    return resultado;
}

std::vector<Tarefa> GerenciadorDeTarefas::filtrarPorCategoria(const std::string& categoria) const {
    std::vector<Tarefa> resultado;
    for (const Tarefa& t : tarefas) {
        if (t.getCategoria() == categoria) {
            resultado.push_back(t);
        }
    }
    return resultado;
}

std::vector<Tarefa> GerenciadorDeTarefas::listarVencidas() const {
    std::vector<Tarefa> resultado;
    for (const Tarefa& t : tarefas) {
        if (t.estaVencida()) {
            resultado.push_back(t);
        }
    }
    return resultado;
}

void GerenciadorDeTarefas::salvar(const std::string& caminho) const {
    Arquivo::salvar(caminho, tarefas);
    // Nota: salvar() e const no header, entao nao podemos chamar historico.registrarAcao() aqui.
    // Para registrar essa acao, declare salvar() como nao-const no header.
}

void GerenciadorDeTarefas::carregar(const std::string& caminho) {
    tarefas = Arquivo::carregar(caminho);

    // Ajusta o proximoId para evitar colisoes
    proximoId = 1;
    for (const Tarefa& t : tarefas) {
        if (t.getId() >= proximoId) {
            proximoId = t.getId() + 1;
        }
    }

    historico.registrarAcao("Tarefas carregadas de: " + caminho);
}
