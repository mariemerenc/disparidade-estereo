
# Estimativa de Disparidade Estéreo com OpenCV (SAD - Sum of Absolute Differences)

Este projeto implementa um algoritmo simples de estereoscopia baseado na técnica SAD (Sum of Absolute Differences) para calcular a mapa de disparidade a partir de duas imagens estéreo (esquerda e direita).

O código utiliza OpenCV em C++ e é compilável via CMake.

Este projeto foi desenvolvido na disciplina DIM0141 - Visão Computacional.

## Instalação do OpenCV no Ubuntu
```bash
sudo apt install libopencv-dev
```

## Compilando com CMake

### 1. Criar pasta build

```bash
mkdir build
cd build
```
### 2. Gerar arquivos de compilação
```bash
cmake ..
```
### 3. Compilar
```bash
cmake --build .
```

## Como executar

O programa recebe:

```bash
./Stereo <imagem_esquerda> <imagem_direita> <metade_da_janela> <dmax>
```

Por exemplo:
```bash
./Stereo ../a0.png ../a1.png 5 30
```

## Observações

* Para imagens estéreo reais, maiores valores de dmax podem melhorar a precisão, ao custo de desempenho.
