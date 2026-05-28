#include "Arquivo.h"
#include "Tarefa.h"
#include <fstream>
#include <stdexcept>

void Arquivo::salvar(const std::string& caminho, const std::vector<Tarefa>& tarefas) {
    std::ofstream arquivo(caminho);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir o arquivo para escrita: " + caminho);
    }

    for (const Tarefa& t : tarefas) {
        arquivo << t.getId() << "\n";
        arquivo << t.getTitulo() << "\n";
        arquivo << t.getDescricao() << "\n";
        arquivo << t.getPrazo() << "\n";
        arquivo << static_cast<int>(t.getPrioridade()) << "\n";
        arquivo << t.getCategoria() << "\n";
        arquivo << static_cast<int>(t.getStatus()) << "\n";
        arquivo << "---\n";
    }
}

std::vector<Tarefa> Arquivo::carregar(const std::string& caminho) {
    std::vector<Tarefa> tarefas;
    std::ifstream arquivo(caminho);

    if (!arquivo.is_open()) {
        return tarefas;
    }

    std::string idStr, titulo, descricao, prazo, prioridadeStr, categoria, statusStr, separador;

    while (std::getline(arquivo, idStr)) {
        if (!std::getline(arquivo, titulo)) break;
        if (!std::getline(arquivo, descricao)) break;
        if (!std::getline(arquivo, prazo)) break;
        if (!std::getline(arquivo, prioridadeStr)) break;
        if (!std::getline(arquivo, categoria)) break;
        if (!std::getline(arquivo, statusStr)) break;
        std::getline(arquivo, separador); // linha "---"

        int id = std::stoi(idStr);
        Prioridade prioridade = static_cast<Prioridade>(std::stoi(prioridadeStr));
        Status status = static_cast<Status>(std::stoi(statusStr));

        Tarefa t(id, titulo, descricao, prazo, prioridade, categoria);
        if (status == Status::CONCLUIDA) {
            t.marcarConcluida();
        }

        tarefas.push_back(t);
    }

    return tarefas;
}
