#================================================
SHELL := /bin/bash
#================================================
GSRC = ../src
GBIN = bin
GBUILD = build
GBUILD_G = build_g
GTARGET = $(GBIN)/rdv_qt
#================================================
# cpp
#================================================
all: clean_exe qmake compile run
all_g: clean_exe qmake compile run_g
#================================================
qmake:
	@qmake 
compile:
	@make
run:
	@source envs.sh && $(GTARGET) $(argv)
run_g:
	@source envs.sh && gdb -ex run --args $(GTARGET) $(argv)
clean_exe: 
	@if ! [ -d $(GBIN) ] ; then mkdir -p $(GBIN) ; fi
	rm -f $(GTARGET)
clean: clean_g
	@if ! [ -d $(GBIN) ] ; then mkdir -p $(GBIN) ; fi
	@if ! [ -d $(GBUILD) ] ; then mkdir -p $(GBUILD) ; fi
	rm -f $(GBUILD)/* $(GTARGET)
clean_g: 
	@if ! [ -d $(GBIN) ] ; then mkdir -p $(GBIN) ; fi
	@if ! [ -d $(GBUILD_G) ] ; then mkdir -p $(GBUILD_G) ; fi
	rm -f $(GBUILD_G)/* $(GTARGET)
#================================================
