#--------------------------------------------------------------------
# Inviwo hdf Module
ivw_module(HDF5)

find_package(HDF5 COMPONENTS C CXX HL)

#--------------------------------------------------------------------
# Add header files
set(HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/datastructures/hdf5handle.h
    ${CMAKE_CURRENT_SOURCE_DIR}/datastructures/hdf5metadata.h
    ${CMAKE_CURRENT_SOURCE_DIR}/datastructures/hdf5path.h
    ${CMAKE_CURRENT_SOURCE_DIR}/hdf5exception.h
    ${CMAKE_CURRENT_SOURCE_DIR}/hdf5types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/hdf5utils.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ports/hdf5port.h
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/hdf5pathselection.h
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/hdf5source.h
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/hdf5volumesource.h
)
ivw_group("Header Files" ${HEADER_FILES})

#--------------------------------------------------------------------
# Add source files
set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/datastructures/hdf5handle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/datastructures/hdf5metadata.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/datastructures/hdf5path.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hdf5exception.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hdf5types.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hdf5utils.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/hdf5pathselection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/hdf5source.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/processors/hdf5volumesource.cpp
)
ivw_group("Source Files" ${SOURCE_FILES})


#--------------------------------------------------------------------
# Create module
ivw_create_module(${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(inviwo-module-hdf5 PUBLIC ${HDF5_LIBRARIES}
                                                ${HDF5_HL_LIBRARIES}
                                                ${HDF5_CXX_LIBRARIES}
                                                ${HDF5_C_LIBRARIES})

ivw_make_package(InviwoHDF5Module inviwo-module-hdf5)
