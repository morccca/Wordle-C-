# Игра Wordle

Реализация игры Wordle на C++.

## Инструкция по сборке

1. Клонируйте репозиторий
2. Создайте директорию для сборки: `mkdir build && cd build`
3. Настройте CMake: `cmake ..`
4. Соберите проект: `cmake --build .`

## Как играть

1. Запустите исполняемый файл `wordle.exe` в директории `build\Debug`.
2. Вводите слово, которым хотите угадать.
3. Если желтый цвет буквы, то она есть в слове, но не на своем месте. Если зеленый, то буква есть в слове и на своем месте. Если черный/белый, то буквы нет в слове.
4. Угадывайте  буквы, пока не отгадаете

## Какие слова угадывать / какие слова подходят

1. Вы угадываете слово, которое находится в файле `wordle_game.cpp` - ready, его можно изменить
2. Угадывать слово можно только словами из букв нижнего регистра, без цифр и слово должно состоять только из 5 букв.


