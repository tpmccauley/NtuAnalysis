#!/bin/sh

export DIR=`dirname $0`
export TOP=`dirname ${DIR}`

eval `find ${TOP} | grep -i NANO | grep -v removeNANO | awk '{print "rm "$0" ;"}'`

cat << END_OF_INPUT > ${TOP}/Read/interface/NtuNANOReader.h
#ifndef NtuNANOReader_H
#define NtuNANOReader_H
template <class T>
class NtuNANOReader: public T {
};
#endif
END_OF_INPUT
