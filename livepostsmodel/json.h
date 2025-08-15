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
    jsonOut["userId"] = value.userId;
    jsonOut["userName"] = value.userName;
    jsonOut["date"] = LivePostsModel::formatDate(value.tpDate);

    json reactions;
    reactions["thumbsUp"] = value.thumbsUp;
    reactions["hooray"] = value.hooray;
    reactions["heart"] = value.heart;
    reactions["rocket"] = value.rocket;
    reactions["eyes"] = value.eyes;
    jsonOut["reactions"] = reactions;
  }

  inline void from_json(json const &jsonIn, Post &value)
  {
    if (jsonIn.contains("id"))
    {
      jsonIn.at("id").get_to(value.id);
    }
    jsonIn.at("title").get_to(value.title);
    jsonIn.at("content").get_to(value.content);
    jsonIn.at("userId").get_to(value.userId);
    jsonIn.at("userName").get_to(value.userName);
    if (jsonIn.contains("date"))
    {
      jsonIn.at("date").get_to(value.date);
      auto tpOptD = LivePostsModel::parseDate(value.date);
      if (tpOptD)
        value.tpDate = *tpOptD;
    }
    if (jsonIn.contains("reactions"))
    {
      json reactions = jsonIn.at("reactions");
      reactions.at("thumbsUp").get_to(value.thumbsUp);
      reactions.at("hooray").get_to(value.hooray);
      reactions.at("heart").get_to(value.heart);
      reactions.at("rocket").get_to(value.rocket);
      reactions.at("eyes").get_to(value.eyes);
    }
  };

  
  inline void to_json(json &jsonOut, User const &value)
  {
    jsonOut["id"] = value.id;
    jsonOut["name"] = value.name;
    jsonOut["authId"] = value.authId;
  }

  inline void from_json(json const &jsonIn, User &value)
  {
    if (jsonIn.contains("id"))
    {
      jsonIn.at("id").get_to(value.id);
    }
    jsonIn.at("name").get_to(value.name);
    jsonIn.at("authId").get_to(value.authId);
  };

} // namespace
