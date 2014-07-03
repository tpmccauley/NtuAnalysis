#ifndef NtuReader_H
#define NtuReader_H

#include "NtuTool/Read/interface/TreeReader.h"

template<class T>
class NtuReader: public T, public TreeReader {

 public:

  NtuReader() {}

  void beginJob() {
    T::setupNtuple();
    T::beginJob();
    return;
  }

  bool getEntry( int ientry ) {
    return T::getEntry( ientry );
  }

 private:

  // dummy copy constructor and assignment
  NtuReader           ( const NtuReader& );
  NtuReader& operator=( const NtuReader& );

};

#endif
