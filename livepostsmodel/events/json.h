#pragma once

#include "Actions.h"
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace LivePostsEvents
{

  inline void to_json(json &jsonOut, PostCreateEvent const &value)
  {
    json obj;
    obj["id"] = value.id;
    obj["title"] = value.title;

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
    obj.at("title").get_to(value.title);
  };

  inline void to_json(json &jsonOut, PostStageEvent const &value)
  {
    json obj;
    obj["id"] = value.id;
    obj["slug"] = value.slug;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::PostStage)
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

  inline void to_json(json &jsonOut, ModerateJobEvent const &value)
  {
    json obj;
    obj["id"] = value.id;
    obj["userId"] = value.userId;
    obj["value"] = value.value;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::ModerateJob)
    {
      throw std::string("ModerateJobEvent::to_json - Subject should be ModerateJob");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, ModerateJobEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);

    obj.at("id").get_to(value.id);
    obj.at("userId").get_to(value.userId);
    obj.at("value").get_to(value.value);
  };

  inline void to_json(json &jsonOut, ModerateResultEvent const &value)
  {
    json obj;
    obj["id"] = value.id;
    obj["userId"] = value.userId;
    obj["reject"] = value.reject;
    obj["toxicity"] = value.toxicity;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::ModerateResult)
    {
      throw std::string("ModerateResultEvent::to_json - Subject should be ModerateResult");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, ModerateResultEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);

    obj.at("id").get_to(value.id);
    obj.at("userId").get_to(value.userId);
    obj.at("reject").get_to(value.reject);
    obj.at("toxicity").get_to(value.toxicity);
  };

} // namespace Events
