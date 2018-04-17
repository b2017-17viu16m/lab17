## Laboratory work XIV

Данная лабораторная работа посвещена изучению инструментов подписывания и верификации исполняемых файлов на примере **codesign**

```ShellSession
$ open http://bd808.com/blog/2013/10/21/creating-a-self-signed-code-certificate-for-xcode/
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab14** на сервисе **GitHub**
- [x] 2. Ознакомиться со ссылками учебного материала
- [ ] 3. Сгенерировать самоподписанный сертификат
- [x] 4. Выполнить инструкцию учебного материала
- [x] 5. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=b2017-17viu16m
```

```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab13 lab14
$ cd lab14
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab14
```

```ShellSession
$ cmake -H. -B_build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=_install
$ cmake --build _build
$ cmake --build _build --target install
```

```ShellSession
$ codesign -s "Your Company, Inc." ./_install/bin/demo
$ codesign -v ./_install/bin/demo
```

```ShellSession
$ travis setup releases
$ cat .travis.yml
```

```ShellSession
$ cat >> .travis.yml <<EOF
before_deploy:
- codesign -s "Your Company, Inc." ./_install/bin/demo
EOF
```

```ShellSession
$ git add .
$ git commit -m"added code signing"
$ git push origin master
```

```ShellSession
$ travis login --auto
$ travis enable
```

```ShellSession
$ git tag v0.1.0
$ git push origin master
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=14
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```


## Result

В ходе проделанной работы проведено ознакомление с инструментом Codesign подписывания и верификации исполняемых файлов.


## Links

- [Code Sign macOS](https://www.digicert.com/code-signing/mac-os-codesign-tool.htm)
- [Code Sign Windows](https://msdn.microsoft.com/ru-ru/library/windows/desktop/aa380259(v=vs.85).aspx)
- [Code Sign Unix](https://github.com/bartman/elfgpg)

```
Copyright (c) 2017 Братья Вершинины
```
