include ../../../config.mak

TARGET = ../libmlteffectv$(LIBSUF)

OBJS = factory.o \
	   filter_burn.o \
	   image.o \
	   utils.o

CFLAGS += -I../..

LDFLAGS+=-L../../framework -lmlt

SRCS := $(OBJS:.o=.c)

all: 	$(TARGET)

$(TARGET): $(OBJS)
		$(CC) $(SHFLAGS) -o $@ $(OBJS) $(LDFLAGS)

depend:	$(SRCS)
		$(CC) -MM $(CFLAGS) $^ 1>.depend

distclean:	clean
		rm -f .depend

clean:	
		rm -f $(OBJS) $(TARGET) 

install: all
	install -m 755 $(TARGET) "$(DESTDIR)$(prefix)/share/mlt/modules"

ifneq ($(wildcard .depend),)
include .depend
endif