<div align="center">

# ft_printf

**Réimplémentation de la fonction `printf(3)` de la libc en langage C.**

Projet du cursus de l'École **42**.

![C](https://img.shields.io/badge/language-C-00599C?logo=c&logoColor=white)
![Norm](https://img.shields.io/badge/norminette-passing-brightgreen)
![42](https://img.shields.io/badge/school-42-000000)
![Bonus](https://img.shields.io/badge/bonus-included-blueviolet)
![License](https://img.shields.io/badge/license-MIT-blue)

</div>

---

## Sommaire

- [À propos](#-à-propos)
- [Fonctionnalités](#-fonctionnalités)
- [Compilation](#-compilation)
- [Utilisation](#-utilisation)
- [Exemple](#-exemple)
- [Spécificateurs supportés](#-spécificateurs-supportés)
- [Flags supportés (bonus)](#-flags-supportés-bonus)
- [Structure du projet](#-structure-du-projet)
- [Auteur](#-auteur)

---

## À propos

`ft_printf` reproduit le comportement de la fonction standard `printf` de la `libc`. Le projet est compilé sous forme de bibliothèque statique (`libftprintf.a`) que l'on peut linker à n'importe quel programme C.

L'objectif pédagogique est de maîtriser :

- la gestion des **arguments variadiques** (`stdarg.h`),
- l'**analyse et le formatage** de chaînes de caractères,
- la gestion fine de la **mémoire** et des **pointeurs**,
- l'écriture de code **modulaire**, **conforme à la Norme 42** et compilé avec `-Wall -Wextra -Werror`.

---

## Fonctionnalités

### Partie obligatoire

Gestion des conversions suivantes :

`%c` &nbsp;·&nbsp; `%s` &nbsp;·&nbsp; `%p` &nbsp;·&nbsp; `%d` &nbsp;·&nbsp; `%i` &nbsp;·&nbsp; `%u` &nbsp;·&nbsp; `%x` &nbsp;·&nbsp; `%X` &nbsp;·&nbsp; `%%`

### Partie bonus

Gestion complète des **flags**, de la **largeur** et de la **précision** :

- `-` &nbsp;·&nbsp; `0` &nbsp;·&nbsp; `#` &nbsp;·&nbsp; `' '` (espace) &nbsp;·&nbsp; `+`
- Largeur minimale de champ (`%10d`)
- Précision (`%.5s`, `%.10d`)
- Largeur et précision dynamiques via `*` (`%*d`, `%.*s`)

---

## Compilation

```bash
make           # Compile la bibliothèque libftprintf.a
make bonus     # Recompile entièrement avec les bonus
make clean     # Supprime les fichiers objets
make fclean    # Supprime les objets et la bibliothèque
make re        # Recompile entièrement le projet
```

La bibliothèque générée est `libftprintf.a` et le header public est `ft_printf.h`.

---

## Utilisation

Inclure le header dans votre code source :

```c
#include "ft_printf.h"
```

Puis linker la bibliothèque à la compilation :

```bash
cc votre_fichier.c -L. -lftprintf -o votre_programme
```

Prototype :

```c
int ft_printf(const char *format, ...);
```

La fonction renvoie le nombre de caractères écrits, ou `-1` en cas d'erreur.

---

## Exemple

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Decimal       : %d\n", 42);
    ft_printf("Unsigned      : %u\n", 4242);
    ft_printf("Hexadecimal   : %x / %X\n", 255, 255);
    ft_printf("Pointer       : %p\n", &main);
    ft_printf("Padded        : [%10d] [%-10d] [%010d]\n", 42, 42, 42);
    ft_printf("Precision     : [%.5d] [%.3s]\n", 42, "Bonjour");
    ft_printf("Signed flags  : [%+d] [% d]\n", 42, 42);
    return (0);
}
```

Compilation et exécution :

```bash
make
cc main.c -L. -lftprintf -o test && ./test
```

---

## Spécificateurs supportés

| Spéc. | Description                                                     |
| :---: | :-------------------------------------------------------------- |
| `%c`  | Affiche un caractère                                            |
| `%s`  | Affiche une chaîne de caractères                                |
| `%p`  | Affiche une adresse mémoire en hexadécimal (préfixée `0x`)      |
| `%d`  | Affiche un entier signé en base décimale                        |
| `%i`  | Identique à `%d`                                                |
| `%u`  | Affiche un entier non signé en base décimale                    |
| `%x`  | Affiche un entier non signé en hexadécimal minuscule            |
| `%X`  | Affiche un entier non signé en hexadécimal majuscule            |
| `%%`  | Affiche un caractère `%` littéral                               |

---

## Flags supportés (bonus)

| Flag  | Effet                                                                 |
| :---: | :-------------------------------------------------------------------- |
| `-`   | Alignement à gauche dans la largeur de champ                          |
| `0`   | Remplissage à gauche par des `0` au lieu d'espaces                    |
| `#`   | Ajoute `0x` / `0X` aux conversions hexadécimales non nulles           |
| `' '` | Préfixe les nombres positifs signés par un espace                     |
| `+`   | Préfixe les nombres positifs signés par un `+`                        |
| *n*   | Largeur minimale du champ                                             |
| `.n`  | Précision (nombre minimum de chiffres / max. de caractères pour `%s`) |
| `*`   | Largeur ou précision lue depuis les arguments                         |

---

## Structure du projet

```
Printf_42/
├── ft_printf.h                   # Header public
├── ft_printf.c                   # Point d'entrée et parsing principal
├── ft_format_flags.c             # Parsing des flags, largeur, précision
├── ft_print_char_bonus.c         # Conversion %c
├── ft_print_str_bonus.c          # Conversion %s
├── ft_print_ptr_bonus.c          # Conversion %p
├── ft_print_nbr_bonus.c          # Conversions %d / %i
├── ft_print_unsigned_bonus.c     # Conversion %u
├── ft_print_hex_bonus.c          # Conversions %x / %X
├── ft_utils.c                    # Utilitaires (putchar, putstr, atoi…)
├── ft_utils2.c                   # Utilitaires complémentaires
└── Makefile                      # Règles : all / bonus / clean / fclean / re
```

---

## Auteur

**throbert** — étudiant à l'École 42

- GitHub : [@Thomasrbm](https://github.com/Thomasrbm)
- Intra 42 : `throbert`

---

<div align="center">

*Projet réalisé dans le cadre du cursus de l'École 42 — conforme à la Norme 42.*

</div>
