CPPFLAGS =
CXXFLAGS = -std=c++11 -stdlib=libc++
LDFLAGS  = -lrfc

PROGRAMS = http json md5 sha1 uri utf8 uuid

all: $(PROGRAMS)

clean:
	$(RM) $(PROGRAMS) *.o *~

.PHONY: all clean
