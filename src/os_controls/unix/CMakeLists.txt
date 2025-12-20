target_sources(${PROJECT_NAME}
	PRIVATE
		qt_input/qt_init_settings.cpp
		user_input.cpp
		qt_input/qt_key_mapper.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/qt_input"
)
