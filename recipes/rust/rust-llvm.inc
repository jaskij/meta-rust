
SUMMARY = "LLVM compiler framework (packaged with rust)"
LICENSE = "NCSA"

S = "${WORKDIR}/rustc-${PV}/src/llvm"

inherit autotools

EXTRA_OECONF += "--enable-targets=x86,x86_64,arm,aarch64,mips,powerpc"
EXTRA_OECONF += "--enable-optimized"
EXTRA_OECONF += "--disable-bindings"
EXTRA_OECONF += "--enable-keep-symbols"

do_install_append () {
	cd ${D}${bindir}
	ln -s *-llc llc
	for i in *-llvm-*; do
		link=$(echo $i | sed -e 's/.*-llvm-\(.*\)/\1/')
		ln -s $i llvm-$link
	done
}

BBCLASSEXTEND = "native"

