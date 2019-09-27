#pragma once

#include <stdexcept>
#include <string>

#include <formats/parse/to.hpp>
#include <utils/assert.hpp>

namespace server::handlers::auth {
class AuthCheckerBase;
}

namespace server::auth {

// Passport enviroments for users https://nda.ya.ru/3UVzHy
enum class UserEnv : int {
  kProd,
  kTest,
  kProdYateam,
  kTestYateam,
  kStress,
};

template <class Value>
UserEnv Parse(const Value& v, formats::parse::To<UserEnv>) {
  // https://nda.ya.ru/3UVzHy
  const std::string env_name = v.template As<std::string>();
  if (env_name == "Prod" || env_name == "Mimino") {
    return UserEnv::kProd;
  } else if (env_name == "Test") {
    return UserEnv::kTest;
  } else if (env_name == "ProdYateam") {
    return UserEnv::kProdYateam;
  } else if (env_name == "TestYateam") {
    return UserEnv::kTestYateam;
  } else if (env_name == "Stress") {
    return UserEnv::kStress;
  }

  UASSERT_MSG(false, "Unknown user env");
  throw std::runtime_error("Unknown user env " + env_name);
}

std::string ToString(UserEnv env);

}  // namespace server::auth
