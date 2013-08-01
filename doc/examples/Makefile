CPPFLAGS =
CXXFLAGS = -std=c++11 -stdlib=libc++
LDFLAGS  = -lrfc

PROGRAMS = md5 sha1 uri uuid

all: $(PROGRAMS)

clean:
	$(RM) $(PROGRAMS) *.o *~

.PHONY: all clean
