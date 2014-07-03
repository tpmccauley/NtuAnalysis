#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

#include "TMPAnalysis/Ntu/interface/TMPAnalyzerUtil.h"

TMPAnalyzerUtil::TMPAnalyzerUtil() {

  // user parameters are set as names associated to a string, 
  // default values can be set in the analyzer class contructor
  setUserParameter( "use_muons" , "true" );
  setUserParameter( "use_jets"  , "true" );

}


TMPAnalyzerUtil::~TMPAnalyzerUtil() {
}


void TMPAnalyzerUtil::setupNtuple() {

  getUserParameter( "use_muons", use_muons );
  getUserParameter( "use_jets" , use_jets  );
  initTree();

  return;

}


void TMPAnalyzerUtil::beginJob() {

  NtuInterface< TMPNtupleBranch<WrapperBase> >::beginJob();

  // user parameters are retrieved as strings by using their names;
  // numeric parameters ( int, float or whatever ) can be directly set
  // by passing the corresponding variable,
  // e.g. getUserParameter( "name", x )

  return;

}


bool TMPAnalyzerUtil::getEntry( int ientry ) {
  if( !NtuAnalyzerUtil::getEntry( ientry ) ) return false;
  return true;
}

/*
void TMPAnalyzerUtil::getEvent( int ientry ) {
  currentTree->GetEntry( ientry );
  return;
}
*/

