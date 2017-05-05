# Install script for directory: D:/Projects/GIT/SIM_project/Imebra/library

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/imebra")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/libimebra1" TYPE FILE PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ FILES "D:/Projects/GIT/SIM_project/Imebra/build/copyright")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Projects/GIT/SIM_project/Imebra/build/Debug/imebra.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Projects/GIT/SIM_project/Imebra/build/Release/imebra.lib")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Shared library" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/Projects/GIT/SIM_project/Imebra/build/Debug/imebra.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/Projects/GIT/SIM_project/Imebra/build/Release/imebra.dll")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Include files" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/imebra" TYPE FILE FILES
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/VOILUT.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/baseStreamInput.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/baseStreamOutput.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/codecFactory.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/colorTransformsFactory.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/dataSet.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/definitions.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/dicomDictionary.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/dicomDir.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/dicomDirEntry.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/drawBitmap.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/exceptions.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/fileStreamInput.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/fileStreamOutput.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/image.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/imebra.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/lut.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/memoryPool.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/memoryStreamInput.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/memoryStreamOutput.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/modalityVOILUT.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/readMemory.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/readWriteMemory.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/readingDataHandler.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/readingDataHandlerNumeric.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/streamReader.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/streamWriter.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/tag.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/tagId.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/tagsEnumeration.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/transform.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/transformHighBit.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/transformsChain.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/writingDataHandler.h"
    "D:/Projects/GIT/SIM_project/Imebra/library/include/imebra/writingDataHandlerNumeric.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "D:/Projects/GIT/SIM_project/Imebra/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
