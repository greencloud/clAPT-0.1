bin_PROGRAMS = clapt

QUIET_GEN = $(Q:@=@echo '  GEN   '$@;)

clapt_SOURCES =         \
    cab-main.c          \
    cab-ayuda.c         \
    cab-bersyon.c       \
    clapt.h

clapt_CFLAGS =          \
    $(CAB_CFLAGS)       \
    $(CAB_WARNINGS)     \
    -DPACKAGE_DATA_DIR=\""$(datadir)"\" \
    -DPACKAGE_LOCALE_DIR=\""$(datadir)/locale"\"

clapt_CXXFLAGS = $(clapt_CFLAGS)

clapt_LDADD = $(LDADD) -lm
