set(harpoon_dir "${CMAKE_CURRENT_LIST_DIR}")

add_library(harpoon-apps)

target_compile_definitions(harpoon-apps PRIVATE
    OS_ZEPHYR=1
)

if(${TARGET_PEP_BOARD} STREQUAL "mimx8mn_evk_a53_smp")
    target_compile_definitions(harpoon-apps PRIVATE
        CONFIG_BOARD_MIMX8MN_EVK_A53=1
    )
endif()

# Always add these sources
target_sources(harpoon-apps PRIVATE
    ${harpoon_dir}/common/libs/mailbox/mailbox.c
)

target_include_directories(harpoon-apps PRIVATE
	${harpoon_dir}
	${harpoon_dir}/common/
)

# Add these sources for non-linux environments
string(FIND "${TARGET_ENVIRONMENT}" "linux" position)
if( (${position} LESS 0) )
    ################################
    # Not a Linux build
    ###############################
    target_sources(harpoon-apps PRIVATE
        ${harpoon_dir}/common/libs/jailhouse/ivshmem.c
        ${harpoon_dir}/common/libs/hlog/hlog.c
    )

    target_compile_options(harpoon-apps PUBLIC
        -Wno-unused-variable
        -Wno-sign-compare
        -Wno-unused-parameter
    )


    target_include_directories(harpoon-apps PRIVATE
        ${harpoon_dir}/common/libs/jailhouse/
        ${harpoon_dir}/common/libs/hlog
    )

    string(FIND "${TARGET_ENVIRONMENT}" "zephyr" zephPosition)
    if( NOT ${zephPosition} LESS 0)
        target_link_libraries(harpoon-apps PRIVATE kernel)
        message (STATUS "adding harpoon-apps zephyr port")
        target_include_directories(harpoon-apps PRIVATE
            ${harpoon_dir}/common/zephyr
            ${harpoon_dir}/common/zephyr/boards
        )
    endif()

else()
    ################################
    # This is a linux build
    ################################

    target_sources(harpoon-apps PRIVATE
        ${harpoon_dir}/ctrl/ivshmem.c
    )

    target_include_directories(harpoon-apps PRIVATE
        ${harpoon_dir}/ctrl
    )

    target_include_directories(harpoon-apps PUBLIC
        ${harpoon_dir}
    )

    target_include_directories(pep PUBLIC ${harpoon_dir})

endif()




