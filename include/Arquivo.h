#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <vector>
#include "Tarefa.h"

class Arquivo {
public:

    // Salva todas as tarefas em um arquivo local
    // Deve receber o caminho do arquivo e o vetor de tarefas
    static void salvar(const std::string& caminho, const std::vector<Tarefa>& tarefas);

    // Carrega as tarefas salvas em arquivo
    // Deve retornar um vetor contendo as tarefas carregadas
    static std::vector<Tarefa> carregar(const std::string& caminho);
};

#endif
