#pragma once

#include "LivePosts.h"
#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace LivePostsModel
{
    inline std::string to_string(RenderStatus status)
    {
        switch (status)
        {
        case RenderStatus::Pending:
            return "Pending";

        case RenderStatus::Completed:
            return "Completed";

        case RenderStatus::Failed:
            return "Failed";

        }

        throw std::runtime_error("Unknown RenderStatus");
    }

    inline RenderStatus renderStatusFromString(const std::string &value)
    {
        if (value == "Pending")
            return RenderStatus::Pending;

        if (value == "Completed")
            return RenderStatus::Completed;

        if (value == "Failed")
            return RenderStatus::Failed;


        throw std::runtime_error("Invalid RenderStatus: " + value);
    }

}