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
    obj["wsId"] = value.wsId;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::PostCreate)
    {
      throw std::runtime_error("PostCreateEvent::to_json - Subject should be PostCreate");
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
    obj.at("wsId").get_to(value.wsId);
  };

  inline void to_json(json &jsonOut, UserCreateEvent const &value)
  {
    json obj;
    obj["authUserEmail"] = value.authUserEmail;
    obj["authUserId"] = value.authUserId;
    obj["wsId"] = value.wsId;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::UserCreate)
    {
      throw std::runtime_error("UserCreateEvent::to_json - Subject should be UserCreate");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, UserCreateEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);

    obj.at("authUserEmail").get_to(value.authUserEmail);
    obj.at("authUserId").get_to(value.authUserId);
    obj.at("wsId").get_to(value.wsId);
  };

  inline void to_json(json &jsonOut, UserCreatedEvent const &value)
  {
    json obj;
    obj["wsId"] = value.wsId;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::UserCreated)
    {
      throw std::runtime_error("UserCreatedEvent::to_json - Subject should be UserCreated");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, UserCreatedEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);

    obj.at("wsId").get_to(value.wsId);
  };

  inline void to_json(json &jsonOut, PostUpdateEvent const &value)
  {
    json obj;
    obj["id"] = value.id;
    obj["wsId"] = value.wsId;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::PostUpdate)
    {
      throw std::runtime_error("PostUpdateEvent::to_json - Subject should be PostUpdate");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, PostUpdateEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);

    obj.at("id").get_to(value.id);
    obj.at("wsId").get_to(value.wsId);
  };

  inline void to_json(json &jsonOut, PostPublishedEvent const &value)
  {
    json obj;
    obj["postId"] = value.postId;
    obj["authorUserId"] = value.authorUserId;
    obj["slug"] = value.slug;
    obj["wsId"] = value.wsId;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::PostPublished)
    {
      throw std::runtime_error("PostPublished::to_json - Subject should be PostPublished");
    }
    jsonOut["subject"] = SubjectNames.at(value.subject);
  }

  inline void from_json(json const &jsonIn, PostPublishedEvent &value)
  {
    json obj = jsonIn.at("payload");
    std::string subject;
    jsonIn.at("subject").get_to(subject);
    value.subject = SubjectFromNames.at(subject);

    obj.at("postId").get_to(value.postId);
    obj.at("authorUserId").get_to(value.authorUserId);
    obj.at("slug").get_to(value.slug);
    obj.at("wsId").get_to(value.wsId);
  };

  inline void to_json(json &jsonOut, PostStageEvent const &value)
  {
    json obj;
    obj["id"] = value.id;
    obj["slug"] = value.slug;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::PostStage)
    {
      throw std::runtime_error("PostStageEvent::to_json - Subject should be PostStage");
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
    obj["wsId"] = value.wsId;
    obj["seq"] = value.seq;
    obj["value"] = value.value;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::ModerateJob)
    {
      throw std::runtime_error("ModerateJobEvent::to_json - Subject should be ModerateJob");
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
    obj.at("wsId").get_to(value.wsId);
    obj.at("seq").get_to(value.seq);
    obj.at("value").get_to(value.value);
  };

  inline void to_json(json &jsonOut, ModerateResultEvent const &value)
  {
    json obj;
    obj["id"] = value.id;
    obj["wsId"] = value.wsId;
    obj["purpose"] = value.purpose;
    obj["seq"] = value.seq;
    obj["isRejected"] = value.isRejected;
    obj["score"] = value.score;
    obj["classIndex"] = value.classIndex;
    obj["label"] = value.label;
    obj["probabilities"] = value.probabilities;
    obj["matchedLabels"] = value.matchedLabels;

    jsonOut["payload"] = obj;
    if (value.subject != Subject::ModerateResult)
    {
      throw std::runtime_error("ModerateResultEvent::to_json - Subject should be ModerateResult");
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
    obj.at("wsId").get_to(value.wsId);
    obj.at("purpose").get_to(value.purpose);
    obj.at("seq").get_to(value.seq);
    obj.at("isRejected").get_to(value.isRejected);
    obj.at("score").get_to(value.score);
    obj.at("classIndex").get_to(value.classIndex);
    obj.at("label").get_to(value.label);
    obj.at("matchedLabels").get_to(value.matchedLabels);

    if (!obj.contains("probabilities"))
      throw std::runtime_error("ModerateResultEvent missing required field: probabilities");

    const auto &ids = obj.at("probabilities");

    if (!ids.is_array())
      throw std::runtime_error("'probabilities' must be an array");

    if (ids.empty())
      throw std::runtime_error("'probabilities' cannot be empty");

    value.probabilities.clear();

    // Parse logits
    for (const auto &item : ids)
    {
      if (!item.is_number_float())
        throw std::runtime_error("All items in 'probabilities' must be floats");

      value.probabilities.push_back(item.get<float>());
    }
  };

} // namespace Events
