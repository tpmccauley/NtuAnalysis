import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

process = cms.Process('NANO',eras.Run2_2018,eras.run2_nanoAOD_102Xv1)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('PhysicsTools.NanoAOD.nano_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

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

### an empty source is used here for testing purposes
process.source = cms.Source("EmptySource",
    numberEventsInRun   = cms.untracked.uint32(10)
)

process.options = cms.untracked.PSet(
)
#Setup FWK for multithreaded
process.options.numberOfThreads=cms.untracked.uint32(1)
process.options.numberOfStreams=cms.untracked.uint32(0)

### A filter is available to select events using a list having the format of
### a text file with run and event number pairs: 
###     - only events listed in the file will be accepted, by default;
###     - when setting listType to "skip" all events will be accepted
###       but the listed ones, that will be skipped.
#process.evNumFilter = cms.EDFilter('EvNumFilter',
#    eventList = cms.string('evList'),
#    listType = cms.string('skip')
#)

# Path and EndPath definitions
# the EDProducer must have a name "process.tmpNtuTable" to be written to the
# output, otherwise its name must be appended to the outputCommands
process.tmpNtuTable = cms.EDProducer('TMPNANONtuplizer',

    ## mandatory
    ## histogram file name
    histName = cms.untracked.string('test_his.root'),

    ## optional
### A list of events can be given, with the same format as in the filter
### above; discarded events will be passed to following modules but 
### no processing will be done, the ntuple structure will not be filled 
### and nothing will be added to the Event.
#    eventList = cms.string('evtlist'),
#    listType = cms.string('keep'),
##    listType = cms.string('skip'),

    verbose = cms.untracked.bool(True),

### if RANDOM muons will be generated with random momenta in place of reading 
### from input (mandatory when reading from an empty source)
#    labelMuons        = cms.string('calibratedPatMuonsPFlow'),
    labelMuons        = cms.string('RANDOM'),

### if label is not set the "jets" block will not be activated and the
### corresponding branch(es) will not be included in the ntuple
#    labelJets         = cms.string('selectedPatJetsLooseIDUserDataPFlow'),

    ## select events with at least a muon with pT > 10 GeV
    ## (if missing a default ptCut=20GeV will be used, see TMPAnalyzer)
    ptCut = cms.double( 10.0 )

)

process.tmpSequenceNtu = cms.Sequence(#process.evNumFilter *
                                      process.tmpNtuTable
                                     )

# Output definition
process.NANOAODoutput = cms.OutputModule("NanoAODOutputModule",
    compressionAlgorithm = cms.untracked.string('LZMA'),
    compressionLevel = cms.untracked.int32(9),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('NANOAOD'),
        filterName = cms.untracked.string('')
    ),
    fileName = cms.untracked.string('file:test_nnn.root'),
    outputCommands = process.NANOAODEventContent.outputCommands
)
### appending to the outputCommands is not necessary for producers
### named "process.tmpNtuTable:

process.tmpNtuStep = cms.Path(process.tmpSequenceNtu)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.NANOAODoutput_step = cms.EndPath(process.NANOAODoutput)

process.schedule = cms.Schedule(process.tmpNtuStep,process.NANOAODoutput_step)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

