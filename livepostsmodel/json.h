#pragma once

#include "LivePosts.h"
#include "timestamp/timestamp.h"
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace Timestamp;

namespace LivePostsModel
{

  inline void to_json(json &jsonOut, Post const &value)
  {
    jsonOut["id"] = value.id;
    jsonOut["title"] = value.title;
    jsonOut["slug"] = value.slug;
    jsonOut["content"] = value.content;
    jsonOut["userId"] = value.userId;
    jsonOut["userName"] = value.userName;
    jsonOut["date"] = formatDate(value.tpDate);

    json reactions;
    reactions["thumbsUp"] = value.thumbsUp;
    reactions["hooray"] = value.hooray;
    reactions["heart"] = value.heart;
    reactions["rocket"] = value.rocket;
    reactions["eyes"] = value.eyes;
    jsonOut["reactions"] = reactions;

    jsonOut["live"] = value.live;
    jsonOut["allocated"] = value.allocated;
  }

  inline void from_json(json const &jsonIn, Post &value)
  {
    if (jsonIn.contains("id"))
    {
      jsonIn.at("id").get_to(value.id);
    }
    jsonIn.at("title").get_to(value.title);
    if (jsonIn.contains("slug"))
    {
      jsonIn.at("slug").get_to(value.slug);
    }
    jsonIn.at("content").get_to(value.content);
    jsonIn.at("userId").get_to(value.userId);
    if (jsonIn.contains("userName"))
    {
      jsonIn.at("userName").get_to(value.userName);
    }
    if (jsonIn.contains("date"))
    {
      jsonIn.at("date").get_to(value.date);
      auto tpOptD = parseDate(value.date);
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

    if (jsonIn.contains("live"))
    {
      jsonIn.at("live").get_to(value.live);
    }
    if (jsonIn.contains("allocated"))
    {
      jsonIn.at("allocated").get_to(value.allocated);
    }
  };

  inline void to_json(json &jsonOut, PostStage const &value)
  {
    jsonOut["postId"] = value.postId;
    jsonOut["title"] = value.title;
    jsonOut["live"] = value.live;
  }

  inline void from_json(json const &jsonIn, PostStage &value)
  {
    jsonIn.at("postId").get_to(value.postId);
    jsonIn.at("title").get_to(value.title);
    jsonIn.at("live").get_to(value.live);
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

  inline void to_json(json &jsonOut, Moderation const &value)
  {
    jsonOut["id"] = value.id;
    jsonOut["userId"] = value.userId;
    jsonOut["seq"] = value.seq;
    jsonOut["value"] = value.value;
  }

  inline void from_json(json const &jsonIn, Moderation &value)
  {
    jsonIn.at("id").get_to(value.id);
    jsonIn.at("userId").get_to(value.userId);
    jsonIn.at("seq").get_to(value.seq);
    jsonIn.at("value").get_to(value.value);
  };

  inline void to_json(json &j, ModerationToken const &t)
  {
    j = json{
        {"input_ids", t.input_ids},
        {"attention_mask", t.attention_mask}};
  }

  inline void from_json(json const &j, ModerationToken &t)
  {
    // Validate required fields
    if (!j.contains("input_ids"))
      throw std::runtime_error("ModerationToken missing required field: input_ids");

    if (!j.contains("attention_mask"))
      throw std::runtime_error("ModerationToken missing required field: attention_mask");

    const auto &ids = j.at("input_ids");
    const auto &mask = j.at("attention_mask");

    if (!ids.is_array())
      throw std::runtime_error("'input_ids' must be an array");

    if (!mask.is_array())
      throw std::runtime_error("'attention_mask' must be an array");

    if (ids.empty())
      throw std::runtime_error("'input_ids' cannot be empty");

    if (mask.empty())
      throw std::runtime_error("'attention_mask' cannot be empty");

    if (ids.size() != mask.size())
      throw std::runtime_error("'input_ids' and 'attention_mask' must be the same length");

    t.input_ids.clear();
    t.attention_mask.clear();

    // Parse input_ids
    for (const auto &item : ids)
    {
      if (!item.is_number_integer())
        throw std::runtime_error("All items in 'input_ids' must be integers");

      t.input_ids.push_back(item.get<int64_t>());
    }

    // Parse attention_mask
    for (const auto &item : mask)
    {
      if (!item.is_number_integer())
        throw std::runtime_error("All items in 'attention_mask' must be integers");

      t.attention_mask.push_back(item.get<int64_t>());
    }
  }

  inline void to_json(json &j, ModerationLogits const &t)
  {
    j = json{
        {"logits", t.logits}};
  }

  inline void from_json(json const &j, ModerationLogits &t)
  {
    // Validate required fields
    if (!j.contains("logits"))
      throw std::runtime_error("ModerationLogits missing required field: logits");

    const auto &ids = j.at("logits");

    if (!ids.is_array())
      throw std::runtime_error("'logits' must be an array");

    if (ids.empty())
      throw std::runtime_error("'logits' cannot be empty");

    t.logits.clear();

    // Parse logits
    for (const auto &item : ids)
    {
      if (!item.is_number_float())
        throw std::runtime_error("All items in 'logits' must be floats");

      t.logits.push_back(item.get<float>());
    }
  }

} // namespace
