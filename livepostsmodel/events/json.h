#pragma once

#include "Actions.h"
#include "../timestamp.h"
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace LivePostsEvents
{


  // inline void from_json(json const &jsonIn, GameCreateEvent &value)
  // {
  //   json obj = jsonIn.at("payload");
  //   std::string subject;
  //   jsonIn.at("subject").get_to(subject);
  //   value.subject = SubjectFromNames.at(subject);
  //   obj.at("gameId").get_to(value.gameId);
  //   obj.at("board").get_to(value.board);
  //   auto tpOptCA = LivePostsModel::parseDate(value.createdAt);
  //   if (tpOptCA)
  //     value.tpCreatedAt = *tpOptCA;
  // };

  inline void to_json(json &jsonOut, PostCreateEvent const &value)
  {
    json obj;
    obj["id"] = value.id;
    obj["userId"] = value.userId;
    obj["title"] = value.title;
    obj["userName"] = value.userName;
    obj["live"] = value.live;
    obj["allocated"] = value.allocated;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::PostCreate)
    {
      throw std::string("PostCreateEvent::to_json - Subject should be PostCreate");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, PostCreateEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);

    obj.at("id").get_to(value.id);
    obj.at("userId").get_to(value.userId);
    obj.at("title").get_to(value.title);
    obj.at("userName").get_to(value.userName);
    obj.at("live").get_to(value.live);
    obj.at("allocated").get_to(value.allocated);
  };

  inline void to_json(json &jsonOut, PostStageEvent const &value)
  {
    json obj;
    obj["id"] = value.id;
    obj["slug"] = value.slug;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::PostCreate)
    {
      throw std::string("PostStageEvent::to_json - Subject should be PostStage");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, PostStageEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);

    obj.at("id").get_to(value.id);
    obj.at("slug").get_to(value.slug);
  };

} // namespace Events
