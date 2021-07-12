#!/bin/bash

set -ex
shopt -s expand_aliases
export BUILD_DIR=${PWD}
set +u && source ${CMS_PATH}/cmsset_default.sh; set -u
ls -ltr
source ${BUILD_DIR}/uty/setAtA2E.sh
cmsrel ${CMSSW_RELEASE}
cd ${CMSSW_RELEASE}/src
git clone https://github.com/tpmccauley/NtuTool.git
source NtuTool/uty/setAtA2E.sh
cmsenv
scram b -v
