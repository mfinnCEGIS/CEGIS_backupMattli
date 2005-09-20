######################################################################
# Automatically generated by qmake (1.07a) Tue Jan 11 11:44:20 2005
# Manully Edited by $Id: mapimg.pro,v 1.5 2005/09/20 19:46:31 lwoodard Exp $ 
######################################################################

TARGET = mapimg2
#for each platform check that TIFFDIR environment variable is set.
# If it IS set, then set up the library and include paths
# If it is NOT set, report an error and exit

#bring environment variables into qmake variables
TIFFDIR = $$(TIFFDIR)
TIFFINCLUDE = $$(TIFFINCLUDE)
TIFFLIB = $$(TIFFLIB)

#make sure that TIFFDIR and/or TIFFLIB and TIFFINCLUDE are set
isEmpty( TIFFDIR ) {
    isEmpty( TIFFLIB ) {
        error( "TIFFDIR environment variable must be set to the directory containing the TIFF library before qmaking and compiling. You may set TIFFINCLUDE and TIFFLIB instead if the headers and libraries are not in the same directory" )
    }
    isEmpty( TIFFINCLUDE ) {
        error( "TIFFDIR environment variable must be set to the directory containing the TIFF library before qmaking and compiling. You may set TIFFINCLUDE and TIFFLIB instead if the headers and libraries are not in the same directory" )
    }
}

#else
LIBPATH += $(TIFFDIR) $(TIFFDIR)/libtiff $(TIFFDIR)/lib
INCLUDEPATH += . $(TIFFDIR) $(TIFFDIR)/libtiff $(TIFFDIR)/include

!isEmpty( TIFFLIB ) {
     LIBPATH += $(TIFFLIB)
}
!isEmpty( TIFFINCLUDE ) {
     INCLUDEPATH += $(TIFFINCLUDE)

}

win32:LIBS += libtiff.lib
unix:LIBS += -ltiff

TEMPLATE = app
INCLUDEPATH += .

CONFIG += qt warn_on

OBJECTS_DIR		= .tmp\obj
MOC_DIR		= .tmp\moc
UI_DIR		= .tmp\ui
RCC_DIR		= .tmp\rcc

# Input
HEADERS += aboutform.h \
           authorform.h \
           cproj.h \
           gctpnames.h \
           getprojinfo.h \
           imgio.h \
           jt_time.h \
           logform.h \
           mapedit.h \
           mapimg.h \
           mapimgdatatypes.h \
           mapimgedit.h \
           mapimgform.h \
           mapimgpalette.h \
           mapimgprogressdialog.h \
           mapimgvalidator.h \
           mapimgversion.h \
           proj.h \
           projectionedit.h \
           qdmsedit.h \
           qembed_images.h \
           qgctpbox.h \
           qimgframe.h \
           qimgpainter.h \
           rasterinfo.h \
           rasterxml.h \
           resampleform.h \
           resampleinfo.h \
           tiff2img.h \
           tinystr.h \
           tinyxml.h \
           window_flags.h
SOURCES += aboutform.cpp \
           alberfor.c \
           alberinv.c \
           alconfor.c \
           alconinv.c \
           authorform.cpp \
           azimfor.c \
           aziminv.c \
           cproj.c \
           eqconfor.c \
           eqconinv.c \
           equifor.c \
           equiinv.c \
           for_init.c \
           gctp.c \
           gnomfor.c \
           gnominv.c \
           goodfor.c \
           goodinv.c \
           gvnspfor.c \
           gvnspinv.c \
           hamfor.c \
           haminv.c \
           imgio.cpp \
           imolwfor.c \
           imolwinv.c \
           inv_init.c \
           lamazfor.c \
           lamazinv.c \
           lamccfor.c \
           lamccinv.c \
           logform.cpp \
           main.cpp \
           mapedit.cpp \
           mapimg.cpp \
           mapimgedit.cpp \
           mapimgform.cpp \
           mapimgprogressdialog.cpp \
           mapimgvalidator.cpp \
           merfor.c \
           merinv.c \
           millfor.c \
           millinv.c \
           molwfor.c \
           molwinv.c \
           obleqfor.c \
           obleqinv.c \
           omerfor.c \
           omerinv.c \
           orthfor.c \
           orthinv.c \
           paksz.c \
           polyfor.c \
           polyinv.c \
           projectionedit.cpp \
           psfor.c \
           psinv.c \
           qdmsedit.cpp \
           qgctpbox.cpp \
           qimgframe.cpp \
           rasterinfo.cpp \
           rasterxml.cpp \
           report.c \
           resampleform.cpp \
           resampleinfo.cpp \
           robfor.c \
           robinv.c \
           sinfor.c \
           sininv.c \
           somfor.c \
           sominv.c \
           sphdz.c \
           sterfor.c \
           sterinv.c \
           stplnfor.c \
           stplninv.c \
           tinystr.cpp \
           tinyxml.cpp \
           tinyxmlerror.cpp \
           tinyxmlparser.cpp \
           tmfor.c \
           tminv.c \
           untfz.c \
           utmfor.c \
           utminv.c \
           vandgfor.c \
           vandginv.c \
           wivfor.c \
           wivinv.c \
           wviifor.c \
           wviiinv.c
RESOURCES += mapIMGiimages.qrc
