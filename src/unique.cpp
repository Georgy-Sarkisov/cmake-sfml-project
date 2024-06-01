// https://en.cppreference.com/w/cpp/memory/unique_ptr/reset

#include <iostream>
#include <memory>
#include <string_view>
using namespace std;

///////////////////__ѕ≈„ј“№_“»ѕј_ѕ≈–≈ћ≈ЌЌќ…__/////////////////
template <class T> constexpr std::string_view type_name() { //
	using namespace std;                                      //
#ifdef __clang__                                            //
	string_view p = __PRETTY_FUNCTION__;                      //
	return string_view(p.data() + 34, p.size() - 34 - 1);     //
#elif defined(__GNUC__)                                     //
	string_view p = __PRETTY_FUNCTION__; //
#if __cplusplus < 201402                                    //
	return string_view(p.data() + 36, p.size() - 36 - 1); //
#else                                                       //
	return string_view(p.data() + 49, p.find(';', 49) - 49); //
#endif                                                      //
#elif defined(_MSC_VER)                                     //
	string_view p = __FUNCSIG__;                          //
	return string_view(p.data() + 84, p.size() - 84 - 7); //
#endif                                                      //
} //
//////////////////////////////////////////////////////////////

void foo(int* x) { std::cout << "foo()\n"; }

struct FreeDeleter {
	void operator()(int*) const noexcept { cout << "FreeDeleter()\n"; }
};

int main() {

	unique_ptr<int, FreeDeleter>(new int(0), FreeDeleter());
	unique_ptr<int, decltype(&foo)>(new int(0), &foo);

	// как мы определили тип, который должен принимать deleter? :
	cout << type_name<unique_ptr<int, FreeDeleter>::pointer>();
	return 0;
}