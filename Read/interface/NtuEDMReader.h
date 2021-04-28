#ifndef NtuEDMReader_H
#define NtuEDMReader_H

#include "NtuTool/Read/interface/EDMTreeReader.h"
#include <iostream>
#include <string>

template <class T>
class NtuEDMReader: public T, public EDMTreeReader {

 public:

  NtuEDMReader( const std::string& process, const std::string& producer ) {
    std::cout << "NtuEDMReader" << std::endl;
    setProcessName( process );
    setProducerName( producer );
  }
  ~NtuEDMReader() override {}

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
  NtuEDMReader           ( const NtuEDMReader& ) = delete;
  NtuEDMReader& operator=( const NtuEDMReader& ) = delete;

};

#endif
