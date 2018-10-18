# Design Patterns

Implementation of the design patterns discussed in "Design Patterns: Elements of Reusable Code"

## Chapter1.
@TODO

## Chapter2.
@TODO

## Chapter3. Creational patterns
The book presents a use case of constructing a Maze and how to address different design patterns to construct the maze components and assemble them in order to create a maze (see [maze doc](maze/doc/main.md) for more details). Hence, the following patterns are covered:

- [Abstract factory](creational_patterns/src/MazeAbstractFactory.hpp)
- [Factory methods](creational_patterns/src/MazeFactoryMethod.hpp)
- [Builder](creational_patterns/src/MazeBuilder.hpp)
- [Prototype](creational_patterns/src/MazePrototype.hpp)

One more pattern that was included, but not developed as it was designed in the book, is the *Singleton*. However, to cover that topic I decided to implement a very basic *Logger* that prints a message in `std::out`; and therefore, the logger implements the *Singleton* pattern.

- [Singleton](creational_patterns/src/Logger.hpp)


## How to build and compile the code
It is used `cmake` and `ninja` for compiling and building (see the `CMakeLists.txt` file of each example for more details), but 
the straigh forward approach is to use `Makefile` provided that will call the `cmake` commands. Therefore, use:
`make build`, `make compile`, or `make all` respectively.
