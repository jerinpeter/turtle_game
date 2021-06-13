# A simple game using Turtlesim 
## Introduction

A game made with TurtleSim in :::ROS, the task is to drive the turtle around a predefined path without going out of the line.


## Prerequisites

* [Ubuntu version : 20.04 / 18.04](https://ubuntu.com/download/desktop)
* [ROS version : Noetic / Melodic](http://wiki.ros.org/noetic/Installation/Ubuntu)
* Editor used : [Vscode](https://code.visualstudio.com/download)
* Compiler  : catkin


## Building & Installation
```
cd catkin_ws/src

https://github.com/jerinpeter/turtle_game

cd ..

catkin_make

roslaunch turtle_launch.launch

```
## Working in brief

* Subscribed to "/turtle1/color_sensor" topic to get the background colour of the turtle.

```
    " /turtle1/set_pen
    "/turtle1/teleport_absolute"
```
The above services where used to draw a predefined shape in the turtlsim for the user to drive the robot.

* If the turtle when out of line a warning message is given to the user.




## DEMO

![Working](demo/demo.gif)

## Reference

* [ROS wiki TurtleSim](http://wiki.ros.org/turtlesim)

* [ROS Service](http://wiki.ros.org/rosservice)

* [Launch file creation](http://wiki.ros.org/roslaunch)


