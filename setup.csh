#!/bin/csh

if (! $?LD_LIBRARY_PATH) setenv LD_LIBRARY_PATH
if (! $?DYLD_LIBRARY_PATH) setenv DYLD_LIBRARY_PATH

setenv BASEDIR ${HOME}

setenv LinearAlgebra ${PWD}/lib
setenv LD_LIBRARY_PATH ${LinearAlgebra}:${LD_LIBRARY_PATH}
#only for Mac needed
setenv DYLD_LIBRARY_PATH ${LinearAlgebra}:${DYLD_LIBRARY_PATH}

if ($?TERM == 0 || $?prompt == 0) exit 0

echo ''
echo 'Setup our new LinearAlgebra Library'
echo '==========================='
echo ''
echo "<I>---------------Info--------------------<I>"
echo "Setting up the following environments: "
echo "LinearAlgebra: " $LinearAlgebra
echo "<I>---------------Info--------------------<I>"
echo ""
