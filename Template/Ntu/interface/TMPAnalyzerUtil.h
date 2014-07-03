#ifndef TMPAnalyzerUtil_H
#define TMPAnalyzerUtil_H

#include "TMPAnalysis/Ntu/interface/TMPNtupleBranch.h"
#include "NtuAnalysis/Common/interface/NtuInterface.h"

class TMPAnalyzerUtil: public NtuInterface< TMPNtupleBranch<WrapperBase> > {

 public:

  TMPAnalyzerUtil();
  virtual ~TMPAnalyzerUtil();

 protected:

  void setupNtuple();
  virtual void beginJob();

  virtual bool getEntry( int ientry );
//  virtual void getEvent( int ientry );


 private:


  // dummy copy constructor and assignment
  TMPAnalyzerUtil           ( const TMPAnalyzerUtil& );
  TMPAnalyzerUtil& operator=( const TMPAnalyzerUtil& );

};


#endif

