linux_CFLAGS=-pipe
linux_CXXFLAGS=$(linux_CFLAGS)

linux_release_CFLAGS=-O1
linux_release_CXXFLAGS=$(linux_release_CFLAGS)

linux_debug_CFLAGS=-O1
linux_debug_CXXFLAGS=$(linux_debug_CFLAGS)

linux_debug_CPPFLAGS=-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC

ifeq (86,$(findstring 86,$(build_arch)))
i686_linux_CC=gcc -m32
i686_linux_CXX=g++ -m32
i686_linux_AR=ar
i686_linux_RANLIB=ranlib
i686_linux_NM=nm
i686_linux_STRIP=strip

x86_64_linux_CC=x86_64-linux-gnu-gcc -m64
x86_64_linux_CXX=x86_64-linux-gnu-g++ -m64
x86_64_linux_AR=x86_64-linux-gnu-ar
x86_64_linux_RANLIB=x86_64-linux-gnu-ranlib
x86_64_linux_NM=x86_64-linux-gnu-nm
x86_64_linux_STRIP=x86_64-linux-gnu-strip
else
i686_linux_CC=$(default_host_CC) -m32
i686_linux_CXX=$(default_host_CXX) -m32
x86_64_linux_CC=$(default_host_CC) -m64
x86_64_linux_CXX=$(default_host_CXX) -m64
endif
