# Tarefa Stream

[Videoaula 44: aula de 09/08/2021](https://www.loom.com/share/f347a9f662d047e6a300c249e66ba4de) - Instruções para a tarefa.

Implementar uma template que torne possível o seguinte tipo de código:

```
int tab[10] =  { 1, 2, 3, 2, 3, 4, 6, 0, 1, 8 };
vector<int> v{ 2 , 6, 8 };
tab | []( int x ) { cout << x*x << endl; };
tab | [ &v ]( int x ) { v.push_back( x ); };
v | []( int x ) { cout << x*x << endl; };
v | &print;
```

Onde print é uma função que recebe um int. 

```
void print( int x ) { cout << x << " "; }
```

Esse operador será equivalente a:

```
for_each( tab, tab+10,  []( int x ) { cout << x*x << endl; } );
```
