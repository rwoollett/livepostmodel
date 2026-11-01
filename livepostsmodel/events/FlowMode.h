#pragma once

#include "Actions.h"
#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace LivePostsEvents
{
    inline std::string to_string(FlowMode status)
    {
        switch (status)
        {
        case FlowMode::Create:
            return "Create";

        case FlowMode::Update:
            return "Update";
        }
        throw std::runtime_error("Unknown FlowMode");
    }

    inline FlowMode flowModeFromString(const std::string &value)
    {
        if (value == "Create")
            return FlowMode::Create;

        if (value == "Update")
            return FlowMode::Update;

        throw std::runtime_error("Invalid FlowMode: " + value);
    }

}