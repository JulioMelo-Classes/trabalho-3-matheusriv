## Compilando e executando o exemplo

No linux você pode compilar usando o g++. Apenas faça clone do projeto, e faça:

```bash
g++ src/*.cpp -o main -I./include
./main
```

No windows você pode compilar usando o g++ ou o cl de forma análoga:

```bash
g++ src/*.cpp -o main -I./include
.\main.exe
```
ou usando o CL

```bash
cl src/*.cpp -I./include
.\Snaze.exe
```

__Observação sobre o windows__: Ao realizar testes meu sistema detectou o programa como um virus, para conseguir executar eu tive que usar a versão compilada com o g++ ou configurar o windows defender para ignorar o executável que está na pasta do projeto (o problema só ocorre com a versão compilada pelo CL).
