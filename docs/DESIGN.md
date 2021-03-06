# Project Design

## Table of Contents
- [Introduction](#intro)
	+ [Technologies](#tech)
	+ [Why C++](#cpp)
	+ [Why Qt](#qt)
	+ [Why SQLite3](#sqlite)
- [Source Code](#setup)
	+ [Basic Organization](#org)
	+ [Additional Headers](#headers)
	+ [Implementation Directory](#implementation)
	+ [External Dependencies](#dep)
- [Memory Management](#memory)
	+ [Ownership](#ownership)
	+ [Memory Leaks](#leaks)
- [Database](#db)
	+ [Tables](#tables)
	+ [Queries](#queries)
	+ [Namespace](#namespace)
- [Quirks & Design Decisions](#design)
	+ [Connecting Widgets](#connections)
	+ [Universal Separator](#sep)
	+ [Query Generator](#gen)
	+ [Tagging](#tags)
- [Final Notes](#final)


## Introduction<a name="intro"></a>

### Basic Technologies<a name="tech"></a>
The 3 basic technologies used in this project are :
- The C++ Programming Language
- The Qt Framework (v6.1.3)
- SQLite3

Architecture: x64

Compiler: Can be compiled by GCC or MSVC with no issues

### Why C++?<a name="cpp"></a>
I chose C++ because I am very interested in learning this language. Additionally, I had built a proof-of-concept application (i.e. version 1) in Python, and was too slow for my taste. Therefore, the design decision was to go with C++. C++ is extremely fast, the Qt framework's main API is in C++, and memory management is mostly handled by class hierarchy (delete the parents -> delete the children). Moreover, for a GUI application this size, I am much more comfortable with static types.


### Why Qt?<a name="qt"></a>
Qt is a cross-platform fully-fledged framework that comes with a lot of in-built functionality and excellent documentation. Choosing Qt was a no-brainer especially since I wanted to work with C++.

Additionally, since the application has 0 external dependencies outside the framework itself, this means that can I compile my source on any platform (Windows, Linux, MacOs) giving me an almost perfect "Write Once, Run Everywhere", granted there should be a compile in that statement. While I have not tried compiling my app on Linux or MacOs, I am confident that using the GCC would compile the source on any platform.


### Why SQLite3?<a name="sqlite"></a>
For an application this size, I am not communicating with any server and therefore a local db file is all I need. SQLite3 manages to be the fasted option for what I am looking for.


## How the source is setup<a name="setup"></a>
### Basic Organization<a name="org"></a>
As with any framework, there are certain design decisions imposed by the framework itself on the developer. What are they in my case?

Each dialog or window I design will have a corresponding `.ui` file, which is basically an XML document describing the structure of the interface. Moreover, each window or dialog, will have its own header and source file.


### Additional Headers<a name="headers"></a>
There are 2 additional header and source files that do not have a corresponding ui file:
- `queries`: contains all queries in an attempt to not pollute source files with SQL statements
- `common`: a file that contains functions that are used across all source files


### Around the Implemenation Directory <a name="implementation"></a>
Please find descriptions for the following in the implemenation directory:
- `docs`: Contains all documentation files
- `forms`: Contains .ui files for GUI
- `headers`: contains .h header files
- `resources`: contains icons and stylesheets
- `source`: contains .cpp files with code
- `EbookAccess.pro`: specific to the IDE

### External Dependencies <a name="dep"></a>
While this point has been iterated several times, I will explain it from a design perspective. The application in its current state has 0 external dependencies outside of the Qt Framework. Even functions are written in such a way to take into account that the application might run on a different platform.

One of my main concerns when I started with this project was the application being cross-platform. While Windows is definitely pervasive and I use it more than any other OS, I cannot make the mistake of thinking that it will be my primary work OS forever. Therefore, this application when compiled using G++ should be able to work on both Linux and MacOs. Granted that the widgets and UI might not look as native as one might wish them to be, the application should at least run well, which I am confident it would.

## Memory Management <a name="memory"></a>
### Ownership<a name="ownership"></a>
The Qt way of handling memory is following an object ownership hierarchy that will, when the topmost parent is deleted, have all of its children deleted as well.

Using this model, no memory leaks should arise.
### Memory Leaks<a name="leaks"></a>
I have tested my application using `Deleaker` since Valgrind is not available on Windows.

`Deleaker` has a free trial in which you can run your executable and it monitors if there are any leaks. My tests indicate that there are none. Please feel free however to check for yourself.

 [Deleaker](https://www.deleaker.com/download.html)



## Database <a name="db"></a>
### Tables <a name="tables"></a>
The database basically has only 2 tables,`ebooks` and `searches`.

The `ebooks` table has the following fields
- Name
- Folder
- Author
- Genre
- Path (Primary Key)
- Extension
- Size
- Tags
- Timestamp

The `searches` table contains all the information of a saved search.
### Queries <a name="queries"></a>
I created a queries header so that the logic and the SQL statements do not intermix. In the first version of this application, the main source files were polluted with SQL select statements and it became very tedious to search for a certain SQL statement.

Moreover, it is important to note that several of the SQL queries are used across several windows/dialogs and therefore I do not want to rewrite the same thing again. This especially came in handy as I modified my queries and therefore did  not have to do so in multiple places. The purpose of the queries header is to have all SQL logic abstracted away in one file.
### Namespace <a name="namespace"></a>
The queries header has the `queries` namespace so that variables and functions are not intermixed. This is a design choice for clarity since I am inevitably going to reference SQL functions in my main source files.

## Some Quirks & Design Decisions <a name="design"></a>
### Connecting Widgets With Functions <a name="connections"></a>
It is crucial to explain this point because Qt compiles in a certain way (while not forced, increases productivity).

Qt has a connection mechanism in which as it compiles, searches my source files for functions written in this manner: `on_<widgetName>_<signal>`

As the application compiles, Qt generates some cpp files in which it connects every widget with a signal to the corresponding function. That is why all my functions follow the above convention and that is why the functions are not generally commented as to their purpose or what they do, as the name is usually very self-explanatory.

Signals are usually sent by a widget and are often along the lines of `clicked`, `itemChanged`, etc.

Therefore, the way the functions are named is a design decision imposed by the framework. While there is definitely an alternative, it is much less productive and the codebase would triple in size.


### Universal Separator <a name="sep"></a>
I have chosen `|` as a universal separator. The GUI is not advanced enough such that there is a very clear discernible way to separate words and criteria. However, I have gone to great lengths to ensure that the user does not actually have to use the separator manually. For example, he could use the extended search functionality to choose all the criteria he wants.

The `|` is more for the internal functions to generate queries that are effective. The only time a user has to actually use the `|` is when he is updating an ebook's tags.

Why did I choose `|`? This is a very uncommon character and it is especially not common in file names and folder paths. Therefore if I use this uncommon separator, then the user has much more freedom to name his tags however he wishes, even using `,` and `.` in his tags.

In the future of my application, I would make it so that the user does not have to use the separator himself, and let everything be visual for him/her.

### Query Generation <a name="gen"></a>
While we have learned in class not to concatenate queries since that may cause unwanted and even malicious behaviour, I have taken the liberty to use this method in this application.

**First**, my application is not sending queries to a remote server and therefore I do not have to worry about SQL injection attacks. The app is completely offline and the only person that has access to the user's database is the user himself.

**Second**, using concatenation sped up productivity especially while writing the queries. Some queries were complex, and I did not want to write what was basically one query into multiple separate functions.

**Third**, I do to lengths to ensure that the concatenation is safe and there is nothing that can harm the user's data. I have tested my `clean` and `gen` functions and no issues have arisen.


### Tagging <a name="tags"></a>
This will be a controversial design choice, but let me fully explain it perhaps I can win you over.

**First**, why is there no table for tags only and another table that associates said tags with ebooks. This will add to the complexity of the SQL schema and queries and table joins will often slow down performance, granted in this very specific case, using C++ and SQLite3 and of course the users will not have millions of ebooks, performance impacts will be unnoticeable. But queries will grow in complexity.

**Second**, if I update an ebook's tags, then I will have to delete all its tags in an association table and re-insert tags again.

**Third**, what if there are certain tags in the tags table that do not have associations in the association table? Basically ownerless tags.

Therefore for the sake of time and productivity, I decided to store tags as a string of tags that are separated by the universal `|` separator. Searching tags and updating them are much easier this way, granted there are some additional functions whose purpose is to 'clean' tags and make sure they are written in the correct form. I fully acknowledge that this solution may not be ideal, but in my specific application and the capabilities I have granted the user, this makes sense.


## Final Note <a name="final"></a>
I acknowledge that in my code that there have been what would otherwise be called some bad design decisions. 

Therefore, I hope to my credit it is appreciated that I am aware of them and that I am aware there exists better alternatives and that I am aware of the potential dangers that might arise. Moreover, I attempted to demonstrate why they are thought of as bad design.


Granted, I use my application for personal use on a daily base and I have not encountered any malfunctions or bugs specifically related to these design choices.