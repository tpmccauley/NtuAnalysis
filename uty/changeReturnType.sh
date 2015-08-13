#!/bin/sh

export FILE=$1
export FTMP=/tmp/`basename ${FILE}``date +%s`

awk '(index($0,"beginRun")==0){print $0} (index($0,"beginRun")>0){line=$0; sub("bool","void",line); print line}' ${FILE} | awk '(index($0,"endRun")==0){print $0} (index($0,"endRun")>0){line=$0; sub("bool","void",line); print line}' | awk 'BEGIN{ff=0} ((ff==0)||(index($0,"return")==0)){print $0} (index($0,"beginRun")>0){ff=1} ((ff==1)&&(index($0,"return")>0)){print substr($0,1,index($0,"return")+5)";"; ff=0}' | awk 'BEGIN{ff=0} ((ff==0)||(index($0,"return")==0)){print $0} (index($0,"endRun")>0){ff=1} ((ff==1)&&(index($0,"return")>0)){print substr($0,1,index($0,"return")+5)";"; ff=0}' > ${FTMP}
cp ${FTMP} ${FILE}
rm ${FTMP}
