#include "GaudiKernel/Kernel.h"
#include <iostream>

extern "C" GAUDI_IMPORT int GaudiMain( int argc, char* argv[] );

int main( int argc, char* argv[] ) {
  int code;
  code = GaudiMain( argc, argv );
  return code; 
}

