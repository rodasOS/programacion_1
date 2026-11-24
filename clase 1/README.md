# Clase 1 · Ciclos con centinela

**Tema:** entrada de datos, `while`, acumuladores (mayor/menor) y condicionales.

| Archivo | Qué hace |
|---------|----------|
| `main.cpp` | Pide notas hasta que el usuario escribe `-1`; muestra la nota más alta y la más baja |

## Conceptos clave

- **Centinela:** un valor especial (`-1`) que indica "terminé de ingresar datos".
- **Lectura previa:** la primera nota se lee antes del `while`; las siguientes, al final de cada vuelta.
- **Mayor/menor:** `mayor` arranca en el mínimo posible y `menor` en el máximo posible.

```cpp
float nota, mayor = 0, menor = 100;
cin >> nota;
while (nota > -1 && nota < 101) {
    if (nota > mayor) mayor = nota;
    if (nota < menor) menor = nota;   // dos 'if', no 'else if'
    cin >> nota;
}
```

> **Corrección aplicada:** originalmente `menor` empezaba en 0 y nunca se actualizaba.

**Siguiente:** [Clase 2 · Estructuras](../clase%202/README.md)
