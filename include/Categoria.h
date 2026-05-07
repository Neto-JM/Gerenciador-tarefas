#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria {
private:
    int id;
    std::string nome;

public:

    // Construtor da categoria
    // Deve inicializar o id e o nome da categoria
    Categoria(int id, const std::string& nome);

    // Retorna o identificador da categoria
    int getId() const;

    // Retorna o nome da categoria
    std::string getNome() const;

    // Define um novo nome para a categoria
    void setNome(const std::string& nome);
};

#endif
