set(BLOCK_NAME "CoC-Core")

if( NOT TARGET ${BLOCK_NAME} )
	get_filename_component( BLOCK_SOURCE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../src" ABSOLUTE )

	FILE(GLOB BLOCK_SOURCES ${BLOCK_SOURCE_PATH}/*.cpp)

	add_library( ${BLOCK_NAME} ${BLOCK_SOURCES} )
	target_include_directories( ${BLOCK_NAME} PUBLIC "${BLOCK_SOURCE_PATH}" )


	# If Cinder included from this block:

	target_include_directories( ${BLOCK_NAME} SYSTEM BEFORE PUBLIC "${CINDER_PATH}/include" )

	if( NOT TARGET cinder )
		include( "${CINDER_PATH}/proj/cmake/configure.cmake" )
		find_package( cinder REQUIRED PATHS
				"${CINDER_PATH}/${CINDER_LIB_DIRECTORY}"
				"$ENV{CINDER_PATH}/${CINDER_LIB_DIRECTORY}" )
	endif()

	target_link_libraries( ${BLOCK_NAME} PRIVATE cinder )
	
endif()





