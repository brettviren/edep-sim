#!/bin/sh

if [ -f edepsimTree.root ]; then
    rm edepsimTree.root
fi

if [ -d edepsimTree ]; then
    rm -rf edepsimTree
fi

edep-sim -o edepsimTree.root -e 10 -u 
	 ${EDEP_ROOT}/inputs/muon-10000.mac \

root -l -q edepsimTree.root ${EDEP_ROOT}/tools/loadEDepSim.C readTree.C

   
