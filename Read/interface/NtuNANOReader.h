#ifndef NtuNANOReader_H
#define NtuNANOReader_H

#include "NtuTool/Read/interface/NANOTreeReader.h"
#include <iostream>
#include <string>

template <class T>
class NtuNANOReader: public T, public NANOTreeReader {

 public:

  NtuNANOReader() {
    std::cout << "NtuNANOReader" << std::endl;
  }
  ~NtuNANOReader() override {}

  void beginJob() override {
    T::setupNtuple();
    T::beginJob();
    return;
  }

  bool getEntry( int ientry ) override {
    return T::getEntry( ientry );
  };

 private:

  // dummy copy constructor and assignment
  NtuNANOReader           ( const NtuNANOReader& ) = delete;
  NtuNANOReader& operator=( const NtuNANOReader& ) = delete;

};

#endif