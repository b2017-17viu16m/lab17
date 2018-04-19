## Laboratory work XVII

Данная лабораторная работа посвещена изучению процесса создания сеансов совместной разработки с использованием инструмента **ngrok**

```ShellSession
$ open https://ngrok.com/
```

## Tasks

- [x] 1. Ознакомиться со ссылками учебного материала
- [x] 2. Выполнить инструкцию учебного материала
- [x] 3. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ cd ~
$ mkdir install
$ mkdir tmp
$ export HOME_PREFIX=`pwd`/install
$ echo $HOME_PREFIX
$ export USERNAME=`whoami`
```

```ShellSession
$ cd tmp
```

```ShellSession
$ wget https://github.com/libevent/libevent/releases/download/release-2.1.8-stable/libevent-2.1.8-stable.tar.gz
$ tar -xvzf libevent-2.1.8-stable.tar.gz
$ cd libevent-2.1.8-stable
$ ./configure --prefix=${HOME_PREFIX}
$ make && make install 
$ cd ..
```

```ShellSession
$ wget http://invisible-island.net/datafiles/release/ncurses.tar.gz
$ tar -xvzf ncurses.tar.gz
$ cd ncurses-5.9
$ ./configure --prefix=${HOME_PREFIX}
$ make && make install 
$ cd ..
```


```ShellSession
$ wget https://github.com/tmux/tmux/releases/download/2.5/tmux-2.5.tar.gz
$ tar -xvzf tmux-2.5.tar.gz
$ cd tmux-2.5
$ ./configure --prefix=${HOME_PREFIX} CFLAGS="-I${HOME_PREFIX}/include -I${HOME_PREFIX}/include/ncurses" LDFLAGS="-L${HOME_PREFIX}/lib"
$ make && make install
$ cd ..
```

```ShellSession
$ wget https://bin.equinox.io/c/4VmDzA7iaHb/ngrok-stable-linux-amd64.zip
$ unizp ngrok-stable-linux-amd64.zip
$ mv ngrok ${HOME_PREFIX}/bin
```

```ShellSession
$ export LD_LIBRARY_PATH=${HOME_PREFIX}/lib
$ export PATH="${HOME_PREFIX}/bin:${PATH}"
$ tmux new -s session_with_group
```

```ShellSession
# Alisa:
$ open https://ngrok.com/signup
$ export NGROK_TOKEN=6ef94034c7842b283a4de661c910635108009509
$ ngrok authtoken ${NGROK_TOKEN}
$ ngrok tcp 22

```

```ShellSession
# Bob:
$ ssh ${USERNAME}@0.tcp.ngrok.io -p22
1qaz2wsx
$ tmux a -t session_with_group
$ <C-B>"
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

В ходе проделанной работы проведено ознакомление с инструментом cовместной работы Ngrok, для корректной работы которого в ходе данной работы были установлены необходимые компоненты.
С использованием Ngrok была организована совместная работа Alissa и Bob.


## Links

- [Tmux](https://raw.githubusercontent.com/tmux/tmux/master/README)
- [Libevent](http://libevent.org)
- [Ncurses](http://invisible-island.net/ncurses/)

```
Copyright (c) 2017 Братья Вершинины
```
