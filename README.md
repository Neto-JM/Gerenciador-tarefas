# Gerenciador de Tarefas

## Integrantes

* Nome Integrante 1
* Nome Integrante 2
* Nome Integrante 3
* Nome Integrante 4
* Nome Integrante 5

---

# Descrição do Projeto

O Gerenciador de Tarefas é uma aplicação desenvolvida em C++ para auxiliar usuários na organização de atividades, compromissos e prazos. O sistema permite criar, editar, remover e concluir tarefas, além de categorizá-las, armazená-las em arquivos e manter um histórico de ações realizadas.

O projeto foi desenvolvido como Trabalho Prático da disciplina Programação e Desenvolvimento de Software II (PDS2), aplicando conceitos de Programação Orientada a Objetos, modularização, tratamento de exceções e persistência de dados.

---

# Objetivos

* Organizar tarefas pessoais ou profissionais.
* Controlar tarefas com ou sem prazo.
* Permitir categorização das tarefas.
* Registrar histórico de operações realizadas.
* Garantir persistência das informações entre execuções.

---

# Como Compilar

Na raiz do projeto execute:

```bash
make
```

O executável será gerado automaticamente.

---

# Como Executar

Após compilar:

```bash
make run
```

ou

```bash
./build/gerenciador
```

---

# Link do Vídeo

Vídeo de demonstração:

INSERIR_LINK_DO_VIDEO_AQUI

---

# Estrutura do Projeto

```text
Gerenciador-tarefas/
│
├── include/
│   ├── Tarefa.h
│   ├── TarefaSimples.h
│   ├── TarefaComPrazo.h
│   ├── Categoria.h
│   ├── Historico.h
│   ├── Arquivo.h
│   └── GerenciadorDeTarefas.h
│
├── src/
│   ├── Tarefa.cpp
│   ├── TarefaSimples.cpp
│   ├── TarefaComPrazo.cpp
│   ├── Categoria.cpp
│   ├── Historico.cpp
│   ├── Arquivo.cpp
│   ├── GerenciadorDeTarefas.cpp
│   └── main.cpp
│
├── docs/
│
├── build/
│
└── Makefile
```

---

# Arquitetura e Organização

O sistema foi dividido em módulos independentes para facilitar manutenção e reutilização.

## Classe Tarefa

Classe base responsável por representar uma tarefa genérica.

Principais atributos:

* id
* título
* descrição
* categoria
* status

---

## Classe TarefaSimples

Herda da classe Tarefa.

Representa tarefas que não possuem prazo definido.

---

## Classe TarefaComPrazo

Herda da classe Tarefa.

Representa tarefas que possuem data limite para conclusão.

Implementa comportamento específico para verificar vencimento.

---

## Classe Categoria

Responsável pelo gerenciamento das categorias cadastradas no sistema.

Exemplos:

* Trabalho
* Estudos
* Pessoal

---

## Classe Historico

Responsável pelo armazenamento das ações realizadas no sistema.

Exemplos:

* Tarefa criada
* Tarefa removida
* Tarefa concluída

---

## Classe Arquivo

Responsável pela persistência dos dados.

Funções principais:

* salvar()
* carregar()

---

## Classe GerenciadorDeTarefas

Classe central do sistema.

Responsável por:

* Gerenciar tarefas
* Gerenciar categorias
* Realizar buscas
* Registrar histórico
* Controlar persistência

---

# Conceitos de Orientação a Objetos Utilizados

## Encapsulamento

Os atributos das classes são privados e acessados através de métodos públicos.

---

## Herança

Implementada através das classes:

* TarefaSimples
* TarefaComPrazo

que herdam da classe base Tarefa.

---

## Polimorfismo

Utilização de métodos virtuais para permitir comportamentos diferentes entre os tipos de tarefa.

Exemplo:

```cpp
virtual bool estaVencida() const;
```

---

## Abstração

A classe Tarefa representa uma abstração genérica de uma tarefa, servindo como base para especializações.

---

# Funcionalidades Implementadas

## Tarefas

* Criar tarefa
* Editar tarefa
* Remover tarefa
* Concluir tarefa
* Listar tarefas

## Categorias

* Criar categoria
* Listar categorias

## Histórico

* Registrar operações realizadas
* Exibir histórico

## Persistência

* Salvar dados em arquivo
* Carregar dados previamente salvos

---

# Funcionalidades Fora do Escopo

As seguintes funcionalidades foram consideradas, mas não implementadas:

* Interface gráfica
* Multiusuário
* Banco de dados
* Integração com calendário
* Notificações automáticas

---

# Exemplos de Uso

## Criando uma tarefa

Entrada:

```text
Título: Estudar PDS2
Descrição: Revisar herança e polimorfismo
Categoria: Estudos
```

Saída:

```text
Tarefa cadastrada com sucesso.
```

---

## Concluindo uma tarefa

Entrada:

```text
ID da tarefa: 3
```

Saída:

```text
Tarefa concluída com sucesso.
```

---

# Programação Defensiva e Tratamento de Exceções

O sistema utiliza programação defensiva para aumentar sua robustez.

Tratamentos implementados:

* Validação de IDs inexistentes.
* Validação de categorias duplicadas.
* Validação de datas inválidas.
* Tratamento de falhas na leitura de arquivos.
* Tratamento de falhas na gravação de arquivos.

Exemplo:

```cpp
throw std::runtime_error("Tarefa não encontrada.");
```

As exceções são capturadas no programa principal utilizando:

```cpp
catch(const std::exception& e)
```

---

# Documentação Doxygen

Para gerar a documentação:

```bash
doxygen Doxyfile
```

A documentação gerada ficará disponível em:

```text
docs/html/index.html
```

---

# Ciclo de Desenvolvimento (Sprints)

## Sprint 1

Objetivo:

* Escolha do tema
* Configuração do ambiente
* Criação do repositório

Entregas:

* E1
* E2
* E3

---

## Sprint 2

Objetivo:

* Levantamento de requisitos
* Cartões CRC
* Estrutura do projeto

Entregas:

* E4
* E5
* E6

---

## Sprint 3

Objetivo:

* Implementação das funcionalidades
* Persistência
* Tratamento de exceções

Entregas:

* E7
* E8
* E9

---

## Sprint 4

Objetivo:

* Testes finais
* Gravação do vídeo
* Revisão do código

Entregas:

* E10

---

# Planejado x Realizado

## Planejado

* Sistema de gerenciamento de tarefas com persistência.
* Utilização de herança e polimorfismo.
* Histórico de operações.

## Realizado

* Todos os objetivos principais foram implementados.
* Persistência funcional.
* Tratamento de exceções implementado.
* Modularização completa do sistema.

---

# Evidências no GitHub

O desenvolvimento foi realizado utilizando GitHub.

Evidências disponíveis:

* Commits individuais dos integrantes.
* Histórico de versões.
* Branch principal do projeto.
* Tag final de entrega (v1.0.0).

Repositório:

INSERIR_LINK_DO_REPOSITORIO

---

# Aprendizados

Durante o desenvolvimento foram consolidados conhecimentos sobre:

* Programação Orientada a Objetos.
* Herança.
* Polimorfismo.
* Modularização.
* Controle de versão com Git.
* Tratamento de exceções.
* Persistência de dados em arquivos.

---

# Contribuições da Equipe

| Integrante                                                                        | Principais contribuições    |
| --------------------------------------------------------------------------------- | --------------------------- |
| Integrante 1                                                                      | Classe Tarefa               |
| Integrante 2                                                                      | TarefaSimples               |
| Integrante 3                                                                      | TarefaComPrazo              |
| Integrante 4                                                                      | Categoria e Histórico       |
| Integrante 5                                                                      | Gerenciador, Arquivo e Main |
|                                                                                   |                             |
| As contribuições podem ser verificadas através do histórico de commits do GitHub. |                             |
|                                                                                   |                             |
