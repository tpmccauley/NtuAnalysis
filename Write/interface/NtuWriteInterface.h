#ifndef NtuWriteInterface_h
#define NtuWriteInterface_h

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "NtuTool/Common/interface/TreeWriter.h"

template<class T>
class NtuWriteInterface: public T,
                         public TreeWriter {

 public:

  NtuWriteInterface( const edm::ParameterSet& ps );
  virtual ~NtuWriteInterface();

  virtual void beginJob();

  virtual void openNtuple( const std::string& ntuName );

  bool analyzeEDM( const edm::EventBase& ev,
                   int ientry, int event_file );

  virtual void writeNtuple();
  virtual void closeNtuple();

  virtual void endJob();

 private:

  // dummy copy constructor and assignment
  NtuWriteInterface           ( const NtuWriteInterface& c );
  NtuWriteInterface& operator=( const NtuWriteInterface& c );

  std::string ntuName;
  TFile* file;

  bool dumpNtuple;

};

#include "NtuAnalysis/Write/interface/NtuWriteInterface.hpp"

#endif
