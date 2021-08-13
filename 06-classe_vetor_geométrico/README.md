# Criar uma classe Vetor Geometrico

## Tarefa criar uma classe Vetor Geometrico

[Videoaula 43: aula de 09/08/2021](https://www.loom.com/share/bf5ec5fbe99a46ac9a46e15295714508) - Instruções para a tarefa

Implementar uma classe template `Vetor<n,T>` onde `T` deve ser numérico. As operações básicas de vetores geométricos devem estar implementadas.

Um Vetor em duas dimensões seria `Vetor<2,double>`.

Criar os operadores de multiplicação, adição e subtração de vetores. Lembrando que existe produto escalar e produto vetorial. Criar também multiplicação e divisão por escalar.

Bole uma forma do código abaixo compilar:

```
Vetor<2,double> v;
v = 4.5, 6.1;
```

O produto escalar será feito através de `*`, e o produto vetorial, através de `**`.

Esse operador `**` não existe em C++, mas ele pode ser simulado através de 

```
v = a ** b;
```

Para isso você deve redefinir o operador `*` unário (ponteiro) para retornar uma classe intermediária (por exemplo, `MeioDoProdutoVetorial`) que contém o vetor b. Além disso, você deve redefinir o operador `*` entre um Vetor e a classe `MeioDoProdutoVetorial` para realizar o produto vetorial.

Por último, crie o operador `<<` para imprimir. 

Não colocar a `main()` no arquivo - o teste vai ter uma classe `main`.