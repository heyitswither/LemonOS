.ONESHELL:all
CC=gcc
WGET=wget

export PREFIX="$(CURDIR)"
export TARGET=i686-elf
export PATH:="$(PREFIX)/bin:$(PATH)"

notarget: binutils gcc
.NOTPARALLEL:

binutils:
	mkdir -p src/build-binutils
	cd src
	$(WGET) ftp://ftp.gnu.org/gnu/binutils/binutils-2.29.tar.gz
	tar -xvf binutils-2.29.tar.gz
	cd build-binutils
	../binutils-2.29/configure --target=$(TARGET) --prefix="$(PREFIX)" --with-sysroot --disable-nls --disable-werror
	$(MAKE)
	$(MAKE) install
	$(MAKE) clean
	cd ../..

gcc:
	mkdir -p src/build-gcc
	cd src
	@which -- $(TARGET)-as || echo $(TARGET)-as is not in the PATH
	$(WGET) ftp://ftp.gnu.org/gnu/gcc/gcc-7.2.0/gcc-7.2.0.tar.gz
	tar -xvf gcc-7.2.0.tar.gz
	cd build-gcc
	../gcc-7.2.0/configure --target=$(TARGET) --prefix="$(PREFIX)" --disable-nls --enable-languages=c,c++ --without-headers
	$(MAKE) all-gcc
	$(MAKE) all-target-libgcc
	$(MAKE) install-gcc
	$(MAKE)	install-target-libgcc
	$(MAKE) clean

uninstall:
	$(RM) -r bin i686-elf include lib libexec share src

clean:
	$(RM) -r src
