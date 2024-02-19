# Ready-made LLVM IR ModulePass testbed

LLVM IR ModulePass testbed with zero boilerplate coding. Tested with LLVM 15. It probably also works with later versions (with tiny adjustments if needed).

## Setup

1. Clone the repository. 

```
$ git clone git remote add origin git@github.com:gwangmu/IRTestbed.git
$ cd IRTestbed
```

2. Make.

(With system-wide LLVM)

```
$ make
```

(Without system-wide LLVM) Specify the LLVM install directory to `LLVM_ROOT` and make.

```
$ LLVM_ROOT=<absolute/path/to/llvm/install/dir> make
```

3. Check `build` for built binaries (`tb-clang`/`tb-clang++`).

## Usage

1. Implement a module pass in `testbed.cpp::IRTestbed::run()`.
2. Make again.
3. Use `tb-clang` and `tb-clang++` in `build` as C/C++ compilers.

## FAQ

* What is the LLVM install directory?
    - The directory that contains `bin`, `lib`, and `include` directories
      created after building and installing LLVM or, if you're using a prebuilt
      binary, its root directory itself.

## What you can get

* (Obviously) ready-to-use LLVM IR pass testbed.
* How to build an LLVM plugin with CMake. (-> CMakeFiles.txt)
* How to write a compiler wrapper with C. (-> wrapper.cpp)
