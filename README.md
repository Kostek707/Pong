# Elastic Collision Simulator

Pong game based on an original version from 1972.

## Overview

![](https://i.imgur.com/jK8BWkB.gif)

**Frame rate of the giph is much lower than in the game.**

## Getting started

Below you can find instructions on how to run the program on your computer.

### Prerequisites

To run the program, you must have an SFML library installed. You can install it on Linux using the command shown below

```
sudo apt-get install libsfml-dev
```

If you encounter any problems, refer to the SFML library [homepage](https://www.sfml-dev.org/tutorials/2.5/start-linux.php)


To install the SFML library on any other operating system, refer to this [page](https://www.sfml-dev.org/download.php) 

### How to run code on Linux

After downloading files or cloning the repository, compile the main.cpp file with the following command:

```
g++ -c main.cpp 
```

Link the compiled file to the SFML library in order to get the final executable:

```
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
```

Finally, to run the program, use the command:
```
./sfml-app
```

## How to use?
To start each round you need to press **ENTER**. The player controls a right paddle by moving it horizontally using **'W'** and **'S’** keys (UP and DOWN respectively). You use a paddle to hit a ball back and forth. If the computer doesn't hit the ball you get a point, in the opposite case the computer gets the point.
