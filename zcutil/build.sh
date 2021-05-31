#!/usr/bin/env bash
export HOST=aarch64-linux-gnu
CXX=aarch64-linux-gnu-g++
CC=aarch64-linux-gnu-gcc

set -eu -o pipefail

function cmd_pref() {
    if type -p "$2" > /dev/null; then
        eval "$1=$2"
    else
        eval "$1=$3"
    fi
}

# If a g-prefixed version of the command exists, use it preferentially.
function gprefix() {
    cmd_pref "$1" "g$2" "$2"
}

gprefix READLINK readlink
cd "$(dirname "$("$READLINK" -f "$0")")/.."

# Allow user overrides to $MAKE. Typical usage for users who need it:
#   MAKE=gmake ./zcutil/build.sh -j$(nproc)
if [[ -z "${MAKE-}" ]]; then
    MAKE=make
fi

# Allow overrides to $BUILD and $HOST for porters. Most users will not need it.
#   BUILD=i686-pc-linux-gnu ./zcutil/build.sh
if [[ -z "${BUILD-}" ]]; then
    BUILD="$(./depends/config.guess)"
fi
if [[ -z "${HOST-}" ]]; then
    HOST="$BUILD"
fi

# Allow users to set arbitrary compile flags. Most users will not need this.
if [[ -z "${CONFIGURE_FLAGS-}" ]]; then
    CONFIGURE_FLAGS=""
fi

if [ "x$*" = 'x--help' ]
then
    cat <<EOF
Usage:
$0 --help
  Show this help message and exit.
$0 [ --enable-lcov || --disable-tests ] [ --disable-mining ] [ --enable-proton ] [ --disable-libs ] [ MAKEARGS... ]
  Build Zcash and most of its transitive dependencies from
  source. MAKEARGS are applied to both dependencies and Zcash itself.
  If --enable-lcov is passed, Zcash is configured to add coverage
  instrumentation, thus enabling "make cov" to work.
  If --disable-tests is passed instead, the Zcash tests are not built.
  If --disable-mining is passed, Zcash is configured to not build any mining
  code. It must be passed after the test arguments, if present.
  If --enable-proton is passed, Zcash is configured to build the Apache Qpid Proton
  library required for AMQP support. This library is not built by default.
  It must be passed after the test/mining arguments, if present.
EOF
    exit 0
fi

set -x

# If --enable-lcov is the first argument, enable lcov coverage support:
LCOV_ARG=''
HARDENING_ARG='--enable-hardening'
TEST_ARG=''
if [ "x${1:-}" = 'x--enable-lcov' ]
then
    LCOV_ARG='--enable-lcov'
    HARDENING_ARG='--disable-hardening'
    shift
elif [ "x${1:-}" = 'x--disable-tests' ]
then
    TEST_ARG='--enable-tests=no'
    shift
fi

# If --disable-mining is the next argument, disable mining code:
MINING_ARG=''
if [ "x${1:-}" = 'x--disable-mining' ]
then
    MINING_ARG='--enable-mining=no'
    shift
fi

# If --enable-proton is the next argument, enable building Proton code:
PROTON_ARG='--enable-proton=no'
if [ "x${1:-}" = 'x--enable-proton' ]
then
    PROTON_ARG=''
    shift
fi

eval "$MAKE" --version
as --version
ld -v

HOST="$HOST" BUILD="$BUILD" NO_PROTON="$PROTON_ARG" "$MAKE" "$@" -C ./depends/ V=1
./autogen.sh

CONFIG_SITE="$PWD/depends/$HOST/share/config.site" ./configure "$HARDENING_ARG" "$LCOV_ARG" "$TEST_ARG" "$MINING_ARG" "$PROTON_ARG" "$CONFIGURE_FLAGS" CXXFLAGS='-g'

#BUILD CCLIB

WD=$PWD

cd src/cc
echo $PWD
./makecustom


cd $WD
./autogen.sh
CONFIG_SITE=$PWD/depends/aarch64-linux-gnu/share/config.site CXXFLAGS="-DCURL_STATICLIB -DCURVE_ALT_BN128 -fopenmp -pthread" ./configure --prefix="${PREFIX}" --host=x86_64-linux-gnu --target=aarch64-linux-gnu --enable-static --disable-shared
sed -i 's/-lboost_system-mt /-lboost_system-mt-s /' configure
cd src/
CC="${CC} -g " CXX="${CXX} -g " make V=1 NO_GTEST=1 STATIC=1  komodod komodo-cli
