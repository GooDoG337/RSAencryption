# RSA шифрование на C++

RSA 2048bit с собственным классом, позволяющий хранить достаточно большие для этого шифрования числа на С++ и более-менее оптимизированное.

![image](https://github.com/user-attachments/assets/9b9cfd47-6c87-41ba-bed4-ec2f4c1f5c15)

## Использованные библиотеки в main.cpp:<br>
&emsp;Использована собственноручно написанный класс longone для хранения больших чисел, подходящие для RSA 2048bit<br>
&emsp;&emsp;Использована библиотека <ostream> для вывода класса longone<br>
&emsp;&emsp;Использована библиотека <vector> для хранения цифр.<br>
&emsp;Использована библиотека <iostream> для ввода, вывода<br>
&emsp;Исползована библиотека <random> для получения рандомных чисел.<br>

## Зависимости:
g++, cmake

## Сборка:
В корневой папке проекта ввести следующие команды в терминал:
$ cmake -S . -B "ваше название папки"
$ cd "ваше название папки"
$ make

## Запуск:
После сборки в "ваше название папки" ввести следующую команду в терминал:
$ ./Codes

