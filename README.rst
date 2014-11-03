*************************************
librfc: RFC implementations for C++14
*************************************

.. image:: https://api.travis-ci.org/dryproject/librfc.svg?branch=master
   :target: https://travis-ci.org/dryproject/librfc
   :alt: Travis CI build status

.. image:: https://scan.coverity.com/projects/3227/badge.svg
   :target: https://scan.coverity.com/projects/3227
   :alt: Coverity Scan build status

``librfc`` is a C/C++ shared library containing public domain implementations
of core RFC data structures and algorithms written in C++11.

Features
========

* No runtime dependencies other than the system's C++ standard library.
* No build prerequisites beyond the Autotools toolchain and a C++11 compiler.
* Compatible with Clang and GCC, or any standard C++11 implementation.
* Plays nice with others: all exported symbols are prefixed with ``rfc``.
* 100% free and unencumbered `public domain <http://unlicense.org/>`_ software,
  usable in any context and for any purpose.

Current Status
==============

This table summarizes which RFC specifications are implemented at present:

=============== ======== ==================================== ==================
Header          Spec     Description                          Status
=============== ======== ==================================== ==================
<rfc/http.h>    RFC 2616 Hypertext Transfer Protocol HTTP/1.1 WIP
<rfc/json.h>    RFC 4627 JavaScript Object Notation (JSON)    WIP
<rfc/md5.h>     RFC 1321 The MD5 Message-Digest Algorithm     WIP
<rfc/sha1.h>    RFC 3174 US Secure Hash Algorithm 1 (SHA1)    WIP
<rfc/uri.h>     RFC 3986 Uniform Resource Identifier (URI)    WIP
<rfc/utf8.h>    RFC 3629 UTF-8                                WIP
<rfc/uuid.h>    RFC 4122 Universally Unique Identifier (UUID) WIP
=============== ======== ==================================== ==================

Build Prerequisites
===================

* Clang_ (>= 3.2) or GCC_ (>= 4.8)
* Autoconf_ (>= 2.68)
* Automake_ (>= 1.11)
* Libtool_ (>= 2.2)

.. note::

   Older releases may work, but are not actively tested for.

.. _Clang:    http://clang.llvm.org/
.. _GCC:      http://gcc.gnu.org/
.. _Autoconf: http://www.gnu.org/software/autoconf/
.. _Automake: http://www.gnu.org/software/automake/
.. _Libtool:  http://www.gnu.org/software/libtool/

Installation
============

Installation on Unix
--------------------

::

   $ ./autogen.sh
   $ ./configure                        # on Linux
   $ ./configure --with-stdlib=libc++   # on FreeBSD / Mac OS X
   $ make
   $ sudo make install
   $ sudo ldconfig                      # on Linux

Elsewhere
=========

Find this project at: GitHub_, Bitbucket_, Ohloh_, Freecode_, SourceForge_,
`Travis CI`_, `Coverity Scan`_, Twitter_, and Tumblr_.

.. _GitHub:        http://github.com/dryproject/librfc
.. _Bitbucket:     http://bitbucket.org/dryproject/librfc
.. _Ohloh:         http://www.ohloh.net/p/librfc
.. _Freecode:      http://freecode.com/projects/librfc
.. _SourceForge:   http://sourceforge.net/projects/librfc/
.. _Travis CI:     http://travis-ci.org/dryproject/librfc
.. _Coverity Scan: http://scan.coverity.com/projects/3227
.. _Twitter:       http://twitter.com/librfc
.. _Tumblr:        http://librfc.tumblr.com/

Author
======

This project is part of the `DRY <http://dryproject.org/>`_ initiative.

* `Arto Bendiken <https://github.com/bendiken>`_ - http://ar.to/

Donations
=========

If you found this software useful and would like to encourage its
maintenance and further development, please consider making a $5 donation
to the author(s) via Gratipay_ or Bitcoin_.

.. _Gratipay: https://gratipay.com/bendiken/
.. _Bitcoin:  bitcoin:1BahgMdZYkLYmauNeu2fJKYKmeLy9ysqur?label=librfc.org&message=Donation

License
=======

This is free and unencumbered public domain software. For more information,
see http://unlicense.org/ or the accompanying ``UNLICENSE`` file.
