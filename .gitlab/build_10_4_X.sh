#!/bin/bash

set -ex
shopt -s expand_aliases
export BUILD_DIR=${PWD}
set +u && source ${CMS_PATH}/cmsset_default.sh; set -u
source ${BUILD_DIR}/uty/setAtA40.sh
cmsrel ${CMSSW_RELEASE}
cd ${CMSSW_RELEASE}/src
git clone https://github.com/tpmccauley/NtuTool.git NtuTool
mkdir -p NtuAnalysis
mv ${BUILD_DIR}/Common NtuAnalysis
mv ${BUILD_DIR}/Read NtuAnalysis
mv ${BUILD_DIR}/Template NtuAnalysis
mv ${BUILD_DIR}/Write NtuAnalysis
mv ${BUILD_DIR}/uty NtuAnalysis
ls -ltr
cmsenv
scram b -v
