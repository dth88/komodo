#!/bin/bash
export HOST=aarch64-linux-gnu
CXX=aarch64-linux-gnu-g++
CC=aarch64-linux-gnu-gcc
PREFIX="$(pwd)/depends/$HOST"

set -eu -o pipefail

set -x
cd "$(dirname "$(readlink -f "$0")")/.."

cd depends/ && make HOST=$HOST V=1 NO_QT=1
cd ../
WD=$PWD
cd src/cc
echo $PWD
./makecustom
cd $WD

./autogen.sh
CONFIG_SITE=$PWD/depends/aarch64-linux-gnu/share/config.site CXXFLAGS="-DPTW32_STATIC_LIB -DCURL_STATICLIB -DCURVE_ALT_BN128 -fopenmp -pthread" ./configure --prefix="${PREFIX}" --host=aarch64-linux-gnu --enable-static --disable-shared
sed -i 's/-lboost_system-mt /-lboost_system-mt-s /' configure
cd src/
CC="${CC} -g " CXX="${CXX} -g " make V=1  komodod komodo-cli
