#ifndef NtuReader_H
#define NtuReader_H

#include "NtuTool/Common/interface/TreeReader.h"

template <class T>
class NtuReader: public T, public TreeReader {

 public:

  NtuReader() {}
  ~NtuReader() override {}

  void beginJob() override {
    T::setupNtuple();
    T::beginJob();
    return;
  }

  bool getEntry( int ientry ) override {
    return T::getEntry( ientry );
  }

 private:

  // dummy copy constructor and assignment
  NtuReader           ( const NtuReader& ) = delete;
  NtuReader& operator=( const NtuReader& ) = delete;

};

#endif
