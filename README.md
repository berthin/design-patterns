# Design Patterns

Implementation of the design patterns discussed in "Design Patterns: Elements of Reusable Code"

## Chapter1.
@TODO

## Chapter2.
@TODO

## Chapter3. Creational patterns
The book presents a use case of constructing a Maze and how to address different design patterns to construct the maze components and assemble them in order to create a maze. Therefore, the following patterns are explored:

- [Abstract factory](maze/src/MazeAbstractFactory.hpp)
- [Factory methods](maze/src/MazeFactoryMethod.hpp)
- [Builder](maze/src/MazeBuilder.hpp)
- [Prototype](maze/src/MazePrototype.hpp)

One more pattern that was included in the book, but not developed as it was designed in the book is the Singleton. However, to cover that topic I decided to implement a very basic *Logger* that prints a message in `std::out`.

- [Singleton](maze/src/Logger.hpp)


## How to build and compile the code
It is used `cmake` and `ninja` for compiling and building (see the `CMakeLists.txt` file of each example for more details), but 
the straigh forward approach is to use `Makefile` provided that will call the `cmake` commands. Therefore, use:
`make build`, `make compile`, or `make all` respectively.
