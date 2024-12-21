# Описание проекта

Проект представляет собой порт игры Magic Square, написанной на языке BASIC, на язык C. Исходный код взят из сборника [More BASIC Computer Games](https://www.roug.org/retrocomputing/languages/basic/morebasicgames).

# Запуск игры

С помощью утилиты `make`, игру можно запустить в Windows, Linux и веб-браузере. Для запуска необходима установленная утилита `make`.

## Windows

Команда:
```bash
make windows
```
![](gifs/windows_demo.gif)

## Linux

Команда: 
```bash
make linux
```
![](gifs/linux_demo.gif)

## Web

Команда:
```bash
make web
```
![](gifs/web_demo.gif)


## Android

Для сборки под Android нужно использовать Android NDK. Для запуска программы используйте Termux.
![](images/android.jpg)

## Тестирование

Для проверки работы программы было реализовано автоматическое тестирование, симулирующее пользовательский ввод.
![](gifs/tests_gif.gif)
