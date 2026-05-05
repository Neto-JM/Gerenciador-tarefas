E5- Requisitos e Modelagem



1.User Stories:



US01 - Como usuário, quero cadastrar uma tarefa com título, descrição, prazo e prioridade, para registrar meus compromissos.

US02 - Como usuário, quero editar uma tarefa existente, para corrigir informações erradas.

US03 - Como usuário, quero remover uma tarefa, para eliminar o que não é mais necessário.

US04 - Como usuário, quero definir uma prioridade (baixa, média, alta) para cada tarefa, para saber o que fazer primeiro.

US05 - Como usuário, quero organizar tarefas por categoria, para separar trabalho, estudos, pessoal, etc.

US06 - Como usuário, quero listar tarefas filtradas por status, prioridade ou data, para encontrar o que preciso rapidamente.

US07 - Como usuário, quero marcar uma tarefa como concluída, para acompanhar meu progresso.

US08 - Como usuário, quero visualizar tarefas vencidas, para saber o que está atrasado.

US09 - Como usuário, quero que minhas tarefas sejam salvas em arquivo, para não perder os dados ao fechar o programa.

US10 - Como usuário, quero consultar o histórico de ações, para saber o que foi feito no sistema.





2.Cartões CRC



Classe: Tarefa

Responsabilidades: armazenar título, descrição, prazo, prioridade, categoria e status. Informar se está vencida. Permitir marcar como concluída.

Colaboradores: Categoria



Classe: Categoria

Responsabilidades: armazenar o nome da categoria e agrupar tarefas relacionadas.

Colaboradores: Tarefa



Classe: GerenciadorDeTarefas

Responsabilidades: cadastrar, editar e remover tarefas. Listar tarefas com filtros. Identificar tarefas vencidas. Coordenar as demais classes.

Colaboradores: Tarefa, Categoria, Historico, Arquivo



Classe: Historico

Responsabilidades: registrar cada ação realizada no sistema e permitir consulta do histórico.

Colaboradores: GerenciadorDeTarefas



Classe: Arquivo

Responsabilidades: salvar tarefas em arquivo local e carregar os dados ao iniciar o programa.

Colaboradores: GerenciadorDeTarefas, Tarefa

