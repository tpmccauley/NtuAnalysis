#!/bin/sh

cd `dirname $0`/..
export TMP_PACK_DIR=`/bin/pwd`
cd ../..
export TMP_ROOT_DIR=`/bin/pwd`
echo $TMP_PACK_DIR
echo $TMP_ROOT_DIR

export TMP_EXE_FILE=${TMP_PACK_DIR}/bin/tmpTreeAnalyze
rm -f ${TMP_EXE_FILE}

c++ -Wall `root-config --cflags`              \
-I ${TMP_ROOT_DIR} -I ${NTU_TOOL_DIR}/include \
-o ${TMP_EXE_FILE}                            \
`ls -1 $TMP_PACK_DIR/src/*cc      |\
       grep -v TMPAnalyzer.cc     |\
       grep -v TMPAnalyzerUtil.cc |\
       awk '{printf($0" ")}'`                 \
${TMP_PACK_DIR}/bin/TMPAnalyzerInstance.cc    \
${XYZ_ROOT_DIR}/NtuAnalysis/*/src/*cc         \
-L${NTU_TOOL_DIR}/lib -lNtupleTool            \
`root-config --glibs`

echo ${TMP_EXE_FILE}
