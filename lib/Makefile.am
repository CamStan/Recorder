

lib_LTLIBRARIES = librecorder.la

if HAVE_GOTCHA
lib_LTLIBRARIES += librecorder_gotcha.la
endif


disabled_layers = $(DISABLE_POSIX) $(DISABLE_MPI) $(DISABLE_HDF5)

librecorder_la_SOURCES = recorder-hdf5.c  recorder-logger.c  recorder-mpi.c  recorder-mpi-init-finalize.c  recorder-posix.c  recorder-utils.c
librecorder_la_CFLAGS = -I$(top_srcdir)/include -D_LARGEFILE64_SOURCE -DRECORDER_PRELOAD $(disabled_layers)
librecorder_la_LDFLAGS = -lpthread -lhdf5 -version-info 0:0:0

if HAVE_GOTCHA

librecorder_gotcha_la_SOURCES = recorder-posix.c  recorder-logger.c  recorder-mpi-init-finalize.c  recorder-utils.c  gotcha_map_recorder_list.c
librecorder_gotcha_la_LIBADD = $(GOTCHA_LIBS)
librecorder_gotcha_la_CFLAGS = -I$(top_srcdir)/include -D_LARGEFILE64_SOURCE $(disabled_layers) -DRECORDER_GOTCHA $(GOTCHA_INCLUDE)
librecorder_gotcha_la_LDFLAGS = -lpthread -lhdf5 $(GOTCHA_LIBS) -version-info 0:0:0

endif
