#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <vector>
#include "Tarefa.h"

class Arquivo {
public:

    // Salva todas as tarefas em um arquivo local
    static void salvar(const std::string& caminho, const std::vector<Tarefa*>& tarefas);

    // Carrega as tarefas salvas em arquivo
    static std::vector<Tarefa*> carregar(const std::string& caminho);
};

#endif
