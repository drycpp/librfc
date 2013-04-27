librfc: RFC implementations for C/C++
=====================================

.. image:: https://travis-ci.org/bendiken/librfc.png?branch=master
   :target: https://travis-ci.org/bendiken/librfc
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

Build Prerequisites
-------------------

* Clang_ (>= 3.0) or GCC_ (>= 4.6)
* Autoconf_ (>= 2.68)
* Automake_ (>= 1.11)
* Libtool_ (>= 2.2)

.. _Clang:    http://clang.llvm.org/
.. _GCC:      http://gcc.gnu.org/
.. _Autoconf: http://www.gnu.org/software/autoconf/
.. _Automake: http://www.gnu.org/software/automake/
.. _Libtool:  http://www.gnu.org/software/libtool/

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
---------

Find the project at: GitHub_, Bitbucket_, Ohloh_, Freecode_, SourceForge_,
and `Travis CI`_.

.. _GitHub:      http://github.com/bendiken/librfc
.. _Bitbucket:   http://bitbucket.org/bendiken/librfc
.. _Ohloh:       http://www.ohloh.net/p/librfc
.. _Freecode:    http://freecode.com/projects/librfc
.. _SourceForge: http://sourceforge.net/projects/librfc/
.. _Travis CI:   http://travis-ci.org/bendiken/librfc

License
-------

This is free and unencumbered public domain software. For more information,
see http://unlicense.org/ or the accompanying ``UNLICENSE`` file.
