#include <iostream>

#include "TMPAnalysis/Ntu/interface/TMPNtupleData.h"

TMPNtupleData::TMPNtupleData() {

  // muons
  nMuons = 0;
  muoPt = new std::vector<number>;

  // muons
  nJets = 0;
  jetPt = new std::vector<number>;

}

TMPNtupleData::~TMPNtupleData() {
}


