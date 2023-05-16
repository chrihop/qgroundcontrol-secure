
set(EXTRA_SRC)
if(BUILD_TESTING)
	list(APPEND EXTRA_SRC
		MockLink.cc
		MockLink.h
		MockLinkFTP.cc
		MockLinkFTP.h
		MockLinkMissionItemHandler.cc
		MockLinkMissionItemHandler.h
	)
endif()

include(FetchContent)

FetchContent_Declare(
    attestation
    GIT_REPOSITORY https://github.com/chrihop/attestation.git
    GIT_TAG v2
)

FetchContent_MakeAvailable(attestation)

set (ATTESTATION_INCLUDE_DIR "${attestation_SOURCE_DIR}/inc" CACHE STRING "" FORCE)
set (MBEDTLS_INCLUDE_DIR     "${attestation_SOURCE_DIR}/backend/mbedtls/include" CACHE STRING "" FORCE)

add_library(comm
	#BluetoothLink.cc
	#BluetoothLink.h
	LinkConfiguration.cc
	LinkConfiguration.h
	LinkInterface.cc
	LinkInterface.h
	LinkManager.cc
	LinkManager.h
	LogReplayLink.cc
	LogReplayLink.h
	MavlinkMessagesTimer.cc
	MavlinkMessagesTimer.h
	MAVLinkProtocol.cc
	MAVLinkProtocol.h
	QGCMAVLink.cc
	QGCMAVLink.h
	QGCSerialPortInfo.cc
	QGCSerialPortInfo.h
	SerialLink.cc
	SerialLink.h
	TCPLink.cc
	TCPLink.h
	UdpIODevice.cc
	UdpIODevice.h
	UDPLink.cc
	UDPLink.h
	EncryptionChacha20.cc

	${EXTRA_SRC}
)

target_link_libraries(comm
	PUBLIC
		qgc
		Qt5::Location
		Qt5::SerialPort
		Qt5::Test
		Qt5::TextToSpeech
		Qt5::Widgets
		qmdnsengine
		crypto_abstract
		mbedcrypto
)

target_include_directories(comm INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
	${ATTESTATION_INCLUDE_DIR}
	${MBEDTLS_INCLUDE_DIR}
)

target_compile_definitions(comm
	PRIVATE
	POSIX_LIBC
)