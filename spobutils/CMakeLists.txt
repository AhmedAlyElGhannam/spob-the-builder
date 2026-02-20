cmake_minimum_required(VERSION 3.22)

project(SPOB_UTILS)

include(GNUInstallDirs)

set(SPOB_LIBS
	spob_memory
	spob_string
)

foreach(spob_lib ${SPOB_LIBS})
	add_subdirectory(
	    "${CMAKE_CURRENT_SOURCE_DIR}/${spob_lib}/"
	    "${CMAKE_BINARY_DIR}/${spob_lib}/"
	)
endforeach()

install(FILES
    bit_math.h
    spobutils.h
    std_types.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/spobutils
)

