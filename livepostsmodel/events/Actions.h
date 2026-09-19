
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
    std::string title;

    PostCreateEvent() = default;
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
    std::string id;     // id
    std::string userId; // ws user id
    std::string value;
    uint64_t seq{0};

    ModerateJobEvent() = default;
  };

  struct ModerateResultEvent
  {
    Subject subject{Subject::ModerateResult};
    std::string id;     // id
    std::string userId; // ws user id
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
