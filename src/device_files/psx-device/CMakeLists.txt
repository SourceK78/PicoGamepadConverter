# SPDX-License-Identifier: GPL-3.0-or-later
#
add_library(psx-device INTERFACE)
target_include_directories(psx-device INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(psx-device INTERFACE pico_stdlib hardware_pio hardware_gpio)
target_sources(psx-device INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/controller_simulator.c
    ${CMAKE_CURRENT_LIST_DIR}/controller_simulator.h)

if(PICO_BOARD STREQUAL "waveshare_rp2040_zero")
    # GPIO19-22 not exposed on RP2040 Zero.
    # Pins match config.h profile: CMD=5, CLK=6, ATT(SEL)=7, DAT=8, ACK=26
    set(PSX_PIN_CMD 5)
    set(PSX_PIN_CLK 6)
    set(PSX_PIN_SEL 7)
    set(PSX_PIN_DAT 8)
    set(PSX_PIN_ACK 26)
    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/psxSPI.pio.in
        ${CMAKE_CURRENT_BINARY_DIR}/psxSPI.pio
        @ONLY
    )
    pico_generate_pio_header(psx-device ${CMAKE_CURRENT_BINARY_DIR}/psxSPI.pio)
else()
    pico_generate_pio_header(psx-device ${CMAKE_CURRENT_LIST_DIR}/psxSPI.pio)
endif()
