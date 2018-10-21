Chapter 4: Structural Patterns
==============================

- Structural patterns are concerned on how classes and objects are composed to form large structures
    - Structural class patterns use inheritance to compose interfaces or implementations
    - Structural object patterns describe ways to compose objects to realize new functionality. It allows object composition change their types at runtime

Adapter
-------
- makes one interface conform to another, provides a uniform abstraction of different interfaces
- Converts the interface of a class into another interface that the client expects
- Lets clases work together that could not otherwise because of its incompatible interfaces
- It is a wrapper
- Usage:
    - When you want to use an existing class, but the interface does not match your contract
    - When you want to create a reusable class that cooperates with unrelated or unforseen classes with or without compatible interfaces
- There are two types of adapters:
    1. Class adapter, that uses class inheritance
    2. Object adapter, that uses object composition
- Participants:
    - Client, the one who uses the target
    - Target, defines the general interface
    - Adaptee, the new class interface we want to adapt
    - Adapter, the class that adapts the Adaptee by following the Target's contract

Composite
---------
- Describes how to build a class hierarchy made up of classes for two kinds of objects: primitive and composite.
- It is used when you want to represent part-whole hierarchies of objects. Also, when you want to ignore difference between compositions of objects and individual objects.
- Participants:
    1. Component; who declares the general interface
    2. Leaf; an implementation of Component who has no composition
    3. Composite; an implementation of Component who has elements of the type Component
    4. Client; who manipulates objects in the composition through the component interface

Proxy
-----
- A proxy acts like a placeholder for another object.
- Might protect access to sensitive object, therefore it restricts, enhances, or alter object propertities.  

Flyweight
---------
- Defines an structure for sharing objects, these objects are shared for two reasons:
    1. efficiency
    2. consistency

Facade
------
- Show how to make a single object represent an entire subsystem
- It is a representative for a set of objects
- Carries out its responsabilities by forwarding messages to the objects it represents

Bridge
------
- Separates and object's abstraction from its implementation
- Usually, the interface defines the behavior of an object and the implementation of that interface is done through inheritance. Abstractions and concrete classes are, therefore, attached forever which makes it hard to change any of the without altering both.
- Usage:
    - Avoid binding between the abstract classes and their implementations
    - Combine different abstractions and implementations that are independent from each other
    - Hide the implemenation of an abstraction from the client
    - Avoid have a proliferation of subclasses
- Participants:
    - Abstraction, defines the abstract interface 
    - RefinedAbstraction, extends the interface defined by Abstraction
    - Implementor, defines the interface for implementation classes
    - ConcreteImplementor, the implementation of the Implementor

Decorator
---------
- Describes how to add responsibilities to objects dynamically

Differences
===========
- Adapter vs Bridge: Adapter is meant to adapt the interface of another library while Bridge separates an interface from its implementation.
- Adapter vs Decorator: A decorator enhances an object without changing its interface, in that sense a decorator is more transparent to the application than the adapter.
- Adapter vs Proxy: A proxy defines a representative for another object and does not change its interface.


