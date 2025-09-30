
#ifndef EVENT_LIVEPOST_ACTIONS_H
#define EVENT_LIVEPOST_ACTIONS_H

#include "Subjects.h"
#include <string>
#include <chrono>

namespace LivePostsEvents
{

  struct PostCreateEvent
  {
    Subject subject{Subject::PostCreate};
    int id;
    int userId;
    std::string title;
    std::string userName;
    bool live;
    bool allocated;
    
    PostCreateEvent() = default;
  };

  struct PostStageEvent
  {
    Subject subject{Subject::PostStage};
    int id;
    std::string slug;

    PostStageEvent() = default;
  };

}
#endif // EVENT_LIVEPOST_ACTIONS_H
