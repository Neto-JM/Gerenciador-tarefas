#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria {
private:
    std::string nome;

public:
    Categoria(const std::string& nome);

    std::string getNome() const;
    void setNome(const std::string& nome);
};

#endif
