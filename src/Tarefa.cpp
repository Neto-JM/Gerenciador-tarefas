#include "Tarefa.h"
#include <ctime>
#include <sstream>

Tarefa::Tarefa(int id, const std::string& titulo, const std::string& descricao,
               const std::string& prazo, Prioridade prioridade, const std::string& categoria)
    : id(id), titulo(titulo), descricao(descricao), prazo(prazo),
      prioridade(prioridade), categoria(categoria), status(Status::PENDENTE) {}

int Tarefa::getId() const { return id; }
std::string Tarefa::getTitulo() const { return titulo; }
std::string Tarefa::getDescricao() const { return descricao; }
std::string Tarefa::getPrazo() const { return prazo; }
Prioridade Tarefa::getPrioridade() const { return prioridade; }
std::string Tarefa::getCategoria() const { return categoria; }
Status Tarefa::getStatus() const { return status; }

void Tarefa::setTitulo(const std::string& titulo) { this->titulo = titulo; }
void Tarefa::setDescricao(const std::string& descricao) { this->descricao = descricao; }
void Tarefa::setPrazo(const std::string& prazo) { this->prazo = prazo; }
void Tarefa::setPrioridade(Prioridade prioridade) { this->prioridade = prioridade; }
void Tarefa::setCategoria(const std::string& categoria) { this->categoria = categoria; }

void Tarefa::marcarConcluida() {
    status = Status::CONCLUIDA;
}

bool Tarefa::estaVencida() const {
    if (status == Status::CONCLUIDA) return false;

    int dia, mes, ano;
    char sep;
    std::istringstream ss(prazo);
    ss >> dia >> sep >> mes >> sep >> ano;

    time_t agora = time(nullptr);
    struct tm* hoje = localtime(&agora);

    int anoHoje = hoje->tm_year + 1900;
    int mesHoje = hoje->tm_mon + 1;
    int diaHoje = hoje->tm_mday;

    if (ano != anoHoje) return ano < anoHoje;
    if (mes != mesHoje) return mes < mesHoje;
    return dia < diaHoje;
}