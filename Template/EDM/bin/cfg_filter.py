import FWCore.ParameterSet.Config as cms

process = cms.Process("tmpSelect")

process.load("FWCore.MessageService.MessageLogger_cfi")

# Quiet Mode or event dump
#process.MessageLogger.cerr.threshold = 'ERROR'
process.MessageLogger.cerr.threshold = 'WARNING'
#process.MessageLogger.cerr.FwkReport.reportEvery = 10000

#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )

### define here a list of (MINI)AOD files
#filename = open('edm_files.list', 'r')
#fileList = cms.untracked.vstring( filename.readlines() )

#process.source = cms.Source ("PoolSource", fileNames=fileList)
process.source = cms.Source("EmptySource",
    numberEventsInRun   = cms.untracked.uint32(10)
)

### A filter is available to select events using a list having the format of
### a text file with run and event number pairs: 
###     - only events listed in the file will be accepted, by default;
###     - when setting listType to "skip" all events will be accepted
###       but the listed ones, that will be skipped.
#process.evNumFilter = cms.EDFilter('EvNumFilter',
#    eventList = cms.string('evList')
#)

process.tmpFilter = cms.EDFilter('TMPFilter',

    ## mandatory
    ## ntuple file name: giving an empty string the ntuple structure is 
    ## filled but it's not written to the ROOT file
    ntuName = cms.untracked.string('test_ntu.root'),
    ## histogram file name
    histName = cms.untracked.string('test_his.root'),

    ## optional
### A list of events can be given, with the same format as in the filter
### above; discarded events will not be passed to following modules, if any,
### and the ntuple structure will not be written to the ROOT file.
### To use this module as a simple analyzer look at the "cfg_fwfull.py" script
#    eventList = cms.string('evtlist'),
#    listType = cms.string('skip'),

    verbose = cms.untracked.bool(True),

### if RANDOM muon will be generated with random momenta in place of reading 
### from input (mandatory when reading from 
#    labelMuons        = cms.string('calibratedPatMuonsPFlow'),
    labelMuons        = cms.string('RANDOM'),

### if label is not set the "jets" block will not be activated and the
### corresponding branch(es) will not be included in the ntuple
#    labelJets         = cms.string('selectedPatJetsLooseIDUserDataPFlow'),

    ## select events with at least a muon with pT > 10 GeV
    ## (if missing a default ptCut=20GeV will be used, see TMPAnalyzer)
    ptCut = cms.double( 10.0 )

)


process.p = cms.Path(#process.evNumFilter *
                     process.tmpFilter)

### including an output module the filter can be used to skim (MINI)AOD
### on the basis of a simple ntuple analysis
process.out = cms.OutputModule("PoolOutputModule",
    outputCommands = cms.untracked.vstring('keep *_*_*_HLT',
                                           'keep *_*_*_RECO',
                                           'keep *_*_*_PAT' ,
                                           'drop *_*_*_tmpSelect'),
#                                           'drop *_puJetId_*_*',
#  output file name:
    fileName = cms.untracked.string('selectedEvents.root'),
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('p')
    )
)
process.e = cms.EndPath(process.out)
