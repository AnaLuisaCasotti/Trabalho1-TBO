**Algoritmo de Agrupamento de Espaçamento Máximo (MST)**

Este projeto foi desenvolvido como um trabalho prático para a disciplina de Técnicas de Busca e Ordenação (TBO). A aplicação resolve o problema de agrupamento de espaçamento máximo através da implementação de uma Árvore Geradora Mínima (MST).
O grande diferencial deste projeto foi o processo de análise empírica e refatoração de código, onde a aplicação foi otimizada para reduzir o tempo de execução de um dos casos de teste de 17 minutos para apenas 1,3 segundos.

🛠️ **Tecnologias e Conceitos Utilizados**

- Linguagem: C

- Estruturas de Dados: Tipos Abstratos de Dados (TADs), Matrizes/Vetores, Tabelas Hash e Heap (Min-Heap).

- Algoritmos Gráficos: Algoritmo de Kruskal e Union-Find (com as otimizações Weighted Quick-Union e compressão de caminho).

🧠 **Desafios e Aprendizados (Processo de Otimização)**

A primeira versão do sistema apresentou gargalos severos de desempenho devido a loops aninhados e realocações excessivas de memória. O projeto foi refatorado em três etapas principais:

1. Eliminação de Loops Aninhados: Substituição de buscas complexas por uma estrutura de dados Hash para mapear as raízes dos grupos em tempo constante (O(1)).

2. Otimização de Memória: Remoção de funções de desalocação e cópias desnecessárias de vetores que ocorriam dentro de loops principais. Isso reduziu o tempo de execução do maior caso de teste de 17 minutos para 7 segundos.

3. Substituição do Quick Sort por Heap: A ordenação inicial das arestas usava o qsort do C (O(N²logN²)) repetidas vezes. Ao implementar uma estrutura de Heap (in-place), garantimos a extração do menor elemento de forma eficiente, baixando o tempo final do pior caso para 1,3 segundos.

📊 **Análise de Complexidade e Resultados**

A complexidade assintótica final do algoritmo foi determinada em O(N²logN²), onde N representa o número de pontos.
Os testes empíricos demonstraram que o perfil de execução está totalmente alinhado com a teoria de complexidade de algoritmos:

- Ordenação de Distâncias + Criação da MST: Responsável por ~60% a 67% do tempo total de execução (funções dominantes: constroiHeap e unionArestas).
  
- Cálculo de Distâncias: Cerca de 32% a 38% do tempo (função geraArestas com O(N²M)).
