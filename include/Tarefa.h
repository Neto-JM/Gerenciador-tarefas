#ifndef TAREFA_H
#define TAREFA_H

#include <string>

enum class Prioridade {
    BAIXA,
    MEDIA,
    ALTA
};

enum class Status {
    PENDENTE,
    CONCLUIDA
};

class Tarefa {
protected:
    int id;
    std::string titulo;
    std::string descricao;
    std::string prazo;
    Prioridade prioridade;
    std::string categoria;
    Status status;

public:
    Tarefa(int id,
            const std::string& titulo,
            const std::string& descricao,
            const std::string& prazo,
            Prioridade prioridade,
            const std::string& categoria);

    // Destrutor virtual para garantir a limpeza correta das subclasses
    virtual ~Tarefa() = default;

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

    // Metodo polimorfico que sera sobrescrito pelas subclasses
    virtual bool estaVencida() const;
};

#endif
