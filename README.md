# Snaze

Neste projeto a tarefa é desenvolver uma simulação do jogo clássico com uma diferença: a cobra está presa dentro de um labirinto!

A simulação do jogo Snaze carrega o nível do labirinto a partir de um arquivo texto de entrada, cujo nome é fornecido via argumento de linha de comando, e controla os movimentos da cobra. O desafio principal neste projeto de programação é projetar um motor básico de inteligência artificial (IA) que guia a cobra até a comida que surge em posições aleatórias dentro do labirinto sem que a cobra colida com as paredes do mesmo ou consigo mesma.

## Compilando e executando o exemplo

1. Entre na pasta `build`:
```
cd build
```
2. Execute os comandos do `cmake` para gerar os arquivos intermediários e o executável dentro de `build`.
```
cmake ..
cmake --build .
```

Isso criará um executável dentro da pasta `build` chamado de `snaze`.

Você deve colocar o arquivo de entrada por meio de argumentos de linha de comando para executar o programa, veja abaixo um exemplo com o arquivo dentro da pasta data:

```console
./snaze ../data/maze1.txt
```

## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

Não implementado

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

Ok

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

ok

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**

Não implementado, quando eu executo vejo o mapa mas ficam aparecendo uns Qs em vários pontos mas nenhuma snake.

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

Não implementado.

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

Não implementado.

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

Vou considerar, uma vez que a interação inicial ficou muito boa.

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

Vou considerar 50% uma vez que a classe não tem qualquer função no código

## Comentários gerais CP1
- Como você ainda não fez a parte básica que seria movimentar a cobra no mapa sugiro focar nas funcionalidades do CP1