#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <vector>
#include "Tarefa.h"

class Arquivo {
public:
    static void salvar(const std::string& caminho, const std::vector<Tarefa>& tarefas);
    static std::vector<Tarefa> carregar(const std::string& caminho);
};

#endif
