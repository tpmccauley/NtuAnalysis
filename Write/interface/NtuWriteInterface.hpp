
#include "TFile.h"
#include "TROOT.h"

using namespace std;

template<class T>
NtuWriteInterface<T>::NtuWriteInterface( const edm::ParameterSet& ps ):
  T( ps ) {

  cout << "NtuWriteInterface::NtuWriteInterface" << endl;

  ntuName = ps.getUntrackedParameter<string>( "ntuName" );
  dumpNtuple = ( ntuName != "" );

}


template<class T>
NtuWriteInterface<T>::~NtuWriteInterface() {
}


template<class T>
void NtuWriteInterface<T>::beginJob() {

  cout << "NtuWriteInterface::beginJob()" << endl;

  T::beginJob();
  openNtuple( ntuName );

  return;

}


template<class T>
void NtuWriteInterface<T>::openNtuple( const string& name ) {
  TDirectory* current = gDirectory;
  file = ( dumpNtuple ? new TFile( name.c_str(), "CREATE" ) : 0 );
  initWrite( file );
  current->cd();
  return;
}


template<class T>
bool NtuWriteInterface<T>::analyzeEDM( const edm::EventBase& ev,
                                       int ientry, int event_file ) {
  bool select = T::analyzeEDM( ev, ientry, event_file );
  if ( select ) writeNtuple();
  return select;
}


template<class T>
void NtuWriteInterface<T>::writeNtuple() {

  if ( !dumpNtuple ) return;
  // function provided by the tool to actually fill the tree
  fill();

  return;

}


template<class T>
void NtuWriteInterface<T>::closeNtuple() {
  if ( !dumpNtuple ) return;
  std::cout  << "NtuWriteInterface::closeNtuple" << std::endl;
  close();
  file->Close();
  return;
}


template<class T>
void NtuWriteInterface<T>::endJob() {
  T::endJob();
  closeNtuple();
  return;
}

