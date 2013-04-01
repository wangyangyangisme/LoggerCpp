LoggerC++
---------

LoggerC++ (LoggerCpp) is a simple, elegant and efficient C++ logger library.

### The goals of LoggerC++ are:

- to keep dependencies to a minimum (STL and shared_ptr)
- to be portable
- to minimize cpu utilisation when no log are outputed
- to be thread-safe (output logs in same channel accross multiple threads)
- to be well documented with Doxygen tags
- to use a permissive MIT license, similar to BSD or Boost, for proprietary/commercial usage

### Suported platforms:

Developements and tests are done under the following OSs :
- Debian 7 (testing)
- Ubuntu 12.10
- Windows XP/7/8
And following IDEs/Compilers
- GCC 4.7.x with a provided Makefile
- Eclipse CDT under Linux, using the provided Makefile
- Visual Studio Express 2008/2010/2012 for testing compatibility purpose

### Dependencies:

- a STL implementation (even an old one, like the one provided with VC6 should work).
- a boost::shared_ptr, the C++ 11 std::shared_ptr, or my minimap shared_ptr implementation.

### Installation

To use this C++ Logger, you need to include the sources files into your project codebase.

### License

Copyright (c) 2013 Sébastien Rombauts (sebastien.rombauts@gmail.com)

Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
or copy at http://opensource.org/licenses/MIT)

## Getting started
### First sample demonstrates how to create a Logger and print some logs:

```C++
int main ()
{
    // Configure the default severity Level of new Channel objects
    Log::Manager::setDefaultLevel(Log::Log::eNotice);

    // Setup the list of Config for the Output objects,
    Log::Config::Vector configList;
    Log::Config::addOutput(configList, "OutputConsole");
    Log::Config::addOutput(configList, "OutputFile");
    Log::Config::setOption(configList, "filename",          "log.txt");
    Log::Config::setOption(configList, "max_size",          "10000");
    // and configure the Log Manager (create the Output objects)
    Log::Manager::configure(configList);
    
    // Create a Logger object, using a "Main.Example" Channel
    Log::Logger logger("Main.Example");
    
    // Test outputs of various kind of variables, and some common stream manipulations.
    std::string     str("string");
    unsigned int    ui  = 123;
    double          dbl = -0.023f;
    logger.debug() << "Variables ; '" << str << "', '" << ui << "', '" << dbl << "'";
    logger.debug() << "Hexa = " << std::hex << 0x75af0 << " test";
    logger.debug() << "Deci = " << std::right << std::setfill('0') << std::setw(8) << 76035 << " test";

    // Test outputs of various severity Level
    logger.debug()  << "Debug.";
    logger.info()   << "Info.";
    logger.notice() << "Notice.";
    logger.warning()<< "Warning.";
    logger.error()  << "Error.";
    logger.critic() << "Critic.";
    
    // Modify the output Level of the underlying Channel, and test various severity Level again
    logger.setLevel(Log::Log::eWarning);
    logger.debug()  << "NO Debug.";     // NO more debug logs
    logger.info()   << "NO Info.";      // NO more info logs
    logger.notice() << "NO Notice.";    // NO more notice logs
    logger.warning()<< "Warning.";
    logger.error()  << "Error.";
    logger.critic() << "Critic.";

    // Reset Level of the "Main.example" channel by its name
    Log::Manager::get("Main.Example")->setLevel(Log::Log::eDebug);
```

## How to contribute
### GitHub website
The most efficient way to help and contribute to this wrapper project is to
use the tools provided by GitHub:
- please fill bug reports and feature requests here: https://github.com/SRombauts/LoggerCpp/issues
- fork the repository, make some small changes and submit them with pull-request

### Contact
You can also email me directly, I will answer any questions and requests.

### Coding Style Guidelines
The source code use the CamelCase naming style variant where :
- type names (class, struct, typedef, enums...) begins with a capital letter
- files (.cpp/.h) are named like the class they contains
- function and variable names begins with a lower case letter
- member variables begins with a 'm', function arguments begins with a 'a', boolean with a 'b', pointers with a 'p'
- each file, class, method and member variable is documented using Doxygen tags
See also http://www.appinf.com/download/CppCodingStyleGuide.pdf for good guidelines
