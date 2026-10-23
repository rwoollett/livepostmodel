
#ifndef EVENT_LIVEPOST_ACTIONS_H
#define EVENT_LIVEPOST_ACTIONS_H

#include "Subjects.h"
#include <string>
#include <chrono>
#include <vector>

namespace LivePostsEvents
{

  struct PostCreateEvent
  {
    Subject subject{Subject::PostCreate};
    int id = 0;
    std::string wsId;

    PostCreateEvent() = default;
  };

  struct UserCreateEvent
  {
    Subject subject{Subject::UserCreate};
    std::string authUserEmail;
    std::string wsId;

    UserCreateEvent() = default;
  };

  struct PostUpdateEvent
  {
    Subject subject{Subject::PostUpdate};
    int id = 0;
    std::string wsId;

    PostUpdateEvent() = default;
  };

  struct PostPublishedEvent
  {
    Subject subject{Subject::PostPublished};
    int postId = 0;
    int authorUserId = 0;
    std::string slug;
    std::string wsId;

    PostPublishedEvent() = default;
  };

  struct PostStageEvent
  {
    Subject subject{Subject::PostStage};
    int id = 0;
    std::string slug;

    PostStageEvent() = default;
  };

  struct ModerateJobEvent
  {
    Subject subject{Subject::ModerateJob};
    std::string id;
    std::string wsId;
    std::string value;
    uint64_t seq{0};

    ModerateJobEvent() = default;
  };

  struct ModerateResultEvent
  {
    Subject subject{Subject::ModerateResult};
    std::string id;
    std::string wsId;
    std::string purpose; // = "live" | "publish"
    uint64_t seq{0};
    bool isRejected = true;
    float score = 0.0;
    int classIndex = 0;
    std::string label;
    std::vector<float> probabilities;
    std::vector<std::string> matchedLabels;

    ModerateResultEvent() = default;
  };

}
#endif // EVENT_LIVEPOST_ACTIONS_H
