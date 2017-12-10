.ONESHELL:all
CC=gcc
export PREFIX="$(HOME)/LemonOS/toolchain"
export TARGET=i686-elf
export PATH:="$(PREFIX)/bin:$(PATH)"

notarget: binutils gcc

binutils:
	mkdir -p src/build-binutils
	cd src
	wget ftp://ftp.gnu.org/gnu/binutils/binutils-2.29.tar.gz
	tar -xvf binutils-2.29.tar.gz
	cd build-binutils
	../binutils-2.29/configure --target=$(TARGET) --prefix="$(PREFIX)" --with-sysroot --disable-nls --disable-werror
	$(MAKE)
	$(MAKE) install
	cd ../..

gcc:
	mkdir -p src/build-gcc
	cd src
	@which -- $(TARGET)-as || @echo $(TARGET)-as is not in the PATH
	wget ftp://ftp.gnu.org/gnu/gcc/gcc-6.3.0/gcc-6.3.0.tar.gz
	tar -xvf gcc-6.3.0.tar.gz
	cd build-gcc
	../gcc-6.3.0/configure --target=$(TARGET) --prefix="$(PREFIX)" --disable-nls --enable-languages=c,c++ --without-headers
	$(MAKE) all-gcc
	$(MAKE) all-target-libgcc
	$(MAKE) install-gcc
	$(MAKE)	install-target-libgcc

clean:
	rm -rf src
