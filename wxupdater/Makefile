
include ../Makefile.config

CFLAGS+=`wx-config --cflags`
CLIBS+=`wx-config --libs`

BUILDDIR=../build-$(TARGET)

CFLAGS+=-I../chacolib

SOURCES=\
	BasicFile.cpp \
	Chameleon.cpp \
	ChFrm.cpp \
	Dbg.cpp \
	main.cpp \
	TaskMgr.cpp \
	Threading.cpp

HEADER=\
	BasicFile.h \
	Chaco.h \
	Chameleon.h \
	ChFrm.h \
	Dbg.h \
	Task.h \
	TaskMgr.h \
	Threading.h

all: $(BUILDDIR)/wxflasher$(EXE)

$(BUILDDIR)/wxflasher$(EXE): mkdata$(EXE) $(SOURCES) $(HEADER) Makefile coreversion.h $(BUILDDIR)/chacolib.a
	./mkdata$(EXE) update/*beta??.rbf update/*beta??_v2.rbf update/*.bin data.c
#	$(CXX) $(CFLAGS) -o $(BUILDDIR)/wxflasher$(EXE) $(SOURCES) $(BUILDDIR)/chacolib.a $(CLIBS)
	$(CXX) $(CFLAGS) -o $(BUILDDIR)/wxflasher$(EXE) $(SOURCES) ../chacolib/chacolib.c $(CLIBS)
#	-$(UPX) $(BUILDDIR)/wxflasher$(EXE)

coreversion.h: update/*.rbf update/*.bin Makefile
	echo "#define __COREVERSION__" '"'`ls update/*beta??.rbf | sed 's:.*chameleon_\(.*\).rbf:\1:'`'"' > coreversion.h

mkdata$(EXE): mkdata.c
	$(CC) -o mkdata$(EXE) mkdata.c

clean:
	$(RM) $(BUILDDIR)/wxflasher$(EXE)
	$(RM) ./mkdata$(EXE)

