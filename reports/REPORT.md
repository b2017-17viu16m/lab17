## Laboratory work XVI

Данная лабораторная работа посвещена изучению систем организации совместных сеансов разработки на примере **tmux**

```ShellSession
$ open https://wiki.archlinux.org/index.php/Tmux_(Русский)
```

## Tasks

- [x] 1. Ознакомиться со ссылками учебного материала
- [x] 2. Выполнить инструкцию учебного материала
- [x] 3. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ tmux
$ tmux new -s sergey
```

```ShellSession
$ tmux a
$ tmux a -t sergey
```

```ShellSession
$ tmux ls
$ tmux kill-session -t sergey
```

```ShellSession
<C-B>s
<C-B>$
```

```ShellSession
<C-B>c
<C-B>w
<C-B>n
<C-B>p
<C-B>f
<C-B>,
<C-B>&
```

```ShellSession
<C-B>%
<C-B>"
<C-B>o
<C-B>q
<C-B>x
<C-B>+
<C-B>-
<C-B>⍽
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=16
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Result

В ходе проделанной работы проведено ознакомление с менеджером терминалов Tmux, создана и окончена терминальная сессия, изучены управляющие сочетания клавиш.


## Links

- [Tmux](https://tmux.github.io)

```
Copyright (c) 2017 Братья Вершинины
```
