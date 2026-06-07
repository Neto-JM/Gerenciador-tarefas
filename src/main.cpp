#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "GerenciadorDeTarefas.h"

const std::string ARQUIVO_DADOS = "tarefas.txt";


std::string prioridadeStr(Prioridade p) {
    switch (p) {
        case Prioridade::BAIXA: return "Baixa";
        case Prioridade::MEDIA: return "Media";
        case Prioridade::ALTA:  return "Alta";
    }
    return "?";
}

std::string statusStr(Status s) {
    return s == Status::CONCLUIDA ? "Concluida" : "Pendente";
}

void exibirTarefas(const std::vector<Tarefa*>& lista) {
    if (lista.empty()) {
        std::cout << "Nenhuma tarefa encontrada.\n";
        return;
    }
    std::cout << "\n";
    for (const Tarefa* t : lista) {
        std::cout << "-------------------------------------------\n";
        std::cout << "ID        : " << t->getId() << "\n";
        std::cout << "Titulo    : " << t->getTitulo() << "\n";
        std::cout << "Descricao : " << t->getDescricao() << "\n";
        std::cout << "Prazo     : " << t->getPrazo() << "\n";
        std::cout << "Prioridade: " << prioridadeStr(t->getPrioridade()) << "\n";
        std::cout << "Categoria : " << t->getCategoria() << "\n";
        std::cout << "Status    : " << statusStr(t->getStatus()) << "\n";
        if (t->estaVencida()) std::cout << "*** VENCIDA ***\n";
    }
    std::cout << "-------------------------------------------\n";
}

bool validarPrazo(const std::string& prazo) {
    if (prazo.empty()) return true;
    std::regex fmt(R"(\d{2}/\d{2}/\d{4})");
    if (!std::regex_match(prazo, fmt)) return false;
    int dia  = std::stoi(prazo.substr(0, 2));
    int mes  = std::stoi(prazo.substr(3, 2));
    int ano  = std::stoi(prazo.substr(6, 4));
    if (mes < 1 || mes > 12) return false;
    if (ano < 1900 || ano > 2100) return false;

    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    if (mes == 2 && bissexto) diasNoMes[1] = 29;

    if (dia < 1 || dia > diasNoMes[mes - 1]) return false;
    return true;
}
std::string lerPrazo() {
    std::string prazo;
    while (true) {
        std::cout << "Prazo (DD/MM/AAAA) ou [Enter] para tarefa simples: ";
        std::getline(std::cin, prazo);
        if (prazo.empty()) return "";
        if (validarPrazo(prazo)) return prazo;
        std::cout << "Formato invalido. Use DD/MM/AAAA (ex: 31/12/2025).\n";
    }
}

Prioridade lerPrioridade() {
    while (true) {
        std::cout << "Prioridade (0=Baixa, 1=Media, 2=Alta): ";
        int p; std::cin >> p; std::cin.ignore();
        if (p == 0) return Prioridade::BAIXA;
        if (p == 1) return Prioridade::MEDIA;
        if (p == 2) return Prioridade::ALTA;
        std::cout << "Opcao invalida. Digite 0, 1 ou 2.\n";
    }
}

bool confirmar(const std::string& mensagem) {
    std::cout << mensagem << " (s/n): ";
    char c; std::cin >> c; std::cin.ignore();
    return c == 's' || c == 'S';
}

void menuListar(GerenciadorDeTarefas& g) {
std::cout << "\n[1] Todas  [2] Por status  [3] Por prioridade  [4] Por categoria  [5] Vencidas  [6] Por data\n";
    std::cout << "Opcao: ";
    int op; std::cin >> op; std::cin.ignore();

    if (op == 1) {
        exibirTarefas(g.listarTarefas());

    } else if (op == 2) {
        std::cout << "Status (0=Pendente, 1=Concluida): ";
        int s; std::cin >> s; std::cin.ignore();
        if (s < 0 || s > 1) { std::cout << "Opcao invalida.\n"; return; }
        exibirTarefas(g.filtrarPorStatus(static_cast<Status>(s)));

    } else if (op == 3) {
        exibirTarefas(g.filtrarPorPrioridade(lerPrioridade()));

    } else if (op == 4) {
        // Exibe categorias disponíveis
        std::vector<std::string> cats = g.listarCategorias();
        if (cats.empty()) {
            std::cout << "Nenhuma categoria cadastrada.\n";
            return;
        }
        std::cout << "Categorias disponíveis:\n";
        for (size_t i = 0; i < cats.size(); ++i) {
            std::cout << "  [" << (i+1) << "] " << cats[i] << "\n";
        }
        std::cout << "Categoria: ";
        std::string cat; std::getline(std::cin, cat);
        exibirTarefas(g.filtrarPorCategoria(cat));

    } else if (op == 5) {
        exibirTarefas(g.listarVencidas());

    } else if (op == 6) {
    std::string data;
    while (true) {
        std::cout << "Data (DD/MM/AAAA): ";
        std::getline(std::cin, data);
        if (validarPrazo(data) && !data.empty()) break;
        std::cout << "Formato invalido. Use DD/MM/AAAA (ex: 31/12/2025).\n";
    } 
    exibirTarefas(g.filtrarPorData(data));
} else {
        std::cout << "Opcao invalida.\n";
    }
}
int main() {
    GerenciadorDeTarefas gerenciador;
    gerenciador.carregar(ARQUIVO_DADOS);

    int opcao = -1;
    while (opcao != 0) {
        std::cout << "\n========== Gerenciador de Tarefas ==========\n";
        std::cout << "[1] Adicionar tarefa\n";
        std::cout << "[2] Editar tarefa\n";
        std::cout << "[3] Remover tarefa\n";
        std::cout << "[4] Marcar como concluida\n";
        std::cout << "[5] Listar tarefas\n";
        std::cout << "[6] Buscar tarefa por titulo\n";
        std::cout << "[7] Estatisticas de produtividade\n";
        std::cout << "[8] Historico de acoes\n";
        std::cout << "[9] Gerenciar categorias\n";
        std::cout << "[10] Salvar\n";
        std::cout << "[0] Sair\n";
        std::cout << "Opcao: ";
        std::cin >> opcao; std::cin.ignore();

        try {
            if (opcao == 1) {
                std::string titulo, descricao, categoria;
                std::cout << "Titulo: ";    std::getline(std::cin, titulo);
                std::cout << "Descricao: "; std::getline(std::cin, descricao);
                std::string prazo = lerPrazo();
                Prioridade prio = lerPrioridade();

                // Exibe categorias existentes como sugestao
                std::vector<std::string> cats = gerenciador.listarCategorias();
                if (!cats.empty()) {
                    std::cout << "Categorias existentes: ";
                    for (size_t i = 0; i < cats.size(); ++i) {
                        std::cout << cats[i];
                        if (i + 1 < cats.size()) std::cout << ", ";
                    }
                    std::cout << "\n";
                }
                std::cout << "Categoria: "; std::getline(std::cin, categoria);

                gerenciador.adicionarTarefa(titulo, descricao, prazo, prio, categoria);
                std::cout << "Tarefa adicionada com sucesso!\n";

            } else if (opcao == 2) {
                std::cout << "ID da tarefa a editar: ";
                int id; std::cin >> id; std::cin.ignore();
                std::string titulo, descricao, categoria;
                std::cout << "Novo titulo: ";    std::getline(std::cin, titulo);
                std::cout << "Nova descricao: "; std::getline(std::cin, descricao);
                std::string prazo = lerPrazo();
                Prioridade prio = lerPrioridade();
                std::cout << "Nova categoria: "; std::getline(std::cin, categoria);
                gerenciador.editarTarefa(id, titulo, descricao, prazo, prio, categoria);
                std::cout << "Tarefa editada com sucesso!\n";

            } else if (opcao == 3) {
                std::cout << "ID da tarefa a remover: ";
                int id; std::cin >> id; std::cin.ignore();
                if (confirmar("Tem certeza que deseja remover a tarefa ID " + std::to_string(id) + "?")) {
                    gerenciador.removerTarefa(id);
                    std::cout << "Tarefa removida com sucesso!\n";
                } else {
                    std::cout << "Remocao cancelada.\n";
                }

            } else if (opcao == 4) {
                std::cout << "ID da tarefa a concluir: ";
                int id; std::cin >> id; std::cin.ignore();
                gerenciador.marcarConcluida(id);
                std::cout << "Tarefa marcada como concluida!\n";

            } else if (opcao == 5) {
                menuListar(gerenciador);

            } else if (opcao == 6) {
                std::cout << "Digite o termo para busca: ";
                std::string termo; std::getline(std::cin, termo);
                exibirTarefas(gerenciador.buscarPorTitulo(termo));

            } else if (opcao == 7) {
                gerenciador.exibirEstatisticas();

            } else if (opcao == 8) {
                gerenciador.exibirHistorico();

            } else if (opcao == 9) {
                std::vector<std::string> cats = gerenciador.listarCategorias();
                std::cout << "\n=== Categorias cadastradas ===\n";
                if (cats.empty()) {
                    std::cout << "Nenhuma categoria ainda.\n";
                } else {
                    for (const std::string& c : cats) std::cout << "  - " << c << "\n";
                }
                std::cout << "\nDigite o nome de uma nova categoria (ou Enter para cancelar): ";
                std::string nova; std::getline(std::cin, nova);
                if (!nova.empty()) {
                    gerenciador.adicionarCategoria(nova);
                    std::cout << "Categoria '" << nova << "' adicionada!\n";
                }

            } else if (opcao == 10) {
                gerenciador.salvar(ARQUIVO_DADOS);
                std::cout << "Tarefas salvas em '" << ARQUIVO_DADOS << "'.\n";

            } else if (opcao == 0) {
                gerenciador.salvar(ARQUIVO_DADOS);
                std::cout << "Tarefas salvas. Ate logo!\n";

            } else {
                std::cout << "Opcao invalida.\n";
            }

        } catch (const std::exception& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    return 0;
}
