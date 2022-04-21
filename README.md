# Pipex

Quatrième projet de [42](https://42.fr/) dont le but est de recréer un système similaire aux pipes de Bash.

---

### Compilation :

Pour compiler le projet, exécutez la commande suivante :

```
make
```

### Utilisation :

Le programme doit s'exécuter de la façon suivante : 

```
./pipex [input file] [cmd1] [cmd2] [output file]

./pipex_bonus [input file] [cmd1] [cmd2] [cmd3] ... [cmdn] [output file]
```


### Exemple d'utiliation :

```
./pipex input.txt cat rev output.txt

./pipex_bonus hp1.txt cat "grep Voldemort" rev  output.txt

./pipex_bonus here_doc END /bin/cat rev md5 output.txt
```

---
### Diagrammes :

| Diagramme d'activité |
| --- |
| <img src="./img/activity-diagram.png" style="zoom:85%;" /> |

---
### Tests automatisés :

| [pipex-tester](https://github.com/vfurmane/pipex-tester) | 
| --- |
| ![](./img/test1.png) |
| ![](./img/test2.png) |

---
### Correction :

| |
| --- |
| <img src="./img/note.png" style="zoom: 50%;" /> |

| | |
| --- | --- |
| Correcteur 1 | <img src="./img/correction1.png" style="zoom: 67%;" /> |
| Correcteur 2 | <img src="./img/correction2.png" style="zoom:67%;" /> |
| Correcteur 3 | <img src="./img/correction3.png" style="zoom:67%;" /> |
