
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

    ModerateJobEvent() = default;
  };

  struct ModerateResultEvent
  {
    Subject subject{Subject::ModerateResult};
    std::string id;     // id
    std::string userId; // ws user id
    // bool reject = true;
    // double toxicity = 0.0;
    bool isRejected = true;
    float score = 0.0;
    int classIndex = 0;
    std::string label;
    std::vector<float> probabilities;

    ModerateResultEvent() = default;
  };

  // struct ModerateResultEvent
  // {
  //   std::string subject = "moderate_result";
  //   std::string userId;
  //   bool isRejected;
  //   float score;
  //   int classIndex;
  //   std::vector<float> probabilities;
  // };

}
#endif // EVENT_LIVEPOST_ACTIONS_H
