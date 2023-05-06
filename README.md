# Ready-made LLVM IR ModulePass testbed

LLVM IR ModulePass testbed with definitely no boilerplate coding. Tested with
LLVM 15. Probably also work with later versions too (with tiny adjustment if
needed).

## Setup

1. Enter this directory. 

```
$ cd IRTestbed
```

2. Create a symbolic link to the LLVM install directory at `llvm`.

```
$ ln -s <path/to/llvm/install> llvm
```

3. Make.

```
$ make
```

## Usage

1. Implement a module pass in `testbed.cpp::runOnFunction()`.
2. Make again.
3. Use `build/tb-clang` and `build/tb-clang++` as C/C++ compilers.

## FAQ

* What is the LLVM install directory?
    - The directory that contains `bin`, `lib`, and `include` directories
      created after building and installing LLVM or, if you're using a prebuilt
      binary, its root directory itself.
