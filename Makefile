all: json-test-asan json-test-no-asan

json-test-asan: main.cpp json.hpp test_json.hpp
	$(CXX) -g -O0 -fsanitize=address $(CXXFLAGS) -o json-test-asan main.cpp

json-test-no-asan: main.cpp json.hpp test_json.hpp
	$(CXX) -g -O0 $(CXXFLAGS) -o json-test-no-asan main.cpp

clean:
	rm -f json-test-asan json-test-no-asan
