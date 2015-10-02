#!/bin/sh

export DIR=`dirname $0`
export TOP=`dirname ${DIR}`

${DIR}/changeReturnType.sh ${TOP}/Write/interface/NtuFilter.h
${DIR}/changeReturnType.sh ${TOP}/Write/interface/NtuFilter.hpp

${DIR}/changeReturnType.sh ${TOP}/Write/plugins/EvNumFilter.h
${DIR}/changeReturnType.sh ${TOP}/Write/plugins/EvNumFilter.cc

eval `find ${TOP} | grep BuildFile | grep 'xml$' | awk -v DIR=${DIR} '{print DIR"/cleanupBuildFile.sh "$0" ;"}'`
