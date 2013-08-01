librfc: RFC implementations for C/C++
=====================================

.. image:: https://travis-ci.org/unlicensed/librfc.png?branch=master
   :target: https://travis-ci.org/unlicensed/librfc
   :align: right
   :alt: Travis CI build status

``librfc`` is a C/C++ shared library containing public domain implementations
of core RFC data structures and algorithms written in C++11.

Features
--------

* No runtime dependencies other than the system's C++ standard library.
* No build prerequisites beyond the Autotools toolchain and a C++11 compiler.
* Compatible with Clang and GCC, or any standard C++11 implementation.
* Plays nice with others: all exported symbols are prefixed with ``rfc``.
* 100% free and unencumbered `public domain <http://unlicense.org/>`_ software,
  usable in any context and for any purpose.

Current Status
--------------

This table summarizes which RFC specifications are implemented at present:

=============== ======== ==================================== ================
Header          Spec     Description                          Status
=============== ======== ==================================== ================
<rfc/http.h>    RFC 2616 Hypertext Transfer Protocol HTTP/1.1 WIP
<rfc/json.h>    RFC 4627 JavaScript Object Notation (JSON)    WIP
<rfc/md5.h>     RFC 1321 The MD5 Message-Digest Algorithm     WIP
<rfc/sha1.h>    RFC 3174 US Secure Hash Algorithm 1 (SHA1)    WIP
<rfc/uri.h>     RFC 3986 Uniform Resource Identifier (URI)    WIP
<rfc/utf8.h>    RFC 3629 UTF-8                                WIP
<rfc/uuid.h>    RFC 4122 Universally Unique Identifier (UUID) WIP
=============== ======== ==================================== ================

Build Prerequisites
-------------------

* Clang_ (>= 3.0) or GCC_ (>= 4.7)
* Autoconf_ (>= 2.68)
* Automake_ (>= 1.11)
* Libtool_ (>= 2.2)

.. _Clang:    http://clang.llvm.org/
.. _GCC:      http://gcc.gnu.org/
.. _Autoconf: http://www.gnu.org/software/autoconf/
.. _Automake: http://www.gnu.org/software/automake/
.. _Libtool:  http://www.gnu.org/software/libtool/

Build Dependencies
------------------

* Boost.Test_ (>= 1.48), for ``make check`` unit tests only

.. _Boost.Test: http://www.boost.org/libs/test/

Installation
------------

Installation on Unix
^^^^^^^^^^^^^^^^^^^^

::

   $ ./autogen.sh
   $ ./configure                        # on Linux
   $ ./configure --with-stdlib=libc++   # on FreeBSD / Mac OS X
   $ make
   $ sudo make install
   $ sudo ldconfig                      # on Linux

Elsewhere
---------

Find this project at: GitHub_, Bitbucket_, Ohloh_, Freecode_, SourceForge_,
and `Travis CI`_.

.. _GitHub:      http://github.com/unlicensed/librfc
.. _Bitbucket:   http://bitbucket.org/unlicensed/librfc
.. _Ohloh:       http://www.ohloh.net/p/librfc
.. _Freecode:    http://freecode.com/projects/librfc
.. _SourceForge: http://sourceforge.net/projects/librfc/
.. _Travis CI:   http://travis-ci.org/unlicensed/librfc

Author
------

* `Arto Bendiken <https://github.com/bendiken>`_ - http://ar.to/

Donations
---------

If you found this software useful and would like to encourage its
maintenance and further development, please consider making a donation to
the `Bitcoin`_ wallet address `15vNqz4kKWGjQmMv55KvuZwtbSkqXDx5AW`__.

.. _Bitcoin: http://en.wikipedia.org/wiki/Bitcoin
.. __: bitcoin:15vNqz4kKWGjQmMv55KvuZwtbSkqXDx5AW?label=librfc.org&message=Donation

License
-------

This is free and unencumbered public domain software. For more information,
see http://unlicense.org/ or the accompanying ``UNLICENSE`` file.
