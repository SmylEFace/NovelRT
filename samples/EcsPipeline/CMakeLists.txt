if(NOVELRT_VULKAN_SDK)
  find_package(Vulkan ${NOVELRT_VULKAN_VERSION} REQUIRED)
endif()

set(SOURCES
  main.cpp
  )

add_executable(EcsPipeline ${SOURCES})
add_dependencies(EcsPipeline Resources)
target_link_libraries(EcsPipeline
  PRIVATE
  Engine
  )
target_compile_definitions(EcsPipeline PUBLIC -DNOVELRT_MOLTENVK_VENDORED=$<IF:$<BOOL:${NOVELRT_MOLTENVK_VENDORED}>,1,0>)

copy_build_products(EcsPipeline
  DEPENDENCY Resources
  TARGET_LOCATION $<TARGET_FILE_DIR:EcsPipeline>/Resources

  DEPENDENCY Engine
  TARGET_LOCATION $<TARGET_FILE_DIR:EcsPipeline>
  )
