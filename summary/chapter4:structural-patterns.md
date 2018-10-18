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

Decorator
---------
- Describes how to add responsibilities to objects dynamically
