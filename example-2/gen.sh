#!/bin/bash

cd ${THIS_DIR:="$(pwd)"}

PLATFORM_NAME=linux32
WORKSPACE_DIR=${THIS_DIR}/../../..
WORKSPACE_USR_DIR=${WORKSPACE_DIR}/usr/${PLATFORM_NAME}
export LD_LIBRARY_PATH=${WORKSPACE_USR_DIR}/lib:${LD_LIBRARY_PATH}

${WORKSPACE_USR_DIR}/bin/thrift -r --gen cpp example.thrift
