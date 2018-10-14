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

Factory Method
==============
- Defines an interface for creating objects, but let subclasses decide which class to instantiate.
- Factory method is used when:
    - A class cannot anticipate the class of objects it must create.
    - A class wants its subclasses to specify the objects it creates.
    - Classes delegate responsability to one of several helper subclasses.
- A factory method receives 4 participants:
    1) Product; defines the interface of the objects that the factory method creates
    2) ConcreteProduct; the implementation of Product.
    3) Creator; declares the factory method that returns an object of type Product, it can call the factory method to create the Product object.
    4) ConcreteCreator; overrides the factory method to return an instance of a ConcreteProduct.

Prototype
=========
- Specifies the kinds of objects to create using a prototypical instance and creates new objects by copying this prototype.
- Prototype is used when a system must be independent of how products are created. It can also be used in the following cases:
    - When the classes to instantiate are specified at run-time.
    - To avoid building a class hierarchy of factories
    - When instances of a class have one of only a few different combinations of state.
- The Prototype patterns needs three participants:
    1. Prototype; declares the interface for cloning itself
    2. ConcretePrototype; implements prototype
    3. Client; creates a new object by asking a prototype to build itself
- Benefits of prototype:
    - It allows you to add and remove products at run-time
    - New objects can be created by varying its values or structure
    - Reduces subclassing
    - It is easy to configure an application with classes dynamically
- Note: subclasses of Prototype must implement the clone operation. Implementing clone can be difficult when internal objects do not support copying or have ciruclar references.



Differences
===========
Abstract Factory vs Builder:
----------------------------
- Builder focuses on constructing a complex object step by step.
- Abstract Factory puts emphasis on families of product objects.
- Builder returns the product as a final step.
- Abstract Factory return the product inmediately.

Abstract Factory vs Factory Methods
-----------------------------------
- Abstract Factory is commonly implemented with factory methods
- Factory methods are called also Template Methods.
- Factory methods dont require initialize the objects.


