# Corner Grocer Item Tracker

## Project Overview

The Corner Grocer Item Tracker is a C++ console program that analyzes a daily purchase-record file. It counts how often each grocery item appears and allows the user to search for one item, display all item frequencies, or view the results as a text-based histogram. The program also creates `frequency.dat` automatically so the calculated frequencies are preserved in a backup file.

## Features

- Reads purchase records from `CS210_Project_Three_Input_File.txt`
- Stores item frequencies in a `std::map`
- Handles searches without requiring exact capitalization
- Displays a complete frequency list
- Displays a histogram using asterisks
- Validates menu input and reports file errors
- Writes the required `frequency.dat` backup file
- Accepts an alternate input-file path as a command-line argument

## Project Files

- `main.cpp` contains the menu, input handling, and program flow.
- `CornerGrocer.h` declares the `CornerGrocer` class.
- `CornerGrocer.cpp` loads the data, counts purchases, performs searches, writes the backup, and displays results.
- `CS210_Project_Three_Input_File.txt` contains the purchase records used by the program.
- `frequency.dat` contains the generated item-frequency backup.
- `CornerGrocer.sln` and the Visual Studio project files support building the program in Visual Studio 2022.

## Running the Program

Open `CornerGrocer.sln` in Visual Studio 2022 and run the project. The input file must remain in the program's working directory. If Visual Studio starts the executable from a Debug or Release subfolder, set the debugging working directory to `$(ProjectDir)`.

The program can also be compiled from a terminal with a C++17 compiler:

```text
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp CornerGrocer.cpp -o CornerGrocer
./CornerGrocer
```

## Reflection

### Project Summary

This project solved the problem of turning a plain list of grocery purchases into useful frequency information. The program reads the records once, stores the counts in a map, and gives the user several ways to review the results. This makes it easier for the store to identify how often products are purchased without counting each record manually.

### What I Did Well

I did particularly well at organizing the program into focused parts. The `CornerGrocer` class handles the purchase data, searches, backup file, and reports, while `main.cpp` controls the menu and user interaction. I also added input normalization so searches are not affected by capitalization or extra spaces, and I included clear error messages when an input or output file cannot be opened.

### Opportunities for Improvement

I could improve the program by separating report formatting from console output so the results would be easier to test or reuse in another interface. I would also add automated tests for empty files, repeated items, unusual capitalization, invalid menu entries, and failed file operations. These changes would make future updates safer, improve test coverage, and reduce the chance that an edge case causes incorrect output.

### Challenges and Support Resources

The most challenging parts were normalizing item names consistently and making sure invalid menu input did not interrupt the program. I addressed these problems by breaking the logic into small functions and testing searches with different capitalization, surrounding spaces, and invalid choices. Resources I would continue adding to my support network include compiler warnings, the Visual Studio debugger, C++ reference documentation, GitHub version history, and a unit-testing framework such as Catch2 or GoogleTest.

### Transferable Skills

The most transferable skills from this project are file input and output, data organization with standard library containers, input validation, error handling, and class design. I can apply the same approach to programs that read records, summarize data, create reports, or provide a menu-driven interface. Breaking a larger requirement into small functions will also help me manage more complex projects in later courses.

### Maintainability Readability and Adaptability

I made the program maintainable by separating declarations, implementation, and program flow into different files. Descriptive names such as `LoadPurchaseData`, `GetItemFrequency`, and `WriteBackupFile` make each function's purpose clear, while `const` methods show which operations do not change stored data. The short functions, limited responsibilities, and optional command-line input path make the program easier to read, test, and adapt to a different data file or user interface.
