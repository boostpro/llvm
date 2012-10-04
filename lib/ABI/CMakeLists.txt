add_definitions(-Dclang=llvm_abi)

add_llvm_library(LLVMABI
  CodeGenModule.cpp

CGCUDARuntime.cpp
CGCXXABI.cpp
CGCall.cpp
CGObjCRuntime.cpp
CGOpenCLRuntime.cpp
CGVTables.cpp
CodeGenFunction.cpp
CodeGenTBAA.cpp
CodeGenTypes.cpp
TargetInfo.cpp

  )
