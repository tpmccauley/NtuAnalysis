#ifndef NtuInterface_H
#define NtuInterface_H

#include "NtuAnalysis/Common/interface/NtuAnalyzerUtil.h"

#define FULL 2
#define BARE 3

#  if UTIL_USE == FULL

// use all the functionalities provided by NtuTool
#include "NtuTool/Common/interface/TreeWrapper.h"
typedef TreeWrapper WrapperBase;

#elif UTIL_USE == BARE

// get the bare ntuple definition, with no usage of other utilities
// in addition to the analysis specific ones
// "NtuLightReader" simply forward calls directly to ROOT with no 
// additional operation
#include "NtuAnalysis/Common/interface/NtuLightReader.h"
typedef NtuLightReader WrapperBase;

#else
#error use -D UTIL_USE=FULL or -D UTIL_USE=BARE
#endif

template<class T>
class NtuInterface: public virtual NtuAnalyzerUtil,
                    public virtual T {

 public:

  NtuInterface() { currentTPtr = &(T::currentTree); }
  virtual ~NtuInterface() {}

 protected:

  void beginJob() {
    std::string evl = this->getUserParameter( "eventList" );
    bool flag = read( evl );
    skipList = ( flag && ( this->getUserParameter( "listType" ) == "skip" ) );
    return;
  }

  bool lightAnalyze( int entry, int event_file ) {
    bool acceptEv = this->analyze( entry, event_file, T::analyzedEvts++ );
    if ( acceptEv ) T::acceptedEvts++;
    return acceptEv;
  }

 private:

  // dummy copy constructor and assignment
  NtuInterface           ( const NtuInterface& );
  NtuInterface& operator=( const NtuInterface& );

};


#endif

