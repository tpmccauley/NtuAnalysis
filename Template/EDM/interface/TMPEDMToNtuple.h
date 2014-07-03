#ifndef TMPEDMToNtuple_h
#define TMPEDMToNtuple_h

#include "NtuAnalysis/Write/interface/NtuEDMAnalyzer.h"
#include "TMPAnalysis/Ntu/interface/TMPAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include <string>
#include <vector>
class TFile;

namespace pat {
  class Muon;
  class Jet;
}

class TMPEDMToNtuple: public TMPAnalyzer,
                      public NtuEDMAnalyzer {

 public:

  TMPEDMToNtuple( const edm::ParameterSet& ps );
  virtual ~TMPEDMToNtuple();

  virtual void beginJob();
  virtual void beginRun();
  virtual void read( const edm::EventBase& ev );
  virtual void endRun();
  virtual void endJob();

 private:

  template<class PATObject> class CompareByPt {
   public:
    bool operator()( const PATObject* l, const PATObject* r ) {
      return l->pt() > r->pt();
    }
  };

  std::string labelMuons;
  std::string labelJets;

  edm::Handle< std::vector<pat::Muon> > muons;
  edm::Handle< std::vector<pat::Jet > > jets;
  void fillMuons();
  void fillJets();

};

#endif
