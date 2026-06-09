/**
 * @file Tarefa.cpp
 * @brief Implementação da classe base Tarefa.
 */

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
    if (prazo.size() != 10) return false; // formato invalido

    int dia, mes, ano;
    char sep1, sep2;
    std::istringstream ss(prazo);
    ss >> dia >> sep1 >> mes >> sep2 >> ano;

    if (ss.fail() || sep1 != '/' || sep2 != '/') return false;
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900) return false;

    time_t agora = time(nullptr);
    struct tm* hoje = localtime(&agora);

    int anoHoje = hoje->tm_year + 1900;
    int mesHoje = hoje->tm_mon + 1;
    int diaHoje = hoje->tm_mday;

    if (ano != anoHoje) return ano < anoHoje;
    if (mes != mesHoje) return mes < mesHoje;
    return dia < diaHoje;
}