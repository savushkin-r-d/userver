project(userver-samples CXX)

add_custom_target(${PROJECT_NAME})

# Imitate an installed userver in samples.
file(WRITE "${CMAKE_BINARY_DIR}/package_stubs/userverConfig.cmake")

add_subdirectory(config_service)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-config_service)

add_subdirectory(testsuite-support)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-testsuite-support)

if (USERVER_FEATURE_GRPC)
  add_subdirectory(grpc_service)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-grpc_service)

  add_subdirectory(grpc_middleware_service)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-grpc_middleware_service)
endif()

add_subdirectory(json2yaml)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-json2yaml)

add_subdirectory(hello_service)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-hello_service)

add_subdirectory(http_middleware_service)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-http_middleware_service)

add_subdirectory(multipart_service)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-multipart_service)

add_subdirectory(websocket_service)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-websocket_service)

add_subdirectory(https_service)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-https_service)

add_subdirectory(tcp_service)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-tcp_service)

add_subdirectory(tcp_full_duplex_service)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-tcp_full_duplex_service)

if (USERVER_FEATURE_MONGODB)
  add_subdirectory(http_caching)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-http_caching)

  add_subdirectory(mongo_service)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-mongo_service)

  add_subdirectory(mongo-support)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-mongo-support)
endif()

if (USERVER_FEATURE_POSTGRESQL)
  add_subdirectory(postgres_service)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-postgres_service)

  add_subdirectory(postgres_auth)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-postgres_auth)

  add_subdirectory(digest_auth_service)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-digest_auth)

  add_subdirectory(postgres-support)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-postgres-support)
endif()

add_subdirectory(production_service)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-production_service)

add_subdirectory(static_service)
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-static_service)

if (USERVER_FEATURE_REDIS)
  add_subdirectory(redis_service)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-redis_service)
endif()

if (USERVER_FEATURE_CLICKHOUSE)
  add_subdirectory(clickhouse_service)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-clickhouse_service)
endif()

if (USERVER_FEATURE_RABBITMQ)
  add_subdirectory(rabbitmq_service)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-rabbitmq_service)
endif()

if (USERVER_FEATURE_MYSQL)
  add_subdirectory(mysql_service)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-mysql_service)
endif()

if (USERVER_FEATURE_YDB AND USERVER_FEATURE_MONGODB)
  add_subdirectory(ydb_service)
  add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-ydb_service)
endif()

# Clean up fake userver installation above to avoid messing
# with find_package(userver) in the parent project.
file(REMOVE "${CMAKE_BINARY_DIR}/package_stubs/userverConfig.cmake")
