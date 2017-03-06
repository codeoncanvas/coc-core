if( NOT TARGET CoC-Core )
	get_filename_component( COC-CORE_SOURCE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../src" ABSOLUTE )

	FILE(GLOB COC-CORE_SOURCES ${COC-CORE_SOURCE_PATH}/*.cpp)

	add_library( CoC-Core ${COC-CORE_SOURCES} )
	target_include_directories( CoC-Core PUBLIC "${COC-CORE_SOURCE_PATH}" )

	# If Cinder included from this block:

	target_include_directories( CoC-Core SYSTEM BEFORE PUBLIC "${CINDER_PATH}/include" )

	if( NOT TARGET cinder )
		include( "${CINDER_PATH}/proj/cmake/configure.cmake" )
		find_package( cinder REQUIRED PATHS
				"${CINDER_PATH}/${CINDER_LIB_DIRECTORY}"
				"$ENV{CINDER_PATH}/${CINDER_LIB_DIRECTORY}" )
	endif()

	target_link_libraries( CoC-Core PRIVATE cinder )

endif()