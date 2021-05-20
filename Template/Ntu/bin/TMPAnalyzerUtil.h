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
  void beginJob() override;

  // optional: pre-selection, with minimal data process 
  // before full ntuple entry reading
  bool preSelect( int ientry ) override;

 private:

  // dummy copy constructor and assignment
  TMPAnalyzerUtil           ( const TMPAnalyzerUtil& ) = delete;
  TMPAnalyzerUtil& operator=( const TMPAnalyzerUtil& ) = delete;

};


#endif

