# Gerenciador de Tarefas

## Problema

* Dificuldade de organizar tarefas e compromissos do dia a dia
* Falta de controle de prazos e prioridades
* Possibilidade de perda de atividades importantes

---

## Objetivo Geral

Desenvolver um sistema em C++ para gerenciamento de tarefas, utilizando conceitos de Programação Orientada a Objetos.

---

## Objetivos Específicos

* Permitir o cadastro, edição e remoção de tarefas
* Definir prioridade e prazo para cada tarefa
* Organizar tarefas por categorias
* Listar tarefas com diferentes filtros (status, prioridade, data)
* Marcar tarefas como concluídas
* Manter um histórico básico de ações

---

## Escopo do Sistema

* Sistema executado em terminal (linha de comando)
* Gerenciamento completo de tarefas (CRUD)
* Filtros por status, prioridade e data
* Identificação de tarefas vencidas
* Persistência de dados em arquivos locais

---

## Como compilar e executar

Para compilar o programa, use o comando:
make

Para executar o programa após a compilação:
make run

---

## Vídeo de demonstração

O vídeo mostrando o sistema funcionando pode ser visto neste link:
[Link do Vídeo]

---

## Organização do projeto

O código está dividido da seguinte forma:

*   include: Todos os arquivos de cabeçalho (.h), com as definições das classes.
*   src: Os arquivos de implementação (.cpp), onde está a lógica de verdade.
*   docs: Documentos sobre os requisitos e a modelagem do sistema.
*   build: Pasta para os arquivos temporários da compilação (.o).

---

## Funcionalidades entregues

Funçẽos implementadasd no projeto:
* Adicionar tarefas (com ou sem prazo)
* Editar e remover tarefas
* Marcar tarefas como concluídas
* Buscar tarefas pelo título
* Ver estatísticas (quantas concluídas, atrasadas etc)
* Listar tarefas aplicando filtros ( prioridade, categoria, status)

---

## Instruções de uso

Ao rodar o programa, um menu com 11 opções (0 a 10) vai aparecer na tela. Basta digitar o número da opção e apertar Enter
* **Para criar uma tarefa simples:** Na hora de adicionar, quando pedir o "Prazo", aperte Enter sem digitar nada
* **Para datas:** Sempre use o formato DD/MM/AAAA
* **Categorias:** O sistema vai te sugerir as categorias que já existem, mas você pode digitar uma nova que será criada instantaneamente
* **Para fechar:** Use sempre a opção `0` para sair

---


### Commits da primeira entrega:

//Ruan Cândido Fraga Vieira - Primeiro Commit   
//José Manoel Borges Neto - Commit  
//Henrique Tomasi de Araujo - Commit  
//Arthur Felipe Paredes Gonçalves  
//Luiza Ribeiro Tavares - Commit  
