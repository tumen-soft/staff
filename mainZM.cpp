	// This is me using std::format to print out a struct.
	#include <iostream>
	#include <format>
	#include <string>

	struct Point {
		int x;
		int y;
	};

	template <>
struct std::formatter<Point> : public std::formatter<std::string_view>{
public:
    template <typename FormatContext>
    auto format(const Point& p, FormatContext& ctx) const {
        return std::format_to(ctx.out(), "x={} y={}", p.x, p.y);
    }
};




	int main() {
		Point myPoint = {3, 4};
		std::cout << std::format("The point is: {}", myPoint) << std::endl;
		return 0;
	}
