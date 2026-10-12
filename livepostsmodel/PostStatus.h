#pragma once

#include "LivePosts.h"
#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace LivePostsModel
{
    inline std::string to_string(PostStatus status)
    {
        switch (status)
        {
        case PostStatus::Draft:
            return "Draft";

        case PostStatus::PendingModeration:
            return "PendingModeration";

        case PostStatus::Live:
            return "Live";

        case PostStatus::Rejected:
            return "Rejected";
        }

        throw std::runtime_error("Unknown PostStatus");
    }

    inline PostStatus postStatusFromString(const std::string &value)
    {
        if (value == "Draft")
            return PostStatus::Draft;

        if (value == "PendingModeration")
            return PostStatus::PendingModeration;

        if (value == "Live")
            return PostStatus::Live;

        if (value == "Rejected")
            return PostStatus::Rejected;

        throw std::runtime_error("Invalid PostStatus: " + value);
    }

}