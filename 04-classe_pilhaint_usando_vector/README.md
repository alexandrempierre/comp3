# Classe PilhaInt - usando vector

[Videoaula 30: aula de 28/07](https://www.loom.com/share/1434f0f5c80845db8c4f0ab61e9c638e?sharedAppSource=personal_library) - descrição do trabalho

Partindo da última implementação da Classe `PilhaInt` você irá modificá-la para utilizar `vector<int>`. Mantenha toda a especificação dos exercícios anteriores, note que a classe `vector` possui comportamento bem diferente quanto à atribuição e redimensionamento.
Envie um único arquivo `pilha.cc` (ou copie e cole no editor) contendo apenas a definição da classe. Não é permitido nenhum `#include`, nem o uso de nenhuma biblioteca além de `vector` e `iostream` (que será incluída pelo meu programa principal). Não coloque nesse arquivo a função `main`, ou dará erro de compilação.

Exemplo de `pilha.cc`:

```
class PilhaInt {
  public:
    // Seus métodos contendo o seu código
  private:
    // Atributos da sua classe
};
```

Os testes irão utilizar a função auxilar listada abaixo para testar o construtor de cópia:

```
PilhaInt embaralha( PilhaInt q ) {
    int aux = q.desempilha();
    q << 32 << 9 << aux;
    
    return q;
}
```