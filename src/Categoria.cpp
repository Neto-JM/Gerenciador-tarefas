#include "Categoria.h"

Categoria::Categoria(int id, const std::string& nome) {
    this->id = id;
    this->nome = nome;
}

int Categoria::getId() const {
    return id;
}

std::string Categoria::getNome() const {
    return nome;
}

void Categoria::setNome(const std::string& nome) {
    this->nome = nome;
}
