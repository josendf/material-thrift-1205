#! /bin/bash

cd ${THIS_DIR:="$(pwd)"}

PLATFORM_NAME=linux32
WORKSPACE_DIR=${THIS_DIR}/../../..
export LD_LIBRARY_PATH=${WORKSPACE_DIR}/usr/${PLATFORM_NAME}/lib

exec ./$1