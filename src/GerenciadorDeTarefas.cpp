#include "GerenciadorDeTarefas.h"
#include "Arquivo.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

GerenciadorDeTarefas::GerenciadorDeTarefas() : proximoId(1) {}

// ---------- Categorias ----------

void GerenciadorDeTarefas::adicionarCategoria(const std::string& nome) {
    if (categoriaExiste(nome)) {
        throw std::runtime_error("Categoria '" + nome + "' ja existe.");
    }
    int novoId = static_cast<int>(categorias.size()) + 1;
    categorias.push_back(Categoria(novoId, nome));
    historico.registrarAcao("Categoria adicionada: " + nome);
}

bool GerenciadorDeTarefas::categoriaExiste(const std::string& nome) const {
    for (const Categoria& c : categorias) {
        if (c.getNome() == nome) return true;
    }
    return false;
}

std::vector<std::string> GerenciadorDeTarefas::listarCategorias() const {
    std::vector<std::string> nomes;
    for (const Categoria& c : categorias) {
        nomes.push_back(c.getNome());
    }
    return nomes;
}

// ---------- Tarefas ----------

void GerenciadorDeTarefas::adicionarTarefa(const std::string& titulo,
                                            const std::string& descricao,
                                            const std::string& prazo,
                                            Prioridade prioridade,
                                            const std::string& categoria) {
    // Garante que a categoria existe; cria automaticamente se nao existir
    if (!categoriaExiste(categoria)) {
        adicionarCategoria(categoria);
    }
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
    if (!categoriaExiste(categoria)) {
        adicionarCategoria(categoria);
    }
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

    historico.registrarAcao("Tarefa removida: " + it->getTitulo() +
                             " (ID " + std::to_string(id) + ")");
    tarefas.erase(it);
}

void GerenciadorDeTarefas::marcarConcluida(int id) {
    for (Tarefa& t : tarefas) {
        if (t.getId() == id) {
            t.marcarConcluida();
            historico.registrarAcao("Tarefa concluida: " + t.getTitulo() +
                                    " (ID " + std::to_string(id) + ")");
            return;
        }
    }
    throw std::runtime_error("Tarefa com ID " + std::to_string(id) + " nao encontrada.");
}

// ---------- Listagem e filtros ----------

std::vector<Tarefa> GerenciadorDeTarefas::listarTarefas() const {
    // Ordenado por prioridade (Alta > Media > Baixa) e depois por prazo
    std::vector<Tarefa> copia = tarefas;
    std::sort(copia.begin(), copia.end(), [](const Tarefa& a, const Tarefa& b) {
        if (a.getPrioridade() != b.getPrioridade()) {
            return static_cast<int>(a.getPrioridade()) > static_cast<int>(b.getPrioridade());
        }
        // Ordena prazo DD/MM/AAAA como AAAA-MM-DD para comparacao lexicografica
        auto toISO = [](const std::string& s) -> std::string {
            if (s.size() != 10) return s;
            return s.substr(6,4) + s.substr(3,2) + s.substr(0,2);
        };
        return toISO(a.getPrazo()) < toISO(b.getPrazo());
    });
    return copia;
}

std::vector<Tarefa> GerenciadorDeTarefas::filtrarPorStatus(Status status) const {
    std::vector<Tarefa> resultado;
    for (const Tarefa& t : listarTarefas()) {
        if (t.getStatus() == status) resultado.push_back(t);
    }
    return resultado;
}

std::vector<Tarefa> GerenciadorDeTarefas::filtrarPorPrioridade(Prioridade prioridade) const {
    std::vector<Tarefa> resultado;
    for (const Tarefa& t : listarTarefas()) {
        if (t.getPrioridade() == prioridade) resultado.push_back(t);
    }
    return resultado;
}

std::vector<Tarefa> GerenciadorDeTarefas::filtrarPorCategoria(const std::string& categoria) const {
    std::vector<Tarefa> resultado;
    for (const Tarefa& t : listarTarefas()) {
        if (t.getCategoria() == categoria) resultado.push_back(t);
    }
    return resultado;
}

std::vector<Tarefa> GerenciadorDeTarefas::listarVencidas() const {
    std::vector<Tarefa> resultado;
    for (const Tarefa& t : listarTarefas()) {
        if (t.estaVencida()) resultado.push_back(t);
    }
    return resultado;
}

// ---------- Historico ----------

void GerenciadorDeTarefas::exibirHistorico() const {
    historico.exibirHistorico();
}

// ---------- Persistencia ----------

void GerenciadorDeTarefas::salvar(const std::string& caminho) {
    Arquivo::salvar(caminho, tarefas);
    historico.registrarAcao("Tarefas salvas em: " + caminho);
}

void GerenciadorDeTarefas::carregar(const std::string& caminho) {
    tarefas = Arquivo::carregar(caminho);

    // Reconstroi categorias a partir das tarefas carregadas
    categorias.clear();
    for (const Tarefa& t : tarefas) {
        if (!categoriaExiste(t.getCategoria())) {
            int novoId = static_cast<int>(categorias.size()) + 1;
            categorias.push_back(Categoria(novoId, t.getCategoria()));
        }
    }

    // Ajusta proximoId para evitar colisoes
    proximoId = 1;
    for (const Tarefa& t : tarefas) {
        if (t.getId() >= proximoId) {
            proximoId = t.getId() + 1;
        }
    }

    historico.registrarAcao("Tarefas carregadas de: " + caminho);
}
