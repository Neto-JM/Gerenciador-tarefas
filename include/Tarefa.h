#ifndef TAREFA_H
#define TAREFA_H

#include <string>

/**
 * @brief Níveis de prioridade de uma tarefa.
 */
enum class Prioridade {
    BAIXA,  ///< Prioridade baixa
    MEDIA,  ///< Prioridade média
    ALTA    ///< Prioridade alta
};

/**
 * @brief Possíveis estados de uma tarefa.
 */
enum class Status {
    PENDENTE,  ///< Tarefa ainda não concluída
    CONCLUIDA  ///< Tarefa finalizada
};

/**
 * @brief Classe base que representa uma tarefa genérica.
 *
 * Contém os atributos e comportamentos comuns a todos os tipos de tarefas
 * do sistema. Deve ser herdada por TarefaSimples e TarefaComPrazo.
 */
class Tarefa {
protected:
    int id;                  ///< Identificador único da tarefa
    std::string titulo;      ///< Título da tarefa
    std::string descricao;   ///< Descrição detalhada da tarefa
    std::string prazo;       ///< Prazo no formato DD/MM/AAAA (ou "Sem Prazo")
    Prioridade prioridade;   ///< Nível de prioridade da tarefa
    std::string categoria;   ///< Categoria à qual a tarefa pertence
    Status status;           ///< Status atual da tarefa

public:
    /**
     * @brief Constrói uma nova tarefa.
     * @param id          Identificador único.
     * @param titulo      Título descritivo da tarefa.
     * @param descricao   Descrição detalhada.
     * @param prazo       Prazo no formato DD/MM/AAAA ou string vazia.
     * @param prioridade  Nível de prioridade (BAIXA, MEDIA ou ALTA).
     * @param categoria   Nome da categoria associada.
     */
    Tarefa(int id,
           const std::string& titulo,
           const std::string& descricao,
           const std::string& prazo,
           Prioridade prioridade,
           const std::string& categoria);

    /**
     * @brief Destrutor virtual para garantir a limpeza correta das subclasses.
     */
    virtual ~Tarefa() = default;

    /** @brief Retorna o identificador único da tarefa. */
    int getId() const;

    /** @brief Retorna o título da tarefa. */
    std::string getTitulo() const;

    /** @brief Retorna a descrição da tarefa. */
    std::string getDescricao() const;

    /** @brief Retorna o prazo da tarefa (formato DD/MM/AAAA ou "Sem Prazo"). */
    std::string getPrazo() const;

    /** @brief Retorna o nível de prioridade da tarefa. */
    Prioridade getPrioridade() const;

    /** @brief Retorna o nome da categoria associada. */
    std::string getCategoria() const;

    /** @brief Retorna o status atual da tarefa. */
    Status getStatus() const;

    /**
     * @brief Define um novo título para a tarefa.
     * @param titulo Novo título.
     */
    void setTitulo(const std::string& titulo);

    /**
     * @brief Define uma nova descrição para a tarefa.
     * @param descricao Nova descrição.
     */
    void setDescricao(const std::string& descricao);

    /**
     * @brief Define um novo prazo para a tarefa.
     * @param prazo Novo prazo no formato DD/MM/AAAA.
     */
    void setPrazo(const std::string& prazo);

    /**
     * @brief Define um novo nível de prioridade.
     * @param prioridade Nova prioridade.
     */
    void setPrioridade(Prioridade prioridade);

    /**
     * @brief Define uma nova categoria para a tarefa.
     * @param categoria Nome da nova categoria.
     */
    void setCategoria(const std::string& categoria);

    /**
     * @brief Marca a tarefa como concluída, alterando seu status para CONCLUIDA.
     */
    void marcarConcluida();

    /**
     * @brief Verifica se a tarefa está vencida (prazo anterior à data atual).
     *
     * Método virtual que pode ser sobrescrito pelas subclasses.
     * A implementação padrão analisa o campo @p prazo e compara com a data do sistema.
     *
     * @return true se a tarefa está vencida e ainda pendente, false caso contrário.
     */
    virtual bool estaVencida() const;
};

#endif
