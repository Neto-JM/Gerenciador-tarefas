#ifndef GERENCIADORDETAREFAS_H
#define GERENCIADORDETAREFAS_H

#include <vector>
#include <string>

#include "Tarefa.h"
#include "Categoria.h"
#include "Historico.h"

/**
 * @brief Controlador principal do sistema de gerenciamento de tarefas.
 *
 * Centraliza todas as operações sobre tarefas e categorias:
 * criação, edição, remoção, listagem, filtragem, busca,
 * persistência em arquivo e exibição de estatísticas e histórico.
 *
 * Gerencia internamente a alocação dinâmica dos objetos Tarefa,
 * liberando-os corretamente no destrutor.
 */
class GerenciadorDeTarefas {
private:
    std::vector<Tarefa*> tarefas;       ///< Lista de ponteiros para todas as tarefas cadastradas
    std::vector<Categoria> categorias;  ///< Lista de categorias registradas no sistema
    Historico historico;                ///< Registro cronológico das ações realizadas
    int proximoId;                      ///< Próximo id disponível para novas tarefas

public:
    /**
     * @brief Constrói o gerenciador e inicializa o contador de ids.
     */
    GerenciadorDeTarefas();

    /**
     * @brief Destrói o gerenciador e libera toda a memória alocada com new.
     */
    ~GerenciadorDeTarefas();

    /**
     * @brief Adiciona uma nova tarefa ao sistema.
     *
     * Se o prazo for vazio ou "Sem Prazo", cria uma TarefaSimples;
     * caso contrário, cria uma TarefaComPrazo.
     * Cria a categoria automaticamente se ela ainda não existir.
     *
     * @param titulo      Título da tarefa.
     * @param descricao   Descrição detalhada.
     * @param prazo       Prazo no formato DD/MM/AAAA ou string vazia.
     * @param prioridade  Nível de prioridade.
     * @param categoria   Nome da categoria.
     */
    void adicionarTarefa(const std::string& titulo,
                         const std::string& descricao,
                         const std::string& prazo,
                         Prioridade prioridade,
                         const std::string& categoria);

    /**
     * @brief Edita os dados de uma tarefa existente.
     *
     * Localiza a tarefa pelo id e atualiza todos os seus campos.
     * Cria a categoria automaticamente se ela ainda não existir.
     *
     * @param id          Identificador da tarefa a ser editada.
     * @param titulo      Novo título.
     * @param descricao   Nova descrição.
     * @param prazo       Novo prazo (DD/MM/AAAA ou vazio).
     * @param prioridade  Nova prioridade.
     * @param categoria   Nova categoria.
     * @throws std::runtime_error Se a tarefa com o id fornecido não for encontrada.
     */
    void editarTarefa(int id,
                      const std::string& titulo,
                      const std::string& descricao,
                      const std::string& prazo,
                      Prioridade prioridade,
                      const std::string& categoria);

    /**
     * @brief Remove uma tarefa pelo seu id.
     *
     * Libera a memória do objeto removido e registra a ação no histórico.
     *
     * @param id Identificador da tarefa a ser removida.
     * @throws std::runtime_error Se a tarefa não for encontrada.
     */
    void removerTarefa(int id);

    /**
     * @brief Marca uma tarefa como concluída.
     *
     * @param id Identificador da tarefa.
     * @throws std::runtime_error Se a tarefa não for encontrada.
     */
    void marcarConcluida(int id);

    /**
     * @brief Retorna todas as tarefas ordenadas por prioridade e prazo.
     *
     * A ordenação é decrescente por prioridade (ALTA > MEDIA > BAIXA)
     * e crescente por data de prazo para tarefas de mesma prioridade.
     *
     * @return Vetor de ponteiros para as tarefas (não transfere a propriedade).
     */
    std::vector<Tarefa*> listarTarefas() const;

    /**
     * @brief Filtra as tarefas por status (PENDENTE ou CONCLUIDA).
     * @param status Status desejado.
     * @return Vetor de ponteiros para as tarefas que correspondem ao filtro.
     */
    std::vector<Tarefa*> filtrarPorStatus(Status status) const;

    /**
     * @brief Filtra as tarefas por nível de prioridade.
     * @param prioridade Prioridade desejada.
     * @return Vetor de ponteiros para as tarefas que correspondem ao filtro.
     */
    std::vector<Tarefa*> filtrarPorPrioridade(Prioridade prioridade) const;

    /**
     * @brief Filtra as tarefas pelo nome da categoria.
     * @param categoria Nome da categoria a ser filtrada.
     * @return Vetor de ponteiros para as tarefas da categoria informada.
     */
    std::vector<Tarefa*> filtrarPorCategoria(const std::string& categoria) const;

    /**
     * @brief Filtra as tarefas por uma data de prazo exata.
     * @param data Data no formato DD/MM/AAAA.
     * @return Vetor de ponteiros para as tarefas com o prazo informado.
     */
    std::vector<Tarefa*> filtrarPorData(const std::string& data) const;

    /**
     * @brief Retorna todas as tarefas com prazo vencido e status pendente.
     * @return Vetor de ponteiros para as tarefas vencidas.
     */
    std::vector<Tarefa*> listarVencidas() const;

    /**
     * @brief Adiciona uma nova categoria ao sistema.
     *
     * Lança exceção se a categoria já existir.
     *
     * @param nome Nome da nova categoria.
     * @throws std::runtime_error Se a categoria já estiver cadastrada.
     */
    void adicionarCategoria(const std::string& nome);

    /**
     * @brief Verifica se uma categoria com o nome fornecido já está cadastrada.
     * @param nome Nome da categoria a verificar.
     * @return true se existir, false caso contrário.
     */
    bool categoriaExiste(const std::string& nome) const;

    /**
     * @brief Retorna os nomes de todas as categorias cadastradas.
     * @return Vetor de strings com os nomes das categorias.
     */
    std::vector<std::string> listarCategorias() const;

    /**
     * @brief Exibe o histórico completo de ações no console.
     */
    void exibirHistorico() const;

    /**
     * @brief Persiste as tarefas no arquivo informado.
     *
     * Delega para Arquivo::salvar e registra a ação no histórico.
     *
     * @param caminho Caminho do arquivo de destino.
     */
    void salvar(const std::string& caminho);

    /**
     * @brief Carrega as tarefas a partir de um arquivo.
     *
     * Reconstrói a lista de tarefas e categorias e ajusta o próximo
     * id disponível para evitar colisões.
     *
     * @param caminho Caminho do arquivo de origem.
     */
    void carregar(const std::string& caminho);

    /**
     * @brief Busca tarefas cujo título contenha o termo informado.
     *
     * A busca é sensível a maiúsculas/minúsculas (usa std::string::find).
     *
     * @param termo Substring a ser procurada nos títulos.
     * @return Vetor de ponteiros para as tarefas correspondentes.
     */
    std::vector<Tarefa*> buscarPorTitulo(const std::string& termo) const;

    /**
     * @brief Exibe um resumo de produtividade no console.
     *
     * Mostra o total de tarefas, quantidade de concluídas (com percentual),
     * pendentes e atrasadas.
     */
    void exibirEstatisticas() const;
};

#endif
