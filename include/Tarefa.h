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
private:
    int id;

    std::string titulo;
    std::string descricao;

    // Prazo armazenado no formato DD/MM/AAAA
    std::string prazo;

    Prioridade prioridade;
    std::string categoria;

    Status status;

public:

    // Construtor da classe Tarefa
    // Deve inicializar todos os atributos da tarefa
    Tarefa(int id,
            const std::string& titulo,
            const std::string& descricao,
            const std::string& prazo,
            Prioridade prioridade,
            const std::string& categoria);

    // Retorna o ID da tarefa
    int getId() const;

    // Retorna o título da tarefa
    std::string getTitulo() const;

    // Retorna a descrição da tarefa
    std::string getDescricao() const;

    // Retorna o prazo da tarefa
    std::string getPrazo() const;

    // Retorna a prioridade da tarefa
    Prioridade getPrioridade() const;

    // Retorna a categoria da tarefa
    std::string getCategoria() const;

    // Retorna o status atual da tarefa
    Status getStatus() const;

    // Define um novo título
    void setTitulo(const std::string& titulo);

    // Define uma nova descrição
    void setDescricao(const std::string& descricao);

    // Define um novo prazo
    void setPrazo(const std::string& prazo);

    // Define uma nova prioridade
    void setPrioridade(Prioridade prioridade);

    // Define uma nova categoria
    void setCategoria(const std::string& categoria);

    // Marca a tarefa como concluída
    void marcarConcluida();

    // Verifica se a tarefa está vencida
    // Deve comparar o prazo com a data atual
    bool estaVencida() const;
};

#endif
