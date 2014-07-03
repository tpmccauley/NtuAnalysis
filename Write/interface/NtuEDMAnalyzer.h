#ifndef NtuEDMAnalyzer_h
#define NtuEDMAnalyzer_h

#define UTIL_USE FULL

#include "NtuAnalysis/Common/interface/NtuEventHeader.h"
#include "NtuAnalysis/Common/interface/NtuAnalyzerUtil.h"
#include "NtuTool/Common/interface/TreeWrapper.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/GeometryVector/interface/GlobalVector.h"
#include "DataFormats/GeometryCommonDetAlgo/interface/Measurement1D.h"

#include <string>
#include <vector>
class TFile;

namespace edm {
  class TriggerResults;
  class TriggerNames;
  class LumiReWeighting;
}

class NtuEDMAnalyzer: public virtual NtuEventHeader,
                      public virtual NtuAnalyzerUtil,
                      public virtual TreeWrapper {

 public:

  NtuEDMAnalyzer( const edm::ParameterSet& ps );
  virtual ~NtuEDMAnalyzer();

  virtual void beginJob();
  virtual void beginRun();
  virtual bool analyzeEDM( const edm::EventBase& ev,
                           int ientry, int event_file );
  virtual void read( const edm::EventBase& ev );
  virtual void endRun();
  virtual void endJob();

 private:

  // dummy copy constructor and assignment
  NtuEDMAnalyzer           ( const NtuEDMAnalyzer& c );
  NtuEDMAnalyzer& operator=( const NtuEDMAnalyzer& c );

};

#endif
