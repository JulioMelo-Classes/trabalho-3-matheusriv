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
