# Clase 2 · Estructuras (`struct`)

**Tema:** agrupar datos relacionados en un solo tipo.

| Archivo | Qué hace |
|---------|----------|
| `main.cpp` | Struct `Auto` (marca + número de serie); introduce `cin.getline` |
| `tarea1.cpp` | Struct `Cliente` que contiene un struct `Auto` (estructuras anidadas) |

## Conceptos clave

```cpp
struct Auto {
    char marca[20];     // cadena estilo C: máx. 19 caracteres + '\0'
    int numSerie;
};
struct Cliente {
    char nombre[30];
    Auto autoAdquirido; // struct anidado
};

cliente1.autoAdquirido.marca   // acceso encadenado con '.'
```

| Lectura | Comportamiento |
|---------|----------------|
| `cin >> marca` | Lee hasta el primer espacio |
| `cin.getline(marca, 20, '\n')` | Lee la línea completa (admite espacios) |

**Anterior:** [Clase 1](../clase%201/README.md) · **Siguiente:** [Clase 3](../clase%203/README.md)
