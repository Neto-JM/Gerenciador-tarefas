#ifndef TAREFA_H
#define TAREFA_H

#include <string>

enum class Prioridade { BAIXA, MEDIA, ALTA };
enum class Status { PENDENTE, CONCLUIDA };

class Tarefa {
private:
    int id;
    std::string titulo;
    std::string descricao;
    std::string prazo;
    Prioridade prioridade;
    std::string categoria;
    Status status;

public:
    Tarefa(int id, const std::string& titulo, const std::string& descricao,
           const std::string& prazo, Prioridade prioridade, const std::string& categoria);

    int getId() const;
    std::string getTitulo() const;
    std::string getDescricao() const;
    std::string getPrazo() const;
    Prioridade getPrioridade() const;
    std::string getCategoria() const;
    Status getStatus() const;

    void setTitulo(const std::string& titulo);
    void setDescricao(const std::string& descricao);
    void setPrazo(const std::string& prazo);
    void setPrioridade(Prioridade prioridade);
    void setCategoria(const std::string& categoria);

    void marcarConcluida();
    bool estaVencida() const;
};

#endif
