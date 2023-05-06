/*
 * Executable clang wrapper with the testbed.
 * 
 * Mostly based on AFL. (https://github.com/google/AFL)
 * See "llvm_mode/afl-clang-fast.c" for the original implementation.
 */

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>

int main(int argc, char** argv) {
  char** cc_params = (char**)malloc((argc + 128) * sizeof(char*));
  int cc_par_cnt = 1;

  char _exepath[512];
  int _len = readlink("/proc/self/exe", _exepath, sizeof(_exepath));
  if (_len < 0) {
    std::cerr << "fatal: fail to resolve executable path.\n";
    abort();
  }

  std::string exepath = std::string(_exepath);
  
  int _name_pos = exepath.rfind('/');
  std::string exename = exepath.substr(_name_pos + 1); 
  std::string basepath = exepath.substr(0, _name_pos) + "/..";

  std::string real_exepath;
  if (exename == "tb-clang++")
    real_exepath = basepath + "/llvm/bin/clang++";
  else
    real_exepath = basepath + "/llvm/bin/clang";
  cc_params[0] = (char*)real_exepath.c_str();

  if (access(cc_params[0], X_OK)) {
    std::cerr << "fatal: fail to find '" << real_exepath << "'.";
    abort();
  }

  std::string libpath = std::string(basepath + "/build/libIRTestbed.so");

  cc_params[cc_par_cnt++] = (char*)"-Xclang";
  cc_params[cc_par_cnt++] = (char*)"-flegacy-pass-manager";
  cc_params[cc_par_cnt++] = (char*)"-Xclang";
  cc_params[cc_par_cnt++] = (char*)"-load";
  cc_params[cc_par_cnt++] = (char*)"-Xclang";
  cc_params[cc_par_cnt++] = (char*)libpath.c_str();

  while (--argc) {
    char* cur = *(++argv);
    cc_params[cc_par_cnt++] = cur;
  }
  cc_params[cc_par_cnt] = NULL;

  execvp(cc_params[0], (char**)cc_params);

  return 0;
}
