# Synchronizing a printing queue using a binary semaphore

![C++](https://img.shields.io/badge/C++-20%2B-green?logo=c++)
![Build](https://img.shields.io/badge/build-manual-lightgrey)
[![Docs](https://img.shields.io/badge/doc-Doxygen-purple)](./doc/index.html)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

This C++ program demonstrates how a binary semaphore controls access to a shared printer. It creates a number of print job threads, each representing a job and requesting access to the printer. The job holds the semaphore while printing is simulated for one second, then releases it so another waiting job can proceed.

The semaphore starts with a count of one, allowing one job into the printing section at a time. Other threads wait until the current job releases it. The semaphore does not guarantee which waiting thread goes next, so the print order can vary between runs.

This project is part of the **Concurrent Programming** module at the [Federal University of Rio Grande do Norte (UFRN)](https://www.ufrn.br), Natal, Brazil.

## 📂 Repository Structure

```text
.
├── doc/                    # Documentation
├── include/                # Directory with header files
│   ├── job.h               # Definition of the Job class
│   └── printingqueue.h     # Definition of the PrintingQueue class
├── src/                    # Directory with source files
│   ├── job.cpp             # Implementation of the Job class
│   └── printingqueue.cpp   # Implementation of the PrintingQueue class
├── Doxyfile                # Doxygen configuration
├── main.cpp                # Main program
├── Makefile
└── README.md
```

## 🚀 Getting Started

### ✅ Prerequisites

- A C++ compiler with C++20 support, such as GCC 15 or a recent Clang
- A terminal or IDE
- GNU Make for the Makefile targets
- [Doxygen](https://www.doxygen.nl), only if you want to generate the HTML documentation

The Makefile currently sets `CC=g++-15`, so that command must exist on `PATH` when building C++ examples through `make`.

### 🔧 Compilation

Inside the project root, compile all sources from the [Makefile](Makefile):

```bash
make
```

This creates the compiled object files in the `build/` directory and the `printingqueue` executable in the `bin` directory.

### ▶️ Running

```bash
./bin/printingqueue
```

The program reports each job as it is sent to the printer and when printing completes. After all threads have joined, it prints `All printing jobs are finished`. The interleaving and order of job messages may differ between runs.

## Generate documentation

The [`Doxyfile`](Doxyfile) specifies `src` as the input and `doc/` as the HTML output directory. Use this configuration rather than running `doxygen -g`, which creates a new default configuration file.

With Doxygen installed, regenerate the documentation with either command:

```bash
make doc
# or
doxygen Doxyfile
```

Open [`doc/index.html`](doc/index.html). The generated `doc/` files are build artifacts; Doxygen comments in the source files provide the documentation content.

## Clean generated files

Remove compiled objects and executables with:

```bash
make clean
```

This removes compiled objects and the executables.

## 🤝 Contributing

Contributions are welcome! Fork this repository and submit a pull request 🚀

## 📜 License

This project is licensed under the [MIT License](LICENSE).
