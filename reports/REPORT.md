## Laboratory work XI

Данная лабораторная работа посвещена изучению инструментов отладки на примере **lldb**

```ShellSession
$ open https://lldb.llvm.org/tutorial.html
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab11** на сервисе **GitHub**
- [x] 2. Выполнить инструкцию учебного материала
- [x] 3. Ознакомиться со ссылками учебного материала
- [x] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=b2017-17viu16m
$ alias gsed=sed # for *-nix system
```

```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab10 lab11
$ cd lab11
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab11
```

```ShellSession
$ cmake -H. -B_build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=_install
$ cmake --build _build --target install
$ cd _install/bin
```

```ShellSession
$ lldb demo
(lldb) process launch --stop-at-entry
(lldb) breakpoint list
(lldb) breakpoint set --name print
(lldb) breakpoint set --file demo.cpp --line 6
(lldb) breakpoint list
(lldb) process launch
(lldb) exit
```

```ShellSession
$ demo
<Command>-T
$ ps
$ lldb
(lldb) process attach --pid <идентификатор_процесса> 
(lldb) process attach --name demo
(lldb) exit
```

```ShellSession
$ lldb demo
(lldb) process launch --stop-at-entry -- -program_arg "text1 text2 text3"
(lldb) thread list
(lldb) thread backtrace
(lldb) frame variable
(lldb) frame variable argv[0] 
```

```ShellSession
$ lldb demo
(lldb) process launch --stop-at-entry
(lldb) thread continue
(lldb) thread step-in
(lldb) thread step-over
(lldb) thread step-out
(lldb) thread step-inst
(lldb) thread step-over-inst
(lldb) exit
```

```ShellSession
$ cd ../..
$ gsed -i 's/lab10/lab11/g' README.md
```

```ShellSession
$ git add .
$ git commit -m"debugging"
$ git push origin master
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=11
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Result

В ходе проделанной работы проведено ознакомление с работой инструмента отладки Lldb, осуществлен запуск сервиса отладки для процесса demo, созданы точки отладки.

## Links

- [gdb](https://www.gnu.org/software/gdb/)
- [lldb](https://lldb.llvm.org)
- [windbg](https://msdn.microsoft.com/en-us/library/windows/hardware/dn745911(v=vs.85).aspx)

```
Copyright (c) 2017 Братья Вершинины
```
