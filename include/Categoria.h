#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

/**
 * @brief Representa uma categoria de tarefas.
 *
 * Cada categoria possui um identificador numérico único e um nome.
 * As categorias são usadas para agrupar e filtrar tarefas dentro do
 * GerenciadorDeTarefas.
 */
class Categoria {
private:
    int id;           ///< Identificador único da categoria
    std::string nome; ///< Nome da categoria

public:
    /**
     * @brief Constrói uma categoria com id e nome fornecidos.
     * @param id   Identificador único da categoria.
     * @param nome Nome descritivo da categoria.
     */
    Categoria(int id, const std::string& nome);

    /**
     * @brief Retorna o identificador da categoria.
     * @return Inteiro com o id da categoria.
     */
    int getId() const;

    /**
     * @brief Retorna o nome da categoria.
     * @return String com o nome da categoria.
     */
    std::string getNome() const;

    /**
     * @brief Define um novo nome para a categoria.
     * @param nome Novo nome a ser atribuído.
     */
    void setNome(const std::string& nome);
};

#endif
