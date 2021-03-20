#!/bin/sh



cppcheck --addon=cert.py sources/

cppcheck --addon=threadsafety.py sources/

cppcheck --addon=y2038.py sources/

