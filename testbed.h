#pragma once

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

/* Pass declaration */

class IRTestbed : public ModulePass {
public:
	static char ID;
	IRTestbed() : ModulePass(ID) {}
	virtual bool runOnModule(Module &M);
};

char IRTestbed::ID = 0;
static RegisterPass<IRTestbed> X("IRTestbed", "IR ModulePass testbed", false, false);

/* Pass registration (legacy) */

static void registerIRTestbed(const PassManagerBuilder &PMB,
		legacy::PassManagerBase &PM) 
{	PM.add(new IRTestbed()); }

static RegisterStandardPasses RegisterIRTestbedPass(
		PassManagerBuilder::EP_OptimizerLast, registerIRTestbed);
static RegisterStandardPasses RegisterIRTestbedPassL0(
		PassManagerBuilder::EP_EnabledOnOptLevel0, registerIRTestbed);
