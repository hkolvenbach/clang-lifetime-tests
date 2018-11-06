#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

struct my_pointer {
  int &operator*();
};

namespace { int fixed_int = 0; }
int & my_pointer::operator*() { return fixed_int; }

struct Owner {
  ~Owner();
  int m;
  int f();
};

Owner::~Owner() { }
int Owner::f() { return 0; }

void f(int *) { }
void g(int **) { }
void h(int *, int **) { }

namespace supress_further_warnings {
namespace { int fixed_int_2 = 0; }
int *f(int *) { return &fixed_int_2; }
}

namespace P0936 {

template <typename T> void use(const T &);
template <> void use(const std::string &) { }
template <> void use(const std::string_view &) { }

std::vector<int> getVec() { return std::vector<int>(); }

std::optional<std::vector<int>> getOptVec() {
  return std::optional<std::vector<int>>();
}

std::vector<int> getVec_alt() { return std::vector<int>(); }

std::unique_ptr<std::vector<int>> getOptVec_alt()  {
  return std::unique_ptr<std::vector<int>>();
}

std::string GetString() { return std::string(); }

void f(std::string_view) { }

} // namespace P0936

std::string operator"" _s(const char *, std::size_t) { return std::string(); }

int main() { return 0; }

