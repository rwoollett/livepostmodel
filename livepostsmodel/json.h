#pragma once

#include "LivePosts.h"
#include "timestamp.h"
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace LivePostsModel
{

  inline void to_json(json &jsonOut, Post const &value)
  {
    jsonOut["id"] = value.id;
    jsonOut["title"] = value.title;
    jsonOut["content"] = value.content;
    jsonOut["user"] = value.user;
    jsonOut["date"] = LivePostsModel::formatDate(value.tpDate);

    jsonOut["thumbsUp"] = value.thumbsUp;
    jsonOut["hooray"] = value.hooray;
    jsonOut["heart"] = value.heart;
    jsonOut["rocket"] = value.rocket;
    jsonOut["eyes"] = value.eyes;

  }

  inline void from_json(json const &jsonIn, Post &value)
  {
    if (jsonIn.contains("id"))
    {
      jsonIn.at("id").get_to(value.id);
    }
    jsonIn.at("title").get_to(value.title);
    jsonIn.at("content").get_to(value.content);
    jsonIn.at("user").get_to(value.user);
    if (jsonIn.contains("date"))
    {
      jsonIn.at("date").get_to(value.date);
      auto tpOptD = LivePostsModel::parseDate(value.date);
      if (tpOptD)
        value.tpCreatedAt = *tpOptD;
    }

    jsonIn.at("thumbsUp").get_to(value.thumbsUp);
    jsonIn.at("hooray").get_to(value.hooray);
    jsonIn.at("heart").get_to(value.heart);
    jsonIn.at("rocket").get_to(value.rocket);
    jsonIn.at("eyes").get_to(value.eyes);
  };

} // namespace
