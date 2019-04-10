## Laboratory work XVII

Отчет по лабораторной работе №17 - итерация части исполнения контроля Рубежного Контроля №1: Шмаков Илья Станиславович, Группа: ИУ8-21М.

Данная лабораторная работа посвещена изучению процесса создания сеансов совместной разработки с использованием инструмента **ngrok**

```ShellSession
$ open https://ngrok.com/
```

## Tasks

- [x] 1. Ознакомиться со ссылками учебного материала
- [x] 2. Выполнить инструкцию учебного материала
- [x] 3. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial
Преднастройка переменных окружения и пути расширения
```ShellSession
$ cd ~
$ mkdir install
$ mkdir tmp
$ export HOME_PREFIX=`pwd`/install 
$ echo $HOME_PREFIX
$ export USERNAME=`whoami` # предопределения инициализирования аутентификации
```
Целевой каталог относительно корневого
```ShellSession
$ cd tmp
```
Преднастройка libevent-2.1.8 stable
```ShellSession
$ wget https://github.com/libevent/libevent/releases/download/release-2.1.8-stable/libevent-2.1.8-stable.tar.gz
$ tar -xvzf libevent-2.1.8-stable.tar.gz
$ cd libevent-2.1.8-stable
$ ./configure --prefix=${HOME_PREFIX} # конфигурирование проектной части
$ make && make install # формирование проектной части
$ cd ..
```
Преднастройка ncurses
```ShellSession
$ wget http://invisible-island.net/datafiles/release/ncurses.tar.gz
$ tar -xvzf ncurses.tar.gz
$ cd ncurses-5.9
$ ./configure --prefix=${HOME_PREFIX} # конфигурирование проектной части
$ make && make install # формирование проектной части
$ cd ..
```
Преднастройка tmux-2.5
```ShellSession
$ wget https://github.com/tmux/tmux/releases/download/2.5/tmux-2.5.tar.gz
$ tar -xvzf tmux-2.5.tar.gz
$ cd tmux-2.5
$ ./configure --prefix=${HOME_PREFIX} CFLAGS="-I${HOME_PREFIX}/include -I${HOME_PREFIX}/include/ncurses" LDFLAGS="-L${HOME_PREFIX}/lib" 
# конфигурирование проектной части
$ make && make install # формирование проектной части
$ cd ..
```
Преднастройка ngrok-stable
```ShellSession
$ wget https://bin.equinox.io/c/4VmDzA7iaHb/ngrok-stable-linux-amd64.zip
$ unizp ngrok-stable-linux-amd64.zip
$ mv ngrok ${HOME_PREFIX}/bin # перемещение по переменной окружения пути расширения
```
Преднастройка переменных окружения организации сеанса tmux
```ShellSession
$ export LD_LIBRARY_PATH=${HOME_PREFIX}/lib
$ export PATH="${HOME_PREFIX}/bin:${PATH}"
$ tmux new -s session_with_group # итерирования сеаса session_with_group
```
Представление подключения сессии к Host
```ShellSession
# Host: итерации исполнения для предоставляющей доступ стороны
$ open https://ngrok.com/signup # подключения к github - ngrok учетной записи
$ export NGROK_TOKEN=<7wYnFZkMg7CrYnsvPeZYu_327UAjgnMcKFXZFiUAfx6> 
# переменная окружения для предопределения туннелирования по ngrok.yml 
$ ngrok authtoken ${NGROK_TOKEN} # подключение, посредством применимости ngrok.yml
# как расширения для аккаунта github
$ ngrok tcp 22 # итерация исполнения туннелирования, либо применимости порта 80, 8000 
# - либо иного, в зависимости от предопределения целесообразности фактических нужд - 
# то есть открытие порта, для туннелирования, в завимости от применимости локального хостинга, 
# либо любой другой программы: корреляция посредством - https://ngrok.com/docs, в том числе и tls
<порт_ngrok_сервера>

# Пример исполнительной части подклчючения, сводной документации:
ngrok by @inconshreveable

Tunnel Status                 online
Version                       2.0/2.0
Web Interface                 http://127.0.0.1:4040
Forwarding                    http://92832de0.ngrok.io -> localhost:80
Forwarding                    https://92832de0.ngrok.io -> localhost:80

Connnections                  ttl     opn     rt1     rt5     p50     p90
                              0       0       0.00    0.00    0.00    0.00

# Примеры формирования собственной реализационной части подключения:
ngrok by @inconshreveable                                     (Ctrl+C to quit)
                                                                             
Session Status                online                                          
Account                       Elijah Doman (Plan: Free)                      
Version                       2.2.8                                          
Region                        United States (us)                              
Web Interface                 http://127.0.0.1:4040                          
Forwarding                    http://c60b11bc.ngrok.io -> localhost:80        
Forwarding                    https://c60b11bc.ngrok.io -> localhost:80      
                                                                             
Connections                   ttl     opn     rt1     rt5     p50     p90    
                             0       0       0.00    0.00    0.00    0.00


ngrok by @inconshreveable                                       (Ctrl+C to quit)
                                                                               
Session Status                online                                            
Account                       Elijah Doman (Plan: Free)                        
Version                       2.2.8                                            
Region                        United States (us)                                
Web Interface                 http://127.0.0.1:4040                            
Forwarding                    tcp://0.tcp.ngrok.io:16509 -> localhost:22        
                                                                               
Connections                   ttl     opn     rt1     rt5     p50     p90      
                             0       0       0.00    0.00    0.00    0.00

```
Представление подключения к сесиии Host
```ShellSession
# Introper: итерации исполнения для подключаеющейся стороны к предоставляющей
$ ssh ${USERNAME}@0.tcp.ngrok.io -p<порт_ngrok_сервера> 
# удаленное подключение по <порт_ngrok_сервера> к Host: предоставляющей доступ стороне
<пароль_от_учетной_записи> # предоставляющей доступ стороны
$ tmux a -t session_with_group # подключение к действующей предопределенной сессии session_with_group
$ <C-B>" # предопределение горизонтального разделения окна сессии
$ <C-B>& # итерация закрытия действующего окна
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
```
Copyright (c) 2017 Братья Вершинины
```
