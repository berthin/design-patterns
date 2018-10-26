Document Representation
-----------------------
Requirements for internal representation
 - Maintain the document's physical structure
 - Generate and present the document visually
 - Map the positions on the display to elements in the internal representation.

 Constrains:
  - Treat text and graphics uniformly
  - The implementation shoud not have to distinguish between single elements and groups of elements. Obs. It is required as well spell checking and hyphenations.

Hierarchial structure
- A technique for representing hierarchical structured information is called **recursive composition**. It gives us the way to compose a document out of simple graphical elements. For instance: a composition of single characters forms a line, multiple lines can be arranged in columns, multiple columns gives us a page.
- This technique requires two things:
 1) Objects need corresponding classes
 2) Classes must have compatible interfaces (objects must be treated uniformly) -- which means apply inheritance
a set of lines a column 
- Recursive composition can be used to represent potentially complex hierarchial structures; it captures the essence of recursive composition in object-oriented 

Glyphs
- Is an abstract class for all objects that can appear in a document (images, rows, characters)
- Responsabilities:
 1) They know how to draw themselves
 2) They know what space they ocupy
 3) They know their children and parent

Formatting
----------

Requirements:
- Have a balance between quality and speed. Good responses from the document without sacrificing how good the document looks

- Perhaps the user might not accept the time for a good formatting, or if does, the system can have an easy method to change between different algorithms for formatting
- Because formatting can be complex, it is desirable to keep them independent from the document structure
- Adding new formatting algorithms must not change the structure of Glyphs

Composition and Composition
- A **compositor** class to encapsulate the formatting algorithm is used
- The compositor know what glyphs to format and when to the formatting
- A **composition** is an instance of **compositor** and tell the compositor to compose its glyphs when necessary 
- Compositor-composition class ensures a separation between code that supports the document's physical strucutre and the code for different formatting algorithms.
- New compositors can be added without touching the Glyph, algorithms for formatting can be changing at run-time

Strategy Pattern
- Compositors are strategies, and they encapsulate different formatting algorithms
- Composition is the context for a compositor strategy
- Compositor interface gives compositions whatever they need to initiate formatting

Embellishing the User Interface
-------------------------------

Requirements:
 1) Add a border around the text editing are to demarcate the page of text
 2) Add scroll bards to let the user view differnet parts of the page
Constrains:
 - Make it easy to add and remove the embellishings. To satistfy this constrain, no inheritance must be used and no other objects must know what the embellishments are

Transparent Enclosure:
- Combines the notion of single-child and compatible interfaces, an enclosure delegates all its operations to its components

- To satisfy the condition that glyphs must not know what embellishments are; a new subclass MonoGlyhp is defined that inherits from Glyph with the objective of performing all embellishs that are required (e.g. Border and Scroller)

Decorator Pattern:
- Embellishment refers to anything that adds responsabilities to an object
- captures class and object relationships that support embellishments by transparent enclosure

Supporting Multiple Look-and-Feel Standars
------------------------------------------
Look-and-Feel standards are intented to enfornce uniformity between applications, they are guidelines for how application appear and rect to the user (all applications must react in the same way independently of the platform)

Requirements:
- achieve portability across hardware and software platforms

- A document is composed by invisible glyphs (rows and columns), and glyphs are composed by visible glyphs (buttons and characters); these last components are also called as widgets which, by definition, are elements in a user interface

- Two sets of widget glyph classes:
 1) Abstract glpyh subclass for each category of widget
 2) A set of concrete subclasses for each abstract subclass that implement different look-and-feel standards

Factories and Product Classes:
- Factories are used for e.g. creating elements UI from a guiFactory, which abstracts the process of creating scroll bar for any look-and-feel standard
- Factories create product objects, and products that a factory creates are related to one another. This way products are all widgets for the same look-and-feel
- The GuiFactory can be anywhere, and another pattern design is to use Singletons for managing well-known one-of-a-kind objects

Supporting Multiple Window Systems
----------------------------------
Requirements:
- Windowing enviroment (is another portability issues together with look-and-feel). A platform window creates the illusion of having multiple screen overlapped and events are captures according where they happen. These sort of situations must be handled for all existing OS to support the same behavior

Note:
- As similar as what is done with feel-and-like; it can be thought that Abstract Factories solve this requirements since an abstract class could create different widgets depending on the platform but it is hard to see the problem with this approach since we cannot afford to implement our own non-standard window system

- However, similar to feel-and-like, window system interfaces are not different from one another, therefore it is needed a uniform set of windowing abstractions to manage different *window system implementations*

The window class:
- Provide operations for drawing basic geometric shapes
- Can iconify and de-iconify themselves
- Can resize themselves
- Can re-draw their contents on demand

Alternatives for designing the window class:
- Intersection of functionality; the window class is common to all window systems
- Union of functionality; the window interface must incorporate all capabilities of all existing systems

Since neither of those alternatives are viable solutions, we could try to:
- Abstract the window class and implement it for specific window systems
- Have implementation-specific subclasses of each class in the Window hierarchy and have abother subclass explosion problem like the one done for embellishments
* These two alternatives have the drawback of, once the software is compiled, the window system cannot change, therefore several executables are required, one for each window system

A solution is to encapsulate what varies in the windowing task, and that is the window system implementation. Thus, we can define a window system functionality object and the Window class and subclasses use that object interface.

Window and WindowImp:
- Window is the abstract class, and WindowImp is the specific implementation of Window for  different window systems.
- The relation of Window and WindowImp is an example of the Bridge pattern. The intend behind this pattern is to allow separate class hierarchies to work together even as they evolve independently.

User Operations
---------------
Some of the required functionalities:
- Create a new document
- Open, save, print existing documents
- Cut selected text out and paste it back in
- Change the font and style of selected text
- Chage the format of the text
- Quit the application
- Undo & redo operations of most but not all
- ...

To satistfy all these requirements a MenuItem is implemented. These object will trigger commands and have a state.
Command Class and Subclasses:
- A command abstract class provides the interface for issuing a request. Subclasses of Command must implement the Execute method to fulfill different request, some subclasses may derive responsabilities
- When a user chooses a particular item from the menu, it call and executes its command object

Initially it was discussed about what the command must accept as parameters as well as what is preserved as states, a collection of functions can be an alternative, but functions require parameters so it is not suitable for this case. Thus, objects to represent states are required, and they will be used as parameters to the command class.

Approach for addressing the undo-redo requirement:
- The Command abstract class will have a reversible operation that determines if a given operation is reversible or not
- Commands have a certain level of history (list of commands that have been executed

Spelling Checking and Hyphenation
---------------------------------
Requirements:
- Check for grammatical errors
- Introduce hyphenation points for good formatting

- Multiple algorithms for checking errors are accepted, and they might vary in terms of space/time/quality trade-offs
* In the future, we might add some other analytical features to Lexi such as searching, word counting, ...
- In fact, there are two pieces of software to be considered:
 1) Accessing the information to be analyzed.
 2) Doing the analysis
- The text to be analyzed has a hierarchical structure, a mechanism to have the knowledge of how objects are stores is required and also mechanism for accesing these data. Some analysis strategies may traverse the text from beggining to end, other may do the opposite (e.g. reverse search). Thus, the access mechanisms must accommodate different data structures and we must support different traversal algorithms.
- Traversal are addressed by introducing the idea of **iterators**
- The analysis is separated from the traversal

Visitor Class and subclasses:
- Visitors are objects that visit other objects during traversal and do something appropiate
- Visitors can perform different analyses

Summary
-------
There are applied 8 different design patterns:
- Composite to represent the document's physical structure
- Strategy to allow different formatting algorithms
- Decorator for embellishing the user interface
- Abstract factory for multiple look-and-feel standards
- Bridge to allow multiple window platforms
- Command for undoable user operations
- Iterator for accessing and traversing obeject structures
- Visitor for allowing an open-ended number of analytical tasks

