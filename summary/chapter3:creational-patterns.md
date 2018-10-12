Chapter 3: Creationl Patterns
=============================
- Creational patterns abstract the instatiation process
- Make the system independent on how the objects are created, composed and represented
- Uses inheritance and can delegate the instatiation to another object
- There are two themes when creating objects is referred
    1. Encapsulation, they have all the knowledge about the concrete classes used in the system
    2. High level for instatiation, they hide how instances of these classes are created and put together
- Instatiation can be static (compile-time) or dynamic (run-time)
- Sometimes creational patterns are competitors: e.g. prototype vs abstract factory
- Sometimes creational patterns are complementary: e.g Builder can be used by other patterns, prototype can use singleton.
- To exemplify the creational patterns, a maze game is going to be the study case. 
    - We will focus on how mazes are created
    - A maze is a set of rooms
    - A room knows its neighbors: 
        - another room
        - a wall
        - a door

- Difference between Factory method vs Abstract factory?

Abstract Factory
----------------
- Provide an interface for creating families of related or dependednt objects without specifying theri concrete classes
- It is used when the system 
    - Must be independent of how products are crated, composed, and represented.
    - Should be configured with one of multiple families products
    - A family of related product objests is designed to be used together
    - You want to provide  class library of products
- 

>>> A example of creational patterns can be used in "file"

Builder
-------
- Separates the construction of a complex object from its representations.
- The builder pattern is used when the algorithm that creates a complex object must be independent from that parts that make up the object; also, when the construction must allow different representations of the objects that are being constructed.
- It has two parts:
	1) Director: constructs the object using the builder interface
	2) Builder: specifies the abstract interface for creating parts of the product
		- ConcreteBuilder: is the implementation of the interface
		- Product: is what the ConcreteBuilder returns

- Since the product representation is encapsulated, you are free to change its internal representation. Because the builder provides the director an abstract interface, it hides how the product gets assembled.
- Isolates code for construction and representation and gives you a better control over the construction process.
- In the Maze example, StandardMazeBuilder is in charge of creating all parts of the maze, and MazeGame will be in charge of assemble those parts to create the maze. Also, as an extension, you can also implement a different MazeBuilder (e.g. CountingMazeBuilder) that instead of creating the objects, it just counts how many objects are created. Then, the only thing to change would be the parameter that MazeGame receives.

Differences
===========
Abstract Factory vs Builder:
----------------------------
- Builder focuses on constructing a complex object step by step.
- Abstract Factory puts emphasis on families of product objects.
- Builder returns the product as a final step.
- Abstract Factory return the product inmediately.


