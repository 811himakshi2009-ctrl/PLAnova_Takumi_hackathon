# PLAnova, http://www.planova.org
#
# Copyright (c) 2013-2016, The PLAnova Team and contributors
#
#
#

include(CheckCXXSourceCompiles)
macro(REQUIRE_CXX_SOURCE_COMPILES _code _var)
	CHECK_CXX_SOURCE_COMPILES("${_code}" ${_var})
	if(NOT ${_var})
		unset(${_var} CACHE)
		MESSAGE(FATAL_ERROR "${_var} is required for this project to build properly.${ARGN} Aborting.")
	endif()
endmacro()
