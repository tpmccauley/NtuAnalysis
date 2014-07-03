#ifndef TMPAnalyzer_H
#define TMPAnalyzer_H

#include "TH1.h"
#include "TMPAnalysis/Ntu/interface/TMPAnalyzerUtil.h"

class TMPAnalyzer: public virtual TMPAnalyzerUtil {

 public:

  TMPAnalyzer();
  virtual ~TMPAnalyzer();

  // function called before starting the analysis
  virtual void beginJob();

  // functions to book the histograms
  void book();

  // functions called for each event
  virtual void reset() { autoReset(); }
//  virtual bool getEvent( int ientry );
//  virtual bool analyze( int entry, int event_file );
  virtual bool analyze( int entry, int event_file, int event_tot );

  // function called at the end of the analysis
  virtual void endJob();

  // functions called at the end of the event loop
  virtual void plot();   // plot the histograms on the screen
  virtual void save();   // save the histograms on a ROOT file

  bool verbose;

 protected:

/*
  virtual bool getEntry( int ientry ) {
    return TMPAnalyzerUtil::getEntry( ientry );
  }
*/

  float ptCut;

 private:

  TH1D* hptmumax;
  TH1D* hptmu2nd;
  TH1D* hptmu;

  // dummy copy constructor and assignment
  TMPAnalyzer           ( const TMPAnalyzer& );
  TMPAnalyzer& operator=( const TMPAnalyzer& );

};


#endif

