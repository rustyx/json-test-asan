#include "json.hpp"
#include "test_json.hpp"
#include <chrono>
#include <iostream>

using namespace std::literals;

void test_json_parse() {
  auto t1 = std::chrono::steady_clock::now();
  nlohmann::json j = nlohmann::json::parse(test_json);
  auto t2 = std::chrono::steady_clock::now();
  std::cout << "Parsing took " << ((t2 - t1) / 1ms) << " ms\n";
}

int *ptr;
void test_leak_local() {
  int p = 100;
  ptr = &p;
}

void test_use_after_scope() {
  int *p = nullptr;
  {
    int x[10] = {100};
    p = x;
  }
  *p = 1;
}

int main(int argc, char *argv[]) {
  if (argc > 1 && argv[1] == "local"s) {
    test_leak_local();
    std::cout << "Leak local test: " << *ptr << "\n";
  }
  if (argc > 1 && argv[1] == "scope"s) {
    test_use_after_scope();
    std::cout << "Use after scope test\n";
  }
  test_json_parse();
}
