set(PUBLIC_HEADER
	h/compare.h
	h/component.h
	h/dump.h
	h/list.h
	h/separator.h
	h/easy_apy.h
)

set(EASY_DUMP_SOURCES
	c/component.cpp
	c/dump.cpp
	c/separator.cpp
)

if(BUILD_STATIC_LIBS)
	add_library(EasyDump STATIC ${PUBLIC_HEADERS} ${EASY_DUMP_SOURCES})
endif()




