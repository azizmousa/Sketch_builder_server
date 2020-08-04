# Sketch Builder (server part)

sketch builder is an application that use AI and computer Vision technologies to convert design sketch to real code in multiple programming languages, the server part is the part which is responsible for communications between other parts and give them the orders.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes:

### Prerequisites

- gcc compiler(build version 8.3.0)
- cmake build tool
- Linux System (ubuntu, debian are tested)


### Installing

1- clone the project to your device and unzip it.

2- open the compiler directory suppose it called SERVER_HOME and create directory called build then open it in the terminal.

```
$ cd SERVER_HOME
$ mkdir build
$ cd build
```

3- compile the project and create the executable file

```
$ cmake ..
$ make
```

4- open the executable file directory

```
$ cd ..
$ cd bin
$ ./server
```

### Requirements

- its require ".config/binary.config" file to start
- "binary.config" file contain the paths for other parts binary files
- example

```
bin/compiler
bin/equalizer
bin/generator.jar
bin/ui.jar
```

## Main Project:
- [Sketch builder] (https://github.com/azizmousa/Sketch-Builder)
