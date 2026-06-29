#include <iostream>

#include <entt/entt.hpp>


struct Position {
    double x{0.0};
    double y{0.0};
    double z{0.0};
};

void Update(entt::registry& registry) {
    auto view = registry.view<const Position>();

    view.each([](const auto entity, const auto& pos) {
        std::cout << "Entity: x = " << pos.x << ", y = " << pos.y << ", z = " << pos.z << std::endl;
    });
}


int main(int argc, char* argv[]) {
    std::cout << "Running Comet" << std::endl;

    entt::registry registry;

    {
        const auto entity = registry.create();
        registry.emplace<Position>(entity, 1.0, 2.0, 3.0);
    }

    Update(registry);

    return 0;
}