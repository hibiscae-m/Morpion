#ifndef RESOURCESMANAGER_H
#define RESOURCESMANAGER_H

#include <string_view>
#include <unordered_map>

template <typename T>
class ResourcesManager
{
public:
    ResourcesManager() = delete;
    static T const& getResource(std::string_view const& texture_location) {
        auto result = resources.find(texture_location);
        if (result == std::end(resources)) {
            if (!resources[texture_location].loadFromFile(texture_location.data())) {
                // Handle loading error
            }
            return resources[texture_location];
        }
        return result->second;
    }
private:
    static std::unordered_map<std::string_view, T> resources;
};

#endif //RESOURCESMANAGER_H