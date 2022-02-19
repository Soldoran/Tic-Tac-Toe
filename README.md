## Table of Contents
* [About this project](#about-this-project)
* [What did I learn](#what-did-i-learn)
* [Why a header file?](#why-a-header-file?)
* [Compiled with](#compiled-with)
* [Worked with](#worked-with)

## About this project
I recently began to learn about structs in C and on a whim decided to do a little weekend project about it.
My choice was to do a terminal application of the game Tic Tac Toe. Even though it may not be the best choice,
because of the tiny scope of this project, I still feel like I learned alot from it.

Also I sued this project to deepen my Git and Github skills, by working from 2 different devices on this project,
and by creating this README.md.

## What did I learn
Well initialy I wanted to create an 2 dimensional array in a struct, but then realized (or rather didn't found an answer
if it's even posssible) that I will have to use a normal array.

Also I learned more about the **scanf** and about its weird behaviors.
On my research on an occuring problem, the most common answer was to use fgets and sscanf instead.

## Why a header file?
While a own header file is not necessary for a project of this scope, I still decided to create and use one, to force myself more, to work or rather create header files and to start to make it a kind of habit of mine.

## Compiled with
```
gcc -Wall -Werror -Wextra tictactoe.c tictactow.h -o TicTacToe
```

## Worked on
* Windows 10 - VSCode
* Ubuntu 20.04 - VSCode