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
- AKA wrapper
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
- A proxy is applicable to give a simple pointer a smarter behavior.
- There are 4 types of proxies:
    1. Remote proxy; provides a local represntative for an object in a different address space
    2. Virtual proxy, creates expenside objects on demand
    3. Protection proxy, controls access to the original object
    4. Smart reference, performs additional actions when an object is accessed. E.g. counting the number of references to the real object, loading a persistent object in memory when it is first referenced, checking that the real object is locked to be thread safe
- Participants:
    - Proxy: maintains a reference to the object, provides a similar interface that can be substituted for the real object, controls access to the object. 
    - Subject, defines a common interfaces between the RealSubject and the Proxy
    - RealSubject, defines the real object that the proxy represents
- There are some other responsabilities of the Proxy:
    1. Remote proxies are responsible for encoding a request and its arguments
    2. Virtual proxies may cache additional information about the real object
    3. Protection proxies check that the caller has the access permissions
- @TODO: implement an example

Flyweight
---------
- Defines an structure for sharing objects, these objects are shared for two reasons:
    1. efficiency
    2. consistency
- It creates a pool of objects to share, then uses a factory to manage that pool and return a reference to the object if exists, otherwise it creates the object, adds it to the pool, and return its reference.
- Intrinsic state is stored in the flyweight
- Extrinsic state depends on and varies with the flyweight context. Clients are responsible of handling the extrinsic state
- Participants:
    - Flyweight; defines the interface of the objects
    - ConcreteFlyweight; implements the interfaces and adds storage, keeps the intrinsic state
    - UnsharedConcreteFlyweight; since not all concrete flyweights are shared, this class can represent a collection of concrete flyweights that are going to be unique
    - FlyweightFactory; creates and handles flyweight objects
    - Client; maintains the refereces to flyweights, compputes or stores the extrinsic state of flyweights
- @TODO: Add example

Facade
------
- Shows how to make a single object represent an entire subsystem
- It is a representative for a set of objects
- Carries out its responsabilities by forwarding messages to the objects it represents
- Provides a unified interface to a set of interface in a subsystem
- Reduces complexity
- [client] -> [facade] -> [subsystem classes]
- Usage:
    - To provide a single interface to a complex subsystem
    - Decouple the dependency of subsystem from clients and other subsystems
    - Layers the subsystems. A facade defines an entry point to each subsystem
- Participants:
    - Facade: the entry point to the subsystem, it delegates responsabilities according to the requests that it receives
    - Sub system classes, handle the work that Facade assings
- Clients
- @TODO: implement facade example


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
- It presents a flexible alternative to subclassing for extending functionality.
- AKA wrapper. Even though the book mentions that this pattern is also know as wrapper, the adapter is the one who represents more the wrapper term since it translates how the class is being called, but Decorator includes add more functions(responsabilities) to the class
- Usage:
    - To add or remove responsabilities to individual objects
- Participants:
    - Component, defines the interface for the objects we want to add more responsabilities
    - ConcreteComponent, implements the interface
    - Decorator, defines the interface that will allow us to add or remove responsabilities to the Component
    - ConcreteDecorator, implements the interface that adds or removes responsabilities
- @TODO: Implement the example

Differences
===========
- Adapter vs Bridge: Adapter is meant to adapt the interface of another library while Bridge separates an interface from its implementation.
- Adapter vs Decorator: A decorator enhances an object without changing its interface, in that sense a decorator is more transparent to the application than the adapter.
- Adapter vs Proxy: A proxy defines a representative for another object and does not change its interface.
- Decorator vs Composite: They can be used together.
- Iterator vs Composite: Iterator can be used to traverse the composites.

