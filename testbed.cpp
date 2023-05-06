#include "testbed.h"

using namespace llvm;

#include <iostream>

bool IRTestbed::runOnModule(Module &M) {
  // TODO: your ModulePass test here.

  // EXAMPLE: print the name of all functions.
  for (auto &_F : M.functions())
    std::cout << _F.getName().str() << "\n";

	return false;
}
