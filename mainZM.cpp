// This is me using std::format to print out a struct.
	#include <iostream>
	#include <format>
	#include <string>

	struct Point {
		int x;
		int y;
	};

	template <>
	struct std::formatter<Point> {
		template <typename ParseContext>
		constexpr typename ParseContext::iterator parse(ParseContext& ctx) {
			return ctx.begin();
		}

		template <typename FormatContext>
		FormatContext format(const Point& p, FormatContext& ctx) const {
			return std::format_to(ctx.out(), "({}, {})", p.x, p.y);
		}
	};

	int main() {
		Point myPoint = {3, 4};
		std::cout << std::format("The point is: {}", myPoint.x) << std::endl;
		return 0;
	}
